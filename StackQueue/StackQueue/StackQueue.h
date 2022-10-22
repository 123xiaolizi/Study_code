#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


typedef int STDataType;
typedef int QDataType;

typedef struct Stack
{
	STDataType* data;
	int top;
	int capacity;
}Stack;


//��ʼ��
void StackInit(Stack* ps);

//��ջ
void StackPush(Stack* ps, STDataType data);

//��ջ
void StackPop(Stack* ps);

// ��ȡջ��Ԫ��
STDataType StackTop(Stack* ps);
// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps);

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
bool StackEmpty(Stack* ps);

// ����ջ
void StackDestroy(Stack* ps);


typedef struct QListNode
{
	struct QListNode* next;
	QDataType data;

}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

// ��ʼ������
void QueueInit(Queue* pq);
// ��β�����
void QueuePush(Queue* pq, QDataType data);
// ��ͷ������
void QueuePop(Queue* pq);
// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue * pq);
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* pq);
// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* pq);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
bool QueueEmpty(Queue* pq);
// ���ٶ���
void QueueDestroy(Queue* pq);

