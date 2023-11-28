#include "ApiUtils.h"

#include "../IBaseApi.h"

namespace AsaApi
{
	// UWorld

	void ApiUtils::SetWorld(UWorld* uworld)
	{
		u_world_ = uworld;
	}

	UWorld* ApiUtils::GetWorld() const
	{
		return u_world_;
	}

	// AShooterGameMode

	void ApiUtils::SetShooterGameMode(AShooterGameMode* shooter_game_mode)
	{
		shooter_game_mode_ = shooter_game_mode;
	}

	AShooterGameMode* ApiUtils::GetShooterGameMode() const
	{
		return shooter_game_mode_;
	}

	// Status

	void ApiUtils::SetStatus(ServerStatus status)
	{
		status_ = status;
	}

	ServerStatus ApiUtils::GetStatus() const
	{
		return status_;
	}

	// Cheat Manager
	void ApiUtils::SetCheatManager(UShooterCheatManager* cheatmanager)
	{
		cheatmanager_ = cheatmanager;
	}

	void ApiUtils::SetPlayerController(AShooterPlayerController* player_controller)
	{		
		if (!player_controller)
			return;
		
		const FString eos_id = AsaApi::IApiUtils::GetEOSIDFromController(player_controller);

		if (!eos_id.IsEmpty())
		{
			eos_id_map_[eos_id] = player_controller;
		}
	}

	void ApiUtils::RemovePlayerController(AShooterPlayerController* player_controller)
	{
		if (!player_controller)
			return;

		const FString eos_id = AsaApi::IApiUtils::GetEOSIDFromController(player_controller);

		if (!eos_id.IsEmpty())
		{
			eos_id_map_.erase(eos_id);
		}
	}

	AShooterPlayerController* ApiUtils::FindPlayerFromEOSID_Internal(const FString& eos_id) const
	{
		AShooterPlayerController* found_player = nullptr;
		if (eos_id.IsEmpty())
		{
			return found_player;
		}
		auto iter = eos_id_map_.find(eos_id);
		if (iter != eos_id_map_.end()
			&& iter->first == eos_id)
		{
			found_player = iter->second;
		}

		if (found_player == nullptr)
		{
			const auto& player_controllers = GetWorld()->PlayerControllerListField();
			for (TWeakObjectPtr<APlayerController> player_controller : player_controllers)
			{
				AShooterPlayerController* shooter_pc = static_cast<AShooterPlayerController*>(player_controller.Get());

				if (shooter_pc)
				{
					const FString& iter_eos_id = *API::game_api->GetApiUtils()->GetEOSIDFromController(shooter_pc);
					if (iter_eos_id == eos_id)
					{
						found_player = shooter_pc;
						break;
					}
				}
			}
		}

		return found_player;
	}

	UShooterCheatManager* ApiUtils::GetCheatManager() const
	{
		return cheatmanager_;
	}

	// Free function
	IApiUtils& GetApiUtils()
	{
		return *API::game_api->GetApiUtils();
	}
} // namespace AsaApi