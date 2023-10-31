#include "ArkBaseApi.h"
#include "..\Private\PDBReader\PDBReader.h"
#include "..\Private\Offsets.h"
#include "..\Private\Cache.h"
#include "Tools.h"
#include <Logger/Logger.h>
#include "HooksImpl.h"
#include <filesystem>
namespace API
{
	constexpr float api_version = 1.00;

	ArkBaseApi::ArkBaseApi()
	{
	}

	bool ArkBaseApi::Init()
	{
		namespace fs = std::filesystem;

		Log::GetLog()->info("-----------------------------------------------");
		Log::GetLog()->info("ARK:SA Api V{:.2f}", GetVersion());
		Log::GetLog()->info("Loading...\n");

		PdbReader pdb_reader;

		std::unordered_map<std::string, intptr_t> offsets_dump;
		std::unordered_map<std::string, BitField> bitfields_dump;

		try
		{
			const std::string current_dir = Tools::GetCurrentDir();
			const std::wstring dir = Tools::Utf8Decode(current_dir);
			const std::filesystem::path filepath = dir + L"/ArkAscendedServer.pdb";
			const std::filesystem::path cacheCheckFile = dir + L"/ArkApi/cache_check.txt";
			const std::filesystem::path offsetsFile = dir + L"/ArkApi/offsets_dump.map";
			const std::filesystem::path bitfieldsFile = dir + L"/ArkApi/bitfields_dump.map";
			const std::string fileHash = Cache::calculateSHA256(filepath);
			const std::string storedHash = Cache::readFromFile(cacheCheckFile);

			if (fileHash != storedHash
				|| !fs::exists(offsetsFile)
				|| !fs::exists(bitfieldsFile))
			{
				Log::GetLog()->info("Cache refresh required this will take several minutes to complete");
				pdb_reader.Read(filepath, &offsets_dump, &bitfields_dump);

				Log::GetLog()->info("Caching offsets for faster loading next time");
				Cache::serializeMap(offsets_dump, offsetsFile);

				Log::GetLog()->info("Caching bitfields for faster loading next time");
				Cache::serializeMap(bitfields_dump, bitfieldsFile);
				Cache::saveToFile(cacheCheckFile, fileHash);
			}
			else
			{
				Log::GetLog()->info("Cache is still valid loading existing cache");
				Log::GetLog()->info("Reading cached offsets");
				offsets_dump = Cache::deserializeMap<intptr_t>(offsetsFile);

				Log::GetLog()->info("Reading cached bitfields");
				bitfields_dump = Cache::deserializeMap<BitField>(bitfieldsFile);
			}
		}
		catch (const std::exception& error)
		{
			Log::GetLog()->critical("Failed to read pdb - {}", error.what());
			return false;
		}

		Offsets::Get().Init(move(offsets_dump), move(bitfields_dump));
		Sleep(10);
		AsaApi::InitHooks();
		Log::GetLog()->info("API was successfully loaded");
		Log::GetLog()->info("-----------------------------------------------\n");

		return true;
	}

	float ArkBaseApi::GetVersion()
	{
		return api_version;
	}

	std::string ArkBaseApi::GetApiName()
	{
		return "ArkApi";
	}

	void ArkBaseApi::RegisterCommands()
	{
	}
	std::unique_ptr<AsaApi::IHooks>& ArkBaseApi::GetHooks()
	{
		return hooks_;
	}
} // namespace API