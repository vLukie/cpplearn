#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

bool isright(int *a, int n);
void Print(int *a, int n);
void InsertSort(int *a, int n);              // 插入排序
void ShellSort(int *a, int n);               // 希尔排序
void SelectSort(int *a, int n);              // 选择排序
void HeapSort(int *a, int n);                // 堆排序
void BubbleSort(int *a, int n);              // 冒泡排序
void QuickSort(int *a, int left, int right); // 快速排序
// test