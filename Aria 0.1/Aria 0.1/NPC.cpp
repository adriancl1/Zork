#include "NPC.h"
#include "String.h"
#include "World.h"
#include "Item.h"
#include "DynamicArray.h"
#include <time.h>
#include <stdlib.h>

NPC::NPC(const char* name, const char* description, type mytype, Room* room) : Creature(name, description, mytype, room){

}

NPC::~NPC()
{

}

void NPC::Update(const World* world){
	if (name == "Raccoon"){
		if (location == world->rooms[1] && my_entities.size()== 0){
			if (world->items[12]->my_entities.size()!=0){
				my_entities.push_back(world->items[12]->my_entities[0]);
				printf("The raccoon got the %s from the chest.\n", world->items[12]->my_entities[0]->get_name());
				world->items[12]->my_entities.Remove(0);
				return;
			}
		}
		if (my_entities.size() == 1){
			srand(time(NULL));
			Move(world, dir(rand()%4));
			return;
		}
		if (my_entities.size() == 0 && location!=world->rooms[1]){
			srand(time(NULL));
			Move(world, dir(rand() % 4));
			return;
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
						printf("Raccoon in%s\n%s.\n", world->exits[i]->destination->get_name(), world->exits[i]->destination->get_description());
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