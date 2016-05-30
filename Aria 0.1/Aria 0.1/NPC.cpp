#include "NPC.h"
#include "String.h"
#include "World.h"
#include "Item.h"
#include "Player.h"
#include "DynamicArray.h"
#include <time.h>
#include <stdlib.h>

NPC::NPC(const char* name, const char* description, type mytype, Room* room, Status status) : Creature(name, description, mytype, room), status(status) {

}

NPC::~NPC()
{

}

void NPC::Update(const World* world){
	if (name == "Raccoon"){
		switch (status)
		{
		case WANDER:
			if (location == world->player[0]->location){
				status = ATTACK;
			}
			if (location == world->rooms[1] && my_entities.size() == 0){
				if (world->items[12]->my_entities.size() != 0){
					my_entities.push_back(world->items[12]->my_entities[0]);
					printf("The raccoon got the %s from the chest.\n", world->items[12]->my_entities[0]->get_name());
					world->items[12]->my_entities.Remove(0);
					status = CARRYING;
					return;
				}
			}
			else if (my_entities.size() == 0 && location != world->rooms[1]){
				srand(time(NULL));
				Move(world, dir(rand() % 4));
				return;
			}
		case CARRYING:
			if (location != world->rooms[5] && location !=world->rooms[6]){
				location = world->rooms[5];
				return;
			}
			else if (location != world->rooms[6]){
				location = world->rooms[6];
				return;
			}
			else{
				world->rooms[6]->my_entities.push_back(my_entities[0]);
				printf("The raccoon droped the %s in the garden.\n", my_entities[0]->get_name());
				my_entities.Remove(0);
				status = WANDER;
				return;
			}
		case ATTACK:
			printf("You were hit by the damn raccoon!");
			if (encounters == 0){
				Move(world, dir(rand() % 4));
				printf("And the raccoon fleed!\n");//the raccoon always flees before you can attack back on the first encounter.
				status = WANDER;
				encounters++;
				return;
			}
			if (encounters == 1){

			}
		}
	}
	if (name == "Aria"){
		return;
	}
	if (name == "Stranger"){
		return;
	}
	return;
}

void NPC::Move(const World* world, const dir go)
{

	if (antigo == true){
		for (int i = 0; i < NUM_EXITS; i++){
			if (world->exits[i]->source == this->location){
				if (world->exits[i]->direction == go){
					if (world->exits[i]->open == true){
						this->location = world->exits[i]->destination;
						printf("Raccoon in%s.\n", world->exits[i]->destination->get_name());
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