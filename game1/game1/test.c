#pragma warning(once:4996)
#include <stdio.h>
#include "game.h"

void menu()
{
	printf("*****************************\n");
	printf("*****      1. ��ʼ��Ϸ		 *****\n");
	printf("******	 0.�˳���Ϸ		******\n");
	printf("*****************************\n");
}



void game() 
{
	char mine[ROWS][COLS] = { 0 };//��Ų��úõ��׵���Ϣ
	char show[ROWS][COLS] = { 0 };//����Ų�������׵���Ϣ
	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//��ӡ����
	
	DisplayBoard(show, ROW, COL);

	//������
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);

	//�Ų���
	FindMine(mine, show, ROW, COL);
}

int main() {
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼɨ����Ϸ");
			game(); //ɨ����Ϸ
			break;
		case 0 :
			printf("�˳���Ϸ!");
			break;
		default:
			printf("ѡ�����������ѡ��!");
			break;
		}
	} while (input);

	return 0;		
}


