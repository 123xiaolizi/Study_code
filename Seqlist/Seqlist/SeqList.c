#include "SeqList.h"


//void SeqeListInit(SL *psl)
//{
//	memset(&psl->a, 0, sizeof(SQDataType)*MAX_SIZE);
//	psl->size = 0;
//}
// 
// 
//初始化
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//扩容
void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SQDataType* tmp = (SQDataType*)realloc(ps->a, newcapacity * sizeof(SQDataType));
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity = newcapacity;
		}
	}
	
}

//打印
void SeqListPrint(SL* ps)
{
	for (int i = 0; i <= ps->size-1; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//尾插
void SeqListPushBack(SL* ps, SQDataType x)
{
	//先检查空间是否足够
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//头插
void SeqListPushFront(SL* ps, SQDataType x)
{
	SeqListCheckCapacity(ps);

	// 1、初始条件
	// 2、结束条件
	// 3、迭代过程
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}

	ps->a[0] = x;
	ps->size++;

	//SeqListInsert(ps, 0, x);

}

//头删
void SeqListPopFront(SL* ps)
{
	if (ps->size > 0)
	{
		int start = 1;
		while (start < ps->size)
		{
			ps->a[start - 1] = ps->a[start];
			++start;
		}
		ps->size--;
	}
	else
	{
		printf("暂无数据，无法删除");
	}
}
//尾删
void SeqListPopBack(SL* ps)
{
	assert(ps->size > 0);

	ps->a[ps->size - 1] = 0;
	ps->size--;
	//SeqListErase(ps, ps->size - 1);
}

//指定位置插入
void SeqListInsert(SL* ps, int pos, SQDataType x)
{
	assert(pos <= ps->size);
	SeqListCheckCapacity(ps);

	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}

	ps->a[pos] = x;
	ps->size++;
}
//删除指定位置元素
void SeqListErase(SL* ps, int pos)
{
	assert(pos < ps->size);
	int start = pos + 1;
	while (start < ps->size)
	{
		ps->a[start - 1] = ps->a[start];
		++start;
	}
	ps->size--;
}

//修改
void SeqListModity(SL* ps, int pos, SQDataType x)
{
	assert(pos < ps->size);
	ps->a[pos] = x;
}