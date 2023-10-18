#include <stdio.h>
#include <stdlib.h>
#pragma once
// typedef  int SLDataType;
// #define N 10

// struct SeqList
// {
//     SLDataType a[N];
//     int size;
// };

#define INIT_CAPACITY 4
typedef int SLDataType;
typedef struct SeqList
{
    SLDataType *a;
    int size;     // 数据量
    int capacity; // 容量
} SL;
void SLInit(SL *ps);
void SLDestroy(SL *ps);
void SLPrint(SL *ps);
void SLCheckCapacity(SL *ps);
void SLPushBack(SL *ps, SLDataType x);
void SLPopBack(SL *ps);
void SLPushFront(SL *ps, SLDataType x);
void SLPopFront(SL *ps);
void SLInsert(SL *ps, int pos, SLDataType x);
void SLErase(SL *ps, int pos);
int SLFind(SL *ps, SLDataType x);