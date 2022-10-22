#include"StackQueue.h"


// ��ʼ������
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
// ��β�����
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
// ��ͷ������
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	if (pq->head->next==NULL)//ֻ��һ���ڵ�����
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else//����ڵ�����
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}
// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	return pq->tail->data;
}
// ��ȡ��������ЧԪ�ظ���
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
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->tail;
}
// ���ٶ���
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