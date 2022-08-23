//
// Created by muqing on 2022/8/18.
//

#include "tree.h"

void initTreeNode(pTreeNode node) {
    node->value = 0;
    node->lChild = NULL;
    node->rChild = NULL;
};

void initTreeBody(pTreeBody tree) {
    tree->height = 0;
    tree->treeTop = NULL;
};
