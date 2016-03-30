#include<iostream>
#include<string>
using namespace std; 

bool isSubstring(string s1, string s2) {
	if (s1.find(s2) != string::npos) 
		return true;    // string::npos = -1  no found
	else 
		return false;
}

