#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Room.h"
#include "Exit.h"
#include "Entity.h"

class World;

class Player : Entity
{
public:
	Room* location;
	bool antigo = true;
public:
	void Look()const;
	void LookExit(const World* world, const dir tolook)const;
	void Move(const World* world, const dir go);
	void Close(World* world, const dir close);
	void Open(World* world, const dir open);
	void Help()const;
	Player(const char* name, const char* description, Room* room);
	~Player();
};
#endif