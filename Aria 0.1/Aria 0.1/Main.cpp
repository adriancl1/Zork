#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include "World.h"

int main(){

	bool state = true;
	World* world=new World;
	world->CreateWorld();
	world->kevin->Look();

	while (state == true){
		state = world->Command();
	}

	delete[] world;
	return 0;
}