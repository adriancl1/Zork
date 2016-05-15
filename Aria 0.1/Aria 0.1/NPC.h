#ifndef __NPC_H__
#define __NPC_H__

#include "Creature.h"

class NPC : public Creature{
public:
	NPC(const char* name, const char* description, type mytype, Room* room);
	~NPC();
	void Update(const World* world);
	void Move(const World* world, const dir go);
public:
	bool antigo = true;
};
	

	
#endif
