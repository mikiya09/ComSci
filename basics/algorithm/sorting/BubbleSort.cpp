

#include <iostream>
using namespace std;



void Swap(int& one, int& two)
{
    int temp;
    temp = one;
    one = two;
    two = temp;
}


void display(int arr[], int n)
// display array 
{
    for (int i=0; i<n; i++) {
        cout << arr[i] << "\n";
    }
    cout << endl;
}

void BubbleUp(int values[], int startIndex, int endIndex)
// Post: Adjacent pairs that are out of order have been 
//       switched between values[startIndex]..values[endIndex]
//       beginning at values[endIndex].
{
  for (int index = endIndex; index > startIndex; index--)
    if (values[index] < values[index-1])
      Swap(values[index], values[index-1]);
}

void BubbleSort(int values[], int numValues)
// Post: The elements in the array values are sorted by key.
{
  int current = 0;

  while (current < numValues - 1)
  {
    BubbleUp(values, current, numValues-1);
    cout << "==== " << current+1 << " th iteration =====" << endl;
    display(values, 10);
    current++;
  }
}



int main()
{
    int a[] = {41, 7, 11, 22, 17, 3, 19, 5, 58, 13};
	int arr2[] = {26, 24, 3, 17, 25, 24, 13, 60, 47, 1};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "size of the array is: " << n << endl;

    BubbleSort(arr2, 10);
    cout << "size of the array after bubble sort is: " << n << endl;
    display(arr2, n);

    return 0;
}
