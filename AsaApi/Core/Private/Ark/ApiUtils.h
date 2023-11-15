#pragma once

#include <IApiUtils.h>

namespace AsaApi
{
	class ApiUtils : public IApiUtils
	{
	public:
		ApiUtils() = default;

		ApiUtils(const ApiUtils&) = delete;
		ApiUtils(ApiUtils&&) = delete;
		ApiUtils& operator=(const ApiUtils&) = delete;
		ApiUtils& operator=(ApiUtils&&) = delete;

		~ApiUtils() override = default;

		UWorld* GetWorld() const override;
		AShooterGameMode* GetShooterGameMode() const override;
		ServerStatus GetStatus() const override;
		UShooterCheatManager* GetCheatManager() const override;

		void SetWorld(UWorld* uworld);
		void SetShooterGameMode(AShooterGameMode* shooter_game_mode);
		void SetStatus(ServerStatus status);
		void SetCheatManager(UShooterCheatManager* cheatmanager);

		AShooterPlayerController* FindPlayerFromEOSID_Internal(const FString& eos_id) const override;
		void SetPlayerController(AShooterPlayerController* player_controller);
		void RemovePlayerController(AShooterPlayerController* player_controller);

	private:
		UWorld* u_world_{ nullptr };
		AShooterGameMode* shooter_game_mode_{ nullptr };
		ServerStatus status_{ 0 };
		UShooterCheatManager* cheatmanager_{ nullptr };
		std::unordered_map<const FString, AShooterPlayerController*, FStringHash, FStringEqual> eos_id_map_;
	};
} // namespace AsaApi
