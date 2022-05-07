#include"list.h"


void test01()
{

	ListNode* phead = ListInit();
	ListPushBack(phead,3);
	ListPushBack(phead,4);
	ListPushBack(phead, 5);
	ListPushBack(phead,6);
	ListPushBack(phead,7);
	Printflist(phead);
	ListPopBack(phead);
	printf("这里尾删一次\n");
	Printflist(phead);
	printf("这里头插入一个7\n");
	ListPushFront(phead,7);
	Printflist(phead);
	printf("这里查找元素4，并在前面插入9\n");
	ListNode* ret=ListFind(phead, 4);
	ListInsert(ret, 9);
	Printflist(phead);
	printf("这里头删一次\n");
	ListPopFront(phead);
	Printflist(phead);
	printf("这里查找元素9，并删除前面的一个节点\n");
	ret = ListFind(phead, 9);
	ListErase(ret);
	Printflist(phead);
}


main()
{
	test01();
}