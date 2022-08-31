#include "stack.h"
#include "utils.h"

int main() {
    printf("!!!SeqStack!!!\n");

    int a[INIT_STACK_SIZE + 3];
    getRandToArrays(a, INIT_STACK_SIZE + 3);
    printf("数组：\t");
    traverseArrays(a, INIT_STACK_SIZE + 3);

    pSeqStack pSeqStack1 = (pSeqStack) malloc(sizeof(seqStack));
    int i = initSeqStack(pSeqStack1);
    if (1 == i)printf("顺序栈初始化成功！\n");
    int i1 = isEmptySeqStack(*pSeqStack1);
    if (1 == i1) {
        printf("顺序栈不为空！\n");
    } else {
        printf("顺序栈为空！\n");
    }

    for (int j = 0; j < INIT_STACK_SIZE + 3; ++j) {
        pSeqStackElem tag = (pSeqStackElem) malloc(sizeof(seqStackElem));
        tag->value = a[j];
        pushSeqStack(pSeqStack1, tag);
    }
    int i2 = isEmptySeqStack(*pSeqStack1);
    if (1 == i2) {
        printf("顺序栈不为空！\n");
    } else {
        printf("顺序栈为空！\n");
    }

    int length = seqStackLength(*pSeqStack1);
    printf("栈长：\t%d\n", length);

    pSeqStackElem tag2 = (pSeqStackElem) malloc(sizeof(seqStackElem));
    getSeqStackTop(*pSeqStack1, tag2);
    if (a[17] == tag2->value) {
        printf("获取栈顶元素成功！\n");
    }
    for (int j = 0; j < 18; ++j) {
        traverseSeqStack(*pSeqStack1);
        pSeqStackElem tag3 = (pSeqStackElem) malloc(sizeof(seqStackElem));
        popSeqStack(pSeqStack1, tag3);
    }
    clearSeqStack(pSeqStack1);
    int num = 35;
    while (num != 0) {
        int tag = num % 2;
        pSeqStackElem tag4 = (pSeqStackElem) malloc(sizeof(seqStackElem));
        tag4->value = tag;
        pushSeqStack(pSeqStack1, tag4);
        num /= 2;
    }
    traverseSeqStack(*pSeqStack1);
    clearSeqStack(pSeqStack1);
    destroySeqStack(pSeqStack1);
    return 0;
}
