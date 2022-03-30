


# call by value
    the value store in the memory by default is not changable

# call by reference
    &: address operator
    &x: the address of x
    int &x = y: meaning creating a new variable in the memory and link the it will y in terms of address
    >> when you modify any of two, the other will change correspondingly
    >> for now, think of x is a alias of y
    ! reference doesn't consume any memory

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

# pointer (variable that store address)
    : is the memory space store certainly value of other address
    >> stack memory & heap memory
    >> int[] store in the stack, new int[] will store in the heap
    >> the address of new int[] will store in the stack, that's a pointer

    >> stack memory will be deleted automatically, but heap will not as long as the program is run
    >> allocate: delare a memory to space for using in heap

    # deallocate: delete the memory in the heap
      - memory leak problem: if some memory belongs to certain program but not pointer pointing to it
      - no pointer, and not free, not getting deleted, didn't get used
    # example
      - 1. y = NULL: means to make pointer not pointing to anything
      - 2. delete[]x: means to delete the memory in the location
      - do 2 first, don't do 1 before 2; because that cause pointer pointing to nowhere, but memory still there didn;t get deleted 
    
    # code
    int main() {

      int x = 5;
      int *y = &x;

      cout << y << endl; // pointer: address
      cout << *y << endl;// (dereferencing: going to the location/address and accessing the data store on top of it) 
      return 0;
    }



# dynamic array
    : create temporary array in the working memory

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

# getline
    :read the whole line, ignore the space in the user input 

    int main() {

    string str;

    cout << "Enter your name: ";
    getline(cin, str);
    cout << "Hello, " << str << " Welcome" << endl;

    return 0;
    }


# CLass




# Constructor
    
    [+] a special method that is called when a class is instantiated(实例化) into an object
    [.] could either be implicit or explicit

    < pay attention >
    [+] constructor has the exactly same name as the class
    [+] has no return and return type in the prefix

    <ex.>
    Class User {
        public: 
        User(string firstName, string lastName)
        {
          first_name = firstName;
          last_name = lastName;
          ...
        }
        ...
        private: ...
      } 

    user1("Bruce", "Wayne"); 


# Abstract Data Type
    
    [!]: think of it as if you know nothing about programming, you just know how to click button
    [!]: you can still interact with programs because of some frontend development work has been done by someone

    [+]: abstract data type (ADT) is the same concept -> you write declaration and implement in a separate file, 
         programmers who need your class just need to know the method you have described in the .h (header file), no need for details



