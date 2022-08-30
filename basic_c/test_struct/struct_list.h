//
// Created by muqing on 2022/8/30.
//

#ifndef BASIC_C_STRUCT_LIST_H
#define BASIC_C_STRUCT_LIST_H

#endif //BASIC_C_STRUCT_LIST_H

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
#define ElemTYpe int

typedef struct staticOrderTable {
    ElemTYpe data[MaxSize];
    int length;
} sot, *psot;

typedef struct dynamicOrderTable {
    ElemTYpe *date;
    int length;
} dot, *pdot;
