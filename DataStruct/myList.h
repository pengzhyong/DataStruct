#pragma once
#ifndef __MYLIST__
#define __MYLIST__

#include <iostream>
#include <malloc.h>

//声明
template <typename T> 
struct ListNode
{
	T data;
	ListNode<T>* pNext;
};

template <typename T>
bool listInitial(ListNode<T>** head);

template <typename T>
bool listInsert(ListNode<T>* head, int pos, T data);

template <typename T>
bool listDelete(ListNode<T>* head, int pos);

template <typename T>
unsigned int listLength(ListNode<T>* head);

template <typename T>
bool listDestroy(ListNode<T>* head);

template <typename T>
bool listPrint(const ListNode<T>* head);

//实现
template <typename T>
bool listInitial(ListNode<T>** head)
{
	*head = (ListNode<T>*)malloc(sizeof(ListNode<T>));
	if (*head == 0)
	{
		printf("%s", "malloc falied!");
		return false;
	}
	(*head)->data = 0;//如果链表元素是自定义类，则要求类具有拷贝初始化函数
	(*head)->pNext = 0;
}

template <typename T>
bool listInsert(ListNode<T>* head, int pos, T data)
{
	if (pos < 0 || pos > listLength(head))
	{
		printf("%s\n", "insert position invalid");
		return false;
	}
	ListNode<T>* new_node = (ListNode<T>*)malloc(sizeof(ListNode<T>));
	new_node->data = data;
	new_node->pNext = 0;
	int i = 0;
	ListNode<T>* pNode = head;//带头节点的链表，头节点指向的节点才是首元节点
	while (i++ <= pos - 1)
	{
		if (pNode->pNext == 0)
		{
			printf("%s", "position out of range");
			return false;
		}
		pNode = pNode->pNext;
	}
	new_node->pNext = pNode->pNext;
	pNode->pNext = new_node;
	
	return true;
}

template <typename T>
bool listDelete(ListNode<T>* head, int pos)
{
	if (head == 0)
	{
		printf("%S", "Invalid list");
		return false;
	}
	if (pos < 0 || pos >= listLength(head))
	{
		printf("%s", "position out of range");
		return false;
	}
	ListNode<T>* pNode = head;
	int cur_pos = 0;
	while (cur_pos++ < pos)
	{
		pNode = pNode->pNext;
	}
	ListNode<T>* toDelete = pNode->pNext;
	pNode->pNext = pNode->pNext->pNext;
	free(toDelete);
	return true;
}

template <typename T>
unsigned int listLength(ListNode<T>* head)
{
	unsigned int len = 0;
	ListNode<T>* p = head;
	while (p->pNext != 0)
	{
		len++;
		p = p->pNext;
	}
	return len;
}

template <typename T>
bool listDestroy(ListNode<T>* head)
{
	if (head == 0)
		return true;
	ListNode<T>* pNode = head;
	ListNode<T>* toDelete = 0;
	while (pNode->pNext != 0)
	{
		toDelete = pNode;
		pNode = pNode->pNext;
		free(toDelete);
	}
	head->pNext = 0;
	return true;
}

template <typename T>
bool listPrint(const ListNode<T>* head)
{
	if (head == 0 || head->pNext == 0)
	{
		printf("%s\n", "empty list");
		return false;
	}
	ListNode<T>* pNode = head->pNext;
	while (true)//pNode->pNext != 0)
	{
		//printf("%d ", pNode->data);
		std::cout << pNode->data << std::ends;
		pNode = pNode->pNext;
		if (pNode == 0)
			break;
	}
	printf("\n");
	return true;
}

#endif // !__MYLIST__

