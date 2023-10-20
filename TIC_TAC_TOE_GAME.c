#include "STD_TYPES.h"
#include <stdio.h>
#include <stdlib.h>
#include "TIC_TAC_TOE_GAME.h"

int main()
{
	sint8 choise;
	printf("1.Multiplayer mode\n");
	printf("2.Single player mode\n");
	printf("3.Quit\n");
	printf("choose mode:");
	scanf("%d",&choise);
	system("cls||clear");   // This statement will clear screen.
	switch(choise)
	{
		case 1:
			   printf("Multiplayer mode selected.\n");
			   playgame();
			   break;
		
		case 2:
				printf("Single player mode selected.\n");
				playSinglePlayerGame();
				break;
				
		case 3:
                printf("Quitting the game.\n");
                exit(0);           
				
		default:
                printf("Invalid choice. Try again.\n");	   
	}
	return 0;
}
