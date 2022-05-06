#pragma warning(once:4996)

#include <stdio.h>
//接受一个整型值（无符号），按照顺序打印它的每一位。
void print(int n)
{
	if (n>9)
	{
		print(n / 10);
	}
	printf("%d ", n % 10);
}


//编写函数不允许创建临时变量，求字符串的长度。
//const 修饰常变量
int Strlen(const char* str)
{
	if (*str == '\0')
		return 0;
	else
		return 1 + Strlen(str + 1);
}

//求n的阶乘。（不考虑溢出）
int factorial(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * factorial(n - 1);
}

//求第n个斐波那契数。（不考虑溢出）
//用递归的方式效率极低
int fib(int n)
{
	if (n <= 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}

//非递归的方式来实现：
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
	printf("%d 的阶乘为:>%d\n",num_2, ret);
	ret = fib_2(num_2);
	printf("第%d 个斐波那契数为：%d\n",num_2, ret);
	return 0;
}