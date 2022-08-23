//
// Created by muqing on 2022/8/18.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H

#endif //TREE_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    struct treeNode *lChild;
    int value;
    struct treeNode *rChild;
} treeNode, *pTreeNode;

typedef struct treeBody {
    pTreeNode treeTop;
    int height;
} treeBody, *pTreeBody;

void initTreeNode(pTreeNode);

void initTreeBody(pTreeBody);
