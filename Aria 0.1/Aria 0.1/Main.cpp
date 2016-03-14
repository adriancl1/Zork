#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include "World.h"

#define NUM_ROOMS 11
#define NUM_EXITS 22

int main(){
	char choice[25];
	//char* tok1;
	World* world = new World;
	world->CreateWorld();
	for (int i = 0; i < NUM_EXITS; i++){
		if (world->exits[i].source == &world->rooms[0]){
			printf("%s, %c\n", world->exits[i].name, world->exits[i].direction);
		}//Prints exits for a room
	}
	
	world->kevin->Look();
	while (strcmp(choice, "quit") != 0 || strcmp(choice, "q") !=0){

		scanf_s("%s", choice);
		//tok1 = strtok_s(choice, " ");
		//printf("%s", tok1);
		//Movement ----
		if (strcmp(choice, "east")==0 || strcmp(choice, "e") ==0){
			world->kevin->Move(world, east);
		}
		else if (strcmp(choice, "north") == 0 || strcmp(choice, "n") == 0){
			world->kevin->Move(world, north);
		}
		else if (choice == "west" || strcmp(choice, "w") == 0){
			world->kevin->Move(world, west);
		}
		else if (choice == "south" || strcmp(choice, "s") == 0){
			world->kevin->Move(world, south);
		}
		//Open ----
		//if (strcmp(choice, "Open"))
		else {
			printf("I did not understand what you said. Sorry! Try again.\n");
		}
	}
	system("pause");
	delete world;
	return 0;
}