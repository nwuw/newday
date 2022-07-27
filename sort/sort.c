#include "sort.h"

void quick_sort(int *arr, int num)
{
    printf("快速排序\n");

    for (int i = 0; i < num; i++)
    {
        for (int j = i; j < num; j++)
        {
            if (arr[i] > arr[j])
            {
                int tab = arr[j];
                arr[j] = arr[i];
                arr[i] = tab;
            }
        }
    }
};

void bubble_sort(int *arr, int num)
{
    printf("冒泡排序\n");

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i; j++)
        {
            if (j == num - i - 1)
            {
                break;
            }

            if (arr[j] > arr[j + 1])
            {
                int tab = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tab;
            }
        }
    }
};