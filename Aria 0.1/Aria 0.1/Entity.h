#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "String.h"
#include "DynamicArray.h"

enum type{PLAYER, ROOM, ITEM, EXIT};

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
	virtual void Insert(Entity* container);
	virtual void Remove(Entity*);
	virtual void Look()const;
	char* get_name()const;
	char* get_description()const;
};

#endif