#include "Exit.h"
#include <stdio.h>

Exit::Exit(const char* name, const char* description, bool open, const Room* source, const Room* destination, dir direction) : Entity(name, description, EXIT), open(open), source(source), destination(destination)
{
	
}

Exit::~Exit(){
	
}