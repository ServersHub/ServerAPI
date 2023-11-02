#include "Logger/Logger.h"
#include "..\Private\IBaseApi.h"
#include "..\Private\Ark\ArkBaseApi.h"

#include "Tools.h"
#include <filesystem>
#include <tlhelp32.h>
#include <fstream>
#include <json.hpp>

DWORD GetParentProcessId()
{
	const DWORD InvalidParentProcessId = 0;

	HANDLE Snapshot = 0;
	PROCESSENTRY32 ProcessEntry;
	DWORD PID = GetCurrentProcessId();

	Snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (Snapshot == INVALID_HANDLE_VALUE)
		return InvalidParentProcessId;

	ZeroMemory(&ProcessEntry, sizeof(ProcessEntry));
	ProcessEntry.dwSize = sizeof(ProcessEntry);

	if (!Process32First(Snapshot, &ProcessEntry))
		return InvalidParentProcessId;

	do
	{
		if (ProcessEntry.th32ProcessID == PID)
			return ProcessEntry.th32ParentProcessID;
	} while (Process32Next(Snapshot, &ProcessEntry));

	return InvalidParentProcessId;
}

bool AttachToParent()
{
	const std::string config_path = AsaApi::Tools::GetCurrentDir() + "/config.json";
	std::ifstream file{ config_path };
	if (!file.is_open())
		return false;

	nlohmann::json config;
	file >> config;
	file.close();

	return config["settings"].value("AttachToParent", true);
}

void OpenConsole()
{
	DWORD parentProcessId = GetParentProcessId();
	bool attachToParent = AttachToParent();
	if (GetConsoleWindow())
		return;
	if (attachToParent && parentProcessId && AttachConsole(parentProcessId))
		return;
	AllocConsole();
	FILE* p_cout;
	freopen_s(&p_cout, "conout$", "w", stdout);
	SetConsoleOutputCP(CP_UTF8);
}

void Init()
{
	namespace fs = std::filesystem;

	OpenConsole();

	const std::string current_dir = API::Tools::GetCurrentDir();

	if (!fs::exists(current_dir + "/logs"))
	{
		fs::create_directory(current_dir + "/logs");
	}

	Log::Get().Init("API");

	API::game_api = std::make_unique<API::ArkBaseApi>();
	API::game_api->Init();
}

extern "C" ARK_API void InitApi()
{
	Init();
}

void Unload()
{
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		Unload();
		break;
	}
	return TRUE;
}