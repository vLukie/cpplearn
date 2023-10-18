#include "List.h"

LTNode *LTInit()
{
    LTNode *phead = BuyListNode(-1);
    phead->next = phead;
    phead->prev = phead;
    return phead;
}
void LTPrint(LTNode *phead)
{
    assert(phead);
    printf("<=>head<=>");
    LTNode *cur = phead->next;
    while (cur != phead)
    {
        printf("%d<=>", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
bool LTEmpty(LTNode *phead)
{
    assert(phead);
    return phead->next == phead;
}
LTNode *BuyListNode(LTDateType x)
{
    LTNode *newnode = (LTNode *)malloc(sizeof(LTNode));
    if (newnode == NULL)
    {
        perror("malloc fail");
        return NULL;
    }
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->data = x;
    return newnode;
}
LTNode *LTFind(LTNode *phead, LTDateType x)
{
    assert(phead);
    LTNode *cur = phead->next;
    while (cur != phead)
    {
        if (cur->data == x)
            return cur;
        cur = cur->next;
    }
    return NULL;
}
void LTDestory(LTNode *phead)
{
    assert(phead);
    LTNode *cur = phead->next;
    while (cur != phead)
    {
        LTNode* next=cur->next;
        free(cur);
        cur=next;
    }
    free(phead);   
}
void LTPushBack(LTNode *phead, LTDateType x)
{
    assert(phead);

    // LTNode *newnode = BuyListNode(x);
    // LTNode *tail = phead->prev;
    // tail->next = newnode;
    // newnode->prev = tail;
    // newnode->next = phead;
    // phead->prev = newnode;
    LTInsert(phead, x);
}
void LTPopBack(LTNode *phead)
{
    assert(phead);
    assert(!LTEmpty(phead));
    // LTNode *tail = phead->prev;
    // LTNode *newtail = tail->prev;
    // newtail->next = phead;
    // phead->prev = newtail;
    // free(tail);
    // tail = NULL;
    LTErase(phead->prev);
}

void LTPushFront(LTNode *phead, LTDateType x)
{
    assert(phead);
    // LTNode *newnode = BuyListNode(x);
    // newnode->next = phead->next;
    // phead->next->prev = newnode;
    // phead->next = newnode;
    // newnode->prev = phead;
    LTInsert(phead->next, x);
}
void LTPopFront(LTNode *phead)
{
    assert(phead);
    assert(!LTEmpty(phead));
    // LTNode *tmp = phead->next;
    // phead->next = tmp->next;
    // tmp->next->prev = phead;
    // free(tmp);
    // tmp = NULL;
    LTErase(phead->next);
}
void LTInsert(LTNode *pos, LTDateType x)
{
    assert(pos);
    LTNode *prev = pos->prev;
    LTNode *newnode = BuyListNode(x);
    prev->next = newnode;
    newnode->prev = prev;
    newnode->next = pos;
    pos->prev = newnode;
}
void LTErase(LTNode *pos)
{
    assert(pos);
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    free(pos);
}