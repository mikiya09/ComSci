
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


int MinIndex(int values[], int startIndex, int endIndex)
// Post: Returns the index of the smallest value in
//       values[startIndex]..values[endIndex].
{
  int indexOfMin = startIndex;
  for (int index = startIndex + 1; index <= endIndex; index++)
    if (values[index] < values[indexOfMin])
      indexOfMin = index;
  return indexOfMin;
}


void SelectionSort(int values[], int numValues)
// Post: The elements in the array values are sorted by key.
{
    int endIndex = numValues-1;
    for (int current = 0; current < endIndex; current++) {
        Swap(values[current], values[MinIndex(values, current, endIndex)]);
        cout << "==== " << current+1 << " th iteration" << endl;
        printArray(values, 10);
    }
} 


int main()
{
    // int arr[] = {41, 7, 11, 22, 17, 3, 19, 5, 58, 13};
	int arr2[] = {26, 24, 3, 17, 25, 24, 13, 60, 47, 1};

    int n = sizeof(arr2) / sizeof(arr2[0]);
    SelectionSort(arr2, n);
    printArray(arr2, 10);


}

