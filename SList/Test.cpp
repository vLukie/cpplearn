#include "SList.h"

void SListTest1()
{
    SLTNode *plist = NULL;
    SLTPushBack(&plist, 1);
    SLTPushBack(&plist, 2);
    SLTPushBack(&plist, 3);
    SLTPushFront(&plist, 4);
    SLTPushFront(&plist, 5);
    SLTPushFront(&plist, 6);
    SLTPrint(plist);

    SLTNode *ret = SLTFind(plist, 2);
    SLTInsert(&plist, ret, 20);
    SLTPrint(plist);
    SLTErase(&plist,ret);
    ret=NULL;
    SLTPrint(plist);
}

int main()
{
    SListTest1();
    return 0;
}