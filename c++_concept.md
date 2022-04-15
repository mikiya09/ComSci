


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


# Class

    >> public 

    >> private
    [!]. private variable could only be accessed by member function inside this class

    >> void output() const;
      [ ]: this is just to ensure if any variable inside this class is a const, and you can still able to print out it
      [ ]: because you are set the const variable to be passed in the first place



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


    < basic rule when making ADT >
    [1]. make all the mmeber variables private members of the class 
    [2]. make each of the basic operations that the programmer needs a public member function of the class,
         and fully specify how to use each such member functions
    [3]. make any helping functions private member function


# Char v.s. String

    [!] they are not equal
    
    [+]: char (data type)
        - is array type data, but store character instead of number
        - when using operator on them, we can actually comparing the address of the first element inside the char array
        - therefore we can only use single quote, because char can only compare with char data type

    [+]: string (data type)
        * we have cstring and standard string library in C++
        - when #include <string>, we are refering the standard string library 
        - so when comparing the string object, we could use double quote
    [.] therefore when you are comparing string data type, you can use double quote 


# Qualifier 

    [+] public

    [+] private

    [+] protected
      >> anything under the protected qualifier can be accessed by name in a derived class but not anywhere else.
      >> so only accesseible in derived classes?

      [ex.]
      
      class xxx : public yyy
      {
          public:
          ...
          private: 
          ...
          protected: 
            double fraction(double percent);
      }

      [declaration]
      double xxx:fraction(double percent)
      {
          return percent/100.0;
      }


# overloading



# Inheritance & Polymorphism

    [+]: when compiling the program, remember to include all .cpp file that are related, place the driver.cpp at first
    [+]: that's saying, when compile a derived children class, you have to include at least three files
         1. driver.cpp
         2. child.cpp
         3. parent.cpp
 

# virtual 



# I/O 

    >> istream and ostream (formatting)
    [ex.]

    void BankAccount::output(ostream& outs) const 
    {
        outs.setf(ios::fixed);
        outs.setf(ios::showpoint);
        outs.precision(2);
        outs << "Print Balance: &" << balance << endl;
    }
     
    [+]: when you call this function, the input needed to pass to the function is "cout" --> like this backaccount.output(cout);


    [ex.]
    void BankAccount::input(istream& ins)
    {
        ins >> balance;
    }

    [+]: when calling it --> bankaccount.input(cin);
         - in terminal, you will automatically be prompt to enter something 




# overriding & overloading

    >> creating multiple version of a same function

    >> return type is not part of the function, therefore changing the return type does not make overloading ok
    [bad]:
      int do_stuff(int) {..}
      void do_stiff(int) {..}
      --------------------
      the above thing will mess up, you have to make the signature different


# static

# this

# ->

# const

# setf/precision/overloading operator


