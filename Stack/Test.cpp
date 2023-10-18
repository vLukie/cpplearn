#pragma once
#include"Stack.h"

void Test1()
{
    ST st;
    STInit(&st);
    STPush(&st, 1);
    STPush(&st, 2);
    STPush(&st, 3);
    STPush(&st, 4);
    STPush(&st, 5);
    while (!STEmpty(&st))
    {
       printf("%d ",STTop(&st));   
       STPop(&st);
        
    }
    



    STDestroy(&st);

}

int main()
{
    Test1();
    return 0;
}