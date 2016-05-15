#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "String.h"
#include "DynamicArray.h"

enum type{PLAYER, FRIENDLY, ENEMY, ROOM, ITEM, EXIT, CHEST};//friendly and enemy types are for npcs

class Entity
{
public:
	String name;
	String description;
	Vector<Entity*> my_entities;
	type my_type;

public:
	Entity();
	Entity(const char* name, const char* description, type mytype);
	virtual void Look()const;
	char* get_name()const;
	char* get_description()const;
};

#endif