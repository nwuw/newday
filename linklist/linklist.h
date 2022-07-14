#define NODE sizeof(struct listNode)
#define LIST sizeof(struct listBody)

#include "utils.h"

typedef struct listNode
{
	struct listNode *pPrevious;
	int value;
	struct listNode *pNext;
} node, *pNode;

typedef struct listBody
{
	pNode pointHead;
	int number;
	pNode pointTail;
} list, *pList;

void init(pList);

void add(pList, int);

void traverse(pList);

void deleteValue(pList, int);

void deleteNumber(pList, int);

void updateValue(pList, int, int);

void selectNodeWithValue(pList, int);

void selectNodeWithNumber(pList, int);