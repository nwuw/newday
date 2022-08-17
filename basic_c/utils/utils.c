//
// Created by muqing on 2022/8/17.
//
#include "utils.h"

int isPrimeNumber(int number) {
    int tag = 0;
    if (1 == number || 0 == number) {
        printf(" `0`和`1` 不是素数,也不是合数!!!\n");
        return -1;
    }
    for (int i = 2; i < number; ++i) {
        if (number % i == 0) {
            tag++;
        }
    }
    if (0 == tag) {
        printf("%d是素数!!!\n", number);
        return 1;
    } else {
        printf("%d不是素数!!!\n", number);
        return 0;
    }
}
