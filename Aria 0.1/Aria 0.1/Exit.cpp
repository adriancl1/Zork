#include "Exit.h"
#include "Room.h"

Exit::Exit()
{
	source = new Room;
	destination = new Room;
}

Exit::~Exit(){
	delete[] source;
	delete[] destination;
}