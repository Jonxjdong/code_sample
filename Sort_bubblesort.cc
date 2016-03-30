#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

void BubbleSort(int a[], int len); 

void BubbleSort(int a[], int len)
{
	int tmp; 
	for (int i = 1; i < len; i++)
	{
		for (int j = len - 1; j >= i; j--)  // [len-1 -> i]
		{
			if (a[j] < a[j - 1])
			{
				tmp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = tmp;
			}
		}
	}
}

void main()
{
	int a[] = { 38, 38, 20, 33, 9, 36, 2, 14, 3, 5, 42, 35, 16, 48, 2 };
	int len = sizeof(a) / sizeof(a[0]);
	BubbleSort(a, len);


	for (int i = 0; i < len; i++)
		cout << a[i] << ", ";
	cout << endl;
	system("pause");
}
