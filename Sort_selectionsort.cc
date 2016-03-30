#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

void SelectionSort(int a[], int len); 

void SelectionSort(int a[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int min = a[i];                       // !!!  空间复杂度 min_value 
		int idx = i;						  // !!!  空间复杂度 min_value_idx 

		for (int j = i + 1; j < len; j++)    // select 
		{
			if (a[j] <= min)
			{
				min = a[j]; 
				idx = j; 
			}
		}
		 
		int tmp;               // swap 
		tmp = a[idx]; 
		a[idx] = a[i]; 
		a[i] = tmp; 
	}
}


void main()
{
	int a[] = { 38, 38, 20, 33, 9, 36, 2, 14, 3, 5, 42, 35, 16, 48, 2 };
	int len = sizeof(a) / sizeof(a[0]);
	SelectionSort(a, len);

	for (int i = 0; i < len; i++)
		cout << a[i] << ", ";
	cout << endl;
	system("pause");

}