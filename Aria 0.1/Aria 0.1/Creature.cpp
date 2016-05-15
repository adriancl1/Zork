#include "Creature.h"

Creature::Creature(const char* name, const char* description, type mytype, Room* room) : Entity(name, description, mytype), location(room)
{

}

Creature::~Creature()
{

}