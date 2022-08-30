#include "utils/utils.h"

int main() {
    printf("hello world!\n");
//    int sum = 0;
//    for (int i = 0; i < 100; ++i) {
//        int n = isPrimeNumber(i);
//        if (1 == n) {
//            sum++;
//        }
//    }
//    printf("素数一共有%d个\n", sum);


    outputFileContent("/Users/muqing/Downloads/codes/other/newday/basic_c/demo.txt", "r+");
    int a[] = {1, 3};
    int * p = a;
    char t = 'A';
    short n = 0;

    printf("%lu\n", sizeof(1));
    printf("%lu\n", sizeof(n));
    printf("%lu\n", sizeof(1.1));
    printf("%lu\n", sizeof(t));
    printf("%lu\n", sizeof(p));
    printf("%lu\n", p[0]);
    printf("%lu\n", p[1]);


    return 0;
}
