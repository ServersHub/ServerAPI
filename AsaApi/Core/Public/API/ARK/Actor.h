#pragma once
#include "UE.h"

struct UTexture2D;
struct UCheatManager;
struct USoundBase;
struct AShooterCharacter;
struct APrimalDinoCharacter;
struct UPrimalInventoryComponent;

struct FPrimalChatMessage {
    FString SenderName;
    FString SenderSteamName;
    FString SenderTribeName;
    unsigned int SenderId;
    FString Message;
    FString Receiver;
    int SenderTeamIndex;
    long double ReceivedTime;
    TEnumAsByte<enum EChatSendMode::Type> SendMode;
    unsigned int RadioFrequency;
    TEnumAsByte<enum EChatType::Type> ChatType;
    UTexture2D* SenderIcon;
    FString UserId;
    __int8 SenderIsAdmin : 1;
    FPrimalChatMessage()
        : SenderName(""),
        SenderSteamName(""),
        SenderTribeName(""),
        SenderId(0),
        Message(""),
        Receiver(""),
        SenderTeamIndex(0),
        ReceivedTime(-1),
        SendMode(EChatSendMode::GlobalChat),
        RadioFrequency(0),
        ChatType(EChatType::GlobalChat),
        SenderIcon(nullptr),
        UserId("")
    {
    }
    FPrimalChatMessage* operator=(FPrimalChatMessage* __that) { return NativeCall<FPrimalChatMessage*, FPrimalChatMessage*>(this, "FPrimalChatMessage.operator=", __that); }
};


struct UPrimalActor : UObject
{
    int& TargetingTeamField() { return *GetNativePointerField<int*>(this, "UPrimalActor.TargetingTeam"); }
};

struct AActor : UPrimalActor
{
};
struct AInfo : AActor
{

};
struct FItemNetInfo
{
};
struct UPlayer {

};
struct UNetConnection : UPlayer
{
};
struct APlayerState : AInfo
{
    FString& PlayerNamePrivateField() { return *GetNativePointerField<FString*>(this, "APlayerState.PlayerNamePrivate<<"); }
};
struct AController : AActor
{
    APlayerState* PlayerStateField() {
        TObjectPtr<APlayerState>& ptr = *GetNativePointerField<TObjectPtr<APlayerState>*>(this, "APlayerController.PlayerState");
        return ptr.Get();
    }
};

struct APrimalController : AController
{
};

struct APlayerController : APrimalController
{
    //TObjectPtr<UCheatManager> CheatManager;
    UCheatManager* CheatManagerField() {
        TObjectPtr<UCheatManager>& ptr = *GetNativePointerField<TObjectPtr<UCheatManager>*>(this, "APlayerController.CheatManager");
        return ptr.Get();
    }
    UNetConnection* GetNetConnection() { return NativeCall<UNetConnection*>(this, "APlayerController.GetNetConnection"); }
};
struct APrimalPlayerController : APlayerController
{

};
struct ABasePlayerController : APrimalPlayerController
{

};
struct AShooterPlayerController : ABasePlayerController
{
    __int64& LinkedPlayerIDField() { return *GetNativePointerField<__int64*>(this, "AShooterPlayerController.LinkedPlayerID"); }
    //functions:
    
    void ClientChatMessage_Implementation(FPrimalChatMessage Chat) { NativeCall<void, FPrimalChatMessage>(this, "AShooterPlayerController.ClientChatMessage_Implementation", Chat); }
    void ClientServerChatDirectMessage(FString* MessageText, FLinearColor MessageColor, bool bIsBold) { NativeCall<void, FString*, FLinearColor, bool>(this, "AShooterPlayerController.ClientServerChatDirectMessage", MessageText, MessageColor, bIsBold); }
    void ClientChatMessage(FPrimalChatMessage Chat) { NativeCall<void, FPrimalChatMessage>(this, "AShooterPlayerController.ClientChatMessage", Chat); }   
    void ClientServerSOTFNotificationCustom(FString* MessageText, FLinearColor MessageColor, float DisplayScale, float DisplayTime, UTexture2D* MessageIcon, USoundBase* SoundToPlay) { NativeCall<void, FString*, FLinearColor, float, float, UTexture2D*, USoundBase*>(this, "AShooterPlayerController.ClientServerSOTFNotificationCustom_Implementation", MessageText, MessageColor, DisplayScale, DisplayTime, MessageIcon, SoundToPlay); }
    FString* ConsoleCommand(FString* result, FString* Command, bool bWriteToLog) { return NativeCall<FString*, FString*, FString*, bool>(this, "AShooterPlayerController.ConsoleCommand", result, Command, bWriteToLog); }
    AShooterCharacter* GetPlayerCharacter() { return NativeCall<AShooterCharacter*>(this, "AShooterPlayerController.GetPlayerCharacter"); }
    FString* GetPlayerCharacterName(FString* result) { return NativeCall<FString*, FString*>(this, "AShooterPlayerController.GetPlayerCharacterName", result); }    
    void SetPlayerPos(float X, float Y, float Z) { NativeCall<void, float, float, float>(this, "AShooterPlayerController.SetPlayerPos", X, Y, Z); }
    AActor* SpawnActor(FString* blueprintPath, float spawnDistance, float spawnYOffset, float ZOffset, bool bDoDeferBeginPlay) { return NativeCall<AActor*, FString*, float, float, float, bool>(this, "AShooterPlayerController.SpawnActor", blueprintPath, spawnDistance, spawnYOffset, ZOffset, bDoDeferBeginPlay); }
};

struct APawn : AActor
{
};
struct APrimalPawn: APawn
{
    APrimalPawn* GetOwnerController() { return NativeCall<APrimalPawn*>(this, "APrimalPawn.GetOwnerController"); }
};
struct ACharacter : APrimalPawn
{
};
struct APrimalCharacter : ACharacter
{
    bool IsDead() { return NativeCall<bool>(this, "APrimalCharacter.IsDead"); }
    UPrimalInventoryComponent* MyInventoryComponentField() { return *GetNativePointerField<UPrimalInventoryComponent**>(this, "APrimalCharacter.MyInventoryComponent"); }
    
};
struct FPrimalPlayerDataStruct
{
    unsigned __int64& PlayerDataIDField() { return *GetNativePointerField<unsigned __int64*>(this, "FPrimalPlayerDataStruct.PlayerDataID"); }
};
struct UPrimalPlayerData : UObject
{
    FPrimalPlayerDataStruct* MyDataField() { return GetNativePointerField<FPrimalPlayerDataStruct*>(this, "UPrimalPlayerData.MyData"); }
};

struct APrimalDinoCharacter : APrimalCharacter
{
};
struct AShooterCharacter : APrimalCharacter
{
    //Functions
    APrimalDinoCharacter* GetRidingDino() { return NativeCall<APrimalDinoCharacter*>(this, "AShooterCharacter.GetRidingDino"); }
    UPrimalPlayerData* GetPlayerData() { return NativeCall<UPrimalPlayerData*>(this, "AShooterCharacter.GetPlayerData"); }
    TWeakObjectPtr<AShooterPlayerController>& LastValidPlayerControllerField() { return *GetNativePointerField<TWeakObjectPtr<AShooterPlayerController>*>(this, "AShooterCharacter.LastValidPlayerController"); }
};
struct UCheatManager : UObject
{

};

struct UShooterCheatManager : UCheatManager
{

};