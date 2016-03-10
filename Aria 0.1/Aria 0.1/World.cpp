#include <stdlib.h>
#include <string.h>
#include "Room.h"
#include "Player.h"
#include "Exit.h"
#include "World.h"

void World::CreateWorld(){
	rooms = new Room[11];
	exits = new Exit[20];
	Player Kevin;
	Kevin.location = 0;//Kevin starts at room 0

	//Create Rooms
	strcpy(rooms[0].name, "Entrance");
	strcpy(rooms[0].description, "This is the entrance to what it used to be your house. You remember playing in the porch as a child with your sister when the  walls were still blue, but now the wood looks moldy."
		"You see a little path through the left and another one to the right. The door to the house is north.\n");
	strcpy(rooms[1].name, "House hall");
	strcpy(rooms[1].description, "An empty room. My uncles took all the furniture so now there's nothing left here, just some tables and the big orange sofa covered under cloth. ");
	//...
	//Rooms Created
}