#ifndef EXIT_HEADER
#define EXIT_HEADER
#include "Room.h"
class Exit
{
public:
	bool open;
	Room* source;
	Room* destination;
	char name[15];
	char description[500];
public:
	Exit();
	~Exit();
};
#endif