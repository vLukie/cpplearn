#include "Stack.h"

void STInit(ST *ps)
{
    assert(ps);
    ps->a = (STDateType *)malloc(sizeof(STDateType) * 4);
    if (ps->a == NULL)
    {
        perror("malloc fail");
        return;
    }

    ps->capacity = 4;
    ps->top = 0; // top=0是栈顶元素的下一个位置
}

void STDestroy(ST *ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->top = 0;
    ps->capacity = 0;
}

void STPush(ST *ps, STDateType x)
{
    assert(ps);
    if (ps->top == ps->capacity)
    {
        STDateType *tmp =
            (STDateType *)realloc(ps->a, ps->capacity * 2 * sizeof(STDateType));
        if (ps->a == NULL)
        {
            perror("malloc fail");
            return;
        }
        ps->a = tmp;
        ps->capacity *= 2;
    }
    ps->a[ps->top] = x;
    ps->top++;
}
void STPop(ST *ps)
{
    assert(ps);
    assert(!STEmpty(ps));
    ps->top--;
}
int STSize(ST *ps)
{
    assert(ps);
    return ps->top;
}
bool STEmpty(ST *ps)
{
    assert(ps);
    return ps->top == 0;
}
STDateType STTop(ST *ps)
{
    assert(ps);
    assert(!STEmpty(ps));
    return ps->a[ps->top - 1];
}
