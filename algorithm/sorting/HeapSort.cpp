

#include <iostream>
using namespace std;


void Swap(int& one, int& two)
{
    int temp;
    temp = one;
    one = two;
    two = temp;
}


void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void ReheapDown(int elements[], int root, int bottom)
// Post: Heap properties is restored 
{
    int maxChild;
    int rightChild;
    int leftChild;

    // calculation based on index 
    leftChild = root*2 + 1;
    rightChild = root*2 + 2;

    // all are index, bottom meaning the length
    if (leftChild <= bottom)
    {
        if (leftChild == bottom) {
            maxChild = leftChild;
        }
        else {
            if (elements[leftChild] <= elements[rightChild]) {   // elements is an array, data member
                maxChild = rightChild;
            }
            else {
                maxChild = leftChild;
            }
        }
        if (elements[root] < elements[maxChild]) {         
            Swap(elements[root], elements[maxChild]);  // maxChild is an index
            ReheapDown(elements, maxChild, bottom);              // recursion starts at position of maxChild, not the value
        }
    }
}


void HeapSort(int values[], int numValues)
// Pre:  Struct HeapType is available.
// Post: The elements in the array values are sorted by key.
{
  int index;

  // Convert the array of values into a heap.
  for (index = numValues/2 - 1; index >= 0; index--)
    ReheapDown(values, index, numValues-1);
    // cout << "==== " << index << " th iteration (heapify) ====" << endl;
    // printArray(values, numValues);

  // Sort the array.
  for (index = numValues-1; index >=1; index--)
  {
    Swap(values[0], values[index]);
    ReheapDown(values, 0, index-1);
    cout << "==== " << index << " th iteration (HeapSort) ====" << endl;
    printArray(values, numValues);
  }
}


int main()
{
    // int arr[] = {41, 7, 11, 22, 17, 3, 19, 5, 58, 13};
	int arr2[] = {26, 24, 3, 17, 25, 24, 13, 60, 47, 1};
    int n = sizeof(arr2) / sizeof(arr2[0]);

    HeapSort(arr2, n);

    // ReheapDown(arr, 4, 9);
    // printArray(arr, n);
    // ReheapDown(arr, 3, 9);
    // printArray(arr, n);
    // ReheapDown(arr, 2, 9);
    // printArray(arr, n);
    // ReheapDown(arr, 1, 9);
    // printArray(arr, n);
    // ReheapDown(arr, 0, 9);
    // printArray(arr, n);

    return 0;
}
