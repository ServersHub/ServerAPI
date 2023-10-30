#include "Logger/Logger.h"
#include "..\Private\IBaseApi.h"
#include "..\Private\Ark\ArkBaseApi.h"

void Init()
{
	//Temporary fix for console output
	AllocConsole();
	FILE* p_cout;
	freopen_s(&p_cout, "conout$", "w", stdout);
	SetConsoleOutputCP(CP_UTF8);

	Log::Get().Init("API");

	API::game_api = std::make_unique<API::ArkBaseApi>();
	API::game_api->Init();
}

void Unload()
{
}

extern "C" ARK_API void ExportFunc() {}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Init();
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		Unload();
		break;
	}
	return TRUE;
}