#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 60");

	while ( 1 )
	{
		printf("你的电脑将在60s后关机，警告，别关闭窗口，不然没机会取消关机。\n除非叫（叫）老子一声“爸爸”>:");
		scanf("%s", input);
		if (strcmp(input, "爸爸") == 0)
		{
			system("shutdown -a");
			printf("诶！好儿子。");
			break;
		}
		else
		{
			printf("儿子，别调皮，来叫爸爸");
		}
	}

	return 0;
}