

# Call 
    >> execute a function or line of code, that is a call



# Call by Value
    >> meaning: execute lines of code or function interact with values (variables)
    [!] everytime a value gets called, a copy of that value is created, ex). 

    void Demo(int i) 
    {
      i ++;
    }

    int main()
    {
      int NUM = 5;
      Demo(NUM);
      cout << NUM << endl;
    }

    NUM won't change, because Demo function make a copy of NUM represented as i inside the function, when leaving the function, the copy is gone
    so NUM in main function won't change, still print out 5

    =============================
    [!]: when program gets larger, function gets more complex, lots of copies will be made, and thus take out lots of memory, and slow down the program



# Reference

    => when a value is stored in memory, two things is created
       [1]. the value itself that stored in the memory
       [2]. and its address
       these two are together
 
    => &: reference operator
    => &a: the address of a
    => [ex]

       int a = 5;
       int& ref = a;

       cout << a << &a << ref << endl;
       1. we will get 5 for a,
       2. a series of numbers for &a as the address of a
       3. get 5 for ref

    =====================================
    => reference is just an alias for an existing variable, didn't create new thing

    int& ref = a    // ref is called the reference, or the alias of a
    &a              // &a is not called refernece, it is the address of a


    [call by refernece]
    when calling a function by reference, function will take variables as input, and passing their address into the function;

    [!]=> noted this truth:

          - when you are int& ref = 7, is the same as saying a = 7 

          - when you call the funciton, only variable will be created in the memory, reference will not
            it's just alias, and I think it will store at different part of the memory aside from where store variable value

    => dereferencing:
       - passing the address of a variable to a function, this function then could modify the value stored on that address directlty


# Pointer

    => pointers are variables that store the address of a value (a series of number ≈ 12?)
       [+]. the difference compare to call by value is that it will modify the value at certain address directly
       [+]. so not copy of the value is made, free some memory
        

    => [ex].
        int a = 5;             - int is the type, a is integer variable that store 5 right now
        int* b = &5;           - int* is the type, b is a pointer variable that store the address of 5, 
                                 because of int in the front, this pointer could only pointing to integer value/variable


    => int[] sotre in the stack memory
       - stack memory will be deleted automatically, but heap will not as long as the program is running

    => new int[] wil store in the heap memory (pointer/dynamic memory)
       - allocate: declare a memory of space for using in heap
       - deallocate: delete the memory in heap
    
    [ex]:
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

    => Memory leak
      - 1. y = NULL: means to make pointer not pointing to anything
      - 2. delete[]x: means to delete the memory in the location
      - do 2 first, don't do 1 before 2; because that cause pointer pointing to nowhere, but memory still there didn't get deleted --> causing memory leak


# getline
    :read the whole line, ignore the space in the user input 

    int main() {

    string str;

    cout << "Enter your name: ";
    getline(cin, str);
    cout << "Hello, " << str << " Welcome" << endl;

    return 0;
    }



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



# Inheritance & Polymorphism

    [+]: when compiling the program, remember to include all .cpp file that are related, place the driver.cpp at first
    [+]: that's saying, when compile a derived children class, you have to include at least three files
         1. driver.cpp
         2. child.cpp
         3. parent.cpp
 


# I/O 

    >> istream and ostream (formatting)

    ===================================
    [ex.]

    void BankAccount::output(ostream& outs) const 
    {
        outs.setf(ios::fixed);
        outs.setf(ios::showpoint);
        outs.precision(2);
        outs << "Print Balance: &" << balance << endl;
    }
    [+]: when you call this function, the input needed to pass to the function is "cout" --> like this backaccount.output(cout);
         "cout is also a object, think of like that"


    ===================================
    [ex.]
    void BankAccount::input(istream& ins)
    {
        ins >> balance;
    }

    [+]: when calling it --> bankaccount.input(cin);
         - in terminal, you will automatically be prompt to enter something 


# const (parameter modifier)
    [Front!] 
    remember that when call by value is used, a copy of the variable will be made, and as the program grow later, calculation becomes complex, copies increase 
    => which will take out memory and will slow down the program
    => produce error when you attempt to change the parameter

    >> Money add(const Money& amount1, const Money& amount2);
    here we don't want amount1 and amount2 to change, these two are class objects
    

    [End!]
    >> void output(ostream& outs) const;
    => this means that, if we have class object m1(from Money class), and we use m1.output(). 
       The const in the end of output function means that this function will not modify m1
    => for example, there will be private data that is associated with m1, and we don't want them to change
    
    => so it becomes a read-only function


    [ex]:
    const int MAX_NUM = 90;

    const int* a = new int;   // cannot change the content(address) of that pointer pointing to
    no: *a = 2
    yes: a = 2   // making the pointer pointing to something else, although it's possible but 2 as address is not valid


    int* const a = new int;   // can change the content(address), but cannot change the value that pointer pointing to
    yes: *a = 2
    no:  a = &MAX_NUM


# static
    ============ ex ============
    => static variables in a function
       : when a variable is declared as static, space for the static cariable is allocated once even if the function is called multiple time
    
    void demo()
    {
      static int count = 0;         -------- here --------
      cout << count << " ";

      count ++;
    }

    int main() 
    {
      for (int i=0; i < 5; i++)
        demo();
      return 0;
    }

    [output]: 0 1 2 3 4 
    here the variable count is declared as static, so its value is carried through the function calls (only run once)
    It is not getting initilized every time the function is called.
    ============ ex ============

    -----------------------------------------------------------------------------------------------------------------------------

    ============ ex ============
    => static variables in a class
       : same idea, as static variable in class are initialized only once as they are allocated space in separate staic storage so,
         the static variables in a class are shared by the objects. 
       : there cannot be multiple copies of sa,e static variables for different objects, cannot be initialized using constructors

    class Demo
    {
      public: 
        static int i;

        Demo() {// do nothing};
    };


    => intended to create multiple copies of the static variable i for multiple objects, but nothing happnen
    int main()
    {
      Demo obj1;
      Demo obj2;
      obj1.i = 2;
      obj2.i = 3;

      cout << obj1.i << " " << obj2.i << endl;
    }

    => a static variable inside a class should be initialized explicitly by the user using the class name and scope resolution operator(::) outside the class
    [continue from above]
    int Demo::i = 1;

    int main() 
    {
      Demo obj;
      cout << obj.i << endl;
    }

    ============ ex ============

    -----------------------------------------------------------------------------------------------------------------------------

    ============ ex ============
    => Static functions in a class: same idea of static variables in a class
    => the main idea is that it static function could be called without the existence of class object 

    class Demo
    {
        public:
          static void printMsg()
          {
            cout << "Welcome";
          }
    };

    int main() 
    {
      Demo::printMsg();
    }


# this

    => is a class type pointer
    => Demo* d = this;

    ========= ex ========
    class Demo
    {
      int x, y;

      Demo(int x, int y)
      {
        this->x = x;      // it's the same as dereferencing: (*this).x = x;
      }
    }
    => the first x is the member variable of the class, the second x is the variable that Demo constructor will take in

    more on => [https://www.youtube.com/watch?v=Z_hPJ_EhceI]


# virtual 
    >> late binding


    >> slicing problem


# Friend Function
    >> private variable data needed to be accessed directly without using the object of that class

    [ex.]
    friend bool equal (birthDate d1, brithDate d2) {...}




# overriding & overloading

    >> creating multiple version of a same function

    [!] return type is not part of the function, therefore changing the return type does not make overloading ok
      int do_stuff(int) {..}
      void do_stiff(int) {..}
      --------------------
      the above thing will mess up, you have to make the signature different


# overloading operator
    [+] add => operator +
    [+] equal => operator ==



# Automatic Type Conversion
    [ex.]
    
    Money BaseAmount(100, 60), fullAmount;
    fullAmount = baseAmount + 25;
    fullAmount.output(cout);

    => when the system sees that + expression
       1. It first checks to see if + has been overloaded to work with the combo of variables
       2. if not, it will llook to see if there is a single-argument constructor that can use the other argument so that we can get Money + Money
          - as long as we have constructor that take int variable (25) to build a Money object

