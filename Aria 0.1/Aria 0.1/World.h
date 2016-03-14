#ifndef WORLD_HEADER
#define WORLD_HEADER

#include "Room.h"
#include "Exit.h"
#include "Player.h"



#define NUM_ROOMS 11
#define NUM_EXITS 22


class World
{
public:
	Room* rooms;
	Exit* exits;
	Player* kevin;
public:
	World();
	~World();
	void CreateWorld();
};
#endif
