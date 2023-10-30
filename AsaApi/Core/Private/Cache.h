#pragma once
#include <API/Base.h>
#include "Logger/Logger.h"

#include <unordered_map>
#include <filesystem>
#include <iostream>
#include <fstream>

namespace Cache
{
	std::string calculateSHA256(const std::filesystem::path& filename);

	void saveToFile(const std::filesystem::path& filename, const std::string& content);

	std::string readFromFile(const std::filesystem::path& filename);

	template <typename T>
	void serializeMap(const std::unordered_map<std::string, T>& data, const std::filesystem::path& filename)
	{
		std::ofstream file(filename, std::ios::binary | std::ios::trunc);
		if (!file.is_open())
		{
			Log::GetLog()->error("Error opening file for writing: " + filename.string());
			return;
		}

		for (const auto& entry : data)
		{
			std::size_t keySize = entry.first.size();
			file.write(reinterpret_cast<char*>(&keySize), sizeof(keySize));
			file.write(entry.first.c_str(), keySize);
			file.write(reinterpret_cast<const char*>(&entry.second), sizeof(T));
		}

		file.close();
	}

	template <typename T>
	std::unordered_map<std::string, T> deserializeMap(const std::filesystem::path& filename)
	{
		std::unordered_map<std::string, T> data;

		if (!std::filesystem::exists(filename))
		{
			Log::GetLog()->error("File does not exist: " + filename.string());
			return data;
		}

		std::ifstream file(filename, std::ios::binary);
		if (!file.is_open()) {
			Log::GetLog()->error("Error opening file for writing: " + filename.string());
			return data;
		}

		while (file) {
			std::size_t keySize;
			if (file.read(reinterpret_cast<char*>(&keySize), sizeof(keySize))) {
				std::string key;
				key.resize(keySize);
				if (file.read(&key[0], keySize)) {
					T value;
					if (file.read(reinterpret_cast<char*>(&value), sizeof(T))) {
						data[key] = value;
					}
					else {
						Log::GetLog()->error("Error reading value");
					}
				}
				else {
					Log::GetLog()->error("Error reading key");
				}
			}
		}

		file.close();
		return data;
	}
}