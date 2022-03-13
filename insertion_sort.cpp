// insertion sort with C++
//

#include <iostream>
#include <fstream>
using namespace std;

// Function to sort an array insertion sort
void insertionSort(int arr[], int n) {
	
	int i, key, j;
	for (i=1; i<n; i++) 
	{
		key = arr[i];
		j = i - 1;

		// move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
		while (j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}


int main() {
	int arr[] = {12, 98, 12345, 34, 1, 77, 12/5};
	int n = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, n);
	printArray(arr, n);

	return 0;
}


