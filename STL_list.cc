#include<list>
#include<iostream>
using namespace std; 

void main()
{
	// assign(n, val)
	// begin(); end()
	// push_back(t),  push_front(t),  insert(p, t); 
	// pop_back(), pop_back(), erase(p)


	// build, insert
	list<int> mylist; 
	for (int i = 0; i < 10; i++)
		mylist.push_back(i); 
	
	list<int>::iterator iter = mylist.begin();
	mylist.insert(iter, 100);
	cout << "list size: " << mylist.size() <<endl;

	for (list<int>::iterator iter = mylist.begin(); iter != mylist.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	// delete
	int del = 5;
	for (list<int>::iterator iter = mylist.begin(); iter != mylist.end(); )
	{
		if (*iter == del)
			iter = mylist.erase(iter);                          // !!! 
		else
			iter++;
	}

	for (list<int>::iterator iter = mylist.begin(); iter != mylist.end(); iter++)
		cout << *iter << " ";
	cout << endl;


	system("pause"); 
}