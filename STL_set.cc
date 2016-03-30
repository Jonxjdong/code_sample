#include <set>
#include<iostream>
#include<string>
using namespace std; 

void main()
{
	// begin(), end() 
	// insert(t), insert(iter, t)
	// erase(t)
	// find(); count(); 



	set<int> myset; 
	myset.insert(3);
	myset.insert(1); 
	myset.insert(2);

	set<int>::iterator iter = myset.begin();
	myset.insert(iter, 200); 
	for (set<int>::iterator iter = myset.begin(); iter != myset.end(); iter++)
		cout << *iter << " " << endl; 

	myset.erase(2);
	for (set<int>::iterator iter = myset.begin(); iter != myset.end(); iter++)
		cout << *iter << " " << endl;

	cout << "Find element " << * myset.find(200) << endl;
	cout << "is Find element " << myset.count(200) << endl; 


	system("pause"); 
}
