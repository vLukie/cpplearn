#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int HPDataType;
typedef struct Heap
{
    HPDataType *a;
    int size;
    int capacity;

} HP;
void HeapInit(HP *php);
void HeapDestory(HP *php);
void HeapPush(HP *php, HPDataType x);
void HeapPop(HP *php); // 删除老祖宗
HPDataType HeapTop(HP *php);
bool HeapEmpty(HP *php);
int HeapSize(HP *php);


void Swap(HPDataType *a, HPDataType *b);
void AdjustUp(HPDataType *a, int child);
void AdjustDown(HPDataType *a, int n,int parent);
void HeapSort(HPDataType *a, int n);
