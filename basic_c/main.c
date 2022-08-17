#include "utils/utils.h"

int main() {
    int sum = 0;
    for (int i = 0; i < 100; ++i) {
        int n = isPrimeNumber(i);
        if (1 == n) {
            sum++;
        }
    }
    printf("素数一共有%d个\n", sum);
    return 0;
}
