#pragma warning(once:4996)
#include "game.h"
//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set) 
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++) 
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("----------扫雷游戏-----------\n");
	for(i = 0; i<=col;i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("---------------------------------------\n");
}

//布置雷
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	//布置10个雷
	int count = 10;
	while (count)
	{
		//产生随机下标
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}


static int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - '0' * 8;
}
//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) 
{
	//1.输入排查坐标
	//2.检查坐标是不是雷
		// 1.是雷，游戏结束
		// 2.是不雷，统计周围坐标有几个雷，储存排查雷的信息到show数组，游戏继续
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入要排查的坐标:>");
		scanf("%d%d", &x, &y);

		//判断坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾你踩到雷了，游戏结束\n");
				printf("----------------------------------\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//不是雷的情况下，统计x,y 坐标周围雷的信息
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				//打印棋盘
				DisplayBoard(show, row, col);
				
			}
		}
		else
		{
			printf("输入错误，请重新输入:>\n");
		}
	}

}
