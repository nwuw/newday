#include "sort.h"

void bubble_sort(int *arr, int num)
{
    printf("冒泡排序\n");

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