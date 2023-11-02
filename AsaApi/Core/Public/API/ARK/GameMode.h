#pragma once
struct AGameState;
struct FNetworkNotify {

};
struct UPrimalWorld : UObject
{

};


struct AGameStateBase : AInfo
{

};
struct AGameState : AGameStateBase
{

};
struct AShooterGameState : AGameState
{

};
//template <int IndexSize> class TSizedDefaultAllocator : public TSizedHeapAllocator<IndexSize> { public: typedef TSizedHeapAllocator<IndexSize> Typedef; };

struct UWorld : UPrimalWorld, FNetworkNotify {
	//variables
	APlayerController* GetFirstPlayerController() { return NativeCall<APlayerController*>(this, "UWorld.GetFirstPlayerController"); }

	//functions
	AShooterGameState *GameStateField() { return (AShooterGameState*)GetNativePointerField <TObjectPtr<AGameStateBase>*> (this, "UWorld.GameState")->Get(); }
	//TArray<TAutoWeakObjectPtr<APlayerController>>& PlayerControllerListField() { return *GetNativePointerField<TArray<TAutoWeakObjectPtr<APlayerController>>*>(this, "UWorld.PlayerControllerList"); }

	TArray<TWeakObjectPtr<APlayerController>, TSizedDefaultAllocator<32>> PlayerControllerListField() { 
		return *GetNativePointerField<TArray<TWeakObjectPtr<APlayerController>, TSizedDefaultAllocator<32>>*>(this, "UWorld.PlayerControllerList"); }
};

struct AGameModeBase : AInfo
{

};
struct AGameMode : AGameModeBase
{

};
struct APrimalGameMode : AGameMode
{
	
};
struct ISaveGameInterface {

};
struct AShooterGameMode : APrimalGameMode, ISaveGameInterface {

};
struct UPrimalGameData : UObject {

};