

# getline
// read the whole line, ignore the space in the user input 
/*
int main() {
  
  string str;

  cout << "Enter your name: ";
  getline(cin, str);
  cout << "Hello, " << str << " Welcome" << endl;

  return 0;
}
*/









// call by value: the value store in the memory by default is not changable

// call by reference: & -> address operator
// &x: the address of x
// int &x = y -> meaning creating a new variable in the memory and link the it will y in terms of address
// when you modify any of two, the other will change correspondingly
// for now, sort of think of x is a alias of y
//
// while pointer: is the memory space store certainly value of other address


// reference (doesn't consume any memory)
// ===============================
/*
void change(int value) {
  value ++;
  cout << "look: " << value << endl;
  return;
}


int main() {
  
  int a = 5;
  int &b = a;

  cout << a << endl;
  cout << b << endl;

  change(a);

  cout << "now change" << endl;
  b = 7;
  cout << a << endl;
  cout << b << endl;


  return 0;
}
*/





// udemy class cblues c++ from beginner to advance
//
// stack memory & heap memory
// int[] store in the stack, new int[] will store in the heap
// the address of new int[] will store in the stack, that's a pointer
//
// stack memory will be deleted automatically, but heap will not as long as the program is run
// allocate: delare a memory to space for using in heap
// deallocate: delete the memory in the heap
//  - memory leak problem: if some memory belongs to certain program but not pointer pointing to it
//  - no pointer, and not free, not getting deleted, didn't get used
//  - 1. y = NULL: means to make pointer not pointing to anything
//  - 2. delete[]x: means to delete the memory in the location
//  - do 2 first, don't do 1 before 2; because that cause pointer pointing to nowhere, but memory still there didn;t get deleted 
// pointer (variables that store address)
// =======================================
/*

int main() {

  int x = 5;
  int *y = &x;

  cout << y << endl; // pointer: address
  cout << *y << endl;// (dereferencing: going to the location/address and accessing the data store on top of it) 
  return 0;
}
*?/










// ===========================================================
// dynamic array: create temporary array in the working memory

int main() {

  int size;
  cout << "Size: ";
  cin >> size;
  int *myArray = new int[size];

  for (int i=0; i < size; i++) {
    cout << "Array[" << i << "] ";
    cin >> *(myArray+i);
  }

  for (int i = 0; i < size; i++) {
    // cout << myArray[i] << " ";
    cout << *(myArray+i);
  }
  cout << endl;



  // deallocated, delete the dynamic array after using it
  delete[]myArray; // delete the value store in the allocate memory space 
  myArray = NULL; //  delete the pointer, so myArray pointing to nothing


 return 0;
}
*/
