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
	void LookExit(const World* world, const dir tolook)const;
	void Move(const World* world, const dir go);
	void Close(World* world, const dir close)const;
	void Open(World* world, const dir open)const;
	void Help()const;
	Player();
	~Player();
};
#endif