#pragma comment(lib, "libcrypto.lib")

#include "Cache.h"

#include <unordered_map>
#include <string>
#include <cstdint>
#include <filesystem>
#include <openssl/sha.h>

namespace Cache
{
	std::string calculateSHA256(const std::filesystem::path& filename)
	{
		std::ifstream file(filename, std::ios::binary);
		if (!file.is_open()) {
			Log::GetLog()->error("Error opening file for SHA-256 calculation: " + filename.string());
			return "";
		}

		SHA256_CTX sha256;
		SHA256_Init(&sha256);

		const int bufferSize = 4096;
		char buffer[bufferSize];
		while (!file.eof()) {
			file.read(buffer, bufferSize);
			SHA256_Update(&sha256, buffer, file.gcount());
		}

		unsigned char digest[SHA256_DIGEST_LENGTH];
		SHA256_Final(digest, &sha256);

		std::string result;
		for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
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
			Log::GetLog()->error("Error opening file for reading: " + filename.string());
			return "";
		}
	}
}