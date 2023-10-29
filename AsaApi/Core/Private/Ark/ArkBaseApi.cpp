#include "ArkBaseApi.h"
#include "..\Private\PDBReader\PDBReader.h"
#include "..\Private\Offsets.h"
#include "Tools.h"
#include <Logger/Logger.h>

namespace API
{
	constexpr float api_version = 3.55f;

	ArkBaseApi::ArkBaseApi()
	{

	}

	bool ArkBaseApi::Init()
	{
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
			pdb_reader.Read(dir + L"/ArkAscendedServer.pdb", &offsets_dump, &bitfields_dump);
		}
		catch (const std::exception& error)
		{
			Log::GetLog()->critical("Failed to read pdb - {}", error.what());
			return false;
		}

		Offsets::Get().Init(move(offsets_dump), move(bitfields_dump));

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
} // namespace API