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
	bool antigo = true;
public:
	void Look()const;
	void LookExit(World* world, dir tolook)const;
	void Move(World* world, dir);
	void Close(World* world, dir close)const;
	void Open(World* world, dir open)const;
	Player();
	~Player();
};
#endif