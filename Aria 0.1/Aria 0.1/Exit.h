#ifndef EXIT_HEADER
#define EXIT_HEADER

#include "Room.h"
#include "Entity.h"

enum dir{ north, south, east, west };

class Exit : public Entity
{
public:
	bool open;
	const Room* source=nullptr;
	const Room* destination=nullptr;
	dir direction;
public:
	Exit(const char* name, const char* description, bool open, const Room* source, const Room* destination, dir direction);
	~Exit();
};
#endif