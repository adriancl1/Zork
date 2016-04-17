#ifndef ITEM_HEADER
#define ITEM_HEADER

#include "Entity.h"

class Item : public Entity
{
protected:
	Entity* container;
public:
	Item(const char* name, const char* description, Entity* container);
	Item(const char* name, const char* description, type my_type, Entity* container);
	~Item();
	
};
#endif