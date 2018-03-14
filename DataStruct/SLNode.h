#pragma once
template <typename T>
struct Node
{
	T data;
	Node<T>* next;
};

template <typename T>
void ListInitia(Node<T>** head)//改变的是head本生，所有要使用指针的指针
{
	*head = (Node<T>*)malloc(sizeof(Node<T>*));
	if (*head == 0)
	{
		printf("%s", "List Initial failed!");
		return;
	}
	(*head)->next = 0;
}

template <typename T>
int ListLength(Node<T>* head)
{
	Node<T>* p = head;
	int size = 0;
	while (p->next != 0)
	{
		size++;
		p = p->next;
	}
	return size;
}

template <typename T>
bool ListInsert(Node<T>* head, int pos, T data)
{
	Node<T>* p = 0;
	Node<T>* q = 0;
	p = head;
	int prePos = -1;
	while (p->next != 0 && j < pos - 1)
	{
		p = p->next;
		prePos++;
	}
	if (prePos != pos - 1)
	{
		printf("%s", "Invalid insert position");
		return false;
	}
	Node<T>* newNode = (Node<T>*)malloc(sizeof(Node<T>*));
}