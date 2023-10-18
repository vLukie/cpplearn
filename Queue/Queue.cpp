#include "Queue.h"

void QInit(struct Queue *pq)
{
    assert(pq);
    pq->head = pq->tail = NULL;
    pq->size = 0;
}

void QDestroy(struct Queue *pq)
{
    assert(pq);
    QNode *cur = pq->head;
    while (cur)
    {
        QNode *next = cur->next;
        free(cur);
        cur = next;
    }
    pq->head = pq->tail = NULL;
    pq->size = 0;
}
void QPush(struct Queue *pq, QDataType x)
{
    QNode *newnode = (QNode *)malloc(sizeof(QNode));
    if (newnode == NULL)
    {
        perror("malloc fail");
        return;
    }
    newnode->data = x;
    newnode->next = NULL;

    if (pq->head == NULL)
    {
        assert(pq->tail == NULL);
        pq->head = pq->tail = newnode;
    }
    else
    {
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
    pq->size++;
}
void QPop(struct Queue *pq)
{
    assert(pq);
    assert(pq->head);
    if (pq->head->next == NULL)
    {
        free(pq->head);
        pq->head = pq->tail = NULL;
    }
    else
    {
        QNode *next = pq->head->next;
        free(pq->head);
        pq->head = next;
    }
    pq->size--;
}
int QSize(struct Queue *pq)
{
    assert(pq);
    return pq->size;
}
bool QEmpty(struct Queue *pq)
{
    assert(pq);
    return pq->size == 0;
}
QDataType QFront(struct Queue *pq)
{
    assert(pq);
    assert(!QEmpty(pq));
    return pq->head->data;
}
QDataType QBack(struct Queue *pq)
{
    assert(pq);
    assert(!QEmpty(pq));
    return pq->tail->data; 
}