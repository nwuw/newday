//
// Created by muqing on 2022/8/31.
//

#include "stack.h"

int initSeqStack(pSeqStack stack) {
    stack->stackSize = INIT_STACK_SIZE;
    stack->top = (pSeqStackElem) malloc(sizeof(seqStackElem) * INIT_STACK_SIZE);
    if (!stack->top)exit(-1);
    stack->base = stack->top;
    return 1;
}

int isEmptySeqStack(seqStack stack) {
    if (stack.top == stack.base) {
        return 0;
    } else {
        return 1;
    }
}

int pushSeqStack(pSeqStack stack, pSeqStackElem stackElem) {
    if (0 == isEmptySeqStack(*stack)) {
        // 空栈的进栈
        stack->base->value = stackElem->value;
        stack->top = stack->top + sizeof(seqStackElem);
        return 1;
    } else {
        // 非空栈的进栈
        if (stack->top == stack->base + (stack->stackSize * (sizeof(seqStackElem)))) {
            // 栈满,扩容栈
            pSeqStackElem elem = (pSeqStackElem) malloc(sizeof(seqStackElem) * (stack->stackSize + INCREASE_SIZE));
            for (int i = 0; i < stack->stackSize; ++i) {
                // 复制原栈元素
                elem[i * sizeof(seqStackElem)] = stack->base[i * sizeof(seqStackElem)];
            }
            free(stack->base);
            stack->base = elem;
            (stack->base + (sizeof(seqStackElem) * stack->stackSize))->value = stackElem->value;
            stack->top = stack->base + (sizeof(seqStackElem) * stack->stackSize) + sizeof(seqStackElem);
            stack->stackSize += INCREASE_SIZE;
            return 1;
        } else {
            // 栈不满
            stack->top->value = stackElem->value;
            stack->top = stack->top + sizeof(seqStackElem);
            return 1;
        }
    }
}

int destroySeqStack(pSeqStack stack) {
    free(stack->base);
    stack->top = NULL;
    stack->base = NULL;
    stack->stackSize = 0;
    return 1;
}

int clearSeqStack(pSeqStack stack) {
    destroySeqStack(stack);
    initSeqStack(stack);
    return 1;
}

int seqStackLength(seqStack stack) {
    return 0 == isEmptySeqStack(stack) ? 0 : (stack.top - stack.base) / sizeof(seqStackElem);
}

int getSeqStackTop(seqStack stack, pSeqStackElem elem) {
    if (0 != isEmptySeqStack(stack)) {
        elem->value = (stack.top - sizeof(seqStackElem))->value;
        return 1;
    } else {
        return 0;
    }
}

int traverseSeqStack(seqStack stack) {
    int length = seqStackLength(stack);

    if (length == 0) {
        printf("顺序栈为空！\n");
    } else {
        printf("栈：\t");
        for (int i = 1; i <= length; ++i) {
            printf("%d\t", stack.top[-i * sizeof(seqStackElem)].value);
        }
        printf("\n");
    }

}

int popSeqStack(pSeqStack stack, pSeqStackElem elem) {
    int length = seqStackLength(*stack);
    if (length == 0) {
        printf("顺序栈为空！\n");
        return 0;
    } else if (length == 1) {
        elem->value = stack->base->value;
        stack->base->value = NULL;
        stack->top = stack->base;
        return 1;
    } else {
        elem->value = (stack->top - sizeof(seqStackElem))->value;
        (stack->top - sizeof(seqStackElem))->value = NULL;
        stack->top = stack->top - sizeof(seqStackElem);
        return 1;
    }
}
