#include <algorithm>
#include<iostream>
#include<vector>
using namespace std; 

bool isAnagram1(string s, string t) {
	if (s == "" || t == "") return false;
	if (s.length() != t.length()) return false;

	sort(&s[0], &s[0] + s.length());
	sort(&t[0], &t[0] + t.length());
	if (s == t) return true;
	else return false;
}


void main()
{
	int a[] = { 32,71,12,45,26,80,53,33 };
	vector<int> myvec(a, a + 8);

	sort(a, a + 8); 
	sort(myvec.begin(), myvec.end());

	string s = "aaabbb";
	string t = "ababab";
	cout << isAnagram1(s, t) << endl;

	system("pause"); 
}