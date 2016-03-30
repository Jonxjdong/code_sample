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

bool hash[100];
void deleteDuplicate(Node *head)
{
	if (head == NULL) return;
	Node *p = head, *q = head->next;
	hash[head->data] = true;
	while (q) {
		if (hash[q->data]) {
			Node *t = q;
			p->next = q->next;
			q = p->next;
			delete t;
		}
		else {
			hash[q->data] = true;
			p = q; q = q->next;
		}
	}
}


// no buffers   // O(n^2)
void removedulicate1(Node *head){
    if(head==NULL) return;
    
	node *p, *q, *c=head;
    while(c){
        p=c; q=c->next;
        int d = c->data;
        while(q){
            if(q->data==d){
                node *t = q;
                p->next = q->next;
                q = p->next;
                delete t;
            }
            else{
                p = q; q = q->next;
            }
        }
        c = c->next;
    }
}