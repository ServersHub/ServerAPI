#pragma comment(lib, "libcrypto.lib")

#include "Cache.h"

#include <unordered_map>
#include <string>
#include <cstdint>
#include <filesystem>
#include <openssl/evp.h>

namespace Cache
{
	std::string calculateSHA256(const std::filesystem::path& filename)
	{
		std::ifstream file(filename, std::ios::binary);
		if (!file.is_open()) {
			Log::GetLog()->error("Error opening file for SHA-256 calculation: " + filename.string());
			return "";
		}

		EVP_MD_CTX* mdctx = EVP_MD_CTX_new();
		if (mdctx == nullptr) {
			Log::GetLog()->error("Error creating EVP_MD_CTX");
			return "";
		}

		if (EVP_DigestInit_ex(mdctx, EVP_sha256(), nullptr) != 1) {
			EVP_MD_CTX_free(mdctx);
			Log::GetLog()->error("Error initializing SHA-256 context");
			return "";
		}

		const int bufferSize = 4096;
		char buffer[bufferSize];
		while (!file.eof()) {
			file.read(buffer, bufferSize);
			if (EVP_DigestUpdate(mdctx, buffer, file.gcount()) != 1) {
				EVP_MD_CTX_free(mdctx);
				Log::GetLog()->error("Error updating SHA-256 context");
				return "";
			}
		}

		unsigned char digest[EVP_MAX_MD_SIZE];
		unsigned int digestLen;
		if (EVP_DigestFinal_ex(mdctx, digest, &digestLen) != 1) {
			EVP_MD_CTX_free(mdctx);
			Log::GetLog()->error("Error finalizing SHA-256 context");
			return "";
		}

		EVP_MD_CTX_free(mdctx);

		std::string result;
		for (unsigned int i = 0; i < digestLen; i++) {
			char hex[3];
			snprintf(hex, sizeof(hex), "%02x", digest[i]);
			result += hex;
		}

		file.close();
		return result;
	}

	void saveToFile(const std::filesystem::path& filename, const std::string& content)
	{
		std::ofstream file(filename, std::ios::trunc);
		if (file.is_open()) {
			file << content;
			file.close();
		}
		else {
			Log::GetLog()->error("Error opening file for writing: " + filename.string());
		}
	}

	std::string readFromFile(const std::filesystem::path& filename)
	{
		std::ifstream file(filename);
		if (file.is_open()) {
			std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
			return content;
		}
		else {
			if (std::filesystem::exists(filename))
				Log::GetLog()->error("Error file exists but is not readable: " + filename.string());

			return "";
		}
	}
}