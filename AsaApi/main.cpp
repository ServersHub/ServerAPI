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

void DeleteOldLogFiles()
{
	const std::string config_path = AsaApi::Tools::GetCurrentDir() + "/config.json";
	std::ifstream file{ config_path };
	if (!file.is_open())
		return;

	nlohmann::json config;
	file >> config;
	file.close();

	const std::string folderPath = API::Tools::GetCurrentDir() + "\\logs";
	const int maxFiles = config["settings"].value("MaxFiles", 20); // 20 files
	const int maxAgeInSeconds = config["settings"].value("MaxAgeInSeconds", 86400); //24hrs
	const bool enableDeleteLogging = config["settings"].value("EnableDeleteLogging", true);

	std::vector<std::pair<std::string, time_t>> fileTimePairs;
	// Iterate through the files in the folder
	for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
		if (entry.is_regular_file()) {
			std::string fileName = entry.path().filename().string();

			// Extract datetime from the file name
			std::string dateTimeString = fileName.substr(14, 19); // Extract data and time from "ArkApi_00000_yyyy-mm-dd_hh-mm.log"

			struct tm tm = {};
			std::istringstream ss(dateTimeString);
			ss >> std::get_time(&tm, "%Y-%m-%d_%H-%M");

			if (ss.fail()) {
				Log::GetLog()->error("Failed to parse datetime from file: {}", fileName);
				continue;
			}

			// Convert tm to time_t
			time_t fileTime = std::mktime(&tm);

			fileTimePairs.push_back(std::make_pair(fileName, fileTime));
		}
	}

	// Sort files by time in descending order
	std::sort(fileTimePairs.begin(), fileTimePairs.end(),
		[](const auto& a, const auto& b) { return a.second > b.second; });

	int filesToDelete = static_cast<int>(fileTimePairs.size()) - maxFiles;
	filesToDelete = (filesToDelete > 0) ? filesToDelete : 0;

	for (int i = 0; i < filesToDelete; ++i) {
		std::string filePath = folderPath + "\\" + fileTimePairs[i].first;

		// Check if the file is older than the specified datetime
		if (fileTimePairs[i].second < maxAgeInSeconds) {
			if (enableDeleteLogging)
				Log::GetLog()->info("Deleted log file: {}", filePath);

			std::remove(filePath.c_str());
		}
	}
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

	DeleteOldLogFiles();

	API::game_api = std::make_unique<API::ArkBaseApi>();
	API::game_api->Init();
}

extern "C" ARK_API void InitApi()
{
	Init();
}