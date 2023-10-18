#include "SeqList.h"

void TestSeqList1()
{
    SL s;
    SLInit(&s);
    SLPushBack(&s, 1);
    SLPushBack(&s, 2);
    SLPushBack(&s, 3);
    SLPushBack(&s, 4);
    SLPushBack(&s, 5);
    SLPushBack(&s, 6);
    SLPushBack(&s, 7);
    SLPrint(&s);
    SLPopBack(&s);
    SLPopBack(&s);
    SLPrint(&s);

    SLDestroy(&s);
}
void TestSeqList2()
{
    SL s;
    SLInit(&s);
    SLPushBack(&s, 1);
    SLPushBack(&s, 2);
    SLPushBack(&s, 3);
    SLPushBack(&s, 4);
    SLPushBack(&s, 5);
    SLPushBack(&s, 6);
    SLPushBack(&s, 7);
    SLPrint(&s);
    SLErase(&s,3);
    SLPrint(&s);

    SLDestroy(&s);
}
int main()
{
    // TestSeqList2();
    void *ptr1=malloc(10);
    printf("%p\n",ptr1);
    void *ptr2=realloc(ptr1,5);
    printf("%p\n",ptr2);
    return 0;
}
