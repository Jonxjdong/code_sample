#include <set>
#include <map>
#include<iostream>
#include<string>
using namespace std; 

void main()
{
	// begin(), end() 
	// insert(t), insert(iter, t)
	// erase(t)
	// find(); count(); 

	map<string, int> mymap; 
	mymap["the"] = 3; 
	mymap["what"] = 2; 
	mymap["may"] = 6; 
	mymap["aaa"] = 5; 

	mymap.insert(pair<string, int>("ccc", 7)); 
	mymap.insert(map<string, int>::value_type("bbb", 2)); 

	for (map<string, int>::iterator iter = mymap.begin(); iter != mymap.end(); iter++)
		cout << "key = " << iter->first << "; value = " << iter->second <<  endl;

	// delete
	cout << "delete " << endl; 
	mymap.erase("the"); 
	for (map<string, int>::iterator iter = mymap.begin(); iter != mymap.end(); iter++)
		cout << "key = " << iter->first << "; value = " << iter->second << endl;

	// find, count 
	map<string, int>::iterator iter = mymap.find("bbb");
	cout << "Find: " << iter->first << "; " << iter->second << endl; 
	cout << "Count: " << mymap.count("bbb") << endl; 


	system("pause"); 
}
