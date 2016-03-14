#ifndef EXIT_HEADER
#define EXIT_HEADER

#include "Room.h"

enum dir{ north, south, east, west };

class Exit
{
public:
	bool open;
	Room* source=nullptr;
	Room* destination=nullptr;
	char name[15];
	char description[500];
	dir direction;
public:
	Exit();
	~Exit();
};
#endif