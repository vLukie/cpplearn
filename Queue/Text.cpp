#include"Queue.h"


int main()
{
    Queue q;
    QInit(&q);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        QPush(&q,i);
    
    while (QSize(&q)>2)
    {
        QPop(&q);
        QPush(&q,QFront(&q));
        QPop(&q);
    }
    while (QSize(&q)>1)
        QPop(&q);
    
    
    printf("%d ",QFront(&q));
    QDestroy(&q);
    return 0;
}