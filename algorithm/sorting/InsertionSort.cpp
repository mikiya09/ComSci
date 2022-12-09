
#include <iostream>
#include <fstream>
using namespace std;


// A utility function to print an array of size n
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

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

        cout << "==== " << i <<  " th iteration ====" << endl;
        printArray(arr, n);
	}
}



int main() {
	int arr[] = {41, 7, 11, 22, 17, 3, 19, 5, 58, 13};
	int arr2[] = {26, 24, 3, 17, 25, 24, 13, 60, 47, 1};
	int n = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr2, n);
	// printArray(arr, n);

	return 0;
}
