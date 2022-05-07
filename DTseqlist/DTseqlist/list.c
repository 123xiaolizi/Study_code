#include "list.h"

ListNode * ListCreate(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	assert(node);
	node->data = x;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

ListNode* ListInit()
{
	struct ListNode * phead = ListCreate(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void Printflist(ListNode* phead)
{
	struct ListNode* node = phead->next;
	while (node != phead)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}


void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);
	struct ListNode* newnode = ListCreate(x);
	struct ListNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}

void ListPopBack(ListNode* phead)
{
	ListNode* tail = phead->prev;
	ListNode* prev = tail->prev;

	prev->next = phead;
	phead->prev = prev;
	free(tail);
	tail = NULL;
}

void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* newnode = ListCreate(x);
	ListNode* tail = phead->next;
	newnode->prev = phead;
	newnode->next = tail;
	phead->next = newnode;
	
}

void ListPopFront(ListNode* phead)
{
	ListNode* node = phead->next;
	phead->next = node->next;
	node->next->prev = phead;
	free(node);
	node = NULL;
}

ListNode* ListFind(ListNode* phead, LTDataType x)
{
	struct ListNode* node = phead->next;
	while (node != phead)
	{
		if (node->data == x)
		{
			return node;
		}
		node = node->next;
	}
	return NULL;
}

void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = ListCreate(x);
	newnode->next = pos;
	newnode->prev = pos->prev;
	pos->prev->next = newnode;
	pos->prev = newnode;
}

void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* tmp = pos->prev;
	tmp->prev->next = pos;
	pos->prev = tmp->prev;
	free(tmp);
	tmp = NULL;
}