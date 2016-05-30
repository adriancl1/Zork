#ifndef __NPC_H__
#define __NPC_H__

#include "Creature.h"

enum Status{
	WANDER,
	ATTACK, 
	TALKABLE,
	CARRYING,
	NONE
};
class NPC : public Creature{
public:
	NPC(const char* name, const char* description, type mytype, Room* room, Status status);
	~NPC();
	void Update(const World* world);
	void Move(const World* world, const dir go);
public:
	bool antigo = true;
	Status status;
	unsigned int encounters = 0;
};
	

	
#endif
