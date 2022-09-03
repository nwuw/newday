#include "tree.h"
#include "utils.h"

int main() {

    int arr[20];
    getRandArrays(arr, 20);
    traverseArrays(arr, 20);


    pTreeBody tree = (pTreeBody) malloc(sizeof(treeBody));
    initBaseTreeBody(tree);
    int emptyTree = isEmptyTree(tree);

    for (int i = 0; i < 20; ++i) {
//        baseInsert(tree, arr[i]);
        fullInsert(tree, arr[i]);
    }
    printf("是否为空：%d\n", emptyTree);

    preOrderTraverse(tree->treeTop);
    printf("\n");
    midOrderTraverse(tree->treeTop);
    printf("\n");
    postOrderTraverse(tree->treeTop);
    printf("\n");

    pTreeNode pNode = searchWithValue(tree->treeTop, 99);
    if (pNode) {
        printf("%d\n", pNode->value);
    } else {
        printf("不存在该值！！！\n");
    }

    printf("!!!二叉排序树!!!\n");
    int arr1[6] = {42, 89, 54, 32, 27, 76};
    traverseArrays(arr1, 6);
    pTreeBody sortTree = (pTreeBody) malloc(sizeof(treeBody));
    initBaseTreeBody(sortTree);
    for (int i = 0; i < 6; ++i) {
        sortInsert(sortTree, arr1[i]);
    }
    preOrderTraverse(sortTree->treeTop);
    printf("\n");
    midOrderTraverse(sortTree->treeTop);
    printf("\n");


    return 0;
}
