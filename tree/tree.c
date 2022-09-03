//
// Created by muqing on 2022/8/18.
//

#include "tree.h"

void initBaseTreeBody(pTreeBody tree) {
    tree->number = 0;
    tree->treeTop = NULL;
};

int isEmptyTree(pTreeBody pTree) {
    return pTree->number == 0 && pTree->treeTop == NULL ? 0 : 1;
}

int baseInsert(pTreeBody pTree, int v) {
    pTreeNode newNode = (pTreeNode) malloc(sizeof(treeNode));
    newNode->value = v;
    newNode->lChild = NULL;
    newNode->rChild = NULL;
    int emptyTree = isEmptyTree(pTree);
    if (0 == emptyTree) {
        pTree->treeTop = newNode;
        pTree->number++;
        return 1;
    } else {
        pTreeNode tagNode = pTree->treeTop;
        while (tagNode) {
            if (tagNode->lChild == NULL) {
                tagNode->lChild = newNode;
                pTree->number++;
                return 1;
            } else if (tagNode->rChild == NULL) {
                tagNode->rChild = newNode;
                pTree->number++;
                return 1;
            } else {
                tagNode = tagNode->lChild;
            }
        }
    }
}

void preOrderTraverse(pTreeNode node) {
    if (node) {
        printf("\t%d\t", node->value);
        preOrderTraverse(node->lChild);
        preOrderTraverse(node->rChild);
    }
}

void midOrderTraverse(pTreeNode node) {
    if (node) {
        preOrderTraverse(node->lChild);
        printf("\t%d\t", node->value);
        preOrderTraverse(node->rChild);
    }
}

void postOrderTraverse(pTreeNode node) {
    if (node) {
        preOrderTraverse(node->lChild);
        preOrderTraverse(node->rChild);
        printf("\t%d\t", node->value);
    }
}

void fullInsert(pTreeBody pTree, int v) {
    pTreeNode newNode = (pTreeNode) malloc(sizeof(treeNode));
    newNode->value = v;
    newNode->lChild = NULL;
    newNode->rChild = NULL;

    int emptyTree = isEmptyTree(pTree);
    if (0 == emptyTree) {
        pTree->treeTop = newNode;
        pTree->number++;
    } else {
        pTreeNode tagNode = pTree->treeTop;
        int tag = pTree->number + 1;
        int array[tag - 1];
        for (int i = 0; i < tag - 1; ++i) {
            array[i] = 0;
        }
        int n = 0;

        while (1 != tag) {
            int tap = tag % 2;
            if (tap == 0) {
                array[n] = 0;
                n++;
            } else {
                array[n] = 1;
                n++;
            }
            tag /= 2;
        }
        if (n != 1) {
            n -= 1;
            while (0 != n) {
                if (0 == array[n]) {
                    tagNode = tagNode->lChild;
                } else {
                    tagNode = tagNode->rChild;
                }
                n--;
            }
        }

        if (0 == (pTree->number + 1) % 2) {
            tagNode->lChild = newNode;
        } else {
            tagNode->rChild = newNode;
        }
        pTree->number++;
    }

}

void sortInsert(pTreeBody tree, int v) {
    pTreeNode newNode = (pTreeNode) malloc(sizeof(treeNode));
    newNode->value = v;
    newNode->lChild = NULL;
    newNode->rChild = NULL;

    int emptyTree = isEmptyTree(tree);
    if (0 == emptyTree) {
        tree->treeTop = newNode;
        tree->number++;
    } else {
        pTreeNode withValue = searchWithValue(tree, v);
        if (!withValue) {
            pTreeNode tag = tree->treeTop;
            pTreeNode parents = NULL;
            while (tag) {
                parents = tag;
                tag = (v < tag->value) ? tag->lChild : tag->rChild;
            }
            if (v < parents->value)
                parents->lChild = newNode;
            else
                parents->rChild = newNode;
        } else {
            printf("该树中已存在此值!!!\n");
        }
    }
}

pTreeNode searchWithValue(pTreeNode node, int value) {
    if (node) {
        if (node->value == value) {
            return node;
        } else if (node->lChild && node->lChild->value == value) {
            return node->lChild;
        } else if (node->rChild && node->rChild->value == value) {
            return node->rChild;
        } else {
            searchWithValue(node->lChild, value);
            searchWithValue(node->rChild, value);
        }
        return NULL;
    }
}
