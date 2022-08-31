//
// Created by muqing on 2022/8/31.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#endif //STACK_STACK_H

#include <stdlib.h>
#include <stdio.h>

#define INIT_STACK_SIZE 15
#define INCREASE_SIZE 5

// 顺序存储的栈中每个元素的结构体
typedef struct seqStackElem {
    int value;
} seqStackElem, *pSeqStackElem;

// 顺序存储的栈的结构体
typedef struct seqStack {
    pSeqStackElem top;
    pSeqStackElem base;
    int stackSize;
} seqStack, *pSeqStack;

// 顺序存储的栈的基本操作
int initSeqStack(pSeqStack);

int destroySeqStack(pSeqStack);

int clearSeqStack(pSeqStack);

int isEmptySeqStack(seqStack);

int seqStackLength(seqStack);

int getSeqStackTop(seqStack, pSeqStackElem);

int pushSeqStack(pSeqStack, pSeqStackElem);

int popSeqStack(pSeqStack, pSeqStackElem);

int traverseSeqStack(seqStack);



