#include "tree.h"

int main() {

    pTreeNode node = (pTreeNode) malloc(sizeof(treeNode));
    initTreeNode(node);
    pTreeBody tree = (pTreeBody) malloc(sizeof(treeBody));
    initTreeBody(tree);

    node->value = 12;
    tree->treeTop = node;
    return 0;
}
