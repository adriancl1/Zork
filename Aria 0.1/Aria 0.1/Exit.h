#ifndef EXIT_HEADER
#define EXIT_HEADER

#include "Room.h"
#include "Entity.h"

enum dir{ north, south, east, west };

class Exit : public Entity
{
public:
	bool open;
	Room* source=nullptr;
	Room* destination=nullptr;
	dir direction;
public:
	Exit(const char* name, const char* description, bool open,  Room* source,  Room* destination, dir direction);
	~Exit();
};
#endif