#include"StackQueue.h"


//��ʼ��
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


//��ջ
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	//��������
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


//��ջ
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

// ��ȡջ��Ԫ��
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->data[ps->top - 1];
}
// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;

}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top;
}

// ����ջ
void StackDestroy(Stack* ps)
{
	assert(ps);
	assert(ps->data);
	free(ps->data);
	ps->data = NULL;
	ps->top = ps->capacity = 0;
}