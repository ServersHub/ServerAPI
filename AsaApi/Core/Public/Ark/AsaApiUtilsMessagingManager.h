#pragma once

#include "MessagingManager.h"
#include "..\AsaApiModUtils.hpp"

class AsaApiUtilsMessagingManager : public MessagingManager
{
public:
	std::optional<std::string> MeetsRequirementsToWork() override
	{
		AActor* singleton = AsaApiModUtils::GetSingleton();
		if (!singleton)
			return "Singleton not found, please check the mod is correctly installed";
		return {};
	}

protected:
	void SendServerMessage_Impl(AShooterPlayerController* player_controller, FLinearColor msg_color, const FString& msg) override
	{
		AsaApiModUtils::AddNotification(msg, { player_controller->GetEOSId() }, FLinearColor(0,0,0,0), msg_color, 1.0, 0.0, Position::Center, Position::Center, true);
	}

	void SendNotification_Impl(AShooterPlayerController* player_controller, FLinearColor color, float display_scale,
		float display_time, UTexture2D* icon, const FString& msg) override
	{
		AsaApiModUtils::AddNotification(msg, { player_controller->GetEOSId() }, FLinearColor(0, 0, 0, 0), color, display_scale, display_time, Position::Center, Position::Center, false);
	}
};

// now you would call "AsaApi::GetApiUtils().SetMessagingManager<AsaApiUtilsMessagingManager>(); in your plugin's load function"
