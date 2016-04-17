#include <stdio.h>

#include "String.h"
#include "Player.h"
#include "World.h"
#include "Item.h"
#include "DynamicArray.h"
#include "Room.h"

Player::Player(const char* name, const char* description, Room* room) : Entity(name, description, PLAYER), location(room)
{
	
}

Player::~Player()
{

}

void Player::Look()const{
	printf("%s\n%s",location->get_name(), location->get_description());
	if (location->my_entities.size() >= 1)
	{
		printf("You can see a %s", location->my_entities[0]->get_name());
		for (unsigned int i = 1; location->my_entities.size() > i; i++)
		{
			printf(" and a %s,", location->my_entities[i]->get_name());
		}
		printf(".\n");
	}
}

void Player::LookExit(const World* world, const dir tolook)const{
	for (int i = 0; i < NUM_EXITS; i++){
		if (world->exits[i]->source == location){
			if (world->exits[i]->direction == tolook){
				printf("%s\n", world->exits[i]->get_description());
			}
		}
	}
}

void Player::Move(const World* world, const dir go)
{
	if (antigo == true){
		for (int i = 0; i < NUM_EXITS; i++){
			if (world->exits[i]->source == this->location){
				if (world->exits[i]->direction == go){
					if (world->exits[i]->open == true){
						this->location = world->exits[i]->destination;
						printf("%s\n%s.\n", world->exits[i]->destination->get_name(), world->exits[i]->destination->get_description());
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
		if (world->exits[i]->source == location){
			if (world->exits[i]->direction == close){
				if (world->exits[i]->open == true){
					world->exits[i]->open = false;
					printf("You closed the %s door.\n", world->exits[i]->destination->get_name());
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
		if (world->exits[i]->source == location){
			if (world->exits[i]->direction == open){
				if (world->exits[i]->open == false){
					world->exits[i]->open = true;
					printf("You opened the %s door.\n", world->exits[i]->destination->get_name());
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

void Player::Inventory()const
{
	if (my_entities.size() == 0){
		printf("You don't have any items at the moment.\n");
	}
	for (unsigned int i = 0; my_entities.size() > i; i++)
	{
		printf("%s\n", my_entities[i]->get_name());
	}
}

void Player::Stats()
{
	for (unsigned int i = 0; i < my_entities.size(); i++){
		if (my_entities[i]->name == "diary"){
			knowledge += 3;
		}
		if (my_entities[i]->name == "knife"){
			attack += 2;
		}
	}
	printf("Attack: %i\nKnowledge:%i", attack, knowledge);
	knowledge = 0, attack = 0;
}
void Player::Pick(String item)
{
	if (item == "chest"){
		printf("You can't pick up the chest!");
	}
	else if (my_entities.size() < 4){//inventory size
		for (unsigned int i = 0; location->my_entities.size() > i; i++)
		{
			if (item == location->my_entities[i]->get_name() && location->my_entities[i]->my_type == ITEM){
				my_entities.push_back(location->my_entities[i]);
				printf("You picked up a %s", location->my_entities[i]->get_name());
				location->my_entities.Remove(i);
				return;
			}
		}
		printf("There's no such thing in here!");
	}
	else{
		printf("You're already carrying too much stuff.");
	}
}


void Player::Drop(String item)
{
	if (my_entities.size() > 0){
		for (unsigned int i = 0; my_entities.size() > i; i++)
		{
			if (item == my_entities[i]->get_name()){
				location->my_entities.push_back(my_entities[i]);
				printf("You droped the %s", my_entities[i]->get_name());
				my_entities.Remove(i);
				return;
			}
		}
		printf("You don't have that item.");
	}
	else{
		printf("You don't have any items!");
	}
}

void Player::Get(World* world, String item)
{
	if (location == world->rooms[1]){
		if (my_entities.size() < 4){//inventory size
			for (unsigned int i = 0; world->items[12]->my_entities.size() > i; i++)
			{
				if (item == world->items[12]->my_entities[i]->get_name() && world->items[12]->my_entities[i]->my_type == ITEM){
					my_entities.push_back(world->items[12]->my_entities[i]);
					printf("You got a %s from the chest.", world->items[12]->my_entities[i]->get_name());
					world->items[12]->my_entities.Remove(i);
					return;
				}
			}
			printf("There's no such thing in here!");
		}
		else{
			printf("You're already carrying too much stuff.");
		}
	}

}


void Player::Put(World* world, String item)
{
	if (location == world->rooms[1]){
		if (my_entities.size() > 0){
			for (unsigned int i = 0; my_entities.size() > i; i++)
			{
				if (item == my_entities[i]->get_name()){
					world->items[12]->my_entities.push_back(my_entities[i]);
					printf("You put the %s into the chest.", my_entities[i]->get_name());
					my_entities.Remove(i);
					return;
				}
			}
			printf("You don't have that item.");
		}
		else{
			printf("You don't have any items!");
		}
	}
	
}


void Player::Help()const{
	printf("You can move through the rooms with the keys n, s, e, w, or with the complete words north, south, east, west. You can also use go 'direction'. If you wish to inspect the room, use the 'look' command, you can also look out to wherever direction you want to head next before going in!All rooms can be opened / closed with the open / close 'direction' command(obviously, it'll only work if there's a room that way!). You can quit the game by hitting 'q' or 'quit'.\n");
}