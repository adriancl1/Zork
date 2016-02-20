//Adrián Castillo 
#include <stdio.h>
#include <stdlib.h>

int main(){
	char player='n';
	char location = 'd';//d=dinning room, k=kitchen, b=bathroom, r=bedroom, p=pantry
	printf("You are at the dinning room.");
	while (player != 'q'){
		printf("\n\nWhich direction do you want to go ? (n / s / e / w / q) ");
		fflush(stdin);
		scanf_s("%c", &player);
		switch (player){
			case 'n':
				if (location == 'd'){
					printf("You are now at the kitchen.");
					location = 'k';
					break;
				}
				if (location == 'r'){
					printf("You are now at the dinning room.");
					location = 'd';
					break;
				}
				else{
					printf("You found a wall.");
					break;
				}
			case 's':
				if (location == 'd'){
					printf("You are now at the bedroom.");
					location = 'r';
					break;
				}
				if (location == 'k'){
					printf("You are now at the dinning room.");
					location = 'd';
					break;
				}
				else{
					printf("You found a wall.");
					break;
				}
			case 'e':
				if (location == 'd'){
					printf("You are now at the bathroom.");
					location = 'b';
					break;
				}
				if (location == 'k'){
					printf("You are now at the pantry.");
					location = 'p';
					break;
				}
				else{
					printf("You found a wall.");
					break;
				}
			case 'w':
				if (location == 'p'){
					printf("You are now at the kitchen.");
					location = 'k';
					break;
				}
				if (location == 'b'){
					printf("You are now at the dinning room.");
					location = 'd';
					break;
				}
				else{
					printf("You found a wall.");
					break;
				}
			case 'q':
				printf("Thank you for playing!\n");
				break;
		}
	}
	system("pause");
	return 0;
}