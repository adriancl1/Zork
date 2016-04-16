#include "Item.h"

Item::Item(const char* name, const char* description, Entity* container) : Entity(name, description, ITEM), container(container)
{

}

Item::~Item(){}
