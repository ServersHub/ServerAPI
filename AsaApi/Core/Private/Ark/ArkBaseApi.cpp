#include "ArkBaseApi.h"
#include "..\Private\PDBReader\PDBReader.h"
#include "..\PluginManager\PluginManager.h"
#include "..\Private\Offsets.h"
#include "..\Private\Cache.h"
#include "..\Hooks.h"
#include "..\Commands.h"
#include "Tools.h"
#include <Logger/Logger.h>
#include "HooksImpl.h"
#include "ApiUtils.h"
#include <filesystem>

namespace API
{
	constexpr float api_version = 1.02;

	ArkBaseApi::ArkBaseApi()
		: commands_(std::make_unique<AsaApi::Commands>()),
		hooks_(std::make_unique<Hooks>()),
		api_utils_(std::make_unique<AsaApi::ApiUtils>())
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
			TCHAR buffer[MAX_PATH];
			GetModuleFileName(NULL, buffer, sizeof(buffer));
			fs::path exe_path = std::filesystem::path(buffer).parent_path();

			const fs::path filepath = fs::path(exe_path).append("ArkAscendedServer.pdb");

			if (!fs::exists(fs::path(exe_path).append(ArkBaseApi::GetApiName())))
				fs::create_directory(fs::path(exe_path).append(ArkBaseApi::GetApiName()));

			if (!fs::exists(fs::path(exe_path).append(ArkBaseApi::GetApiName() + "/Plugins")))
				fs::create_directory(fs::path(exe_path).append(ArkBaseApi::GetApiName() + "/Plugins"));

			if (!fs::exists(fs::path(exe_path).append(ArkBaseApi::GetApiName()+"/Cache")))
				fs::create_directory(fs::path(exe_path).append(ArkBaseApi::GetApiName()+"/Cache"));

			const fs::path pdbIgnoreFile = fs::path(exe_path).append(ArkBaseApi::GetApiName() + "/pdbignores.txt");
			const fs::path keyCacheFile = fs::path(exe_path).append(ArkBaseApi::GetApiName()+"/Cache/cached_key.cache");
			const fs::path offsetsCacheFile = fs::path(exe_path).append(ArkBaseApi::GetApiName()+"/Cache/cached_offsets.cache");
			const fs::path bitfieldsCacheFile = fs::path(exe_path).append(ArkBaseApi::GetApiName()+"/Cache/cached_bitfields.cache");
			const fs::path offsetsCacheFilePlain = fs::path(exe_path).append(ArkBaseApi::GetApiName() + "/Cache/cached_offsets.txt");
			const std::string fileHash = Cache::calculateSHA256(filepath);
			const std::string storedHash = Cache::readFromFile(keyCacheFile);
			std::unordered_set<std::string> pdbIgnoreSet = Cache::readFileIntoSet(pdbIgnoreFile);

			if (fileHash != storedHash
				|| !fs::exists(offsetsCacheFile)
				|| !fs::exists(bitfieldsCacheFile))
			{
				Log::GetLog()->info("Cache refresh required this will take several minutes to complete");
				pdb_reader.Read(filepath, &offsets_dump, &bitfields_dump, pdbIgnoreSet);

				Log::GetLog()->info("Caching offsets for faster loading next time");
				Cache::serializeMap(offsets_dump, offsetsCacheFile);

				Log::GetLog()->info("Caching bitfields for faster loading next time");
				Cache::serializeMap(bitfields_dump, bitfieldsCacheFile);
				Cache::saveToFile(keyCacheFile, fileHash);
				Cache::saveToFilePlain(offsetsCacheFilePlain, offsets_dump);
			}
			else
			{
				Log::GetLog()->info("Cache is still valid loading existing cache");
				Log::GetLog()->info("Reading cached offsets");
				offsets_dump = Cache::deserializeMap<intptr_t>(offsetsCacheFile);

				Log::GetLog()->info("Reading cached bitfields");
				bitfields_dump = Cache::deserializeMap<BitField>(bitfieldsCacheFile);
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

	std::unique_ptr<AsaApi::IHooks>& ArkBaseApi::GetHooks()
	{
		return hooks_;
	}

	std::unique_ptr<AsaApi::ICommands>& ArkBaseApi::GetCommands()
	{
		return commands_;
	}

	std::unique_ptr<AsaApi::IApiUtils>& ArkBaseApi::GetApiUtils()
	{
		return api_utils_;
	}

	void ArkBaseApi::RegisterCommands()
	{
		GetCommands()->AddConsoleCommand("plugins.load", &LoadPluginCmd);
		GetCommands()->AddConsoleCommand("plugins.unload", &UnloadPluginCmd);
		GetCommands()->AddRconCommand("plugins.load", &LoadPluginRcon);
		GetCommands()->AddRconCommand("plugins.unload", &UnloadPluginRcon);
	}

	FString ArkBaseApi::LoadPlugin(FString* cmd)
	{
		TArray<FString> parsed;
		cmd->ParseIntoArray(parsed, L" ", true);

		if (parsed.IsValidIndex(1))
		{
			const std::string plugin_name = parsed[1].ToString();

			try
			{
				PluginManager::Get().LoadPlugin(plugin_name);
			}
			catch (const std::exception& error)
			{
				Log::GetLog()->warn("({}) {}", __FUNCTION__, error.what());
				return FString::Format("Failed to load plugin - {}", error.what());
			}

			Log::GetLog()->info("Loaded plugin - {}", plugin_name.c_str());

			return "Successfully loaded plugin";
		}

		return "Plugin not found";
	}

	FString ArkBaseApi::UnloadPlugin(FString* cmd)
	{
		TArray<FString> parsed;
		cmd->ParseIntoArray(parsed, L" ", true);

		if (parsed.IsValidIndex(1))
		{
			const std::string plugin_name = parsed[1].ToString();

			try
			{
				PluginManager::Get().UnloadPlugin(plugin_name);
			}
			catch (const std::exception& error)
			{
				Log::GetLog()->warn("({}) {}", __FUNCTION__, error.what());
				return *FString::Format("Failed to unload plugin - {}", error.what());
			}

			Log::GetLog()->info("Unloaded plugin - {}", plugin_name.c_str());

			return L"Successfully unloaded plugin";
		}

		return L"Plugin not found";
	}

	// Command Callbacks
	void ArkBaseApi::LoadPluginCmd(APlayerController* player_controller, FString* cmd, bool /*unused*/)
	{
		auto* shooter_controller = static_cast<AShooterPlayerController*>(player_controller);
		AsaApi::GetApiUtils().SendServerMessage(shooter_controller, FColorList::Green, *LoadPlugin(cmd));
	}

	void ArkBaseApi::UnloadPluginCmd(APlayerController* player_controller, FString* cmd, bool /*unused*/)
	{
		auto* shooter_controller = static_cast<AShooterPlayerController*>(player_controller);
		AsaApi::GetApiUtils().SendServerMessage(shooter_controller, FColorList::Green, *UnloadPlugin(cmd));
	}

	// RCON Command Callbacks
	void ArkBaseApi::LoadPluginRcon(RCONClientConnection* rcon_connection, RCONPacket* rcon_packet, UWorld* /*unused*/)
	{
		FString reply = LoadPlugin(&rcon_packet->Body);
		rcon_connection->SendMessageW(rcon_packet->Id, 0, &reply);
	}

	void ArkBaseApi::UnloadPluginRcon(RCONClientConnection* rcon_connection, RCONPacket* rcon_packet,
		UWorld* /*unused*/)
	{
		FString reply = UnloadPlugin(&rcon_packet->Body);
		rcon_connection->SendMessageW(rcon_packet->Id, 0, &reply);
	}
} // namespace API