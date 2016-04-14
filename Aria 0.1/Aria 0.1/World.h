#ifndef WORLD_HEADER
#define WORLD_HEADER

#include "DynamicArray.h"

class Room;
class Exit;
class Player;
class Item;


#define NUM_ROOMS 11
#define NUM_EXITS 22


class World
{
public:
	Vector<Item*> items;
	Vector<Room*> rooms;
	Vector<Exit*> exits;
	Vector<Player*> player;
public:
	World();
	~World();
	void CreateWorld();
	bool Command();
};
#endif
