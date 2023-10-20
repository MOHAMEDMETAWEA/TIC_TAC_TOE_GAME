#include "STD_TYPES.h"
#include <stdio.h>
#include <stdlib.h>
#include "TIC_TAC_TOE_GAME.h"


void initializeBoard(uint8 board[][3],uint8 rows,uint8 colums)
{
	for(uint8 i=0;i<rows;i++)
	{
		for(uint8 j=0;j<colums;j++)
		{
			board[i][j]=' ';
		}
	}
}


void displayBoard(uint8 board[][3],uint8 rows,uint8 colums)
{
	system("cls||clear");
	printf("----------\n");
	for(uint8 i=0;i<rows;i++)
	{
		printf("|");
		for(uint8 j=0;j<colums;j++)
		{
			printf("%c |",board[i][j]);
		}
		printf("\n----------\n");
	}
	
}


void getPlayerMove(uint8 board[][3],uint8 player)
{
	int row, col;
	printf("Player %c's turn.\n",player);
	printf("Enter your move row (1-3) and column (1-3):\n");
	scanf("%d %d", &row, &col);
	row --;
	col--;
	//check validity of position
	if ((row >= 0 )&& (row < 3) &&( col >= 0 )&& (col < 3 )&&(board[row][col]==' '))
	{
		board[row][col]=player;
	}
	else 
	{
        printf("Invalid move. Try again.\n");
        getPlayerMove(board, player);
    }
}


uint8 isBoardFull(uint8 board[][3],uint8 rows,uint8 colums)
{
	for (uint8 i = 0; i < rows; ++i) 
	{
        for (uint8 j = 0; j < colums; ++j) 
		{
            if (board[i][j] == ' ') 
			{
                return 0;  // Board is not full
            }
        }
    }
    return 1;  // Board is full
}


void playgame()
{
	uint8 board[3][3];
    uint8 currentPlayer = 'X';
	initializeBoard(board,3,3);
	while(1)
	{
		displayBoard(board,3,3);
        getPlayerMove(board, currentPlayer);
		 if (checkWin(board, currentPlayer)) 
		 {
            displayBoard(board,3,3);
            printf("Player %c wins!\n", currentPlayer);
			//check if player want to play again or not
			if(playAgainOrQuit())
			{
				playgame();
			}	
			else
			{
				break;
			}
        }
		else if (isBoardFull(board,3,3)) 
		{
            displayBoard(board,3,3);
            printf("It's a draw!\n");
            if(playAgainOrQuit())
			{
				playgame();
			}	
			else
			{
				break;
			}
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}


uint8 checkWin(uint8 board[][3],uint8 player) 
{
	
	for(uint8 i=0;i<3;i++)
	{	
		// Check rows and columns
		if( ( ((board[i][0])==player) && ((board[i][1])==player) && ((board[i][2])==player) ) || 
				( ((board[0][i])==player) && ((board[1][i])==player) && ((board[2][i])==player) ) )
		{
			return 1; 
		}// Player has won
	}
	
	// Check diagonals
		if( ( ((board[0][0])==player) && ((board[1][1])==player) && ((board[2][2])==player) ) || 
				( ((board[0][2])==player) && ((board[1][1])==player) && ((board[2][0])==player) ) )
		{
			return 1; 
		}// Player has won
		
	return 0;  // No winner yet
}


uint8 playAgainOrQuit() 
{
    uint8 choice;
    printf("Do you want to play again? (1 for yes, 0 for no): ");
    scanf("%d", &choice);
    return choice;
}


void playSinglePlayerGame()
{
	uint8 board[3][3],currentPlayer,User;
	printf("Choose sympol you want to play with(X OR O):");
	scanf(" %c",&User);
	currentPlayer=User;
	initializeBoard(board,3,3);

    while (1) 
	{
		displayBoard(board,3,3);
		
		if(currentPlayer==User)
		{
			getPlayerMove(board, currentPlayer);

		}
		else
		{
			makeSmartMove(board,3,3,currentPlayer);
		}
		if (checkWin(board, currentPlayer)) 
		{
            displayBoard(board,3,3);
			if (currentPlayer == User) 
			{
                printf("You win!\n");
            }
			else
			{
                printf("Computer wins!\n");
				printf("good luck!\n");
            }
			//check if player want to play again or not
			if(playAgainOrQuit())
			{
				playSinglePlayerGame();
			}	
			else
			{
				break;
			}
        }
		else if (isBoardFull(board,3,3)) 
		{
            displayBoard(board,3,3);
            printf("It's a draw!\n");
            if(playAgainOrQuit())
			{
				playSinglePlayerGame();
			}	
			else
			{
				break;
			}
        }
		currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
	}
}


void makeSmartMove(uint8 board[][3], uint8 rows, uint8 columns, uint8 player)
{
    uint8 opponentPlayer = player;

    // Check for a winning move for 'O' and block user's winning move for 'X'
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < columns; ++j) 
        {
            if (board[i][j] == ' ') 
            {
                // Try making a move and check if it leads to a win
                board[i][j] = opponentPlayer;
                if (checkWin(board, opponentPlayer)) 
                {
                    return;  // Win the game
                }

                // Undo the move before checking the next possibility
                board[i][j] = ' ';

                // Check if user can win with this move, and block if necessary
                board[i][j] = player;
                if (checkWin(board, player)) 
                {
                    board[i][j] = opponentPlayer;  // Block user's winning move
                    return;
                }

                // Undo the move before checking the next possibility
                board[i][j] = ' ';
            }
        }
    }

    // If no winning or blocking move, make a random move
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < columns; ++j) 
        {
            if (board[i][j] == ' ') {
                board[i][j] = opponentPlayer;  // Random move
                return;
            }
        }
    }
}
