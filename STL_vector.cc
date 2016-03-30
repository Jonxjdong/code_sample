#include<vector>
#include<iostream>
using namespace std; 

void main()
{
	// size(); 
	// begin(); end()
	// push_back(t),  push_front(t),  insert(p, t); 
	// pop_back(), pop_back(), erase(p) 





	// build, insert 
	vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i); 

	vector<int>::iterator iter = vec.begin();
	vec.insert(iter, 100);

	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter << " "; 
	cout << endl; 


	// delete
	int del = 5; 
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); )
	{
		if (*iter == del)
			iter = vec.erase(iter);                          // !!! 
		else
			iter++; 
	}

	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter << " ";
	cout << endl;




	system("pause"); 
}
