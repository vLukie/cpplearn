#include "List.h"

void Test1()
{
    LTNode *plist = LTInit();
    LTPushBack(plist, 1);
    LTPushBack(plist, 2);
    LTPushBack(plist, 3);
    LTPushBack(plist, 4);
    LTPushFront(plist, 0);
    LTPrint(plist);
    LTPopBack(plist);
    LTPrint(plist);
    LTPopFront(plist);
    LTPrint(plist);
    LTDestory(plist);
    
}
int main()
{
    Test1();
    return 0;
}