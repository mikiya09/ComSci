

# Call 
    >> execute a function or line of code, that is a call



# Call by Value
    >> meaning: execute lines of code or function interact with values (variables)
    [!] everytime a value gets called, a copy of that value is created

    ex.
    -----------------------------
    |                           |
    |   void Demo(int i)        |
    |   {                       |
    |     i ++;                 |
    |   }                       |
    |                           |
    |   int main()              |
    |   {                       |
    |     int NUM = 5;          |
    |     Demo(NUM);            |
    |     cout << NUM << endl;  |
    |   }                       |
    |                           |
    -----------------------------
    // NUM won't change, because Demo function make a copy of NUM represented as i inside the function
    // when leaving the function, the copy is gone
    // so NUM in main function won't change, still print out 5

    =============================
    [!]: when program gets larger, function gets more complex, 
         lots of copies will be made, and thus take out lots of memory, and slow down the program



# Reference

    [ some concept ]:

        >> when a value is stored in memory, two things is created
           <1>. the value itself that stored in the memory
           <2>. and its address
           these two are together
 
        >> &: reference operator
        
        >> &a: the address of a
        
        ex.
        ---------------------------------------------------------
        |                                                       |
        |   int a = 5;                                          |
        |   int& ref = a;                                       |
        |                                                       |
        |   cout << a << &a << ref << endl;                     |
        |                                                       |
        |   // we will get 5 for a                              |
        |   // a series of numbers for &a as the address of a   |   
        |   // get 5 for ref                                    |
        |                                                       |
        ---------------------------------------------------------



    [ call by reference ]:

        >> reference is just an alias for an existing variable, didn't create new thing


            -----------------------------------------------------------------------------
            |   int& ref = a    // ref is called the reference, or the alias of a       |
            |   &a              // &a is not called refernece, it is the address of a   |
            ---------------------------------------------------------------------- ------


        >> when calling a function by reference, function will take variables as input
           and passing their address into the function;



    [ pay attention ]:

        + when you are int& ref = 7, is the same as saying a = 7 

        + when you call the funciton, only variable will be created in the memory, reference will not
          it's just an alias
          and I think it will store at different part of the memory aside from where store variable value




    [ dereferencing ]:

        >> passing the address of a variable to a function
           this function then could modify the value stored on that address directlty


# Pointer

    [ defintion ]:

        >> pointers are variables that store the address of a value (a series of number ≈ 12?)


    [ v.s. call by value ]:
       
       >> the difference compare to call by value is that it will modify the value at certain address directly
       >> so not copy of the value is made, free some memory
        
        ex.
        -----------------------------------------------------------------------------------------------------
        |                                                                                                   |
        |    int a = 5;         // int is the type, a is integer variable that store 5 right now            |
        |   int* b = &5;        // int* is the type, b is a pointer variable that store the address of 5    |
        |                       // because of int in the front                                              |
        |                       // this pointer could only pointing to integer value/variable               |
        |                                                                                                   |
        -----------------------------------------------------------------------------------------------------


    [ memory ]:
    
        >> int[] sotre in the stack memory
            + stack memory will be deleted automatically, but heap will not as long as the program is running

    
        >> new int[] wil store in the heap memory (pointer/dynamic memory)
            + allocate: declare a memory of space for using in heap
            + deallocate: delete the memory in heap
    
    ex.
    ---------------------------------------------------------------------------------
    |   int main() {                                                                |
    |                                                                               |
    |   int x = 5;                                                                  |
    |   int *y = &x;                                                                |
    |                                                                               |
    |   // pointer: address                                                         |
    |   cout << y << endl;                                                          |
    |                                                                               |
    |   // dereferencing:                                                           |
    |   // going to the locatin/address and accessing the data store on top of it   |
    |   cout << *y << endl;                                                         |
    |   return 0;                                                                   |
    |                                                                               |
    |   }                                                                           |
    |                                                                               |
    ---------------------------------------------------------------------------------


# dynamic array
    
    [ what is this? ]:

            >> create temporary array in the working memory


    ex.
    -------------------------------------------------------------------------------------
    |                                                                                   |
    |   int main() {                                                                    |
    |                                                                                   |
    |     int size;                                                                     |
    |     cout << "Size: ";                                                             |
    |     cin >> size;                                                                  |
    |     int *myArray = new int[size];                                                 |
    |                                                                                   |
    |     for (int i=0; i < size; i++) {                                                |
    |       cout << "Array[" << i << "] ";                                              |
    |       cin >> *(myArray+i);                                                        |
    |     }                                                                             |
    |                                                                                   |
    |     for (int i = 0; i < size; i++) {                                              |
    |       // cout << myArray[i] << " ";                                               |
    |       cout << *(myArray+i);                                                       |
    |     }                                                                             |
    |     cout << endl;                                                                 |
    |                                                                                   |
    |     // deallocated:          delete the dynamic array after using it              |
    |     delete[]myArray;      // delete the value store in the allocate memory space  |   
    |     myArray = NULL;       //  delete the pointer, so myArray pointing to nothing  |
    |                                                                                   |
    |     return 0;                                                                     |
    |   }                                                                               |
    |                                                                                   |
    -------------------------------------------------------------------------------------

    [ memory leak ]:

            >> Memory leak
                <1>. y = NULL: means to make pointer not pointing to anything
                <2>. delete[]x: means to delete the memory in the location
                <3>. do 2 first, don't do 1 before 2; because that cause pointer pointing to nowhere
                     but memory still there didn't get deleted --> causing memory leak


# getline

        >> read the whole line, ignore the space in the user input 

        ex.
        ---------------------------------------------------------
        |                                                       |
        |   int main() {                                        |
        |                                                       |
        |   string str;                                         |
        |                                                       |
        |   cout << "Enter your name: ";                        |
        |   getline(cin, str);                                  |
        |   cout << "Hello, " << str << " Welcome" << endl;     |
        |                                                       |
        |   return 0;                                           |
        |   }                                                   |
        |                                                       |
        ---------------------------------------------------------


# Char v.s. String

    <1>. they are not equal
    

    <2>. char (data type)
            + is array type data, but store character instead of number
            + when using operator on them,
              we can actually comparing the address of the first element inside the char array
            + therefore we can only use single quote, because char can only compare with char data type


    <3>. string (data type)
        
        * we have cstring and standard string library in C++
        - when #include <string>, we are refering the standard string library 
        - so when comparing the string object, we could use double quote
    [.] therefore when you are comparing string data type, you can use double quote 





# ================================================



# static

    [ Properties ]:

        >> when a variable is declared as static
           space for the static cariable is allocated once even if the function is called multiple time
    
    ex.
    ---------------------------------------------------------
    |                                                       |
    |   void demo()                                         |
    |   {                                                   |
    |     static int count = 0;         // declare here     |
    |     cout << count << " ";                             |
    |                                                       |
    |     count ++;                                         |
    |   }                                                   |
    |                                                       |
    |   int main()                                          |
    |   {                                                   |
    |     for (int i=0; i < 5; i++)                         |
    |       demo();                                         |
    |     return 0;                                         |
    |   }                                                   |
    |                                                       |
    ---------------------------------------------------------

        < output >: 0 1 2 3 4 
    
        + here the variable count is declared as static
        + so its value is carried through the function calls (only run once)
        + It is not getting initilized every time the function is called.



    [ static variable in class]:

        >> same idea
            + as static variable in class are initialized only once 
            + as they are allocated space in separate staic storage so,
            + the static variables in a class are shared by the objects. 

        >> there cannot be multiple copies of sa,e static variables for different objects
           cannot be initialized using constructors

    ex.
    -------------------------------------------------------------------------------------------------
    |                                                                                               |
    |   class Demo                                                                                  |
    |   {                                                                                           |
    |     public:                                                                                   |
    |       static int i;                                                                           |
    |                                                                                               |
    |       Demo() {// do nothing};                                                                 |
    |   };                                                                                          |
    |                                                                                               |
    |                                                                                               |
    |   // intended to create multiple copies of the static variable i for multiple objects         |
    |   // but nothing happnen                                                                      |
    |   int main()                                                                                  |
    |   {                                                                                           |
    |     Demo obj1;                                                                                |
    |     Demo obj2;                                                                                |
    |     obj1.i = 2;                                                                               |
    |     obj2.i = 3;                                                                               |
    |                                                                                               |
    |     cout << obj1.i << " " << obj2.i << endl;                                                  |
    |   }                                                                                           |
    |                                                                                               |
    |                                                                                               |
    |   // a static variable inside a class should be initialized explicitly                        |
    |   // by the user using the class name and scope resolution operator(::) outside the class     |
    |   // continue from above                                                                      |
    |   int Demo::i = 1;                                                                            |
    |                                                                                               |
    |   int main()                                                                                  |
    |   {                                                                                           |
    |     Demo obj;                                                                                 |
    |     cout << obj.i << endl;                                                                    |
    |   }                                                                                           |
    |                                                                                               |
    -------------------------------------------------------------------------------------------------



    [ static function in class]:

        >>  same idea of static variables in a class
            + the main idea is that it static function could be called without the existence of class object 

    ex.
    ---------------------------------
    |                               |
    |   class Demo                  |
    |   {                           |
    |   public:                     |
    |       static void printMsg()  |
    |       {                       |
    |           cout << "Welcome";  |
    |       }                       |
    |   };                          |
    |                               |
    |   int main()                  |
    |   {                           |
    |       Demo::printMsg();       |
    |   }                           |
    |                               |
    ---------------------------------




# Struct 

    >> it's like class, but everything is public by default




# CLASS


    [ Def ]: a data type whose variables are objects, themselves are variables with member functions and data values
             -----------       ---------------------                 -------------------------------     -----------

                    ->[ create data type that has method to do stuff ]



    >> ELements:

        < 1 >. member function

                
                + everything is private by default if no label(qualifier) provided
                

                + setter/getter: member functions that could access to private member of the class


                + know how to define a classes and member function
                    
                    > scope resolution operator(::)
                    > ex.
                    -----------------------------------------------------------------
                    |    // .header file                                            |
                    |                                                               |
                    |    #ifndef TEST_H                                             |
                    |    #define TEST_H                                             |
                    |                                                               |
                    |    #include <iostream>                                        |
                    |    using namespace std;                                       |
                    |                                                               |
                    |                                                               |
                    |    class Test {                                               |
                    |    public:                                                    |
                    |                                                               |
                    |        // default constructor: same name with class           |
                    |        Test();                                                |
                    |        // custom constructor                                  |
                    |        Test(int n);                                           |
                    |                                                               |   
                    |        // getter                                              |
                    |        void getNumerator();                                   |
                    |        void getDenominator();                                 |
                    |                                                               |
                    |        // setter                                              |
                    |        void setNumerator();                                   |
                    |        void setDenominator();                                 |
                    |                                                               |
                    |    private:                                                   |
                    |        int numerator;                                         |
                    |        int denominator;                                       |
                    |    };                                                         |
                    |                                                               |
                    |    #endif                                                     |
                    |                                                               |
                    |    // remember that at the end of class you need semi-colon   |
                    |    // you cannot assign value under private qualifier         |
                    |    // not allow                                               |
                    -------------------------------------------------------------------------
                    |    // .cpp file                                                       |
                    |    #include "Test.h"                                                  |
                    |                                                                       |
                    |    Test::Test() : numerator(0), denominator(1)                        |
                    |    {                                                                  |
                    |        // default constructor                                         |
                    |        // you don't need to give it a default value                   |
                    |        // because default constructor will be called automatically    |
                    |        // but if you want to give a default value                     |
                    |        // you have do it like this                                    |
                    |        // Class::Class() : x(), y()                                   |
                    |        // remember the colon                                          |
                    |    }                                                                  |
                    |                                                                       |
                    |                                                                       |
                    |    Test::Test(int n) : numerator(n), denominator(2)                   |
                    |    {                                                                  |
                    |        // there are many ways to do this                              |
                    |        // you could do the current version                            |   
                    |        // you could also initialize one private variable              |   
                    |        // and set the other inside constructor                        |       
                    |        // not restriction, you will assign value if don't specify     |
                    |        // you can do initialize whatever many private var you want    |
                    |    }                                                                  |
                    |                                                                       |
                    |                                                                       |
                    |    void Test::getNumerator()                                          |
                    |    {                                                                  |
                    |        cout << numerator << endl;                                     |
                    |    }                                                                  |
                    |                                                                       |
                    |                                                                       |
                    |                                                                       |
                    |    void Test::getDenominator()                                        |
                    |    {                                                                  |
                    |        cout << denominator << endl;                                   |
                    |    }                                                                  |   
                    -------------------------------------------------------------------------
                    |    // main.cpp                |
                    |    #include "Test.h"          |
                    |                               |
                    |    int main() {               |
                    |                               |
                    |        Test t;                |
                    |        Test t2(3);            |
                    |                               |
                    |        t.getNumerator();      |
                    |        t.getDenominator();    |
                    |                               |
                    |        t2.getNumerator();     |
                    |        t2.getDenominator();   |
                    |                               |
                    |        return 0;              |
                    |                               |
                    |    }                          |
                    ---------------------------------



        < 2 >. qualifier

                + public: all member functions and variable under have no access restrictions

                + private: everything under cannot be directly accessed by the program (only by public member functions)

                    > make all member variables private

                + protected: derived classes could access directly without member function only for derived class


        < 3 >. properties

                + black box analogy: one should know what it does without need to know how it does it

                + procedural abstraction (why do we need qualifiers?)

                    • hide info from users, so that they don't need to worry about implement some method in the class
                    • they just need to use method, and they can use them across several programs


        < 4 >. constructor (for instantiate 实例化)

                + initialize "member variables" when declaring an object

                + constructor is automatically called when an object of that class is declared

                [ ! ]:
                > constructor must have the same name as the class it is used in
                > constructor definition cannot return a value, and no return type is given - not even void

                ---------------------------------------------------------------------
                |    // default: constructor that can be called with no arguments   |
                |    // it will be called by default if you don't specify it        |
                |    // one argument                                                |
                |    // two arguments                                               |
                |                                                                   |
                |    < refer to example in section 1 >                              |
                ---------------------------------------------------------------------




# Abstract Data Type (ADT)

    [ Concept ]: for procedural abstraction, accessing self-defined data type with class from other programs.
                     ----------------------            -----------------------------------------------------

               >> Benefit

                    <1>. can change the implementation of your class without changing the other parts of the program
                    <2>. divide work 
                    <3>. subdivide, make class independent of the program, making the program that uses the class



    [ Interface & Implementation ]:

                >> Interface: (tells you how to use an ADT)

                    • public/private member functions/variable + comments that tell you how to use them
                    • should only tell people how to use it, no mention of implementation
                    
                    [ .h file ] 


                >> Implementation: (tell you how the ADT is realized in C++ code)
                    
                    • definition of public and private members functions
                    • details of functions

                    [ .cpp file ] 
                    


    [ Include Guards ]

                >> include "interface.h"

                    + require line for .cpp file 
                    + because of include refering, multiple files can contain the defintions more then once
                    + could possibly cause compilation errors

            
                >> ex.
                -------------------------------------------
                | # ifndef NAMEOFCLASS_H                  |
                | # define NAMEOFCLASS_H                  |
                |                                         |
                | < the rest of the your code goes here > |
                | < refer to CLASS section example 1 >    |
                |                                         |
                | # endif                                 |
                -------------------------------------------



# Inheritance


    [ Derived Class ]:

        >> base class --> originally starting class

        >> derived class --> inherited properties/function from base class

            + representation

                   -----------
                   | Species |
                   -----------
                    /       \
                   /         \
               --------    ----------
               | Male |    | Female |
               --------    ----------
                  |            |
               --------    ----------
               | Man  |    | Woman  |
               --------    ----------

        
        >> define derived class

            ex.
            ----------------------------------------
            // class BASECLASS : public DERIVEDCLASS 
            ----------------------------------------


            + Properties

            < 1 >. a derived class has access to all of the member funct/var of the base class plus its own members

            < 2 >. passing a parameters required by base class, 
                   this parameter could also be passed to its derived class for testing

               ------------------               ---------------
               | derived class  |  -- is a -->  | base class  |
               ------------------               ---------------

               ------------------                 ---------------
               | derived class  |  <-- is not --  | base class  |
               ------------------                 ---------------



            < 3 >. constructor is not inherited

                    • invoke a constructor of the base class within defintion of a derived class
                    -----------------------------------------------
                    # overload the constructor in the derived class

                    -----------------------------------------------

            < 4 >. top down order (declaration order)

                    • when an object of derived class is created, its constructor will be called
                    • in this process, the base class's constructor will be called first, and then its children's
                      then its grandchildren's


            < 5 >. this (pointer)

            ---------------------------------------------------------------------------------------------------------
            | when use in the constructor, or other places in class, you are pointing to the instance of the class  |
            |                                                                                                       |
            | so to say, you have a paramter named "x", and you also have a member variable named "x" as well       |
            |                                                                                                       |
            | when you takes the parameter in                                                                       |
            | and you have to remove confusion so that member variable is member variables, parameter is paremeter  |
            |                                                                                                       |
            | this->x = x: assigning the parameter x to the member variables x of this class                        |
            |                                                                                                       |
            | basically, it is just pointer pointing to some class, so we can correctly refers it                   |
            ---------------------------------------------------------------------------------------------------------


        >> Protect Qualifier (inheritance pitfalls)

            + derived class have all access to public members of base class
            - not direct access to private members
            - private member not inherited
            + declare protected label

            ex.
            --------------------
            | class BASECLASS  |
            | {                |
            |                  |
            | public:          |
            |    // functions  |
            | protected:       |
            |    double xxxxx; |
            |    double yyyyy; |
            |    double zzzzz; |
            |                  |
            | }                |
            --------------------
            [ you could accees to members under protected: ]



    [ Redefintion & Overloading ]:


        >> redefinition 

            + a derived class needs to implement an inherited member function differently than that in the base class

            + refined-function should have the same function name & parameter list

            + and write the new details in it

            ex.
            -------------------------
            // refer to example below
            -------------------------


        >> overloading

            + overloaded function share the same name but have different parameter list

            + redefined function has the same number and types of parameter as the original function

            + in other words, overloaded functions have different "signatures" compare to the original class
              while redefined functions has the same



    [ ex ]:
            ------------------------------------------------------------------------------------------------------------
            |    // .h file                             |       // .h file                                             |
            |    #ifndef SPECIES_H                      |       #idndef HUMAN_H                                        |
            |    #define SPECIES_H                      |       #define HUMAN_H                                        |
            |                                           |                                                              |
            |    #include <iostream>                    |       #include "Species.h"                                   |
            |    using namespace std;                   |       #include <string>                                      |
            |                                           |                                                              |
            |                                           |       // remember colon and public keyword for base class    |
            |    class Species {                        |       class Human : public Species {                         |
            |    public:                                |       public:                                                |
            |        // default constructor             |                                                              |
            |        Species();                         |           // derived class default constructor               |
            |                                           |           Human();                                           |
            |        // customed constructor            |                                                              |
            |        Species(int type, int stage);      |           // custom constructor                              |
            |                                           |           Human(string sName);                               |
            |        // print type - for redefinition   |                                                              |
            |        void printType(Species s);         |           // getter                                          |
            |                                           |           string getName();                                  |
            |        // getter                          |                                                              |
            |        int getType();                     |           // redefintion                                     |
            |        int getStage();                    |           void printType(Species s);                         |
            |                                           |                                                              |
            |        // virtual is under public         |           // virtual function from base class                |
            |        virtual void eat();                |           // no need virtual keyword here again              |
            |                                           |           // but better to have it here for clarity          |
            |    private:                               |           virtual void eat();                                |
            |        int type;                          |                                                              |
            |        int stage;                         |       private:                                               |
            |                                           |           string name;                                       |
            |    protected:                             |       };                                                     |
            |        bool existence;                    |                                                              |
            |    };                                     |       #endif                                                 |
            |    #endif                                 |                                                              |
            |                                           |                                                              |
            ------------------------------------------------------------------------------------------------------------
            |    // .cpp file                                   |       // .cpp file                                   |
            |    #include "Species.h"                           |                                                      |
            |    Species::Species() : type(0), stage(0)         |       #include "Human.h"                             |
            |    {                                              |                                                      |
            |        //                                         |                                                      |
            |    }                                              |       // constructor is not inherited                |
            |                                                   |       // overload it in the inherited class          |
            |                                                   |       // remmeber to include base class after colon  |
            |    Species::Species(int type, int stage)          |       Human::Human() : Species(), name("human")      |
            |    {                                              |       {                                              |
            |        if (type >= 0) {                           |           // default constructor                     |
            |            this->type = type;                     |       }                                              |
            |        }                                          |                                                      |
            |                                                   |       // customed constructor                        |
            |        this->stage = stage;                       |       Human::Human(string sName) : Species(3, 5)     |
            |    }                                              |       {                                              |
            |                                                   |           name = sName;                              |
            |    // testing for redefinition                    |       }                                              |
            |    // takes same paraemter list                   |                                                      |
            |    void Species::printType(Species s)             |                                                      |
            |    {                                              |       // getter                                      |
            |        cout << "TYPE: " << s.type                 |       string Human::getName()                        |
            |             << " STAGE: " << s.stage << endl;     |       {                                              |
            |    }                                              |           return name;                               |
            |                                                   |       }                                              |
            |                                                   |                                                      |
            |    // getter                                      |       // redefintion of printType                    |
            |    int Species::getType()                         |       void Human::printType(Species s)               |
            |    {                                              |       {                                              |
            |        return type;                               |           cout << "TYPE: " << s.getType()            |
            |    }                                              |               << "STAGE: " << s.getStage()           |
            |                                                   |               << "NAME: " << name                    |
            |                                                   |               << "EXISTENCE:" << existence << endl;  |
            |    int Species::getStage()                        |       }                                              |
            |    {                                              |                                                      |
            |        return stage;                              |                                                      |
            |    }                                              |       // virutal function                            |
            |                                                   |       void Human::eat()                              |
            |                                                   |       {                                              |
            |    // implementation of virtual function          |           cout << "eat fast food" << endl;           |
            |    // you don't need the keyword virtual here     |       }                                              |
            |    void Species::eat()                            |                                                      |
            |    {                                              |                                                      |
            |        cout << "possibly eat anything" << endl;   |                                                      |
            |    }                                              |                                                      |
            |                                                   |                                                      |
            ------------------------------------------------------------------------------------------------------------
            |                                       |
            |   // main.cpp                         |
            |                                       |
            |   #include "Species.h"                |
            |   #include "Human.h"                  |
            |                                       |
            |   int main() {                        |
            |                                       |
            |       Species s;                      |
            |       s.printType(s);                 |
            |                                       |
            |       // virtual                      |
            |       s.eat();                        |
            |       cout << "=========" << endl;    |
            |                                       |
            |       Human h, h2("bird");            |
            |       cout << h2.getName() << endl;   |
            |                                       |
            |       // call parent's function       |
            |       cout << h2.getType() << endl;   |
            |       cout << h2.getStage() << endl;  |
            |                                       |
            |       // predefintion                 |
            |       h2.printType(s);                |   
            |                                       |
            |       // virtual                      |
            |       h2.eat();                       |  
            |                                       |
            |       return 0;                       |
            |   }                                   |
            |                                       |
            -----------------------------------------




# this


    [ what is that ]:

            >> is a class type pointer
                + Demo* d = this;

    ex.
    -------------------------------------------------------------------------------------
    |                                                                                   |
    |   class Demo                                                                      |
    |   {                                                                               |
    |       int x, y;                                                                   |
    |                                                                                   |
    |       Demo(int x, int y)                                                          |
    |       {                                                                           |
    |           this->x = x;      // it's the same as dereferencing: (*this).x = x;     |
    |       }                                                                           |
    |   }                                                                               |
    |                                                                                   |
    -------------------------------------------------------------------------------------

    => the first x is the member variable of the class, the second x is the variable that Demo constructor will take in

    more on => [https://www.youtube.com/watch?v=Z_hPJ_EhceI]








# Polymorphism


    >> The ability to associate multiple meanings to one function name by means of late binding


    [ late binding ]: 后期绑定

        + definition --> associated it later in the time

        + for example, 

            ---------------------------------------------------------------------------------------------
            | <1>. you have a class named people in the school                                          |
            | <2>. you have derived classes students, teachers, director, etc                           |
            | <3>. they all could have a method call goToWork()                                         |
            |      but it's not necessary that we need to define them everytime in each child class     |
            | <4>. a good way is it only defined in the base class, and every child can call goToWork() |
            | <5>. when different classes call goToWork(), they behave differently                      |
            | <6>. teacher go to teach, student go to study, ...etc                                     |
            ---------------------------------------------------------------------------------------------


    [ virtual function ]:

        + we can achieve that by making the "goToWork()" function virtual 

        + late (dynamic) binding <官方定义>

            • [place virtual keyword in base class definition, not implementation]
                
                - this tells the compiler to wait until runtime to determine the implemetation of the function,
                  based on the object that calls it

                - if there is a derived class with a redefined version of the function,
                  it will use that version instead of the original

        ex.
        -------------------------------------
        // refer to above inheritance example
        -------------------------------------


        + why not make all functions virtual? - Efficiency

            - The compiler and run-time environment need to do more work to handle virtual function. 
            - using keyword virtual only when necessary


        + slicing problem

            <1>. extended type: children type is also a parent type logicially, and it's true in C++

            <2>. you can extend the type like the following example, but after doing that, 
                 vSpecies could no access to the member in Human class, because Species type doesn't have that

                ex.
                -------------------------------------------------
                |                                               |
                |   vHuman.name = "human";                      |
                |   // extend type                              |
                |   vSpecies = vHuman;                          |
                |   // assume string name is a public variable  |
                |   // cannot do this: vSpecies.name            |
                |                                               |
                -------------------------------------------------



            <3>. to overcome this, use pointer: treat Speices as Human, refering to the following example

                ex.
                ------------------------------------------------------------------------------------
                |                                                                                  |
                |   Species* pS;                                                                   |
                |   Human* pH;                                                                     |
                |                                                                                  |   
                |   // use -> instread of dot(.) for accessing all members                         |
                |   pH = new Human;                                                                |
                |   pH->name = "Human";                                                            |
                |   pH->printType();                                                               |
                |                                                                                  |
                |   pS = pH;                                                                       |
                |   pS->printType()  // here we are using the overidden function in Human class    |
                |                                                                                  |
                ------------------------------------------------------------------------------------


    [ pitfalls ]:

            >> you won't be able to access non-virtual data without using virutal function

                ex.
                -------------------------------------
                |                                   |
                |   pS->name;   // won't work       |
                |                                   |
                |   pS->printType();    // work     |
                |                                   |
                -------------------------------------





# Friend Function

    >> not a member of class

    [ Properties ]:

        <1>. remove messy as much as possible

            ex. if you are write a date class, and comparing two objects of date, you will end up like this

                d1.equal(d2), d2.equal(d1) -- it's correct but also messy

                -------------------------------------------------------------------------------------------------
                |    // original                                                                                |
                |    bool equal(Date date1, Date date2)                                                         |
                |    {                                                                                          |
                |        return (date1.getMonth() == date2.getMonth() && date1.getDay() == date2.getDay());     |
                |    }                                                                                          |
                |                                                                                               |
                |    // friend                                                                                  |
                |    friend bool equal(Date date1, Date date2)                                                  |
                |    {                                                                                          |
                |        return (date1.month == date2.month && date1.day == date2.day);                         |
                |    }                                                                                          |
                -------------------------------------------------------------------------------------------------

        <2>. friend function is NOT a member function, but have access to private members like actualy member function


        <3>. in most situation, 
             the only reason to make a function a friend is to make the function definition simpler and more efficient

        
        <4>. Rule of Thumb
                
                + use member function if the task being performed invluves only one object(one instance of class)

                + use non-member/friend function if the task being performed involves more than one object
                

    

# Overloading Operators


    [ overload (binary) operator ]:

        <1>. if we have a function that overlaps with how the operator works, 
             then overloading the operator is a matter of changing some syntax

            [!] add --> operator +
            [!] equal --> operator ==

        <2>. usually used with friend function, but there's exception 

            ex.
            ------------------------------
            ------------------------------


        <3>. rules

            + when you overloaded an operator
            + at least one argument of the resulting overloaded operator must be of a class type
                
            + overload operator can be, but does not have to be friend of a class.
            + It can ALSO be a member of the class or an ordinary(nonfriend) function

            ex.
            ------------------------------------------------------------------------------
            |                                                                            |
            | friendfriend Money operator +(const Money& amount1, const Money& amount2); |
            |                                                                            |
            |                               |                                            |
            |                               |                                            |
            |                               V                                            |
            |                                                                            |
            |               Money operator +(const Money& amount2);         => at least one argument is a class type
            |                                                                            |
            ------------------------------------------------------------------------------


            + you can only overload existing operators

            + you cannot change the arity(稀有度) of an operator
              -> a unary operator cannot used as a binary operator and vice versa


        <4>. operators that could or could not be overloaded

            + yes: 

            + no: (.) (::) (.*) (?:)

            + must be member function: ([]) (=) (()) (->)

            + must be friend function: (>>) (<<)

        
        <5>. assignment operator (=)



    [ automatic type conversion ]:

        //


    [ overload unary operator ]:

        + ex.
        ------------------------------
        refer to the following example
        ------------------------------



    [ overloading << and >> ]:

        + ex.
        ------------------------------
        refer to the following example
        ------------------------------


    [ ex ].
    -------------------------------------------------------------------------------------
    |   // .h                                                                           |
    |                                                                                   |
    |   #ifndef OPERATION_H                                                             |
    |   #define OPERATION_H                                                             |
    |                                                                                   |
    |   #include <iostream>                                                             |
    |   using namespace std;                                                            |
    |                                                                                   |
    |                                                                                   |
    |   class Operation {                                                               |
    |   public:                                                                         |
    |                                                                                   |
    |       // default constructor                                                      |
    |       Operation();                                                                |
    |                                                                                   |
    |       // custom constructor                                                       |
    |       Operation(int count);                                                       |
    |                                                                                   |
    |       // getter                                                                   |
    |       int getCount();                                                             |
    |                                                                                   |
    |       // (no overload):                                                           |
    |       // friend Operation add(const Operation& o1, const Operation& o2);          |   
    |       friend Operation operator +(const Operation& o1, const Operation& o2);      |
    |                                                                                   |
    |       friend Operation operator /(const Operation& o1, const Operation& o2);      |
    |                                                                                   |
    |       // unary overload                                                           |
    |       friend Operation operator -(const Operation& o);                            |
    |                                                                                   |
    |       friend bool operator >(const Operation& o1, const Operation& o2);           |
    |                                                                                   |
    |       // insertion                                                                |
    |       friend istream& operator >>(istream& ins, Operation& o);                    |
    |                                                                                   |
    |       // extraction, have here because output cannot be modified                  |
    |        friend ostream& operator <<(ostream& outs, const Operation& o);            |
    |                                                                                   |
    |   private:                                                                        |
    |       int count;                                                                  |
    |   };                                                                              |
    |                                                                                   |
    |   #endif                                                                          |
    |                                                                                   |
    -----------------------------------------------------------------------------------------------------------------
    |   // .cpp                                    |   // main.cpp                                                  |
    |                                              |                                                                |   
    |   #include "Operation.h"                     |   int main() {                                                 |
    |                                              |                                                                |  
    |   Operation::Operation() : count(1)          |       Operation o1, o2(14), o3;                                |
    |   {                                          |       o3 = o1 + o2;                                            |
    |       // default constructor                 |       Operation o4 = o1 - o2;                                  |
    |   }                                          |                                                                |   
    |                                              |       // ==== not overload << and >> =====                     |
    |   Operation::Operation(int newCount)         |       // cout << o3.getCount() << endl;                        |
    |   {                                          |       // cout << o4.getCount() << endl;                        |
    |       // custom constructor                  |       // cout << -o4.getCount() << endl;                       |
    |       count = newCount;                      |       // cout << ( o3.getCount() > o4.getCount() ) << endl;    |
    |   }                                          |                                                                |
    |                                              |                                                                |
    |   // getter                                  |       Operation o5, o6;                                        |
    |   int Operation::getCount()                  |       cout << "Enter for o5: ";                                |
    |   {                                          |       cin >> o5;                                               |
    |       return count;                          |                                                                |
    |   }                                          |       cout << "Enter for o6: ";                                |
    |                                              |       cin >> o6;                                               |
    |                                              |                                                                |
    |   // unary overload                          |       cout << "o5: " << o5 << endl;                            |
    |   Operation operator -(const Operation& o)   |       cout << "o6: " << o6 << endl;                            |
    |   {                                          |                                                                |
    |       Operation temp;                        |                                                                |
    |                                              ------------------------------------------------------------------
    |       temp.count = -o.count;                                      |
    |       return temp;                                                |
    |   }                                                               |
    |                                                                   |
    |   bool operator >(const Operation& o1, const Operation& o2)       |
    |   {                                                               |
    |       return o1.count > o2.count;                                 |
    |   }                                                               |
    |                                                                   |
    |                                                                   |
    |   // friend function, overloading addition operator               |
    |   // return Operation class object                                |
    |   Operation operator +(const Operation& o1, const Operation& o2)  |
    |   {                                                               |
    |       Operation temp;                                             |
    |                                                                   |
    |       temp.count = o1.count + o2.count;                           |
    |       return temp;                                                |
    |   }                                                               |
    |                                                                   |
    |                                                                   |
    |   // overload division                                            |
    |   // since I declare temp as int,                                 |
    |   // therefore if fraction gets, 0 might be expected              |
    |   Operation operator /(const Operation& o1, const Operation& o2)  |
    |   {                                                               |
    |       Operation temp;                                             |
    |                                                                   |
    |       temp.count = o1.count / o2.count;                           |
    |       return temp;                                                |
    |   }                                                               |
    |                                                                   |
    |                                                                   |
    |   // insertion operator overload                                  |
    |   istream& operator >>(istream& ins, Operation& o)                |
    |   {                                                               |
    |       int temp;                                                   |
    |       ins >> temp;                                                |
    |                                                                   |
    |       if(temp < 5) {                                              |
    |           o.count = temp + 5;                                     |
    |       }                                                           |
    |       else                                                        |
    |       {                                                           |
    |       o.count = temp - 5;                                         |
    |       }                                                           |
    |                                                                   |   
    |       return ins;                                                 |
    |   }                                                               |
    |                                                                   |
    |                                                                   |
    |   // extraction operator overload                                 |
    |   ostream& operator <<(ostream& outs, const Operation& o)         |
    |   {                                                               |
    |       outs << o.count;                                            |
    |                                                                   |
    |       return outs;                                                |
    |   }                                                               |
    |                                                                   |
    ---------------------------------------------------------------------





# I/O stream

    [ concept ]:

        -----------------------
        #include <iostream>     // iostream is a class, you include it

        + this class has two derived class: istream and ostream
        + each of derived class has its own instance

        >> cout

            • cout is a built-in instance of ostream class
            • << insertion operator only works with ostream object, so that's why only "cout <<" can print

        >> cin
            
            • same for cin, cin is an instance of istream
            • therefore only "cin >>" can take input

    [ istream ]:
        
        friend istream& opeator >>(istream& ins, Operation& o);
        <1>. ins pass by reference as an istream type
        <2>. therefore we can declaring ins is also an istream data type, then we can use >> to it
        <3>. and we need pass by refernece for return type
             because the object we are returning is also pass in by reference - istream& -

    [ ostream ]:

        same with explanation above



    [ formatting ]:

    ex.
    ---------------------------------------------------------
    |                                                       |
    |   void BankAccount::output(ostream& outs) const       |
    |   {                                                   |
    |       outs.setf(ios::fixed);                          |
    |       outs.setf(ios::showpoint);                      |
    |       outs.precision(2);                              |
    |       outs << "Print Balance: &" << balance << endl;  |
    |   }                                                   |
    |                                                       |
    ---------------------------------------------------------
    // when you call this function
    // the input needed to pass to the function is "cout" --> like this backaccount.output(cout);




# Const (parameter modifier)

    [ at Front ]:

        >> produce error when you attempt to change the parameter
            + remember that when call by value is used, a copy of the variable will be made
            + and as the program grow later, calculation becomes complex, copies increase 
            + which will take out memory and will slow down the program

    
        // here we don't want amount1 and amount2 to change, these two are class objects
        >> Money add(const Money& amount1, const Money& amount2);
    

    [ At the End ]:

        >> void output(ostream& outs) const;
            + this means that, if we have class object m1(from Money class), and we use m1.output(). 
            + The const in the end of output function means that this function will not modify m1
            + for example, there will be private data that is associated with m1, and we don't want them to change
    
            => so it becomes a read-only function


    ex.
    -----------------------------------------------------------------------------------------------------
    |                                                                                                   |
    |   const int MAX_NUM = 90;                                                                         |
    |                                                                                                   |
    |   const int* a = new int;     // cannot change the content(address) of that pointer pointing to   |
    |   no: *a = 2                                                                                      |
    |   yes: a = 2                  // making the pointer pointing to something else                    |
    |                               // although it's possible but 2 as address is not valid             |                
    |                                                                                                   |
    |   int* const a = new int;     // can change the content(address)                                  |
    |                               // but cannot change the value that pointer pointing to             |
    |   // yes: *a = 2                                                                                  |
    |   // no:  a = &MAX_NUM                                                                            |
    |                                                                                                   |
    -----------------------------------------------------------------------------------------------------



# Dynamic Arrays with Class


    [ arrays of class ]:

            <1>. Arrays of Classes
            <2>. Arrays as member variables

            + The base type of an array may be any type, so struct/class/ADTs are absolutely fine 
            --------------------------------------------
            |   Money amount[10];                      |
            |                                          |
            |   for (int i=0; i < 10; i++)             |
            |   {                                      |
            |       cin >> amount[i];                  |
            |       cout << amount[i] << endl;         |
            |   }                                      |
            |                                          |
            |   double cash = amount[3].getValue();    |
            --------------------------------------------


    [ dynamic arrays in class ]:

            >> big three

                <1>. Destructor

                        + because dynamically allocated memory needed to delete after using it(occupy space in heap)
                        + but they are like private member, cannot be call delete directly
                        + therefore need declare a destructor for handling that

                        ex. 
                        ------------
                        className::~className()
                        {
                            delete [] value;
                        }


                <2>. copy constructor (deep copy)

                        + why we need copy constructor?
                        ---------------------------------------------------------------------------------
                        |                                                                               |
                        |   when we have derived class, and at the same time we have dynamic array      |
                        |   we could run into situation                                                 |
                        |   when passing dynamic array into two different function at the same time     |
                        |   such as function calling function                                           |
                        |                                                                               |
                        |--------------------------------------------------------------------------------
                        |                                                                               |
                        |   then 2 pointer pointing to the same address                                 |
                        |   if one of the pointer is finished using, and call destructor                |
                        |   and then the other pointer will also pointing to nothing                    |
                        |   therefore we need copy constructor to make a exact same copy of the things  |
                        |   we are working on, and changing one will not affect the other -- deep copy  |
                        |                                                                               |
                        ---------------------------------------------------------------------------------


                        + In circumstances that it will automatically be call 
                            
                            <1>. When a class object is declared and is initialized by another 
                                 object of the same type

                            <2>. when a function returns a value of the class type

                            <3>. whenever an argument of the class tyep is "plugged in" for 
                                 a call-by-value parameter

                        ex.
                        ------------
                        ------------


                <3>. Overloading Assignment(=) Operator

                        + the copy constructor is not automatically called when using assignment operator (=)
                        + so we need to overload that, and make it called the copy constructor


                        ex.
                        -----------
                        -----------


            >> Functions Provided In Every Class

                • (copy) assignment operator (=)
                • Default constructor
                • Copy Constructor
                • Destructor

                [ if you want any of the advanced behaviors specified in this section 
                                      you will need to explicitly define them youself ]



            >> Destructor are called in bottom-up order
               the reverse order of constructor => first the derived class destructor, and then the base class


    [ ex ].
    -------------------------------------------------------------------------------------
    |   // .h                                                                           |
    |                                                                                   |
    |   #ifndef STRINGVAR_H                                                             |
    |   #define STRINGVAR_H                                                             |
    |                                                                                   |
    |                                                                                   |
    |   #include <iostream>                                                             |
    |   using namespace std;                                                            |
    |                                                                                   |
    |                                                                                   |
    |   class StringVar {                                                               |
    |   public:                                                                         |
    |                                                                                   |
    |       // default constructor                                                      |
    |       StringVar();                                                                |
    |                                                                                   |
    |       StringVar(int size);                                                        |
    |                                                                                   |
    |       StringVar(const char a[]);                                                  |
    |                                                                                   |
    |       // copy constructor                                                         |
    |       StringVar(const StringVar& stringObject);                                   |
    |                                                                                   |
    |       // Destructor                                                               |
    |       ~StringVar();                                                               |
    |                                                                                   |
    |       // length of the current string value                                       |
    |       int length() const;                                                         |
    |                                                                                   |
    |       // take string input                                                        |
    |       void inputLine(istream& ins);                                               |
    |                                                                                   |
    |       // overload insertion operator with friend function                         |
    |       friend ostream& operator <<(ostream& outs, const StringVar& theString);     |
    |                                                                                   |
    |       // assignment operator overload                                             |
    |       void operator =(const StringVar& rightSide);                                |
    |                                                                                   |
    |   private:                                                                        |
    |       char* value;                                                                |
    |       int maxLength;                                                              |
    |                                                                                   |
    |   };                                                                              |
    |                                                                                   |
    |   #endif                                                                          |
    |                                                                                   |
    ---------------------------------------------------------------------------------------------
    |                                                                                           |
    |   // .cpp                                                                                 |
    |                                                                                           |
    |    #include "stringVar.h"                                                                 |
    |    #include <cstdlib>                                                                     |
    |    #include <cstddef>                                                                     |
    |    #include <cstring>                                                                     |
    |                                                                                           |
    |   // default constructor                                                                  |
    |   StringVar::StringVar() : maxLength(100)                                                 |
    |   {                                                                                       |
    |       // value is a pointer                                                               |
    |       value = new char[maxLength + 1];                                                    |
    |       // +1 because char array will need to add null value '/0' in the array              |
    |       // +1 so that we can have our string in full size                                   |
    |       value[0] = '\0';                                                                    |
    |   }                                                                                       |
    |                                                                                           |
    |                                                                                           |   
    |   // custom constructor                                                                   |
    |   StringVar::StringVar(int size) : maxLength(size)                                        |
    |   {                                                                                       |
    |       value = new char[maxLength + 1];    // +1 for '\0'                                  |
    |       value[0] = '\0';                                                                    |
    |   }                                                                                       |
    |                                                                                           |
    |                                                                                           |
    |   StringVar::StringVar(const char a[]) : maxLength(strlen(a))                             |
    |   {                                                                                       |
    |       value = new char[maxLength + 1];                                                    |
    |       strcpy(value, a);                   // copy the value from a[] to value             |
    |   }                                                                                       |
    |                                                                                           |
    |   // copy constructor                                                                     |
    |   // it just a copy of result that originally a constructor will do                       |
    |   // so it's still a constructor, don't return any value                                  |
    |   StringVar::StringVar(const StringVar& stringObject) : maxLength(stringObject.length())  |
    |   {                                                                                       |
    |       value = new char[maxLength + 1];    // +1 for '\0'                                  |
    |       strcpy(value, stringObject.value);  // you are doing a deep copy                    |
    |   }                                                                                       |
    |                                                                                           |
    |                                                                                           |
    |   // destructor                                                                           |
    |   StringVar::~StringVar()                                                                 |
    |   {                                                                                       |   
    |       delete [] value;                                                                    |
    |   }                                                                                       |
    |                                                                                           |
    |                                                                                           |
    |   // return size of cstring                                                               |
    |   int StringVar::length() const                                                           |
    |   {                                                                                       |
    |       return strlen(value);                                                               |
    |   }                                                                                       |
    |                                                                                           |
    |                                                                                           |
    |   // use iostream                                                                         |
    |   void StringVar::inputLine(istream& ins)                                                 |
    |   {                                                                                       |
    |       ins.getline(value, maxLength + 1);                                                  |
    |   }                                                                                       |
    |                                                                                           |
    |                                                                                           |
    |   // insertion operator overloading                                                       |
    |   ostream& operator <<(ostream& outs, const StringVar& theString)                         |
    |   {                                                                                       |
    |       outs << theString.value;                                                            |
    |       return outs;                                                                        |
    |   }                                                                                       |
    |                                                                                           |
    |                                                                                           |
    |   // assignment operator overloading                                                      |
    |   // goal: is to implement copy constructor mannully                                      |
    |   // because assignment operatpr won't do that                                            |
    |   void StringVar::operator =(const StringVar& rightSide)                                  |
    |   {                                                                                       |
    |       // make should the private value are set correctly                                  |
    |       int newLength = strlen(rightSide.value);                                            |
    |       if (newLength > maxLength)                                                          |
    |       {                                                                                   |
    |           // in our case we have private pointer of an array                              |
    |           // if the size is not match with the right side                                 |
    |           // set the rightSide's length as the one                                        |
    |           // and then the same procedure                                                  |
    |           delete [] value;                                                                |
    |           maxLength = newLength;                                                          |
    |           value = new char[maxLength + 1];                                                |
    |       }                                                                                   |
    |       // here is just a different of copying all elements                                 |
    |       for (int i=0; i < newLength; i++) {                                                 |
    |           value[i] = rightSide.value[i];                                                  |
    |       value[newLength] = '\0';                                                            |
    |       }                                                                                   |
    |   }                                                                                       |
    |                                                                                           |
    ---------------------------------------------------------------------------------------------




 

# Templates

    >> making a C++ function a template can let it apply to variables of all types



    [ HOW ]:

            + 
            ----------------
            template<class T>
                      |    |
                      |    |
                      |    |
        refers to type;   Type Parameter: used within
        can substitute    the function body; is 
        with typename     replaced by supplied type


            ex: start with a function, and then turn it into template
            ---------------------------------------------------------
            // start
            void swapValues(int& variable1, int& variable2);

            {
                int temp;
                temp = variable1;
                variable1 = variable2;
                variable2 = temp;
            }
            ---------------------------------------------------------
            // turn
            template<class T>                               // added
            void swapValues(T& variable1, T& variable2)
            {
                T temp;
                temp = variables1;
                variable1 = variable2;
                variable2 = temp;
            }

            ---------------------------
            // in main
            int main()
            {
                int num_a = 5, num_b = 3;
                char letter_a = 'a', letter_b = 'b';

                swapValues(num_a, num_b);
                swapValues(letter_a, letter_b);
            }
            ---------------------------


    [ Expand ]:

            >> you may have function template with multiple type parameters, 
               and just specify both in your template prefix

                + template<class T1, class T2>


            >> template can still non-template types
            
                + template<class T>
                  void showStuff(int stuff1, T stuff2, T stuff3);



    [ pay attention ];

            <1>. function template definitions can be placed in one file and included in another file with #include
                 (just like class)

            <2>. some compiler do not support

            <3>. can't use swapValue with a class that does not have a working or proper assignment operator

            <4>. can't pass in any arrays to swapValues, since assignment does not work with array types



    [ ex ]:






# Automatic Type Conversion
    
    ex.
    ---------------------------------------------
    |                                           |
    |   Money BaseAmount(100, 60), fullAmount;  |
    |   fullAmount = baseAmount + 25;           |
    |   fullAmount.output(cout);                |
    |                                           |
    ---------------------------------------------
    [ definition ]:

            >> when the system sees that + expression
                <1>. It first checks to see if + has been overloaded to work with the combo of variables
                <2>. if not, 
                     it will llook to see if there is a single-argument constructor 
                     that can use the other argument so that we can get Money + Money

                <3>. as long as we have constructor that take int variable (25) to build a Money object






