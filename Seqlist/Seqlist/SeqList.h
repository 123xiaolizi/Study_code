#pragma once
#include <stdio.h>
#include<string.h>
#include<stdlib.h>



//为增强程序可维护性
//#define MAX_SIZE 500
typedef int SQDataType;
//动态内存的
typedef struct SeqList
{
	SQDataType* a;
	int size;     // 有效数据的个数
	int capacity; // 容量
}SL;


//初始化函数
void SeqListInit(SL* ps);
//打印
void SeqListPrint(SL* ps);
//释放内存

//增删改查等接口函数

void SeqListPushBack(SL* ps, SQDataType x);//尾加

void SeqListPushFront(SL* ps, SQDataType x);//头加

void SeqListPopBack(SL* ps);

void SeqListPopFront(SL* ps);

void SeqListInsert(SL* ps, int pos, SQDataType x);

void SeqListErase(SL* ps, int pos);