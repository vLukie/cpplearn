#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int STDateType;
typedef struct Stack
{
    int *a;
    int top;
    int capacity;

}ST;
void STInit(ST* ps);
void STDestroy(ST* ps);

void STPush(ST* ps,STDateType data);
void STPop(ST* ps);

STDateType STTop(ST* ps);
bool STEmpty(ST* ps);
int STSize(ST* ps);
