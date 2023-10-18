#include "Sort.h"

int main()
{
    srand(time(0));
    const int N = 1000000;
    int *a1 = (int *)malloc(N * sizeof(int));
    int *a2 = (int *)malloc(N * sizeof(int));
    int *a3 = (int *)malloc(N * sizeof(int));
    int *a4 = (int *)malloc(N * sizeof(int));
    int *a5 = (int *)malloc(N * sizeof(int));
    int *a6 = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        a1[i] = rand();
        a2[i] = a1[i];
        a3[i] = a1[i];
        a4[i] = a1[i];
        a5[i] = a1[i];
        a6[i] = a1[i];
    }
    // int begin1 = clock();
    // InsertSort(a1, N);
    // int end1 = clock();
    // printf("InsertSort: %d\n", end1 - begin1);
    // printf("isright1: %d\n", isright(a1, N));

    // int begin2 = clock();
    // ShellSort(a2, N);
    // int end2 = clock();
    // printf("ShellSort: %d\n", end2 - begin2);
    // printf("isright2: %d\n", isright(a2, N));

    // int begin3 = clock();
    // SelectSort(a3, N);
    // int end3 = clock();
    // printf("SelectSort: %d\n", end3 - begin3);
    // printf("isright3: %d\n", isright(a3, N));

    // int begin4 = clock();
    // HeapSort(a4, N);
    // int end4 = clock();
    // printf("HeapSort: %d\n", end4 - begin4);
    // printf("isright4: %d\n", isright(a4, N));

    // int begin5 = clock();
    // BubbleSort(a5, N);
    // int end5 = clock();
    // printf("BubbleSort: %d\n", end5 - begin5);
    // printf("isright5: %d\n", isright(a5, N));

    int begin6 = clock();
    QuickSort(a6, 0, N - 1);
    int end6 = clock();

    printf("QuickSort: %d\n", end6 - begin6);
    printf("isright6: %d\n", isright(a6, N));

    free(a1);
    free(a2);
    free(a3);
    free(a4);
    free(a5);
    free(a6);

    return 0;
}