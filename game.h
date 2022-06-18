#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#define MAXROW 3
#define MAXLIS 3

void initBoard(char board[MAXROW][MAXLIS]);
void printBoard(char board[MAXROW][MAXLIS]);
void playMove(char board[MAXROW][MAXLIS],int,int);
void computerBoard(char board[MAXROW][MAXLIS],int ,int);
char isWin(char board[MAXROW][MAXLIS],int row,int lis);
