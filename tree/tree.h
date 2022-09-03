//
// Created by muqing on 2022/8/18.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H

#endif //TREE_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 链式形式存储二叉树
typedef struct treeNode {
    struct treeNode *lChild;
    int value;
    struct treeNode *rChild;
} treeNode, *pTreeNode;

typedef struct treeBody {
    pTreeNode treeTop;
    int number;
} treeBody, *pTreeBody;

// 数组形式存储二叉树
typedef struct treeNodeArray {
    int lChild;
    int value;
    int rChild;
} treeNodeArray, *pTreeNodeArray;

typedef struct treeBodyArray {
    treeNodeArray treeArray[100];
    int number;
} treeBodyArray, *pTreeBodyArray;;

// 初始化基础二叉树
void initBaseTreeBody(pTreeBody);

// 二叉树是否为空
int isEmptyTree(pTreeBody);

// 二叉树的普通插入
int baseInsert(pTreeBody, int);

// 完全二叉树插入
void fullInsert(pTreeBody, int);

// 先序遍历
void preOrderTraverse(pTreeNode);

// 中序遍历
void midOrderTraverse(pTreeNode);

// 后序遍历
void postOrderTraverse(pTreeNode);
