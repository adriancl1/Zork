#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include "World.h"
#include "Player.h"

int main(){

	bool state = true;
	World* world=new World;
	world->CreateWorld();

	world->player[0]->Look();//Starts with room[0] description

	while (state == true){
		state = world->Command();
	}

	delete world;
	return 0;
}