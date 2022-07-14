#include "linklist.h"

void init(pList list1)
{
	list1->pointHead = NULL;
	list1->pointTail = NULL;
	list1->number = 0;
};

void add(pList list1, int number)
{
	//    申请节点空间存放对应的值
	pNode node = (pNode)malloc(NODE);
	node->value = number;
	//    如果链表为空直接尾插法插入
	if (list1->pointHead == NULL)
	{
		list1->pointHead = node;
		list1->pointTail = node;
		node->pPrevious = NULL;
		node->pNext = NULL;
		// 链表不为空，需要进行判断
	}
	else
	{
		// 链表的头结点小于新插入的结点的值则直接替代头结点
		if (list1->pointHead->value >= node->value)
		{
			list1->pointHead->pPrevious = node;
			node->pNext = list1->pointHead;
			node->pPrevious = NULL;
			list1->pointHead = node;
			// 在链表的中间插入
		}
		else if (list1->pointHead->value < node->value && list1->pointTail->value > node->value)
		{
			pNode nodeTag = list1->pointHead;
			while (NULL != nodeTag)
			{
				if (node->value <= nodeTag->value)
				{
					node->pNext = nodeTag;
					node->pPrevious = nodeTag->pPrevious;
					nodeTag->pPrevious->pNext = node;
					nodeTag->pPrevious = node;
					nodeTag = NULL;
					break;
				}
				nodeTag = nodeTag->pNext;
			}
			free(nodeTag);
			// 如果链表的尾结点的值大于新插入的结点的值则直接尾插法
		}
		else
		{
			node->pPrevious = list1->pointTail;
			node->pNext = NULL;
			list1->pointTail->pNext = node;
			list1->pointTail = node;
		}
	}
	//    链表的节点个数加一
	list1->number++;
	//    free(node);
};

void traverse(pList list1)
{
	printf("\n");
	if (NULL == list1->pointHead)
	{
		puts("\t该链表为空！");
	}
	else
	{
		printf("\t一共有%d个结点\n", list1->number);
		pNode nodeTag = list1->pointHead;
		while (NULL != nodeTag)
		{
			printf("%5d", nodeTag->value);
			nodeTag = nodeTag->pNext;
		}
		printf("\n");
	}
	printf("\n");
};

void deleteValue(pList list1, int value)
{
	if (NULL == list1->pointHead)
	{
		puts("该链表为空！");
	}
	else
	{
		pNode nodeTag;
		// 删除头结点
		if (value == list1->pointHead->value)
		{
			nodeTag = list1->pointHead;
			list1->pointHead->pNext->pPrevious = NULL;
			list1->pointHead = list1->pointHead->pNext;
			// 删除尾结点
		}
		else if (value == list1->pointTail->value)
		{
			nodeTag = list1->pointTail;
			list1->pointTail->pPrevious->pNext = NULL;
			list1->pointTail = list1->pointTail->pPrevious;
			// 删除中间结点
		}
		else
		{
			nodeTag = list1->pointHead;
			while (NULL != nodeTag)
			{
				if (value == nodeTag->value)
				{
					nodeTag->pPrevious->pNext = nodeTag->pNext;
					nodeTag->pNext->pPrevious = nodeTag->pPrevious;
					list1->number--;
					break;
				}
				nodeTag = nodeTag->pNext;
			}
		}
		if (nodeTag == NULL)
		{
			puts("删除的值不在该链表之中");
			free(nodeTag);
		}
		else
		{
			free(nodeTag);
		}
		list1->number--;
	}
};

void deleteNumber(pList list1, int number)
{
	pNode nodeTag = NULL;
	if (NULL == list1->pointHead)
	{
		puts("该链表为空！");
	}
	else
	{
		if (number <= list1->number)
		{
			if (1 == number)
			{
				list1->pointHead = list1->pointHead->pNext;
				free(list1->pointHead->pPrevious);
				list1->pointHead->pPrevious = NULL;
			}
			else if (number == list1->number)
			{
				list1->pointTail = list1->pointTail->pPrevious;
				free(list1->pointTail->pNext);
				list1->pointTail->pNext = NULL;
			}
			else
			{
				nodeTag = list1->pointHead;
				for (int i = 1; i < number; ++i)
				{
					nodeTag = nodeTag->pNext;
				}
				nodeTag->pNext->pPrevious = nodeTag->pPrevious;
				nodeTag->pPrevious->pNext = nodeTag->pNext;
				free(nodeTag);
			}
			list1->number--;
		}
		else
		{
			puts("超出链表长度，不在链表之中。");
		}
	}
};

void updateValue(pList list1, int number, int value)
{
	pNode nodeTag = NULL;
	if (NULL == list1->pointHead)
	{
		puts("该链表为空！");
	}
	else
	{
		if (number <= list1->number)
		{
			if (1 == number)
			{
				list1->pointHead->value = value;
			}
			else if (number == list1->number)
			{
				list1->pointTail->value = value;
			}
			else
			{
				nodeTag = list1->pointHead;
				for (int i = 1; i < number; ++i)
				{
					nodeTag = nodeTag->pNext;
				}
				nodeTag->value = value;
				free(nodeTag);
			}
		}
		else
		{
			puts("超出链表长度，不在链表之中。");
		}
	}
};

// 通过值查找结点
void selectNodeWithValue(pList list1, int value)
{
	if (NULL == list1->pointHead)
	{
		puts("该链表为空，不存在任何结点！");
	}
	else
	{
		int tag = 1;
		pNode nodeTag = list1->pointHead;
		pNode nodeTag2 = NULL;
		while (NULL != nodeTag)
		{
			if (value != nodeTag->value)
			{
				nodeTag = nodeTag->pNext;
			}
			else
			{
				printf("该值存在与此链表之中，位于第%d个结点。\n", tag);
				nodeTag2 = nodeTag;
				nodeTag = NULL;
			}
			tag++;
		}
		if (NULL == nodeTag2)
		{
			printf("链表不为空且该值不存在与此链表之中。\n");
		}
		free(nodeTag);
	}
};

// 查找第几个结点
void selectNodeWithNumber(pList list1, int number)
{
	if (NULL == list1->pointHead)
	{
		puts("该链表为空，不存在任何结点！");
	}
	else
	{
		pNode nodeTag = list1->pointHead;
		if (number > list1->number)
		{
			printf("超出链表长度，不在链表之中。\n");
			nodeTag = NULL;
		}
		else if (number == 1)
		{
			printf("第%d个结点的值为：%d。\n", 1, list1->pointHead->value);
			nodeTag = NULL;
		}
		else if (number == list1->number)
		{
			printf("第%d个结点的值为：%d。\n", list1->number, list1->pointTail->value);
			nodeTag = NULL;
		}
		else
		{
			for (int i = 0; i < number; ++i)
			{
				nodeTag = nodeTag->pNext;
			}
			printf("第%d个结点的值为：%d。\n", number, nodeTag->pPrevious->value);
		}
		free(nodeTag);
	}
};