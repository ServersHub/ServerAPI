#pragma once
// Not verified -wooly
namespace EChatSendMode
{
	enum Type
	{
		GlobalChat = 0x0,
		GlobalTribeChat = 0x1,
		LocalChat = 0x2,
		AllianceChat = 0x3,
		MAX = 0x4,
	};
}
// Not verified -wooly
namespace EChatType
{
	enum Type
	{
		GlobalChat = 0x0,
		ProximityChat = 0x1,
		RadioChat = 0x2,
		GlobalTribeChat = 0x3,
		AllianceChat = 0x4,
		MAX = 0x5,
	};
}
//not verified -wooly
namespace EServerOctreeGroup
{
	enum Type
	{
		STASISCOMPONENTS = 0x0,
		PLAYERPAWNS = 0x1,
		DINOPAWNS = 0x2,
		PAWNS = 0x3,
		STRUCTURES = 0x4,
		TARGETABLEACTORS = 0x5,
		PLAYERS_CONNECTED = 0x6,
		SPATIALNETWORKEDACTORS = 0x7,
		SPATIALNETWORKEDACTORS_DORMANT = 0x8,
		ALL_SPATIAL = 0x9,
		THERMALSTRUCTURES = 0xa,
		STRUCTURES_CORE = 0xb,
		DINOPAWNS_TAMED = 0xc,
		PLAYERS_AND_TAMED_DINOS = 0xd,
		PLAYERS_CONNECTED_AND_TAMED_DINOS = 0xe,
		DINOFOODCONTAINER = 0xf,
		GRENADES = 0x10,
		TREESAPTAPS = 0x11,
		LARGEUNSTASISRANGE = 0x12,
		TRAPS = 0x13,
		MAX = 0x14,
	};
}