#pragma warning(once:4996)
#include <stdio.h>
#include "game.h"

void menu()
{
	printf("*****************************\n");
	printf("*****      1. 开始游戏		 *****\n");
	printf("******	 0.退出游戏		******\n");
	printf("*****************************\n");
}



void game() 
{
	char mine[ROWS][COLS] = { 0 };//存放布置好的雷的信息
	char show[ROWS][COLS] = { 0 };//存放排查出来的雷的信息
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//打印棋盘
	
	DisplayBoard(show, ROW, COL);

	//布置雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);

	//排查雷
	FindMine(mine, show, ROW, COL);
}

int main() {
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始扫雷游戏");
			game(); //扫雷游戏
			break;
		case 0 :
			printf("退出游戏!");
			break;
		default:
			printf("选择错误，请重新选择!");
			break;
		}
	} while (input);

	return 0;		
}



