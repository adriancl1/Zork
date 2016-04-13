#include "Entity.h"

Entity::Entity(const char* name, const char* description, type mytype) : name(name), description(description), my_type(mytype)
{

}

char* Entity::get_name()const
{
	return name.c_str;
}

char* Entity::get_description()const
{
	return description.c_str;
}