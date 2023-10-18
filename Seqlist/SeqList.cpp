#include "SeqList.h"

void SLInit(SL *ps)
{
    if (ps == nullptr)
        return;

    ps->a = (SLDataType *)malloc(sizeof(SLDataType) * INIT_CAPACITY);
    if (ps->a == NULL)
    {
        perror("malloc fail");
        return;
    }
    ps->size = 0;
    ps->capacity = INIT_CAPACITY;
}

void SLDestroy(SL *ps)
{
    free(ps->a);
    ps->a = NULL;
    ps->size = ps->capacity = 0;
}
void SLPrint(SL *ps)
{
    for (int i = 0; i < ps->size; i++)
        printf("%d ", ps->a[i]);
    printf("\n");
}
void SLCheckCapacity(SL *ps)
{
    if (ps == nullptr)
        return;
    if (ps->size == ps->capacity)
    {
        SLDataType *tmp = (SLDataType *)realloc(ps->a, sizeof(SLDataType) * ps->capacity * 2);
        if (tmp == NULL)
        {
            perror("realloc fail");
            return;
        }
        ps->a = tmp;
        ps->capacity *= 2;
    }
}

void SLPushBack(SL *ps, SLDataType x)
{
    // if (ps == nullptr)
    //     return;
    // // 扩容
    // SLCheckCapacity(ps);
    // ps->a[ps->size++] = x;
    SLInsert(ps, ps->size, x);
}

void SLPopBack(SL *ps)
{
    // if (ps->size == 0 || ps == nullptr)
    //     return;

    // // ps->a[ps->size - 1] = 0;
    // ps->size--;
    SLErase(ps, ps->size - 1);
}
void SLPushFront(SL *ps, SLDataType x)
{
    // if (ps == nullptr)
    //     return;
    // SLCheckCapacity(ps);

    // int end = ps->size - 1;
    // while (end >= 0)
    // {
    //     ps->a[end + 1] = ps->a[end];
    //     --end;
    // }
    // ps->a[0] = x;
    // ps->size++;
    SLInsert(ps, 0, x);
}
void SLPopFront(SL *ps)
{
    // if (ps == nullptr || ps->size <= 0)
    //     return;
    // int begin = 1;
    // while (begin < ps->size)
    // {
    //     ps->a[begin - 1] = ps->a[begin];
    //     ++begin;
    // }
    // ps->size--;
    SLErase(ps, 0);
}
void SLInsert(SL *ps, int pos, SLDataType x)
{
    if (ps == nullptr || pos < 0 || pos > ps->size)
        return;
    SLCheckCapacity(ps);
    int end = ps->size - 1;
    while (end >= pos)
    {
        ps->a[end + 1] = ps->a[end];
        end--;
    }
    ps->a[pos] = x;
    ps->size++;
}
void SLErase(SL *ps, int pos)
{
    if (ps == nullptr || pos < 0 || pos > ps->size)
        return;
    SLCheckCapacity(ps);
    int begin = pos + 1;
    while (begin < ps->size)
    {
        ps->a[begin - 1] = ps->a[begin];
        ++begin;
    }
    ps->size--;
}
int SLFind(SL *ps, SLDataType x)
{
    
    for (int i = 0; i < ps->size; i++)
        if (ps->a[i] == x)
            return i;
    return -1;
}