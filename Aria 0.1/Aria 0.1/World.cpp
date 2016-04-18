#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Room.h"
#include "Item.h"
#include "Exit.h"
#include "Player.h"
#include "World.h"

#define _CRT_SECURE_NO_WARNINGS

World::World()
{

}

World::~World(){
	for (unsigned int i=0; i < rooms.size(); i++){
		delete rooms[i];
	}
	for (unsigned int i = 0; i < exits.size(); i++){
		delete exits[i];
	}
	for (unsigned int i = 0; i < items.size(); i++){
		delete items[i];
	}
	rooms.Clear();
	exits.Clear();
	items.Clear();
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

	//ITEMS ----

	Item* Rug = new Item("rug", "An old rug with a 'hello!' on it.", rooms[0]);
	Item* OldKey = new Item("key", "The key under the rug. It may open something...", rooms[0]);
	Item* Shears = new Item("shears", "Gardening shears. They may be able to break something.", rooms[6]);
	Item* Brick = new Item("brick", "A red brick.", rooms[7]);
	Item* AriaKey = new Item("key to Aria's Room", "You can tell this key is from Aria's by the purple butterfly on it", rooms[5]);
	Item* Rope = new Item("rope", "A rope... Seems that it was once used to hang something heavy.", rooms[3]);
	Item* Candle = new Item("candle", "A candle. Mom used to buy a lot of these cinnamon ones.", rooms[3]);
	Item* MatchesBox = new Item("box of matches", "There are three matches inside.", rooms[2]);
	Item* DrawerKey = new Item("drawer's key", "A key found at the kitchen.", rooms[2]);
	Item* Chair = new Item("chair", "Seems like it would resist my weight if I needed to stand on it...", rooms[1]);
	Item* Knife = new Item("knife", "A knife. Maybe I can use it to scare the man outside.", rooms[2]);
	Item* Diary = new Item("diary", "Aria's diary. Inside are all her thoughts.", rooms[10]);
	Item* Chest = new Item("chest", "A chest where you can store stuff in!", CHEST, rooms[1]);

	items.push_back(Rug);
	items.push_back(OldKey);
	items.push_back(Shears);
	items.push_back(Brick);
	items.push_back(AriaKey);
	items.push_back(Rope);
	items.push_back(Candle);
	items.push_back(MatchesBox);
	items.push_back(DrawerKey);
	items.push_back(Chair);
	items.push_back(Knife);
	items.push_back(Diary);
	items.push_back(Chest);


	rooms[0]->my_entities.push_back(items[0]);//rug
	rooms[0]->my_entities.push_back(items[1]);//oldkey
	rooms[6]->my_entities.push_back(items[2]);//shears
	rooms[7]->my_entities.push_back(items[3]);//brick
	rooms[5]->my_entities.push_back(items[4]);//ariakey
	rooms[3]->my_entities.push_back(items[5]);//rope
	rooms[3]->my_entities.push_back(items[6]);//candle
	rooms[1]->my_entities.push_back(items[9]);//drawerkey
	rooms[2]->my_entities.push_back(items[7]);//matches
	rooms[2]->my_entities.push_back(items[8]);//chair
	rooms[2]->my_entities.push_back(items[10]);//knife
	rooms[10]->my_entities.push_back(items[11]);//diary
	rooms[1]->my_entities.push_back(items[12]);//chest

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
	printf("\n");
	fflush(stdin);
	char choice[50];
	gets_s(choice);
	String beforetoken(choice);

	if (beforetoken == "\0"){
		printf("Type something!\n");
		return true;
	}

	Vector<String*> input;
	input = beforetoken.Tokenize();
	input.shrink_to_fit();


	if (input.size() == 1){
		if (input.buffer[0]->s_str() == "look" || input[0]->s_str() == "l" || input[0]->s_str() == "Look"){
			player[0]->Look();
		}

		else if (input[0]->s_str() == "east" || input[0]->s_str() == "e" || input[0]->s_str() == "East"){
			player[0]->Move(this, east);
		}
		else if (input[0]->s_str() == "north" || input[0]->s_str() == "n" || input[0]->s_str() == "North"){
			player[0]->Move(this, north);
		}
		else if (input[0]->s_str() == "west" || input[0]->s_str() == "w" || input[0]->s_str() == "West"){
			player[0]->Move(this, west);
		}
		else if (input[0]->s_str() == "south" || input[0]->s_str() == "s" || input[0]->s_str() == "South"){
			player[0]->Move(this, south);
		}

		else if (input[0]->s_str() == "open" || input[0]->s_str() == "Open"){
			printf("Which direction? ");
			gets_s(choice);
			input.push_back(new String(choice));
		}

		else if (input[0]->s_str() == "close" || input[0]->s_str() == "Close"){
			printf("Which direction? ");
			gets_s(choice);
			input.push_back(new String(choice));
		}

		else if (input[0]->s_str() == "Pick" || input[0]->s_str() == "pick"){
			printf("What do you want to pick? ");
			gets_s(choice);
			input.push_back(new String(choice));
		}

		else if (input[0]->s_str() == "Drop" || input[0]->s_str() == "drop"){
			printf("What do you want to drop? ");
			gets_s(choice);
			input.push_back(new String(choice));
		}

		else if (input[0]->s_str() == "Equip" || input[0]->s_str() == "equip"){
			printf("What do you want to equip? ");
			gets_s(choice);
			input.push_back(new String(choice));
		}

		else if (input[0]->s_str() == "Unequip" || input[0]->s_str() == "unequip"){
			printf("What do you want to unequip? ");
			gets_s(choice);
			input.push_back(new String(choice));
		}

		else if (input[0]->s_str() == "inventory" || input[0]->s_str() == "i" || input[0]->s_str() == "inv" || input[0]->s_str() == "Inventory")
		{
			player[0]->Inventory();
		}

		else if (input[0]->s_str() == "stats" || input[0]->s_str() == "Stats")
		{
			player[0]->Stats();
		}

		else if (input[0]->s_str() == "help" || input[0]->s_str() == "h" || input[0]->s_str() == "Help"){
			player[0]->Help();
		}

		else if (input[0]->s_str() == "q" || input[0]->s_str() == "quit" || input[0]->s_str() == "Quit"){
			return false;
		}


		else {
			printf("I did not understand what you said. Sorry! Try again.\n");
		}
	}
	if (input.size() == 2){
		if (input.buffer[0]->s_str() == "look" || input[0]->s_str() == "l" || input[0]->s_str() == "Look"){
			if (input[1]->s_str() == "east" || input[1]->s_str() == "e" || input[1]->s_str() == "East"){
				player[0]->LookExit(this, east);
			}
			if (input[1]->s_str() == "north" || input[1]->s_str() == "n" || input[1]->s_str() == "North"){
				player[0]->LookExit(this, north);
			}
			if (input[1]->s_str() == "west" || input[1]->s_str() == "w" || input[1]->s_str() == "West"){
				player[0]->LookExit(this, west);
			}
			if (input[1]->s_str() == "south" || input[1]->s_str() == "s" || input[1]->s_str() == "South"){
				player[0]->LookExit(this, south);
			}
		}
		else if (input[0]->s_str() == "go" || input[0]->s_str() == "Go"){
			if (input[1]->s_str() == "east" || input[1]->s_str() == "e" || input[1]->s_str() == "East"){
				player[0]->Move(this, east);
			}
			if (input[1]->s_str() == "north" || input[1]->s_str() == "n" || input[1]->s_str() == "North"){
				player[0]->Move(this, north);
			}
			if (input[1]->s_str() == "west" || input[1]->s_str() == "w" || input[1]->s_str() == "West"){
				player[0]->Move(this, west);
			}
			if (input[1]->s_str() == "south" || input[1]->s_str() == "s" || input[1]->s_str() == "South"){
				player[0]->Move(this, south);
			}
		}
		else if (input[0]->s_str() == "Open" || input[0]->s_str() == "open"){
			if (input[1]->s_str() == "east" || input[1]->s_str() == "e" || input[1]->s_str() == "East"){
				player[0]->Open(this, east);
			}
			if (input[1]->s_str() == "north" || input[1]->s_str() == "n" || input[1]->s_str() == "North"){
				player[0]->Open(this, north);
			}
			if (input[1]->s_str() == "west" || input[1]->s_str() == "w" || input[1]->s_str() == "West"){
				player[0]->Open(this, west);
			}
			if (input[1]->s_str() == "south" || input[1]->s_str() == "s" || input[1]->s_str() == "South"){
				player[0]->Open(this, south);
			}
		}
		else if (input[0]->s_str() == "Close" || input[0]->s_str() == "close"){
			if (input[1]->s_str() == "east" || input[1]->s_str() == "e" || input[1]->s_str() == "East"){
				player[0]->Close(this, east);
			}
			if (input[1]->s_str() == "north" || input[1]->s_str() == "n" || input[1]->s_str() == "North"){
				player[0]->Close(this, north);
			}
			if (input[1]->s_str() == "west" || input[1]->s_str() == "w" || input[1]->s_str() == "West"){
				player[0]->Close(this, west);
			}
			if (input[1]->s_str() == "south" || input[1]->s_str() == "s" || input[1]->s_str() == "South"){
				player[0]->Close(this, south);
			}
		}

		else if (input[0]->s_str() == "Pick" || input[0]->s_str() == "pick"){
			player[0]->Pick(input[1]->s_str());
		}
		else if (input[0]->s_str() == "Drop" || input[0]->s_str() == "drop"){
			player[0]->Drop(input[1]->s_str());
		}

		else if (input[0]->s_str() == "Equip" || input[0]->s_str() == "equip")
		{
			player[0]->Equip(input[1]->s_str());
		}
		else if (input[0]->s_str() == "Unequip" || input[0]->s_str() == "unequip")
		{
			player[0]->Unequip(input[1]->s_str());
		}
		else {
			printf("I did not understand what you said. Sorry! Try again.\n");
		}
	}

	if (input.size() == 3)
	{
		if((input[0]->s_str() == "Look" || input[0]->s_str() == "look") && (input[1]->s_str() == "at")){
			player[0]->LookAt(input[2]->s_str());
		}
		else {
			printf("I did not understand what you said. Sorry! Try again.\n");
		}
	}
	if (input.size() == 4){
		if ((input[0]->s_str() == "Get" || input[0]->s_str() == "get") && (input[2]->s_str() == "from") && (input[3]->s_str()=="chest")){
			player[0]->Get(this, input[1]->s_str());
		}
		else if ((input[0]->s_str() == "Put" || input[0]->s_str() == "put") && (input[2]->s_str() == "in") && (input[3]->s_str() == "chest")){
			player[0]->Put(this, input[1]->s_str());
		}
		else {
			printf("I did not understand what you said. Sorry! Try again.\n");
		}
	}

	player[0]->antigo = true;
	return true;
}