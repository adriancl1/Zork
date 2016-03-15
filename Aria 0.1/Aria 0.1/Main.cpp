#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include "World.h"

#define NUM_ROOMS 11
#define NUM_EXITS 22

int main(){
	char choice[25];
	bool state = true;
	World world;
	world.CreateWorld();
	world.kevin->Look();

	while (state == true){
		state = world.Command();
	}

	return 0;
}