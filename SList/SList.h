#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDateType;
typedef struct SListNode
{
    SLTDateType date;
    struct SListNode *next;
} SLTNode;

SLTNode* BuySTLNode(SLTDateType x);
void SLTPrint(SLTNode *phead);
void SLTPushBack(SLTNode **phead, SLTDateType x);
void SLTPushFront(SLTNode **phead, SLTDateType x);
void SLTPopBack(SLTNode **phead);
void SLTPopFront(SLTNode **phead);
void SLTInsert(SLTNode **phead,SLTNode* pos,SLTDateType x);
void SLTErase(SLTNode **phead,SLTNode* pos);
void STLInsertAfter(SLTNode* pos);
void STLEraseAfter(SLTNode* pos);
SLTNode* SLTFind(SLTNode* phead,SLTDateType x);
