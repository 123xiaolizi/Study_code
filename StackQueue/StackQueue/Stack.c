#include"StackQueue.h"


//初始化
void StackInit(Stack* ps)
{
	assert(ps);
	ps->data = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (ps == NULL)
	{
		printf("malloc fail !\n");
	}
	ps->capacity = 4;
	ps->top = 0;

	//ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	//if (ps->a == NULL)
	//{
	//	printf("malloc fail\n");
	//	exit(-1);
	//}

	//ps->capacity = 4;
	//ps->top = 0;
}


//入栈
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	//满了扩容
	if (ps->top == ps->capacity)
	{
		STDataType* newp = (STDataType)realloc(ps->data,sizeof(STDataType)*2*ps->capacity);
		if (newp == NULL)
		{
			exit(-1);
		}
		else
		{
			ps->data = newp;
			ps->capacity *= 2;
		}
	}
	else
	{
		ps->data[ps->top] = data;
		ps->top += 1;
	}
}


//出栈
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

// 获取栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->data[ps->top - 1];
}
// 获取栈中有效元素个数
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;

}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top;
}

// 销毁栈
void StackDestroy(Stack* ps)
{
	assert(ps);
	assert(ps->data);
	free(ps->data);
	ps->data = NULL;
	ps->top = ps->capacity = 0;
}