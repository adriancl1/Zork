#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Room.h"
#include "Exit.h"

class World;

class Player
{
public:
	char playername[10];
	Room* location;
public:
	void Look()const;
	void Move(World* world, dir);
	void Close(World* world, dir close);
	void Open(World* world, dir open);
	Player();
	~Player();
};
#endif