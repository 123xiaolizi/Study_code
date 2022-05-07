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


//初始化
void StackInit(Stack* ps);

//入栈
void StackPush(Stack* ps, STDataType data);

//出栈
void StackPop(Stack* ps);

// 获取栈顶元素
STDataType StackTop(Stack* ps);
// 获取栈中有效元素个数
int StackSize(Stack* ps);

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
bool StackEmpty(Stack* ps);

// 销毁栈
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

// 初始化队列
void QueueInit(Queue* pq);
// 队尾入队列
void QueuePush(Queue* pq, QDataType data);
// 队头出队列
void QueuePop(Queue* pq);
// 获取队列头部元素
QDataType QueueFront(Queue * pq);
// 获取队列队尾元素
QDataType QueueBack(Queue* pq);
// 获取队列中有效元素个数
int QueueSize(Queue* pq);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
bool QueueEmpty(Queue* pq);
// 销毁队列
void QueueDestroy(Queue* pq);

