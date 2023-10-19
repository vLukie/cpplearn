#include "Sort.h"
#include "Stack.h"
void Swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
bool isright(int *a, int N)
{
    for (int i = 0; i < N - 1; i++)
        if (a[i] > a[i + 1])
            return false;
    return true;
}
int GetMidNumi(int *a, int left, int right)
{
    int mid = (left + right) / 2;
    if (a[left] < a[mid])
        if (a[mid] < a[right])
            return mid;
        else if (a[left] > a[right])
            return left;
        else
            return right;
    else
    {
        if (a[mid] > a[right])
            return mid;
        else if (a[left] > a[right])
            return right;
        else
            return left;
    }
}
void Print(int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void AdjustHeap(int *a, int n, int parent)
{
    int child = 2 * parent + 1;
    while (child < n)
    {
        if (child + 1 < n && a[child] < a[child + 1])
            child++;

        if (a[parent] < a[child])
        {
            Swap(&a[parent], &a[child]);
            parent = child;
            child = 2 * parent + 1;
        }
        else
            break;
    }
}
void InsertSort(int *a, int n) // 插入排序
{
    for (int i = 1; i < n; i++)
    {
        int t = a[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (t < a[j])
            {
                a[j + 1] = a[j];
                a[j] = t;
            }
        }
    }
}

void ShellSort(int *a, int n) // 希尔排序
{
    int gap = n;
    while (gap > 1)
    {
        gap = gap / 3 + 1;
        for (int i = 0; i < n - gap; i++)
        {

            int end = i;
            int tmp = a[i + gap];
            while (end >= 0)
            {
                if (tmp < a[end])
                {
                    a[end + gap] = a[end];
                    end -= gap;
                }
                else
                    break;
            }
            a[end + gap] = tmp;
        }
    }
}
void SelectSort(int *a, int n)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        int min = left, max = left;
        for (int i = left + 1; i <= right; i++)
        {
            if (a[i] < a[min])
                min = i;
            if (a[i] > a[max])
                max = i;
        }
        Swap(&a[left], &a[min]);
        if (left == max)
            max = min;
        Swap(&a[right], &a[max]);
        left++;
        right--;
    }
}
void HeapSort(int *a, int n) // 堆排序,向下调整
{
    for (int i = (n - 1 - 1) / 2; i >= 0; i--)
        AdjustHeap(a, n, i);
    int end = n - 1;
    while (end > 0)
    {
        Swap(&a[0], &a[end]);
        AdjustHeap(a, end, 0);
        --end;
    }
}
void BubbleSort(int *a, int n) // 冒泡排序
{
    for (int i = 0; i < n; i++)
    {
        bool exchange = false;
        for (int j = 1; j < n - i; j++)
            if (a[j - 1] > a[j])
            {
                Swap(&a[j - 1], &a[j]);
                exchange = true;
            }
        if (exchange == false)
            break;
    }
}
// // 6 1 2 5 4 3 8 7 10 8
// void QuickSort(int *a, int left, int right) // 快速排序
// {
//     if (left >= right)
//         return;
//     int begin = left, end = right;
//     // int randi = rand() % (right - left) + left;
//     // Swap(&a[randi], &a[left]);
//     int midi = GetMidNumi(a, left, right);
//     if (midi != left)
//         Swap(&a[left], &a[midi]);
//     int keyi = left;
//     while (left < right)
//     {
//         while (left < right && a[right] >= a[keyi])
//             right--;

//         while (left < right && a[left] <= a[keyi])
//             left++;

//         Swap(&a[left], &a[right]);
//     }
//     Swap(&a[keyi], &a[left]);
//     keyi = left;
//     QuickSort(a, begin, keyi - 1);
//     QuickSort(a, keyi + 1, end);
// }

int PartSort1(int *a, int left, int right) // 快速排序 Hoera
{
    int midi = GetMidNumi(a, left, right);
    if (midi != left)
        Swap(&a[left], &a[midi]);
    int keyi = left;
    while (left < right)
    {
        while (left < right && a[right] >= a[keyi])
            right--;

        while (left < right && a[left] <= a[keyi])
            left++;

        Swap(&a[left], &a[right]);
    }
    Swap(&a[keyi], &a[left]);
    keyi = left;
    return keyi;
}

int PartSort2(int *a, int left, int right) // 快速排序 挖坑法
{
    int midi = GetMidNumi(a, left, right);
    if (midi != left)
        Swap(&a[left], &a[midi]);

    int key = a[left];
    int hole = left;
    while (left < right)
    {
        while (left < right && a[right] >= key)
            right--;
        a[hole] = a[right];
        hole = right;

        while (left < right && a[left] <= key)
            left++;
        a[hole] = a[left];
        hole = left;
    }
    a[hole] = key;
    return hole;
}
int PartSort3(int *a, int left, int right) // 快速排序 前后指针法
{
    int midi = GetMidNumi(a, left, right);
    if (midi != left)
        Swap(&a[left], &a[midi]);
    int cur = left + 1, prev = left, keyi = left;

    while (cur <= right)
    {
        if (a[cur] < a[keyi] && ++prev != cur)
            Swap(&a[prev], &a[cur]);
        ++cur;
    }
    Swap(&a[prev], &a[keyi]);
    keyi = prev;
    return keyi;
}
// void QuickSort(int *a, int left, int right) // 快速排序 挖坑法
// {
//     if (left >= right)
//         return;

//     // 小区间优化
//     if ((right - left + 1) > 10)
//     {
//         int keyi = PartSort3(a, left, right);
//         QuickSort(a, left, keyi - 1);
//         QuickSort(a, keyi + 1, right);
//     }
//     else
//         InsertSort(a + left, right - left + 1);
// }
void QuickSort(int *a, int left, int right) // 快速排序 非递归
{
    ST st;
    STInit(&st);
    STPush(&st, right);
    STPush(&st, left);

    while (!STEmpty(&st))
    {
        int begin = STTop(&st);
        STPop(&st);
        int end = STTop(&st);
        STPop(&st);

        int keyi = PartSort3(a, begin, end);
        if (keyi + 1 < end)
        {
            STPush(&st, end);
            STPush(&st, keyi + 1);
        }
        if (begin < end)
        {
            STPush(&st, keyi - 1);
            STPush(&st, begin);
        }
    }

    STDestroy(&st);
}

void MergeSort(int *a, int n) // 归并排序 原始版本
{


}