#pragma once
#include <stdio.h>
#include<string.h>
#include<stdlib.h>



//Ϊ��ǿ�����ά����
//#define MAX_SIZE 500
typedef int SQDataType;
//��̬�ڴ��
typedef struct SeqList
{
	SQDataType* a;
	int size;     // ��Ч���ݵĸ���
	int capacity; // ����
}SL;


//��ʼ������
void SeqListInit(SL* ps);
//��ӡ
void SeqListPrint(SL* ps);
//�ͷ��ڴ�

//��ɾ�Ĳ�Ƚӿں���

void SeqListPushBack(SL* ps, SQDataType x);//β��

void SeqListPushFront(SL* ps, SQDataType x);//ͷ��

void SeqListPopBack(SL* ps);

void SeqListPopFront(SL* ps);

void SeqListInsert(SL* ps, int pos, SQDataType x);

void SeqListErase(SL* ps, int pos);