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
	printf("����βɾһ��\n");
	Printflist(phead);
	printf("����ͷ����һ��7\n");
	ListPushFront(phead,7);
	Printflist(phead);
	printf("�������Ԫ��4������ǰ�����9\n");
	ListNode* ret=ListFind(phead, 4);
	ListInsert(ret, 9);
	Printflist(phead);
	printf("����ͷɾһ��\n");
	ListPopFront(phead);
	Printflist(phead);
	printf("�������Ԫ��9����ɾ��ǰ���һ���ڵ�\n");
	ret = ListFind(phead, 9);
	ListErase(ret);
	Printflist(phead);
}


main()
{
	test01();
}