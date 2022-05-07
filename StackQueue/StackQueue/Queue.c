#include"StackQueue.h"


// 初始化队列
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
// 队尾入队列
void QueuePush(Queue* pq, QDataType data)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode==NULL)
	{
		printf("malloc fail.\n");
		exit(-1);
	}
	newnode->data = data;
	newnode->next = NULL;
	if (pq->tail==NULL)
	{
		pq->head = newnode;
		pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;

	}

}
// 队头出队列
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	if (pq->head->next==NULL)//只有一个节点的情况
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else//多个节点的情况
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}
// 获取队列头部元素
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}
// 获取队列队尾元素
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	return pq->tail->data;
}
// 获取队列中有效元素个数
int QueueSize(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	int size = 0;
	Queue* cur = pq->head;
	while (cur)
	{
		++size;
		cur = cur->head->next;
	}
	return size;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->tail;
}
// 销毁队列
void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->head = pq->tail = NULL;
}