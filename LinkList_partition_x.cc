#include <iostream>
#include <fstream>
#include <stack>
#include <hash_map>
#include <map>
#include <set>
using namespace std; 

// 
struct Node
{
	int data;
	Node *next;
};
class LinkList
{
	LinkList() { head = NULL }; 
public:
	Node* head; 
	void insertHead(int val); 
};

void partition(Node *head, int x)
{
	LinkList link_l; 
	LinkList link_g; 

	Node *ptr = head; 
	while (ptr != NULL)
	{
		if (ptr->data <= x)
			link_l.insertHead(ptr->data);
		else
			link_g.insertHead(ptr->data); 
		ptr = ptr->next; 
	}

	// merge; 
	Node *tail;
	tail = link_l.head; 
	while (tail != NULL)
		tail = tail->next; 
	tail = link_g.head; 
}

