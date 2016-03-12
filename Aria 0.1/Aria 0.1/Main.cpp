#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Room.h"
#include "Player.h"
#include "Exit.h"
#include "World.h"

int main(){
	World* world = new World;
	for (int i = 0; i < 11; i++){
		printf("%s\n", world->rooms[i].name);
		printf("%s", world->rooms[i].description);
	}
	delete world;
	system("pause");
	return 0;
}