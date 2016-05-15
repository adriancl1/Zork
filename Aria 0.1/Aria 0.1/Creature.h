#ifndef CREATURE_HEADER
#define CREATURE_HEADER


#include "Exit.h"
#include "Entity.h"

class Room;

class World;

class Creature : public Entity
{
public:
	Room* location;
public:
	
	Creature(const char* name, const char* description, type mytype, Room* room);
	virtual ~Creature();
};
#endif