#ifndef ROOM_HEADER
#define ROOM_HEADER

#include "Entity.h"

class Room : public Entity
{

public:
	Room(const char* name, const char* description);
	~Room();
};
#endif