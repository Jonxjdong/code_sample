#include <string>
#include<iostream>
using namespace std; 

void swap(char &a, char &b) {
	a = a^b;
	b = a^b;
	a = a^b;
}

void reverse2(char *s) {
	int n = strlen(s);
	for (int i = 0; i<n / 2; ++i)       // 0<->(n-1), 1<->(n-2), ...
		swap(s[i], s[n - i - 1]);
}

void reverse1(char *s) {
	if (!s) return;
	char *p = s, *q = s;
	while (*q) ++q;
	--q;
	while (p < q)
		swap(*p++, *q--);
}

int main() {
	char s[] = "1234567890";
	reverse1(s);
	cout << s << endl;
	return 0;
}

