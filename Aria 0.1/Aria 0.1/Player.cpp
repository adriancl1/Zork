#include <stdio.h>

#include "Player.h"
#include "World.h"

Player::Player()
{
	location = new Room;
}

Player::~Player()
{
	delete[] location;
}

void Player::Look()const{
	printf("%s",location->description);
}

void Player::LookExit(World* world, dir tolook)const{
	for (int i = 0; i < NUM_EXITS; i++){
		if (world->exits[i].source == location){
			if (world->exits[i].direction == tolook){
				printf("%s\n", world->exits[i].description);
			}
			else{
				printf("There's nothing that way.\n");
				break;
			}
		}
		else{
			printf("Theres nothing there.\n");
		}
	}
}

void Player::Move(World* world, dir go)
{

	for (int i = 0; i < NUM_EXITS; i++){
		if (world->exits[i].source == location){
			if (world->exits[i].direction == go){
				if (world->exits[i].open == true){
					location = world->exits[i].destination;
					printf("%s\n%s.\n", world->exits[i].destination->name, world->exits[i].destination->description);
					break;
				}
				else{
					printf("The door is closed.\n");
					break;
				}
			}
			else{
				printf("Theres nothing there.\n");
			}
		}
	}
}

void Player::Close(World* world, dir close)const
{
	for (int i = 0; i < NUM_EXITS; i++){
		if (world->exits[i].source == location){
			if (world->exits[i].direction == close){
				if (world->exits[i].open == true){
					world->exits[i].open = false;
					printf("You closed the %s door.\n", world->exits[i].destination);
				}
				else{
					printf("You can't do that.\n");
				}
			}
		}
	}
}

void Player::Open(World* world, dir open)const
{
	for (int i = 0; i < NUM_EXITS; i++){
		if (world->exits[i].source == location){
			if (world->exits[i].direction == open){
				if (world->exits[i].open == false){
					world->exits[i].open = true;
					printf("You opened the %s door.\n", world->exits[i].destination);
				}
				else{
					printf("You can't do that.\n");
				}
			}
		}
	}
}