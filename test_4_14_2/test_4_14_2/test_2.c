#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(once:4996)


void menu()
{
	char i[9] = { "*" };
	printf("%s", i);
	printf("%s", i);
}
void game()
{
	int random_num = rand() % 100 + 1;
	int input = 0;
	while (1)
	{
		printf("��������µ�����>:\n");
		scanf("%d", &input);
		if (input > random_num)
		{
			printf("��´��ˣ�\n");
		}
		else if (input < random_num)
		{
			printf("���С�ˣ�\n");
		}
		else
		{
			printf("��ϲ��¶��ˣ�����\n");
			break;

		}
	}
}

int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		printf("��ʼ������Ϸ>:1\n�˳���Ϸ>0:\n-->:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0: 
			break;
		default:
			printf("����������������룺");
			break;
		}
	} while (input);
}