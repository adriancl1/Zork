#include <stdio.h>

#include "String.h"
#include "Player.h"
#include "World.h"
#include "DynamicArray.h"

Player::Player(const char* name, const char* description, Room* room) : Entity(name, description, PLAYER), location(room)
{
	
}

Player::~Player()
{

}

void Player::Look()const{
	printf("%s\n%s",location->get_name, location->get_description);
}

void Player::LookExit(const World* world, const dir tolook)const{
	for (int i = 0; i < NUM_EXITS; i++){
		if (world->exits[i]->source == location){
			if (world->exits[i].direction == tolook){
				printf("%s\n", world->exits[i].description);
			}
		}
	}
}

void Player::Move(const World* world, const dir go)
{
	if (antigo == true){
		for (int i = 0; i < NUM_EXITS; i++){
			if (world->exits[i].source == location){
				if (world->exits[i].direction == go){
					if (world->exits[i].open == true){
						location = world->exits[i].destination;
						printf("%s\n%s.\n", world->exits[i].destination->name, world->exits[i].destination->description);
						antigo = false;
						break;
					}
					else{
						printf("The door is closed.\n");
						antigo = false;
						break;
					}
				}
			}
		}
	}
	if (antigo == true){
		printf("There's nothing there.\n");
	}//If the previous for hasn't changed antigo (it doesn't find a exit with that direction in the source room), it will print the message. Otherwise antigo goes false and it won't procceed. Antigo is set to true in the world::Command everytime it loops.
}

void Player::Close(World* world, const dir close)
{
	
	for (int i = 0; i < NUM_EXITS; i++){
		if (world->exits[i].source == location){
			if (world->exits[i].direction == close){
				if (world->exits[i].open == true){
					world->exits[i].open = false;
					printf("You closed the %s door.\n", world->exits[i].destination);
					antigo = false;
					break;
				}
				else{
					printf("The door is already closed.\n");
					antigo = false;
					break;
				}
			}
		}
	}
	if (antigo == true){
		printf("There's no door that way!.\n");
	}//Antigo has the same purpose as in the move method
}

void Player::Open(World* world, const dir open)
{
	for (int i = 0; i < NUM_EXITS; i++){
		if (world->exits[i].source == location){
			if (world->exits[i].direction == open){
				if (world->exits[i].open == false){
					world->exits[i].open = true;
					printf("You opened the %s door.\n", world->exits[i].destination);
					antigo = false;
					break;
				}
				else{
					printf("That door is already open!.\n");
					antigo = false;
					break;
				}
			}	
		}
	}
	if (antigo == true){
		printf("There's no door that way!.\n");
	}//Antigo has the same purpose as in the move method
}

void Player::Help()const{
	printf("You can move through the rooms with the keys n, s, e, w, or with the complete words north, south, east, west. You can also use go 'direction'. If you wish to inspect the room, use the 'look' command, you can also look out to wherever direction you want to head next before going in!All rooms can be opened / closed with the open / close 'direction' command(obviously, it'll only work if there's a room that way!). You can quit the game by hitting 'q' or 'quit'.\n");
}