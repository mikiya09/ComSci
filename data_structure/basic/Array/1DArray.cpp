
// passing array to the function correctly 
// ---------------------------------------


// method 1:
// passing the size as a variable 
#include <iostream>
using namespace std;
void fun(int arr[], int n)                // same as void fun(int *arr, int n)
{                                         // array as parameter is always treated as pointer
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
}
 
// Driver program
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    fun(arr, n);
    return 0;
}



// method 2: 
// when you have function that correctly calculate size with string 
void fun(char* arr)                 // same as void fun(char arr[]) {...}
{
    int i;
    int n = strlen(arr);
    cout << "n = " << n << endl;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
}
 
// Driver program
int main()
{
    char arr[] = "comeonbaby";
    fun(arr);
    return 0;
}


// method 3: 
// or passing it as a pointer or by reference
