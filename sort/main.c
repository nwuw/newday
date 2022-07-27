#include "utils.h"
#include "sort.h"

int main()
{
    printf("!!!sort!!!\n");

    int a[10];
    int len = (int)sizeof(a) / sizeof(*a);

    getRand(a, len);
    printf("原数组\n");
    traverseArrays(a, len);
    bubble_sort(a, len);
    traverseArrays(a, len);

    return 0;
}