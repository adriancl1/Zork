#ifndef WORLD_HEADER
#define WORLD_HEADER
#include "Room.h"
#include "Player.h"
#include "Exit.h"

class World
{
public:
	Room* rooms =new Room[11];
	Exit* exits = new Exit[20];
	Player Kevin;

	void CreateWorld();
};
#endif
