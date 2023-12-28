#pragma once

#include "API/ARK/Ark.h"

class ARK_API MessagingManager
{
public:
	virtual void SendServerMessage(AShooterPlayerController* player_controller, FLinearColor msg_color, const FString& msg)
	{

	}
};
