#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

void MergeSeg(int a[], int first, int mid, int last, int tmp[]); 
void MergeSort(int a[], int first, int last, int tmp[]); 

// merge sort 
void MergeSeg(int a[], int first, int mid, int last, int tmp[])
{
	int i = first, j = mid + 1;   // [i, m], [j, n]
	int m = mid, n = last; 
	int k = 0;    // len of seg 

	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			tmp[k++] = a[i++];
		else
			tmp[k++] = a[j++];
	}
	while(i <= m)				// if [i, m] remains 
		tmp[k++] = a[i++]; 
	while (j <= n)				// if [j, n] reamins 
		tmp[k++] = a[j++]; 

	for (i = 0; i < k; i++)		// recover that seg (after order)
		a[first + i] = tmp[i]; 
}

void MergeSort(int a[], int first, int last, int tmp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		MergeSort(a, first, mid, tmp);
		MergeSort(a, mid + 1, last, tmp);
		MergeSeg(a, first, mid, last, tmp);
	}

}

void main()
{
	int a[] = { 38, 38, 20, 33, 9, 36, 2, 14, 3, 5, 42, 35, 16, 48, 2 };
	int len = sizeof(a) / sizeof(a[0]);
	int *tmp = new int[len]; 
	MergeSort(a, 0, len - 1, tmp); 
	delete[] tmp; 

	for (int i = 0; i < len; i++)
		cout << a[i] << ", "; 
	cout << endl; 

	system("pause"); 
}