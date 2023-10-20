#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H

void initializeBoard(uint8 board[][3],uint8 rows,uint8 colums);
void displayBoard(uint8 board[][3],uint8 rows,uint8 colums);
uint8 isBoardFull(uint8 board[][3],uint8 rows,uint8 colums);
void getPlayerMove(uint8 board[][3],uint8 player);
uint8 checkWin(uint8 board[][3],uint8 player); 
void playgame();
uint8 playAgainOrQuit(); 
void playSinglePlayerGame();
void makeSmartMove(uint8 board[][3],uint8 rows,uint8 colums,uint8 player);

#endif