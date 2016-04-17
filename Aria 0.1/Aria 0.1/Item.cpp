#include "Item.h"

Item::Item(const char* name, const char* description, Entity* container) : Entity(name, description, ITEM), container(container)
{

}

Item::Item(const char* name, const char* description, type my_type, Entity* container) : Entity(name, description, my_type), container(container)
{

}

Item::~Item(){}
