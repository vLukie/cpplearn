#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int QDataType;
typedef struct QueueNode
{
    struct QueueNode *next;
    QDataType data;
} QNode;
typedef struct Queue
{
    QNode *head;
    QNode *tail;
    int size;
}Queue;

void QInit(struct Queue *pq);
void QDestroy(struct Queue *pq);
void QPush(struct Queue *pq, QDataType x);
void QPop(struct Queue *pq);
int QSize(struct Queue *pq);
bool QEmpty(struct Queue *pq);
QDataType QFront(struct Queue *pq);
QDataType QBack(struct Queue *pq);