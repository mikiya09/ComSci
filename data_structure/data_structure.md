




# Basic Concepts

### Software Engineering 
```
A disciplined approach to the design, production, and maintenance of computer programs
```

### Abstraction
```
[Abstraction]: a model of a complex system that includes only the essential details
[Information Hiding]: simplify work by hiding complex details

- Programs are abstractions -
--------------------------------------------------------------------
[.h]    file explains how the class work, what functionalities and properties it has
[.cpp]  detailed implementations of how each function/properties works
```

### Functional Decomposition v.s Object-oriented Design
```
[1]. functional decomposition 
     >> breaks the program into functions 
     >> these functions form a complete solution to the problem when used together

[2]. Object-oriented Design 
     • Divide-and-Conquer: break down the program into things instead of tasks
     • The design consists of objects, which are defined by classes
     • Objects combine data and operations
```
```
[Quote]

Grady Booch, "what Is and Isn't Object Oriented Design", 1989
-------------------------------------------------------------
"Read the specification of the software you want to build. 
 Underline the verbs if you are after procedural code, 
 the nouns if you aim for an object-oriented program."
```

### BUG
```
[1]. Compile-Time Errors
     • unclean
     • syntactically incorrect
     • know your programming language, editor, etc

[2]. Run-Time Errors
     • errors occur during execution, often causing the program to crash
     • (Robustness): the ability of a program to recover from an error 
     • often found with sufficient testing
```

### TEST 
```
[1]. Program Verification
     • checking if a program fulfills specification: "Are we doing the job right?"

[2]. Program Validation
     • checking if the program fulfills its intended purpose: "Are we doing the right job?"

[3]. Precondition
     • a condition that must be true before an operation is exexuted

[4]. Postcondition
     • a condition that will be true after an operation completes

[5]. Exceptions
     • allow programs to interrupt normal control flow to handle exceptional situations
     • handling them should be part of the design
```

### Abstract Data Type (ADT)
```
Data 
• representation of information 
  in a manner suitable for communication or analysis by humans or machines

Data are nouns of the programming world
• The objects that are manipulated
• The information that is processed

Definition 
• A data typen whose (logical) properties (domain and operations) 
  are specified independently of any particular implementation.
```

### Different views of ADT 
#### • Application Level
```
modeling real-life data in a specific context, also known as user level
```
#### • Logical Level
```
abstract view of the domain and operations
```
#### • Implementation Level
```
specific representation to hold the data items, and implementation of operations
```
#### • Ex: ADT List
```
(Application Level) 
  : modeling real-life list, a homogeneous collection of elements with a linear relation
  => there is one first element 
  => every element except first one has a unique predecessor
  => every element except last one has a unique successor

(Logical Level)
  : operations supported: PutItem(), GetItem(), DeleteItem(), GetNext(), ...

(Implementation Level)
  : implemented using array, linked list, or other; codes for operations
```

#### • Library Example
```
[1]. Application Level: Public Library that you can make the use of 

[2]. Logical Level: 
     > domain is a collection of books; 
     > operations inclues, check book out, check book in, pay fine, reserve a book

[3]. Implementation Level:
     > representation of the structure to hold "books", and the coding for operations
```

### ADT operations
```
• Constructor: creates a new instance (object) of an ADT

• Transformer (setter): changes state of the data values of an instance

• Observer (getter): observe the state of the data values without changing them

• Iterator (loop): allows us to process all the components in a data structure sequentially
```
### C++ Data Types

#### • Simple
```
[1]. Integral (完整的)
     > char
     > short
     > int 
     > long
     > enum

[2]. Floating (有小数点)
     > float 
     > double
     > long 
     > double

[3]. Address 
     > pointer 
     > reference 
```
#### • Composite
```
[1]. Definition 
     : stores a collection of individual data components under *one variable name*,
       allows individual components to be accessed

[2]. Type 
     > array 
     > struct 
     > union 
     > class 
```

### Unstructured v.s structured data types
#### • Unstructured 
```
components are [not] organized with respect to one another
e.g. strcut and classes
```
#### • Structured 
```
organization of components determines method used to access individual components
e.g. arrays
```


### Pass-by-value v.s pass-by-reference
#### • Pass by value
```
    sending a copy of the contents of the actual argument
    -----------------               -------------------
    |               |    a copy     |                 |
    | calling block | ------------> | Function Called |
    |               |               |                 |
    -----------------               -------------------
    so, actual argument cannot be changed by the function 
```

#### • Pass by reference (&)
```
 sends the location (memory address) of the actual argument 
    -----------------                -------------------
    |               |    location    |                 |
    | calling block | -------------> | Function Called |
    |               |                |                 |
    -----------------                -------------------
  function access actual argument itself (not just a copy)
```
### Typedef definition
```
typedef: 

[1]. Is a reserved keyword in the programming languages C and C++
[2]. It is used to create an additional name (alias) for another data type
[3]. It is often used to simlify the syntax of complex data structure (struct/class)
[4]. used to provide specific descriptive type names for integer data type of varying sizes
     > int
     > double 
     > long
     > ...

[ex]. 
const int NUM_DEPTS = 5;
const int NUM_MONTHS = 12;
const int NUM_STORES = 3;
typedef long MonthlySalesType [NUM_DEPTS] [NUM_MONTHS] [NUM_STORES];
MonthlySalesType monthSales;

=> here MonthlySales is a 3 dimensonal array that could hold up to 5*12*3 amount of value
=> so it's also a alias of basic type long


                -------------------------------------------------
                |   |   |   |   |   |   |   |   |   |   |   |///|  <- monthlySales[0][11][2]
            ----------------------------------------------------|
            |   |   |   |   |   |   |   |   |   |   |   |   |   |  
  ---   ----------------------------------------------------|---|
   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
   |    |-----------------------------------------------|---|---|
   |    |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
        |-----------------------------------------------|---|---|
   5    |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
  rows  |-----------------------------------------------|---|----    ---
        |   |   |   |   |   |   |   |   |   |   |   |   |   |        /
   |    |-----------------------------------------------|----   3 widths
   |    |   |   |   |   |   |   |   |   |   |   |   |   |          /
  ---   -------------------------------------------------        ---

        | ------------------ 12 months -----------------|
```
### Namespaces
```
• Definition: 
  >> In computing, a namespace is a set of signs (names) that are used to identify and 
     refer to objects of various kinds. A namespace ensures that all of a given set of 
     objects have unique names so that they can be easily identified.

• Example:
  namespace mySpace
  {
      // all variables and functions within this block must be accessed using 
      // scope resolution operator (::) for avoiding namespace pollution
  }

• Three ways to access members within a Namespace 
    + Qualify each reference:
        > mySpace::name with every reference 
    
    + Using declaration:
        > using mySpace::name;
        ( All future references to name refer to mySpace::name )

    + Using directive:
        > using namespace mySpace;
        ( All members of mySpace can be referenced without qualification )
```

### Scope of variables
```
-------------------------
| Type: local & global  |
-------------------------

[ex].
--------------------------------------------------------------------------------------------
#include<iostream>
using namespace std;

int global = 5;                 // global variable 

int func() 
{
    int local = 3;              // local variable 
    int global = 10;            // local variable with same name as the global variable
    
    cout << global << endl;     // 10 compiler will assign global to 10 because run in lines
    cout << ::global << endl;   // 5  the way of accessing global varibles in local ::
    cout << local << endl;  ;   // 3  local variable
}

int main() 
{
    cout << local << endl;      // can't access out of where local variables is defined
}

```

### Structs (alias: records)
```
[ex].

struct NameType {
   char first[15];
   char middleInit;
   char last[15];
};

struct StudentType {
   NameType name;               // any structure can be a member of a struct 
   int      idNum;
   float    credits;
   float    gpa;
};
StudentType student1,student2;  
student1.name.last;             // accessing struct member using dot(.)
student2.name.first[0];         // accessing struct member that is an array
```


# Array
```
In C++, array cannot be assigned one to another

[ex]. 
{
    int arr1[] = {1, 2, 3};
    int arr2[3];

    arr2 = arr1
}
output[1] error: array type 'int[3]' is not assignable

------------------------------------------------------

nor can be the return type of a function in C++

[ex].
output[2] error: array type cannot be return 
```

### One-dimensional Array
```
C++ array elements are stored in a contiguous memory block with a base address

float values[5];      // assume 4 bytes for float

Base address (lowest address) 
    |
    |       
    ------->    7000        7004        7008        7012        7016
            -------------------------------------------------------------
            |           |           |           |           |           |
            -------------------------------------------------------------
              values[0]   values[1]   values[2]   values[3]   values[4]

    Address of values[index]?
    = Address(index) = BaseAddress + Index * SizeOfElement

```


### Two-dimensional Array
```
[1]. A two-dimensional array is a structured composite data type made up of a finite, 
     fixed size collection of homogeneous elements having relative positions given 
     by a pair of indexes and to which there is direct access


[2]. Array operation (creation, storing values, retrieving values) are performed
     using a declaration and a "a pair of indexes(row & column)" representing
     the component's position in each dimension


• Mental Presentation

        const int NUM_STATES = 50;
        const int NUM_MONTHS = 12;
        int statHighh [NUM_STATES][NUM_MONTHS];
                          rows       columns


                 [0]         [1]                    [10]         [11]
            -------------------------------------------------------------
        [0] |           |           |  .......  |           |           |
            -------------------------------------------------------------
            -------------------------------------------------------------
        [1] |           |           |  .......  |           |           |
            -------------------------------------------------------------
                                          .
                                          .
                                          .
            -------------------------------------------------------------
       [49] |           |           |  .......  |           |           |
            -------------------------------------------------------------

• In Storage
    
        In memory, C++ stores 2D arrays in row order;
        The first row is followed by the second rows, etc.

            8000                8024                8048
            -------------------------------------------------------------
            |   |   |...|   |   |   |   |...|   |   |   |   |...|   |   |
            -------------------------------------------------------------
            | ----------------- | ----------------- |
           12 highs for state 0 | 12 highs for state 1      etc.
            Alabama (first row) | Alaska (second row)
```

### Element address calculation based on a given base address
```
According to the above example
Based Address 8000 
=> to locate an element such as stateHighs[2][7] 
=> the compiler needs to know that there are 12 columns in this two-dimensional array

so, baseAddress + (2*12 + 7) * 2 
--------------------------------
row index = 2, so pass through first and second row (together 24 spots)
column index = 7, the 7th spot in the third row
assume 2 bytes for type int, memory address is located with bytes
```
### Passing arrays as function parameters
```
[1]. In C++, arrays are always passed by reference, 
     and & is not used with formal parameter type
     Meaning, always pass the base address of an array to function, 
     and function can modify array

[2]. protect array from unintentional changes by using "const" in formal parameter 
     and function prototype
```
#### • One Dimensonal Array
##### - incorrect way
```
#include <iostream>
using namespace std;
 
// Note that arr[] for fun is just a pointer 
// even if square brackets are used
void fun(int arr[])                                 
{
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "\nArray size inside fun() is " << n;
}
 
// Driver Code
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array size inside main() is " << n;
    fun(arr);
    return 0;
}

output[1]: 
Array size inside main() is 8
Array size inside fun() is 2
------------------------------------------------
explain: when passing int arr to fun() in main, it is always treated as a pointer
         so the calculation in fun() will mess up with the sizeof() function
         you can't the correct size of a pointer 
         the solution is passing the size as a parameter to the main as well
```
##### + correct way 1
```
#include <iostream>
using namespace std;
void fun(int arr[], int n)                // same as void fun(int arr[], int n)
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
```
##### + correct way 2
```
(when you have function that correctly calculate size with string)

#include <iostream>
using namespace std;

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
```
#### • Two Dimensonal Array
##### + method 1
```
// specify the size of columns of 2D array
void processArr(int a[][10]) {
   // Do something
}
```
##### + method 2 
```
// pass array containing pointers
void processArr(int *a[10]) {           // passing a pointer of an array of 10 pointers
   // Do Something
}

// When callingint *array[10];
for(int i = 0; i < 10; i++)
   array[i] = new int[10];              // initialize each pointer in the 10 pointer-array
processArr(array);
```
##### + method 3
```
#include <iostream>
using namespace std;

void processArr(int **a)
{
    // Do something
}

int main()
{
    int **array;
    array = new int *[10];
    for (int i=0; i<10; i++)
    {
        array[i] = new int[10];
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
```


# Object-Oriented Programming
### Abstraction 
### Inheritance
### Polymorphism
### Composition
### Templates

# Error & Exception Management
### Define your own exception 
### Try/throw/catch
### Employ pre-defined exception classes/functions

# Algorithm Anslysis
```
1. A logical sequence of discrete steps 
2. steps that describe a complete solution to a problem
3. computable in a finite amount of time (meaning it will terminate)
```
### Comparison of algorithm
### Analysis of algorithm
### Big O 

# Pointers
### Declaration
### Manipulation (initialization, cope, etc)

# Dynamic Memory Allocation
### Static v.s Dynamic memory allocation 
### Use cases
### Static v.s Dynamic arrays 
### initialization
### Memory Leak Issue

# Lists
### Sorted v.s Unsorted Lists
### Sorted List implementations
#### • Array-based (static & dynamic) 
#### • Linked list-based
### Time Complexity/order of magnitude

# Stacks
### Properties
### Implementation 
#### • Array-based 
#### • Linked list-based 

# Queues
### Focus on Floating Queues 
### Properties 
### Implementation 
#### • Array-based 
#### • Linked list-based 
