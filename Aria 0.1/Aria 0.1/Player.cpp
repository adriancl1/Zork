#include <stdio.h>

#include "String.h"
#include "Player.h"
#include "World.h"
#include "Item.h"
#include "DynamicArray.h"
#include "Room.h"
#include "NPC.h"

Player::Player(const char* name, const char* description, Room* room) : Creature(name, description, PLAYER, room){
	
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

void Player::LookAt(String item)
{
	for (unsigned int i = 0; i < my_entities.size(); i++){
		if (item == my_entities[i]->get_name()){
			printf("%s", my_entities[i]->get_description());
		}
	}
}

void Player::Move(const World* world, const dir go)
{
	if (antigo == true){
		for (int i = 0; i < NUM_EXITS; i++){
			if (world->exits[i]->source == this->location){
				if (world->exits[i]->direction == go){
					if (i == 5){
						unsigned int choice;
						printf("To your parent's room(1) or to Aria's(2)? ");
						scanf_s("%i", &choice);
						if (choice == 1){
							this->location = world->exits[6]->destination;
							printf("%s\n%s.\n", world->exits[6]->destination->get_name(), world->exits[6]->destination->get_description());
							antigo = false;
							break;
						}
						else if (choice == 2){
							this->location = world->exits[5]->destination;
							printf("%s\n%s.\n", world->exits[5]->destination->get_name(), world->exits[5]->destination->get_description());
							antigo = false;
							break;
						}
						else{
							printf("You didn't make a choice!\n");
						}
					}
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
	for (unsigned int i = 0; i < gear.size(); i++){
		if (gear[i]->name == "diary"){
			knowledge += 3;
		}
		if (gear[i]->name == "knife"){
			attack += 2;
		}
	}
	printf("Attack: %i\nKnowledge:%i\n", attack, knowledge);
	knowledge = 0, attack = 0;
}
void Player::Pick(String item)
{
	if (item == "chest"){
		printf("You can't pick up the chest!\n");
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
		printf("There's no such thing in here!\n");
	}
	else{
		printf("You're already carrying too much stuff.\n");
	}
}


void Player::Drop(String item)
{
	if (my_entities.size() > 0){
		for (unsigned int i = 0; my_entities.size() > i; i++)
		{
			if (item == my_entities[i]->get_name()){
				location->my_entities.push_back(my_entities[i]);
				printf("You droped the %s\n", my_entities[i]->get_name());
				my_entities.Remove(i);
				return;
			}
		}
		printf("You don't have that item.\n");
	}
	else{
		printf("You don't have any items!\n");
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
					printf("You got a %s from the chest.\n", world->items[12]->my_entities[i]->get_name());
					world->items[12]->my_entities.Remove(i);
					return;
				}
			}
			printf("There's no such thing in here!\n");
		}
		else{
			printf("You're already carrying too much stuff.\n");
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
					printf("You put the %s into the chest.\n", my_entities[i]->get_name());
					my_entities.Remove(i);
					return;
				}
			}
			printf("You don't have that item.\n");
		}
		else{
			printf("You don't have any items!\n");
		}
	}
}

void Player::Equip(String item)
{
	if (my_entities.size() > 0){
		for (unsigned int i = 0; my_entities.size() > i; i++)
		{
			if (item == my_entities[i]->get_name() && ((item== "knife") || item=="diary")){
				gear.push_back(my_entities[i]);
				printf("You equip the %s.\n", my_entities[i]->get_name());
				my_entities.Remove(i);
				return;
			}
		}
		printf("You can't equip that!\n");
	}
	else{
		printf("You don't have any items!\n");
	}
}

void Player::Unequip(String item)
{
	if (gear.size() > 0){
		for (unsigned int i = 0; gear.size() > i; i++)
		{
			if (item == gear[i]->get_name() && ((item == "knife") || item == "diary")){
				my_entities.push_back(gear[i]);
				printf("You unequip the %s.\n", gear[i]->get_name());
				gear.Remove(i);
				return;
			}
		}
		printf("You don't have that item equiped.\n");
	}
	else{
		printf("You don't have any items equiped!\n");
	}
}

void Player::Talk(World* world,String talkto){
	if (location == world->npcs[1]->location && talkto == "Aria" && world->npcs[1]->status==ENCOUNTER1){
		unsigned int choice;
		printf("Hello, darling. I missed you.\n 1. I missed you too!\n 2. Aria? What are you doing here?\n");
		scanf_s("%i", &choice);
		if (choice == 1){
			printf("Don't you worry, we won't be apart anymore now. Unless that man separates us...\n");
		}
		else if (choice == 2){
			printf("That doesn't matter now! Someone's outside, I think he wants to hurt us...\n");
		}
		else{
			printf("Oh dummy did the cat eat your tongue? Hurry, you need to take care of someone outside.\n");
		}
		printf("1. What man?\n2.Did the raccoon attack you too!?");
		scanf_s("%i", &choice);
		if (choice == 1){
			printf("I don't know who he is! But you need to kill him NOW. He tried to hurt me. I'm gonna go to the bathroom and hide there.\n");
		}
		else if (choice == 2){
			printf("Wait what raccoon? Whatever... No, there's a man outside. You gotta kill him, he tried to get into the house. I'll go hide in the bathroom!\n");
		}
		else{
			printf("I don't understand you, you're being weird... Anyway, go kill that man, he's dangerous! I'll hide in the bathroom for now.\n");
		}
		printf("She went to the bathroom and locked herself there.\n");
		world->npcs[1]->location = world->rooms[3];
		world->npcs[1]->status = ENCOUNTER2;
	}
}

void Player::Help()const{
	printf("You can move through the rooms with the keys n, s, e, w, or with the complete words north, south, east, west. You can also use go 'direction'. If you wish to inspect the room, use the 'look' command, you can also look out to wherever direction you want to head next before going in! Items on the room will only appear when looking, not when moving into a new room so be sure to use the look command. All rooms can be opened / closed with the open / close 'direction' command(obviously, it'll only work if there's a room that way!). You can pick/drop items from a room, and also equip them to raise your attack or knowledge stats! You can check those stats typing 'stats', and check the items you're currrently holding by pressing 'inventory' or simply 'i'. If you're running out of inventory space, there's a chest in the hall entrance where you can store your items and come back for them later. Use the 'Put xxx in chest' or 'Get xxx from chest' to do so. You can look at items you're holding by typing 'look at xxx'. You can quit the game by hitting 'q' or 'quit'.\n");
}