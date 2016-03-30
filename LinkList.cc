#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

// LinkList

struct Node
{
	int data; 
	Node *next; 
};

class List
{	
public: 
	Node *head; 
	List() { head = NULL; }; 
	void printList();							// 遍历
	void insertHead(int data); 
	void insertBack(int data); 
	void insertList(int data_pos, int data);      // 插入
	void deleteList(int aData);		            // 删除

	Node *back; 
	void reverseNoRecur(); 
	void reverseRecur(); 
};

void List::insertHead(int data)
{
	Node *ptr = new Node(); 
	ptr->next = head; 
	ptr->data = data; 
	head = ptr;     // !!!
}

void List::insertBack(int data)
{
	Node *ptr = new Node() ;
    ptr->data = val ;
    ptr->next = NULL ;
    if ( head == NULL )
        head = back = ptr ;
    else {
        back->next = ptr ;
        back = ptr ;        // !!! back   value 
    }
}

void List::insertList(int aData, int bData)  
{
	Node *p; 
	Node *pre;			//p:current ，q: previous
	Node *ptr = new Node();  
	
	ptr->data = bData;   //设b为此结点
	
	p = head;
	if (head == NULL)			//condition 1: 空表
	{
		head = ptr;
		ptr->next = NULL;
	}
	else
		if (p->data == aData)   //condition 2: aData 为第1个点
		{
			ptr->next = p;
			head = ptr;
		}
		else
		{
			while (p->data != aData && p->next != NULL)  // condition 3: aData 在链表中
			{
				pre = p;
				p = p->next;
			}
			if (p->data == aData)     
			{
				pre->next = ptr;
				ptr->next = p;
			}
			else							// condition 4: no found 
			{
				p->next = ptr;
				ptr->next = NULL;
			}
		}
}

void List::printList()
{
	Node *current = head;
	while (current != NULL)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

void List::deleteList(int data)
{
	Node*p, *q;            //p -> data, q -> previous
	p = head;

	if (p == NULL)			// condition 1: 空表
		return;
	if (p->data == data)	// condition 2: 第1点
	{
		head = p->next;
		delete p;
	}
	else
	{
		while (p->data != data && p->next != NULL)  // condition 3:  search 
		{
			q = p;
			p = p->next;
		}
		if (p->data == data)    
		{
			q->next = p->next;
			delete p;
		}
	}
}

void List::reverseRecur()
{

}



void main()
{
	int a[] = { 4, 2, 1, 3, 5 }; 
	int len = sizeof(a) / sizeof(a[0]);

	List mylist; 
	for (int i = 0; i < len; i++)		// 创建
		mylist.insertHead(a[i]);		
	mylist.printList();					// 遍历（打印）

	mylist.insertList(1, 100);			// 插入 

	system("pause"); 

}; 