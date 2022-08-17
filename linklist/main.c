#include "linklist.h"
#include "utils.h"

int main() {
    int numbers[20];
    getRand(numbers, sizeof(numbers) / sizeof(numbers[0]));
    traverseArrays(numbers, sizeof(numbers) / sizeof(numbers[0]));
    pList list = (pList) malloc(LIST);
    init(list);
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); ++i) {
        add(list, numbers[i]);
    }
    traverse(list);
    deleteNumber(list, 5);
    // 测试测试
    traverse(list);

    selectNodeWithValue(list, 98);
    selectNodeWithValue(list, 89);
    selectNodeWithValue(list, 18);
    selectNodeWithValue(list, 78);
    return 0;
}