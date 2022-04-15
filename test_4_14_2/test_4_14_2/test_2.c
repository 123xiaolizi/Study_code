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
		printf("请输入你猜的数字>:\n");
		scanf("%d", &input);
		if (input > random_num)
		{
			printf("你猜大了！\n");
		}
		else if (input < random_num)
		{
			printf("你猜小了！\n");
		}
		else
		{
			printf("恭喜你猜对了！！！\n");
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
		printf("开始猜字游戏>:1\n退出游戏>0:\n-->:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0: 
			break;
		default:
			printf("输入错误，请重新输入：");
			break;
		}
	} while (input);
}