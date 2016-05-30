#ifndef PLAYER_HEADER
#define PLAYER_HEADER


#include "Exit.h"
#include "Creature.h"

class Room;

class World;

class Player : public Creature
{
public:
	bool antigo = true;
	unsigned int knowledge = 0, attack = 0;
	Vector<Entity*> gear;
public:
	void Look()const;
	void LookExit(const World* world, const dir tolook)const;
	void LookAt(String item);
	void Move(const World* world, const dir go);
	void Close(World* world, const dir close);
	void Open(World* world, const dir open);
	void Inventory()const;
	void Stats();
	void Pick(String item);
	void Drop(String item);
	void Get(World* world, String item);
	void Put(World* world, String item);
	void Equip(String item);
	void Unequip(String item);
	void Talk(World* world, String talkto);
	void Help()const;
	Player(const char* name, const char* description, Room* room);
	~Player();
};
#endif