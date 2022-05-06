#pragma warning(once:4996)

#include <stdio.h>
//����һ������ֵ���޷��ţ�������˳���ӡ����ÿһλ��
void print(int n)
{
	if (n>9)
	{
		print(n / 10);
	}
	printf("%d ", n % 10);
}


//��д��������������ʱ���������ַ����ĳ��ȡ�
//const ���γ�����
int Strlen(const char* str)
{
	if (*str == '\0')
		return 0;
	else
		return 1 + Strlen(str + 1);
}

//��n�Ľ׳ˡ��������������
int factorial(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * factorial(n - 1);
}

//���n��쳲����������������������
//�õݹ�ķ�ʽЧ�ʼ���
int fib(int n)
{
	if (n <= 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}

//�ǵݹ�ķ�ʽ��ʵ�֣�
int fib_2(int n)
{
	int result;
	int pre_result;
	int next_older_result;
	result = pre_result = 1;
	while (n > 2)
	{
		n -= 1;
		next_older_result = pre_result;
		pre_result = result;
		result = pre_result + next_older_result;
	}
	return result;
}


int main()
{
	int num = 12345;
	print(num);
	printf("\n");
	char* p = "xiaoxiongjun";
	int len = Strlen(p);
	printf("%d\n", len);
	int num_2 = 5;
	int ret = factorial(num_2);
	printf("%d �Ľ׳�Ϊ:>%d\n",num_2, ret);
	ret = fib_2(num_2);
	printf("��%d ��쳲�������Ϊ��%d\n",num_2, ret);
	return 0;
}