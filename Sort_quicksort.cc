#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

// Quick sort 
// 1. choose pivot to sort 
// 2. divide-and-conquer
int AdjustPivot(int src[], int l, int r); 
int QuickSort(int src[], int l, int r); 


int AdjustPivot(int src[], int l, int r)
{
	int i = l, j = r;
	int pivot = src[i];   // pivot number 

	while (i < j)
	{
		while (i < j && src[j] >= pivot)
			j--; 
		if (i < j)
		{
			src[i] = src[j]; 
			i++; 
		}

		while (i < j && src[i] < pivot)
			i++; 
		if (i < j)
		{
			src[j] = src[i]; 
			j--; 
		}
	}

	src[i] = pivot;    //   put the pivot number back; 
	return i; 
}


int QuickSort(int src[], int l, int r)
{
	if (l < r)
	{
		int idx = AdjustPivot(src, l, r);
		QuickSort(src, l, idx - 1); 
		QuickSort(src, idx + 1, r); 
	}
	return 0; 
}


int main()
{
	int a[] = { 38, 38, 20, 33, 9, 36, 2, 14, 3, 5, 42, 35, 16, 48, 2 }; 
	int len = sizeof(a) / sizeof(a[0]); 
	QuickSort(a, 0, len-1); 

	for (int i = 0; i < len; i++)
		cout << a[i] << ", "; 
	cout << endl;
	system("pause"); 
	return 0; 
}