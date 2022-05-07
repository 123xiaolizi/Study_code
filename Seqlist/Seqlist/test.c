#include "SeqList.h"

test1()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl,3);
	SeqListPushBack(&sl,4);
	SeqListPushBack(&sl,5);
	SeqListPushBack(&sl,6);
	SeqListPushBack(&sl,7);
	SeqListPrint(&sl);
	SeqListPushFront(&sl, 2);
	SeqListPrint(&sl);
}

int main()
{
	test1();
	return 0;
}