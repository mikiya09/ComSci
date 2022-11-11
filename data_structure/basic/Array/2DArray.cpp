
#include <iostream>
using namespace std;


// method 1:
// specify the size of columns of 2D array
void processArr(int a[][10]) {
   // Do something
}
// -----------------------------------------------------------------------------------------




// method 2:
// pass array containing pointers
void processArr(int *a[10]) {           // passing a pointer of an array of 10 pointers
   // Do Something                      // a[] = *a in terms of parameter: *a[10] = a[][10]
}

// When callingint *array[10];
for(int i = 0; i < 10; i++)
   array[i] = new int[10];              // initialize each pointer in the 10 pointer-array
processArr(array);

// -----------------------------------------------------------------------------------------




// method 3:
void processArr(int **a)
{
    // Do something
}

int main()
{
    int **array;
    array = new int *[10];          // pay attention to how to declare below one
    for (int i=0; i<10; i++)
    {
        array[i] = new int[10];     // in comparison with above one
    }
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            cout << array[i][j];
        }
        cout << endl;
    }

    cout << *array << endl;     // print out the first address
    // processArr(array);

    return 0;
}
