#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDateType;
typedef struct ListNode
{
    struct ListNode *next;
    struct ListNode *prev;
    LTDateType data;

} LTNode;

LTNode *LTInit();
void LTPrint(LTNode *phead);
bool LTEmpty(LTNode *phead);
LTNode *BuyListNode(LTDateType x);
LTNode* LTFind(LTNode *phead, LTDateType x);
void LTDestory(LTNode *phead);
void LTPushBack(LTNode *phead, LTDateType x);
void LTPopBack(LTNode *phead);
void LTPushFront(LTNode *phead, LTDateType x);
void LTPopFront(LTNode *phead);
void LTInsert(LTNode *pos, LTDateType x);
void LTErase(LTNode *pos);

