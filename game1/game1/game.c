#pragma warning(once:4996)
#include "game.h"
//��ʼ������
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
//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("----------ɨ����Ϸ-----------\n");
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

//������
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	//����10����
	int count = 10;
	while (count)
	{
		//��������±�
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
//�Ų���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) 
{
	//1.�����Ų�����
	//2.��������ǲ�����
		// 1.���ף���Ϸ����
		// 2.�ǲ��ף�ͳ����Χ�����м����ף������Ų��׵���Ϣ��show���飬��Ϸ����
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("������Ҫ�Ų������:>");
		scanf("%d%d", &x, &y);

		//�ж�����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("���ź���ȵ����ˣ���Ϸ����\n");
				printf("----------------------------------\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//�����׵�����£�ͳ��x,y ������Χ�׵���Ϣ
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				//��ӡ����
				DisplayBoard(show, row, col);
				
			}
		}
		else
		{
			printf("�����������������:>\n");
		}
	}

}
