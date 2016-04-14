#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Room.h"
#include "Exit.h"
#include "Player.h"
#include "World.h"

#define _CRT_SECURE_NO_WARNINGS

World::World()
{

}

World::~World(){
	
}

void World::CreateWorld(){
	//ROOMS ----
	Room* Entrance = new Room("Entrance", "This is the entrance to what it used to be your house. You remember playing in the porch as a child with your sister when the  walls were still blue, but now the wood looks moldy."
		"You see a little path through the left and another one to the right. The door to the house is north.\n");

	Room* HouseHall = new Room("House Hall", "An empty room. My uncles took all the furniture so now there's nothing left here, just some tables and the big orange sofa covered under cloth.\n The kitchen is west from here, west is my sister's bedroom along with my parents' and north is the bathroom.");

	Room* Kitchen = new Room("Kitchen", "There's a countetop with drawers in the middle of the room. There's not much more left aside from the washing machine on the right corner. The hall is west.\n");

	Room* Bathroom = new Room("Bathroom", "The bathroom looks so creepy. There's a rope hanging above the bathtub, and everything's a mess in here. You can return to the hall by going south.\n");

	Room* Arias = new Room("Aria's bedroom", "Your sister's bedroom. The walls are still purple, and a song plays from her music box. You see her looking through the window onto the garden, glowing by the moon's light. You can go back to the hall to the west.\n");

	Room* Masters = new Room("Master bedroom","Your parents' room. It's empty. You can go back to the hall to the west, or into the garden through the window to the east.\n");
	
	Room* Garden = new Room("Garden", "The garden is now a complete mess. All the statues and the marble benchs are covered in grass and leaves from the tree. There's a cabin to the east, and the entrance to the south. You can climb inside through inside the house. going west.\n");

	Room* OldCabin = new Room("Old Cabin", "All the gardening stuff is still here, shears, some bricks...\n");

	Room* Graveyard = new Room("Graveyard", "You see the graves with the names of your parents and your sister engraved in them. There's someone here too.\n");

	Room* Ruins = new Room("Ruins", "You used to play with your sister in here. You remember her going deeper into the ruins, but you were too afraid of the darkness, and you still are.\n");

	Room* Cavern = new Room("Cavern", "This is where Aria used to come by herself. There's a purple diary at the middle of the room, and some paintings on the walls.\n");

	rooms.push_back(Entrance);
	rooms.push_back(HouseHall);
	rooms.push_back(Kitchen);
	rooms.push_back(Bathroom);
	rooms.push_back(Arias);
	rooms.push_back(Masters);
	rooms.push_back(Garden);
	rooms.push_back(OldCabin);
	rooms.push_back(Graveyard);
	rooms.push_back(Ruins);
	rooms.push_back(Cavern);

	//EXITS  ----
	exits.push_back(new Exit("House Hall", "North there's the house door", false, rooms[0], rooms[1], north));
	exits.push_back(new Exit("Ruins", "There's a path that seems to lead to some ruins to the west", true, rooms[0], rooms[9], west));
	exits.push_back(new Exit("Garden", "East through a wooden path is the garden.", true, rooms[0], rooms[6], east));
	exits.push_back(new Exit("Kitchen", "The kitchen is west from here", true, rooms[1], rooms[2], west));
	exits.push_back(new Exit("Bathroom", "North there's the bathroom", true, rooms[1], rooms[3], north));
	exits.push_back(new Exit("Aria's Bedroom", "East there's Aria's bedroom alognside your parents'.", true, rooms[1], rooms[4], east));
	exits.push_back(new Exit("Maste Bedroom", "East there's your parent's bedroom alongside Aria's.", true, rooms[1], rooms[5], east));
	exits.push_back(new Exit("Entrance", "South there's the way out to the entrance.", true, rooms[1], rooms[0], south));
	exits.push_back(new Exit("House hall", "You can go back to the house hall going east.", true, rooms[2], rooms[1], east));
	exits.push_back(new Exit("House hall", "You can go back to the house hall going south.", true, rooms[3], rooms[1], south));
	exits.push_back(new Exit("House hall", "You can go back to the house hall going west.", true, rooms[4], rooms[1], west));
	exits.push_back(new Exit("House hall", "You can go back to the house hall going west.", true, rooms[5], rooms[1], west));
	exits.push_back(new Exit("Garden", "You can climb through the eastern window to the garden.", true, rooms[5], rooms[6], east));
	exits.push_back(new Exit("Entrance", "There's a wooden path back to the entrance south.", true, rooms[6], rooms[0], south));
	exits.push_back(new Exit("Old Cabin", "The wooden path continues to the east to what looks like a cabin.", true, rooms[6], rooms[7], east));
	exits.push_back(new Exit("Graveyard", "It seems that there's a path where all the grass now stands to the north.", true, rooms[6], rooms[8], north));
	exits.push_back(new Exit("House Hall", "You can climb through the west window to the master bedroom.", true, rooms[6], rooms[5], west));
	exits.push_back(new Exit("Garden", "You can go back to the garden by the wooden path to the west.", true, rooms[7], rooms[6], west));
	exits.push_back(new Exit("Garden", "You can go back to the garden through the grass to the south.", true, rooms[8], rooms[6], south));
	exits.push_back(new Exit("Entrance", "If you go east you'll return to the entrance.", true, rooms[9], rooms[0], east));
	exits.push_back(new Exit("Cavern", "There seems to be something ahead, but it's really dark.", true, rooms[9], rooms[10], north));
	exits.push_back(new Exit("Ruins", "To the south there's the way back to the ruins. It's spooky here.", true, rooms[10], rooms[9], south));


	//PLAYER ----
	player.push_back(new Player("Kevin", "I am Groot", rooms[0]));
}

bool World::Command(){
	printf("%s", rooms.buffer[3]->get_name());
	Vector<String> input;
	printf("\n");
	fflush(stdin);
	char choice[20];
	char cmd[10];
	char first[10];
	char scnd[10];
	strcpy_s(scnd, "void");
	char *context;
	gets_s(choice);
	if (strcmp(choice, "\0") == 0){
		printf("Type something!\n");
		return true;
	}
	strcpy_s(first, strtok_s(choice, " ", &context));
	if (strcmp(context, "") != 0){
		strcpy_s(scnd, strtok_s(NULL, " ", &context));
	}
	//LOOK ----
	if (strcmp(first, "look") == 0 || strcmp(first, "Look") == 0){
		if (strcmp(scnd, "void")==0){
			player[0]->Look();
		}
		else if (strcmp(scnd, "east") == 0 || strcmp(scnd, "e") == 0 || strcmp(scnd, "East") == 0){
			player[0]->LookExit(this, east);
		}
		else if (strcmp(scnd, "north") == 0 || strcmp(scnd, "n") == 0 || strcmp(scnd, "North") == 0){
			player[0]->LookExit(this, north);
		}
		else if (strcmp(scnd, "west") == 0 || strcmp(scnd, "w") == 0 || strcmp(scnd, "West") == 0){
			player[0]->LookExit(this, west);
		}
		else if (strcmp(scnd, "south") == 0 || strcmp(scnd, "s") == 0 || strcmp(scnd, "South") == 0){
			player[0]->LookExit(this, south);
		}
	}

	//MOVE ----
		else if (strcmp(first, "east") == 0 || strcmp(first, "e") == 0|| strcmp(first, "East") == 0){
			player[0]->Move(this, east);
		}
		else if (strcmp(first, "north") == 0 || strcmp(first, "n") == 0 || strcmp(first, "North") == 0){
			player[0]->Move(this, north);
		}
		else if (strcmp(first, "west") == 0 || strcmp(first, "w") == 0 || strcmp(first, "West") == 0){
			player[0]->Move(this, west);
		}
		else if (strcmp(first, "south") == 0 || strcmp(first, "s") == 0 || strcmp(first, "South") == 0){
			player[0]->Move(this, south);
		}


		else if (strcmp(first, "go") == 0 || strcmp(first, "Go") == 0){
		if (strcmp(scnd, "void") == 0){
			printf("Where? ");
			gets_s(scnd);
		}
		if (strcmp(scnd, "east") == 0 || strcmp(scnd, "e") == 0 || strcmp(scnd, "East") == 0){
			player[0]->Move(this, east);
		}
		if (strcmp(scnd, "north") == 0 || strcmp(scnd, "n") == 0 || strcmp(scnd, "North") == 0){
			player[0]->Move(this, north);
		}
		if (strcmp(scnd, "west") == 0 || strcmp(scnd, "w") == 0 || strcmp(scnd, "West") == 0){
			player[0]->Move(this, west);
		}
		if (strcmp(scnd, "south") == 0 || strcmp(scnd, "s") == 0 || strcmp(scnd, "South") == 0){
			player[0]->Move(this, south);
		}
	}


	//OPEN/CLOSE  ----

		else if (strcmp(first, "open") == 0 || strcmp(first, "Open") == 0){
		if (strcmp(scnd, "void") == 0){
			printf("Which door do you want to open? Give me a direction. ");
			gets_s(scnd);
		}
		if (strcmp(scnd, "east") == 0 || strcmp(scnd, "e") == 0 || strcmp(scnd, "East") == 0){
			player[0]->Open(this, east);
		}
		if (strcmp(scnd, "north") == 0 || strcmp(scnd, "n") == 0 || strcmp(scnd, "North") == 0){
			player[0]->Open(this, north);
		}
		if (strcmp(scnd, "west") == 0 || strcmp(scnd, "w") == 0 || strcmp(scnd, "West") == 0){
			player[0]->Open(this, west);
		}
		if (strcmp(scnd, "south") == 0 || strcmp(scnd, "s") == 0 || strcmp(scnd, "South") == 0){
			player[0]->Open(this, south);
		}
	}

		else if (strcmp(first, "close") == 0 || strcmp(first, "Close") == 0){
		if (strcmp(scnd, "void") == 0){
			printf("Which door do you want to close? Give me a direction. ");
			gets_s(scnd);
		}
		if (strcmp(scnd, "east") == 0 || strcmp(scnd, "e") == 0 || strcmp(scnd, "East") == 0){
			player[0]->Close(this, east);
		}
		if (strcmp(scnd, "north") == 0 || strcmp(scnd, "n") == 0 || strcmp(scnd, "North") == 0){
			player[0]->Close(this, north);
		}
		if (strcmp(scnd, "west") == 0 || strcmp(scnd, "w") == 0 || strcmp(scnd, "West") == 0){
			player[0]->Close(this, west);
		}
		if (strcmp(scnd, "south") == 0 || strcmp(scnd, "s") == 0 || strcmp(scnd, "South") == 0){
			player[0]->Close(this, south);
		}
	}

	//HELP ----

		else if (strcmp(first, "help") == 0 || strcmp(first, "Help") == 0){
			player[0]->Help();
	}

	//QUIT ----

	else if (strcmp(first, "quit") == 0 || strcmp(first, "q") == 0 || strcmp(first, "Quit") == 0){
		return false;
	}

	//WRONG COMMAND ---- 

	else {
		printf("I did not understand what you said. Sorry! Try again.\n");
	}
	player[0]->antigo = true;
	return true;
}