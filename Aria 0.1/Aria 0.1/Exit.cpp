#include "Exit.h"
#include <stdio.h>

Exit::Exit(const char* name, const char* description, bool open, Room* source, Room* destination, dir direction) : Entity(name, description, EXIT), open(open), source(source), destination(destination), direction(direction)
{
	
}

Exit::~Exit(){
	
}