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

    return 0;
}
