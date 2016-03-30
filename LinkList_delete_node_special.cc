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

// only access to that node 
void deleteNode(Node *node)
{
	node->data = node->next->data;   // n+1的data copy 到n
	node->next = node->next->next;   // n->next  to   n+2  
}


