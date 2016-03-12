#ifndef PLAYER_HEADER
#define PLAYER_HEADER
#include "Room.h"
class Player
{
public:
	char playername[10];
	Room* location;
public:
	Player();
	~Player();
};
#endif