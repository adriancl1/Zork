#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "World.h"


#define NUM_ROOMS 11
#define NUM_EXITS 22
#define _CRT_SECURE_NO_WARNINGS

World::World(){
	//Rooms ----
	rooms = new Room[11];
	
	//Exits ---- 
	exits = new Exit[22];
	 
	//Player ----
	kevin = new Player;
}

World::~World(){
	delete[11] rooms;
	delete[21] exits;
	delete kevin;
}

void World::CreateWorld(){
	//Rooms  ----
	strcpy_s(rooms[0].name, "Entrance");
	strcpy_s(rooms[0].description, "This is the entrance to what it used to be your house. You remember playing in the porch as a child with your sister when the  walls were still blue, but now the wood looks moldy."
		"You see a little path through the left and another one to the right. The door to the house is north.\n");

	strcpy_s(rooms[1].name, "House hall");
	strcpy_s(rooms[1].description, "An empty room. My uncles took all the furniture so now there's nothing left here, just some tables and the big orange sofa covered under cloth.\n The kitchen is west from here, west is my sister's bedroom along with my parents' and north is the bathroom.");

	strcpy_s(rooms[2].name, "Kitchen");
	strcpy_s(rooms[2].description, "There's a countetop with drawers in the middle of the room. There's not much more left aside from the washing machine on the right corner. The hall is west.\n");

	strcpy_s(rooms[3].name, "Bathroom");
	strcpy_s(rooms[3].description, "The bathroom looks so creepy. There's a rope hanging above the bathtub, and everything's a mess in here. You can return to the hall by going south.\n");

	strcpy_s(rooms[4].name, "Aria's bedroom");
	strcpy_s(rooms[4].description, "Your sister's bedroom. The walls are still purple, and a song plays from her music box. You see her looking through the window onto the garden, glowing by the moon's light. You can go back to the hall to the west.\n");

	strcpy_s(rooms[5].name, "Master bedroom");
	strcpy_s(rooms[5].description, "Your parents' room. It's empty. You can go back to the hall to the west, or into the garden through the window to the east.\n");

	strcpy_s(rooms[6].name, "Garden");
	strcpy_s(rooms[6].description, "The garden is now a complete mess. All the statues and the marble benchs are covered in grass and leaves from the tree. There's a cabin to the east, and the entrance to the south. You can climb inside through inside the house. going west.\n");

	strcpy_s(rooms[7].name, "Old cabin");
	strcpy_s(rooms[7].description, "All the gardening stuff is still here, shears, some bricks...\n");

	strcpy_s(rooms[8].name, "Graveyard");
	strcpy_s(rooms[8].description, "You see the graves with the names of your parents and your sister engraved in them. There's someone here too.\n");

	strcpy_s(rooms[9].name, "Ruins");
	strcpy_s(rooms[9].description, "You used to play with your sister in here. You remember her going deeper into the ruins, but you were too afraid of the darkness, and you still are.\n");

	strcpy_s(rooms[10].name, "Cavern");
	strcpy_s(rooms[10].description, "This is where Aria used to come by herself. There's a purple diary at the middle of the room, and some paintings on the walls.\n");

	//EXITS ----
	exits[0].open = false;
	exits[0].source = &rooms[0];
	exits[0].destination = &rooms[1];
	exits[0].direction = north;
	strcpy_s(exits[0].name, "House hall");
	
	strcpy_s(exits[0].description, "North there's the house door.");
	exits[1].open = true;
	exits[1].source = &rooms[0];
	exits[1].destination = &rooms[9];
	exits[1].direction = west;
	strcpy_s(exits[1].name, "Ruins");
	strcpy_s(exits[1].description, "There's a path that seems to lead to some ruins to the west.");
	
	exits[2].open = true;
	exits[2].source = &rooms[0];
	exits[2].destination = &rooms[6];
	exits[2].direction = east;
	strcpy_s(exits[2].name, "Garden");
	strcpy_s(exits[2].description, "East through a wooden path is the garden.");
	
	exits[3].open = true;
	exits[3].source = &rooms[1];
	exits[3].destination = &rooms[2];
	exits[3].direction = west;
	strcpy_s(exits[3].name, "Kitchen");
	strcpy_s(exits[3].description, "The kitchen is west from here.");
	
	exits[4].open = true;
	exits[4].source = &rooms[1];
	exits[4].destination = &rooms[3];
	exits[4].direction = north;
	strcpy_s(exits[4].name, "Bathroom");
	strcpy_s(exits[4].description, "North there's bathroom.");
	
	exits[5].open = true;
	exits[5].source = &rooms[1];
	exits[5].destination = &rooms[4];
	exits[5].direction = east;
	strcpy_s(exits[5].name, "Aria's bedroom");
	strcpy_s(exits[5].description, "East there's Aria's bedroom alongside your parents'.");
	
	exits[6].open = true;
	exits[6].source = &rooms[1];
	exits[6].destination = &rooms[5];
	exits[6].direction = east;
	strcpy_s(exits[6].name, "Master bedroom");
	strcpy_s(exits[6].description, "East there's Aria's bedroom alongside your parents'.");
	
	exits[7].open = false;
	exits[7].source = &rooms[1];
	exits[7].destination = &rooms[0];
	exits[7].direction = south;
	strcpy_s(exits[7].name, "Entrance");
	strcpy_s(exits[7].description, "South there's the way out to the entrance.");
	
	exits[8].open = true;
	exits[8].source = &rooms[2];
	exits[8].destination = &rooms[1];
	exits[8].direction = east;
	strcpy_s(exits[8].name, "House hall");
	strcpy_s(exits[8].description, "You can go back to the house hall going east.");
	
	exits[9].open = true;
	exits[9].source = &rooms[3];
	exits[9].destination = &rooms[1];
	exits[9].direction = south;
	strcpy_s(exits[9].name, "House hall");
	strcpy_s(exits[9].description, "You can go back to the house hall going south.");
	
	exits[10].open = true;
	exits[10].source = &rooms[4];
	exits[10].destination = &rooms[1];
	exits[10].direction = west;
	strcpy_s(exits[10].name, "House hall");
	strcpy_s(exits[10].description, "You can go back to the house hall going west.");
	
	exits[11].open = true;
	exits[11].source = &rooms[5];
	exits[11].destination = &rooms[1];
	exits[11].direction = west;
	strcpy_s(exits[11].name, "House hall");
	strcpy_s(exits[11].description, "You can go back to the house hall going west.");
	
	exits[12].open = true;
	exits[12].source = &rooms[5];
	exits[12].destination = &rooms[6];
	exits[12].direction = east;
	strcpy_s(exits[12].name, "Garden");
	strcpy_s(exits[12].description, "You can climb through the eastern window to the garden.");
	
	exits[13].open = true;
	exits[13].source = &rooms[6];
	exits[13].destination = &rooms[0];
	exits[13].direction = south;
	strcpy_s(exits[13].name, "Entrance");
	strcpy_s(exits[13].description, "There's a wooden path back to the entrance south.");
	
	exits[14].open = true;
	exits[14].source = &rooms[6];
	exits[14].destination = &rooms[7];
	exits[14].direction = east;
	strcpy_s(exits[14].name, "Old Cabin");
	strcpy_s(exits[14].description, "The wooden path continues to the east to what looks like a cabin.");
	
	exits[15].open = true;
	exits[15].source = &rooms[6];
	exits[15].destination = &rooms[8];
	exits[15].direction = north;
	strcpy_s(exits[15].name, "Graveyard");
	strcpy_s(exits[15].description, "It seems that there's a path where all the grass now stands to the north.");
	
	exits[16].open = true;
	exits[16].source = &rooms[6];
	exits[16].destination = &rooms[5];
	exits[16].direction = west;
	strcpy_s(exits[16].name, "House hall");
	strcpy_s(exits[16].description, "You can climb through the west window to the master bedroom.");
	
	exits[17].open = true;
	exits[17].source = &rooms[7];
	exits[17].destination = &rooms[6];
	exits[17].direction = west;
	strcpy_s(exits[17].name, "Garden");
	strcpy_s(exits[17].description, "You can go back to the garden by the wooden path to the west.");
	
	exits[18].open = true;
	exits[18].source = &rooms[8];
	exits[18].destination = &rooms[6];
	exits[18].direction = south;
	strcpy_s(exits[18].name, "Garden");
	strcpy_s(exits[18].description, "You can go back to the garden through the grass to the south.");
	
	exits[19].open = true;
	exits[19].source = &rooms[9];
	exits[19].destination = &rooms[0];
	exits[19].direction = east;
	strcpy_s(exits[19].name, "Entrance");
	strcpy_s(exits[19].description, "If you go east you'll return to the entrance.");
	
	exits[20].open = true;
	exits[20].source = &rooms[9];
	exits[20].destination = &rooms[10];
	exits[20].direction = north;
	strcpy_s(exits[20].name, "Cavern");
	strcpy_s(exits[20].description, "There seems to be something ahead, but it's really dark.");
	
	exits[21].open = true;
	exits[21].source = &rooms[10];
	exits[21].destination = &rooms[9];
	exits[21].direction = south;
	strcpy_s(exits[21].name, "Ruins");
	strcpy_s(exits[21].description, "To the south there's the way back to the ruins. It's spooky here.");

	//PLAYER ----
	strcpy_s(kevin->playername, "Kevin.");
	kevin->location = &rooms[0];
}

bool World::Command(){
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
			kevin->Look();
		}
		else if (strcmp(scnd, "east") == 0 || strcmp(scnd, "e") == 0 || strcmp(scnd, "East") == 0){
			kevin->LookExit(this, east);
		}
		else if (strcmp(scnd, "north") == 0 || strcmp(scnd, "n") == 0 || strcmp(scnd, "North") == 0){
			kevin->LookExit(this, north);
		}
		else if (strcmp(scnd, "west") == 0 || strcmp(scnd, "w") == 0 || strcmp(scnd, "West") == 0){
			kevin->LookExit(this, west);
		}
		else if (strcmp(scnd, "south") == 0 || strcmp(scnd, "s") == 0 || strcmp(scnd, "South") == 0){
			kevin->LookExit(this, south);
		}
	}

	//MOVE ----
		else if (strcmp(first, "east") == 0 || strcmp(first, "e") == 0|| strcmp(first, "East") == 0){
			kevin->Move(this, east);
		}
		else if (strcmp(first, "north") == 0 || strcmp(first, "n") == 0 || strcmp(first, "North") == 0){
			kevin->Move(this, north);
		}
		else if (strcmp(first, "west") == 0 || strcmp(first, "w") == 0 || strcmp(first, "West") == 0){
			kevin->Move(this, west);
		}
		else if (strcmp(first, "south") == 0 || strcmp(first, "s") == 0 || strcmp(first, "South") == 0){
			kevin->Move(this, south);
		}


		else if (strcmp(first, "go") == 0 || strcmp(first, "Go") == 0){
		if (strcmp(scnd, "void") == 0){
			printf("Where? ");
			gets_s(scnd);
		}
		if (strcmp(scnd, "east") == 0 || strcmp(scnd, "e") == 0 || strcmp(scnd, "East") == 0){
			kevin->Move(this, east);
		}
		if (strcmp(scnd, "north") == 0 || strcmp(scnd, "n") == 0 || strcmp(scnd, "North") == 0){
			kevin->Move(this, north);
		}
		if (strcmp(scnd, "west") == 0 || strcmp(scnd, "w") == 0 || strcmp(scnd, "West") == 0){
			kevin->Move(this, west);
		}
		if (strcmp(scnd, "south") == 0 || strcmp(scnd, "s") == 0 || strcmp(scnd, "South") == 0){
			kevin->Move(this, south);
		}
	}


	//OPEN/CLOSE  ----

		else if (strcmp(first, "open") == 0 || strcmp(first, "Open") == 0){
		if (strcmp(scnd, "void") == 0){
			printf("Which door do you want to open? Give me a direction. ");
			gets_s(scnd);
		}
		if (strcmp(scnd, "east") == 0 || strcmp(scnd, "e") == 0 || strcmp(scnd, "East") == 0){
			kevin->Open(this, east);
		}
		if (strcmp(scnd, "north") == 0 || strcmp(scnd, "n") == 0 || strcmp(scnd, "North") == 0){
			kevin->Open(this, north);
		}
		if (strcmp(scnd, "west") == 0 || strcmp(scnd, "w") == 0 || strcmp(scnd, "West") == 0){
			kevin->Open(this, west);
		}
		if (strcmp(scnd, "south") == 0 || strcmp(scnd, "s") == 0 || strcmp(scnd, "South") == 0){
			kevin->Open(this, south);
		}
	}

		else if (strcmp(first, "close") == 0 || strcmp(first, "Close") == 0){
		if (strcmp(scnd, "void") == 0){
			printf("Which door do you want to close? Give me a direction. ");
			gets_s(scnd);
		}
		if (strcmp(scnd, "east") == 0 || strcmp(scnd, "e") == 0 || strcmp(scnd, "East") == 0){
			kevin->Close(this, east);
		}
		if (strcmp(scnd, "north") == 0 || strcmp(scnd, "n") == 0 || strcmp(scnd, "North") == 0){
			kevin->Close(this, north);
		}
		if (strcmp(scnd, "west") == 0 || strcmp(scnd, "w") == 0 || strcmp(scnd, "West") == 0){
			kevin->Close(this, west);
		}
		if (strcmp(scnd, "south") == 0 || strcmp(scnd, "s") == 0 || strcmp(scnd, "South") == 0){
			kevin->Close(this, south);
		}
	}

	//HELP ----

		else if (strcmp(first, "help") == 0 || strcmp(first, "Help") == 0){
		kevin->Help();
	}

	//QUIT ----

	else if (strcmp(first, "quit") == 0 || strcmp(first, "q") == 0 || strcmp(first, "Quit") == 0){
		return false;
	}

	//WRONG COMMAND ---- 

	else {
		printf("I did not understand what you said. Sorry! Try again.\n");
	}
	kevin->antigo = true;
	return true;
}