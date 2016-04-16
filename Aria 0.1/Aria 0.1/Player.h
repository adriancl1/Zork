#ifndef PLAYER_HEADER
#define PLAYER_HEADER


#include "Exit.h"
#include "Entity.h"

class Room;

class World;

class Player : public Entity
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
	void Inventory()const;
	void Pick(String item);
	void Drop(String item);
	void Help()const;
	Player(const char* name, const char* description, Room* room);
	~Player();
};
#endif