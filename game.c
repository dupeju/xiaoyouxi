#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//返回1表示满了，返回0表示没满"
int isFULL(char board[MAXROW][MAXLIS], int row, int lis)
{
	int x = 0, y = 0;
	for (x = 0; x < row; x++)
	{
		for (y = 0; y < lis; y++)
			if (board[x][y] == ' ')
				return 0;
	}
	return 1;
}
void initBoard(char board[MAXROW][MAXLIS])
{
	for (int row = 0; row < MAXROW; row++)
		for (int lis = 0; lis < MAXLIS; lis++)
			board[row][lis] = ' ';
}
void printBoard(char board[MAXROW][MAXLIS])
{
	int row = 0;
	int lis = 0;
	printf("yx|");
	for (lis = 0; lis < MAXLIS; lis++)
		printf(" %-2d ", lis+1);
	printf("\n");
	for (int lis = 0; lis < MAXLIS * 3 + (MAXLIS + 1); lis++)
		printf("-");
	printf("\n");
	for (row = 0; row < MAXROW; row++)
	{
		printf("%-2d|",row+1);
		for (lis = 0; lis < MAXLIS; lis++)
		{
			printf(" %c ",board[row][lis]);
			if (lis < MAXLIS - 1)
				printf("|");
			else
				putchar('\n');
		}
		printf("  |");
		if (row < MAXROW - 1)
		{
			for (lis = 0; lis < MAXLIS; lis++)
			{
				printf("---");
				if (lis < MAXLIS - 1)
					putchar('|');
				else
					printf("\n");
			}
			
		}
		
	}
}
void playMove(char board[MAXROW][MAXLIS], int row, int lis)
{
	int x=0, y=0;
	while (1)
	{
		printf("玩家走 (请输入要下坐标):>");
		scanf("%d%d",&x,&y);
		if (x >= 1 && y <= row && y >= 1 &&  x<= lis)
		{
			if (board[y - 1][x - 1] == ' ')
			{
				board[y - 1][x - 1] = 'o';
				system("cls");
				break;
			}
				
			else
				printf("坐标(%d,%d)此处有子\n",x,y);
		}
		else
		{
			printf("输入值非法\n");
		}
	}
}
void computerBoard(char board[MAXROW][MAXLIS],int row,int lis)
{
	printf("电脑正在思考中……\n");
	Sleep(2500);
	int x = 0, y = 0;
	 
	while (1)
	{
		x = rand() % row;
		y = rand() % lis;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'x';
			break;
		}
			

	}
	
}
void isWin(char board[MAXROW][MAXLIS], int row, int lis)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	for (i = 0; i < lis; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ' || board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	if (1 == isFULL(board, MAXROW, MAXLIS))
		return 'q';
	return 'c';
}