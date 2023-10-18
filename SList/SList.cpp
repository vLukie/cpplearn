#include "SList.h"

SLTNode *BuySTLNode(SLTDateType x)
{
    SLTNode *newnode = (SLTNode *)malloc(sizeof(SLTNode));
    if (newnode == NULL)
    {
        perror("malloc fail");
        return NULL;
    }
    newnode->next = NULL;
    newnode->date = x;

    return newnode;
}

void SLTPrint(SLTNode *phead)
{
    // assert(phead);
    SLTNode *cur = phead;
    while (cur)
    {
        printf("%d->", cur->date);
        cur = cur->next;
    }
    printf("NULL\n");
}

void SLTPushBack(SLTNode **pphead, SLTDateType x)
{
    SLTNode *newnode = BuySTLNode(x);

    if (*pphead == NULL)
        *pphead = newnode;
    else
    {
        SLTNode *tail = *pphead;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newnode;
    }
}

void SLTPushFront(SLTNode **pphead, SLTDateType x)
{
    SLTNode *newnode = BuySTLNode(x);

    newnode->next = *pphead;
    *pphead = newnode;
}

void SLTPopBack(SLTNode **pphead)
{
    assert(*pphead);
    assert(pphead);
    if ((*pphead)->next == NULL)
    {
        free(*pphead);
        *pphead = NULL;
    }
    else
    {
        SLTNode *tail = *pphead;
        while (tail->next->next != NULL)
            tail = tail->next;

        free(tail->next);
        tail->next = NULL;
    }
}

void SLTPopFront(SLTNode **pphead)
{
    assert(*pphead);
    assert(pphead);

    SLTNode *first = *pphead;
    *pphead = first->next;
    free(first);
    first = NULL;
}
SLTNode *SLTFind(SLTNode *phead, SLTDateType x)
{
    SLTNode *cur = phead;
    while (cur)
    {
        if (cur->date == x)
            return cur;

        cur = cur->next;
    }
    return NULL;
}

void SLTInsert(SLTNode **pphead, SLTNode *pos, SLTDateType x)
{
    assert(pos);
    assert(pphead);
    if (pos == *pphead)
        SLTPushFront(pphead, x);
    else
    {
        SLTNode *prev = *pphead;
        while (prev->next != pos)
            prev = prev->next;

        SLTNode *newnode = BuySTLNode(x);
        prev->next = newnode;
        newnode->next = pos;
    }
}
void SLTErase(SLTNode **pphead, SLTNode *pos)
{
    assert(pos);
    assert(pphead);
    assert(*pphead);
    if (pos == *pphead)
        SLTPopFront(pphead);
    else
    {
        SLTNode *prev = *pphead;
        while (prev->next != pos)
            prev = prev->next;
        prev->next=pos->next;
        free(pos);
    }
    
}
