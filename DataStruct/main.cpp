#include <iostream> 
#include <malloc.h>
#include "myList.h"
#include "temp.h"
using namespace std;

int main()
{
	
	ListNode<char>* head = 0;// = (ListNode<int>*)malloc(sizeof(ListNode<int>*));
	
	listInitial(&head);//是对地址本身进行操作，而不是对地址指向的值进行操作，所以要把使用引用传递
	for (int i = 0; i <21; i++)
		listInsert<char>(head, i, 'a' + i);
	listPrint(head);
	listInsert<char>(head, 3, 'o');
	listPrint(head);
	cout << "list's length is " << listLength(head) << endl;

	listDelete(head, 1);

	listPrint(head);
	cout << "list's length is " << listLength(head) << endl;

	listDelete(head, 0);

	listPrint(head);
	cout << "list's length is " << listLength(head) << endl;

	listDestroy(head);
	listPrint(head);
	cout << "list's length is " << listLength(head) << endl;

	system("pause");
	return 0;
} 