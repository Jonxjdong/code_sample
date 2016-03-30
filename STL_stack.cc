#include <stack>
#include<iostream>
#include<string>
using namespace std; 

void main()
{
	// top(); size()
	// push(t); pop();  

	stack<string> mystk; 
	mystk.push("aaa"); 
	mystk.push("bbb"); 
	mystk.push("cc"); 
	cout << "top element: " << mystk.top() << endl; 
	 

	system("pause"); 
}
