#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include "World.h"

#define NUM_ROOMS 11
#define NUM_EXITS 22

int main(){
	char choice[25];
	World* world = new World;
	/*for (int i = 0; i < 11; i++){
		//printf("%s\n", world->rooms[i].name);
		//printf("%s", world->rooms[i].description);
		printf("\n\n%s", world->exits[i].name);
		printf("\n\n%s", world->exits[i].description);
	}*/
	for (int i = 0; i < NUM_EXITS; i++){
		if (world->exits[i].source == &world->rooms[0]){
			printf("%s, %c\n", world->exits[i].name, world->exits[i].direction);
		}//Prints exits for a room
	}
	
	world->kevin->Look();
	//world->kevin->Move(world, east);
	world->kevin->Move(world, north);
	printf("Where do u wanna go? ");
	while (1){
		
		scanf_s("%s", choice);
		if (strcmp(choice, "east")==0){
			world->kevin->Move(world, east);
		}
		else if (strcmp(choice,"north")==0){
			world->kevin->Move(world, north);
		}
		else if (choice == "west"){
			world->kevin->Move(world, west);
		}
		else if (choice == "south"){
			world->kevin->Move(world, south);
		}
		else{
			printf("No funciona.\n");
		}
	}
	system("pause");
	delete world;
	return 0;
}