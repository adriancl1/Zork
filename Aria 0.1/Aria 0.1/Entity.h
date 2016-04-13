#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "String.h"
#include "DynamicArray.h"

enum type{PLAYER, ROOM, ITEM, EXIT};

class Entity
{
private:
	String name;
	String description;
	Vector<Entity*> my_entities;
	type my_type;

public:
	Entity();
	Entity(const char* name, const char* description, type mytype);
	void Look();
	void Insert(Entity& container);
	void Remove(Entity&);
	virtual char* get_name()const;
	virtual char* get_description()const;
};

#endif