#include "Heap.h"

void HeapInit(HP *php)
{
    assert(php);
    php->a = (HPDataType *)malloc(sizeof(HPDataType) * 4);
    if (php->a == NULL)
    {
        perror("malloc fail");
        return;
    }
    php->size = 0;
    php->capacity = 4;
}
void HeapDestory(HP *php);
void Swap(HPDataType *a, HPDataType *b)
{
    HPDataType t;
    t = *a;
    *a = *b;
    *b = t;
}
void AdjustUp(HPDataType *a, int child)
{
    int parent = (child - 1) / 2;
    while (child >= 0)
    {
        if (a[child] > a[parent])
        {
            Swap(&a[child], &a[parent]);
            child = parent;
            parent = (child - 1) / 2;
        }
        else
            break;
    }
}
/*parent=(child-1)/2;
leftchild=parent*2+1;
leftchild=parent*2+2;*/
void AdjustDown(HPDataType *a, int n, int parent)
{
    int child = parent * 2 + 1;
    while (child < n)
    {
        if (child + 1 < n && a[child + 1] > a[child]) // 需要选出更大的孩子
            ++child;
        if (a[child] > a[parent])
        {
            Swap(&a[child], &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
            break;
    }
}
void HeapPush(HP *php, HPDataType x)
{
    assert(php);
    if (php->size == php->capacity)
    {
        HPDataType *tmp =
            (HPDataType *)realloc(php->a, php->capacity * 2 * sizeof(HPDataType));
        if (tmp == NULL)
        {
            perror("realloc fail");
            return;
        }
        php->a = tmp;
        php->capacity *= 2;
    }
    php->a[php->size] = x;
    php->size++;
    AdjustUp(php->a, php->size - 1);
}
void HeapPop(HP *php)
{
    assert(php);
    assert(!HeapEmpty(php));

    Swap(&php->a[0], &php->a[php->size - 1]);
    php->size--;
    AdjustDown(php->a, php->size, 0);
}
HPDataType HeapTop(HP *php)
{
    assert(php);
    return php->a[0];
}
bool HeapEmpty(HP *php)
{
    assert(php);
    return php->size == 0;
}
int HeapSize(HP *php)
{
    assert(php);
    return php->size;
}
void HeapSort(HPDataType *a, int n)
{
    for (int i = 0; i < n; i++)
        AdjustUp(a, i);

    int end = n - 1;
    while (end > 0)
    {
        Swap(&a[0], &a[end]);
        AdjustDown(a, end, 0);
        --end;
    }
}