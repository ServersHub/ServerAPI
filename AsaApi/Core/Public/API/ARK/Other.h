#pragma once
enum class ESocketType
{
	SOCKTYPE_Unknown = 0x0,
	SOCKTYPE_Datagram = 0x1,
	SOCKTYPE_Streaming = 0x2,
};
struct RCONPacket
{
	int Length;
	int Id;
	int Type;
	FString Body;
};
struct FSocket
{
	ESocketType& SocketTypeField() { return *GetNativePointerField<ESocketType*>(this, "FSocket.SocketType"); }
	FString& SocketDescriptionField() { return *GetNativePointerField<FString*>(this, "FSocket.SocketDescription"); }
};
struct RCONClientConnection
{
	FSocket* SocketField() { return *GetNativePointerField<FSocket**>(this, "RCONClientConnection.Socket"); }
	UShooterCheatManager* CheatManagerField() { return *GetNativePointerField<UShooterCheatManager**>(this, "RCONClientConnection.CheatManager"); }
	bool& IsAuthenticatedField() { return *GetNativePointerField<bool*>(this, "RCONClientConnection.IsAuthenticated"); }
	bool& IsClosedField() { return *GetNativePointerField<bool*>(this, "RCONClientConnection.IsClosed"); }
	TArray<signed char>& DataBufferField() { return *GetNativePointerField<TArray<signed char>*>(this, "RCONClientConnection.DataBuffer"); }
	unsigned int& CurrentPacketSizeField() { return *GetNativePointerField<unsigned int*>(this, "RCONClientConnection.CurrentPacketSize"); }
	long double& LastReceiveTimeField() { return *GetNativePointerField<long double*>(this, "RCONClientConnection.LastReceiveTime"); }
	long double& LastSendKeepAliveTimeField() { return *GetNativePointerField<long double*>(this, "RCONClientConnection.LastSendKeepAliveTime"); }
	FString& ServerPasswordField() { return *GetNativePointerField<FString*>(this, "RCONClientConnection.ServerPassword"); }

	// Functions

	void Tick(long double WorldTime, UWorld* InWorld) { NativeCall<void, long double, UWorld*>(this, "RCONClientConnection.Tick", WorldTime, InWorld); }
	void ProcessRCONPacket(RCONPacket* Packet, UWorld* InWorld) { NativeCall<void, RCONPacket*, UWorld*>(this, "RCONClientConnection.ProcessRCONPacket", Packet, InWorld); }
	void SendMessageW(int Id, int Type, FString* OutGoingMessage) { NativeCall<void, int, int, FString*>(this, "RCONClientConnection.SendMessageW", Id, Type, OutGoingMessage); }
	void Close() { NativeCall<void>(this, "RCONClientConnection.Close"); }
};
struct UVictoryCore
{
	//functions
	static TArray<AActor*>* ServerOctreeOverlapActors(TArray<AActor*>* result, UWorld* theWorld, FVector* AtLoc, float Radius, EServerOctreeGroup::Type OctreeType, bool bForceActorLocationDistanceCheck) { return NativeCall<TArray<AActor*>*, TArray<AActor*>*, UWorld*, FVector, float, EServerOctreeGroup::Type, bool>(nullptr, "UVictoryCore.ServerOctreeOverlapActors", result, theWorld, AtLoc, Radius, OctreeType, bForceActorLocationDistanceCheck); }
};