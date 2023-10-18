#include "Heap.h"

int main()
{
    HP hp;
    HeapInit(&hp);
    HeapPush(&hp, 4);
    HeapPush(&hp, 18);
    HeapPush(&hp, 42);
    HeapPush(&hp, 12);
    HeapPush(&hp, 2);
    HeapPush(&hp, 3);
    HeapSort(hp.a, hp.size);
    
    for(int i = 0;i<hp.size;++i)
    
        printf("%d ", hp.a[i]);

    

    return 0;
}