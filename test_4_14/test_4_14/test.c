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
		printf("��ĵ��Խ���60s��ػ������棬��رմ��ڣ���Ȼû����ȡ���ػ���\n���ǽУ��У�����һ�����ְ֡�>:");
		scanf("%s", input);
		if (strcmp(input, "�ְ�") == 0)
		{
			system("shutdown -a");
			printf("�����ö��ӡ�");
			break;
		}
		else
		{
			printf("���ӣ����Ƥ�����аְ�");
		}
	}

	return 0;
}