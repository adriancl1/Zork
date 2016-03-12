#ifndef WORLD_HEADER
#define WORLD_HEADER
#include "Room.h"
#include "Player.h"
#include "Exit.h"

class World
{
public:
	Room* rooms =nullptr;
	Exit* exits = nullptr;
	Player* kevin;
public:
	World();
	~World();
};
#endif
