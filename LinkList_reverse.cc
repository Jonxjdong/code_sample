#include <iostream>
#include <fstream>
#include <stack>
using namespace std; 

// 

struct Node
{
	int data;
	Node *next;
};

int GetLength(Node* head)
{
	Node* pNode = head;
	int nCount = 0;

	while (pNode != NULL)
	{
		nCount++;
		pNode = pNode->next;
	}
	return nCount;
}

void PrintListBack(Node* head)  //   复制到数组
{
	int n = GetLength(head);
	Node** p = new Node*[n + 1];
	p[n] = NULL;

	int i = 0;
	Node* pNode = head;
	while (i < n)
	{
		p[i] = pNode;
		pNode = pNode->next;
		i++;
	}

	for (i = n - 1; i >= 0; i--)
	{
		cout << p[i]->data << " ";
	}
}


void PrintListBack3(Node* head)				// 压入 stack
{
	stack<Node*> listStack;
	Node* pNode = head;
	while (pNode != NULL)
	{
		listStack.push(pNode);
		pNode = pNode->next;
	}
	int i = listStack.size();
	for (; i>0; i--)
	{
		Node* p = listStack.top();
		cout << p->next << endl;
		listStack.pop();
	}
}

void PrintListBack4(Node* head)
{
	if (head != NULL)
	{
		if (head->next != NULL)
		{
			PrintListBack4(head->next);
		}
		cout << head->data << endl;
	}
}
