#pragma once
struct RCONPacket
{
	int Length;
	int Id;
	int Type;
	FString Body;
};
struct RCONClientConnection
{

};
struct UVictoryCore
{
	//functions
	static TArray<AActor*>* ServerOctreeOverlapActors(TArray<AActor*>* result, UWorld* theWorld, FVector* AtLoc, float Radius, EServerOctreeGroup::Type OctreeType, bool bForceActorLocationDistanceCheck) { return NativeCall<TArray<AActor*>*, TArray<AActor*>*, UWorld*, FVector, float, EServerOctreeGroup::Type, bool>(nullptr, "UVictoryCore.ServerOctreeOverlapActors", result, theWorld, AtLoc, Radius, OctreeType, bForceActorLocationDistanceCheck); }
};