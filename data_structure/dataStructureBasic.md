

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
[1] functional decomposition 
     >> breaks the program into functions 
     >> these functions form a complete solution to the problem when used together

[2] Object-oriented Design 
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
[1] Compile-Time Errors
     • unclean
     • syntactically incorrect
     • know your programming language, editor, etc

[2] Run-Time Errors
     • errors occur during execution after successfully compiled, refer to BUG we called
     • (Robustness): the ability of a program to recover from an error 
     • often found with sufficient testing
        1) logical error
        2) Input/Output error
        3) undefined object error
        4) division by zero error
        5) etc
```

### TEST 
```
[1] Program Verification
     • checking if a program fulfills specification: "Are we doing the job right?"

[2] Program Validation
     • checking if the program fulfills its intended purpose: "Are we doing the right job?"

[3] Precondition
     • a condition that must be true before an operation is exexuted

[4] Postcondition
     • a condition that will be true after an operation completes

[5] Exceptions
     • allow programs to interrupt normal control flow to handle exceptional situations
     • handling them should be part of the design
```

### Abstract Data Type (ADT)
```
+ we are talking about "nouns", not "verb"

Data 
• representation of information 
  in a manner suitable for communication or analysis by humans or machines

Data are nouns of the programming world
• The objects that are manipulated
• The information that is processed

Definition 
• A data type whose (logical) properties (domain and operations) 
  are specified independently of any particular implementation.
```

### Different views of ADT 

#### [+] Logical Level
```
abstract view of the domain and operations
```
#### [+] Implementation Level
```
specific representation to "hold" the data items, and implementation of operations
```
#### [+] Application Level
```
modeling real-life data in a specific context, also known as user level
```
#### [+] Ex: ADT List
```
(Application Level) 
  : modeling real-life list, a homogeneous collection of elements with a linear relation
  => there is one first element 
  => every element except first one has a unique predecessor
  => every element except last one has a unique successor

(Logical Level)
  => domain: data that resembles private data, or struct that defined in .h/.cpp file
  => operations supported: PutItem(), GetItem(), DeleteItem(), GetNext(), ...

(Implementation Level)
  : implemented using array, linked list, or others; codes for operations
```

#### [+] Library Example
```
[1] Application Level: Public Library that you can make the use of 

[2] Logical Level: 
     > domain is a collection of books; 
     > operations inclues, check book out, check book in, pay fine, reserve a book

[3] Implementation Level:
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

#### [+] Simple
```
[1] Integral (完整的)
     > char
     > short
     > int 
     > long
     > enum

[2] Floating (有小数点)
     > float 
     > double
     > long 
     > double

[3] Address 
     > pointer 
     > reference 
```
#### [+] Composite
```
[1] Definition 
     : stores a collection of individual data components under *one variable name*,
       allows individual components to be accessed

[2] Type 
     > array 
     > struct 
     > union 
     > class 
```

### Unstructured v.s Structured data types
#### [+] Unstructured 
```
components are [not] organized with respect to one another
e.g. strcut and classes
```
#### [+] Structured 
```
organization of components determines method used to access individual components
e.g. arrays
```


### Pass-by-value v.s pass-by-reference
#### [+] Pass by value
```
    sending a copy of the contents of the actual argument
    -----------------               -------------------
    |               |    a copy     |                 |
    | calling block | ------------> | Function Called |
    |               |               |                 |
    -----------------               -------------------
    so, actual argument cannot be changed by the function 
```

#### [+] Pass by reference (&)
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

[1] Is a reserved keyword in the programming languages C and C++
[2] It is used to create an additional name (alias) for another data type
[3] It is often used to simlify the syntax of complex data structure (struct/class)
[4] used to provide specific descriptive type names for integer data type of varying sizes
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

        | ----------------- 12 columns -----------------|
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

--------------------------------------------------------------------------------------------
[ex].
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
**definition**
```
1) another way of creating abstract data type, just like class but by default everything is public 
2) usually used with class

--------------------------------------------------------------------------------------------------
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
   float*    gpa;
};
StudentType student1,student2;  
student1.name.last;             // accessing struct member using dot(.)
student2.name.first[0];         // accessing struct member that is an array
student2->gpa                   // if it is a pointer, accessing the value with ->
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
    = Address(index) = BaseAddress + (The number of)Index * SizeOfElement

```


### Two-dimensional Array
```
[1] A two-dimensional array is a structured composite data type made up of a finite, 
     fixed size collection of homogeneous elements having relative positions given 
     by a pair of indexes and to which there is direct access


[2] Array operation (creation, storing values, retrieving values) are performed
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
row index = 2, so pass through first(index=0) and second(index=1) row (together 24 spots)
column index = 7, the 7th spot in the third row(index=2)
assume 2 bytes for type int, memory address is located with bytes
```
### Passing arrays as function parameters
```
[1] In C++, arrays are always passed by reference, 
     and & is not used with formal parameter type
     Meaning, always pass the base address of an array to function, 
     and function can modify array

[2] protect array from unintentional changes by using "const" in formal parameter 
     and function prototype
```
#### [+] One Dimensonal Array
##### &#x266f; incorrect way
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
##### &#x266f; [correct way](./basic/Array/1DArray.cpp)

#### [+] Two Dimensonal Array
##### &#x266f; [methods](./basic/Array/2DArray.cpp)


# Object-Oriented Programming
```
• Three inter-related constructs: classess, objects and inheritance 
  
[1] Objects are basic run-time entities in an object-oriented system 
[2] A class defines the structure of its objects 
[3] Classes are organized in an "is-a" hierarchy defined by inheritance
```
### Abstraction 
```
[.h]        file -> known as header file, data member and member function specification 
[.cpp]      file -> member function implementation 
[main.cpp]  file -> objects being used in here
```
### Inheritance
```
+ Allows programmers to create a new class that is a specialization of an existing class 

    => new class is called a derived class of the existing class 
    => the existing class is the base class of the new class
```
### Polymorphism
```
+ The ability to associate multiple meanings to one function name by means of late binding

+ [late binding]: associated it later in the time 
---------------------------------------------------------------------------------------------
| <1>. you have a class named people in the school                                          |
| <2>. you have derived classes students, teachers, director, etc                           |
| <3>. they all could have a method call goToWork()                                         |
|      but it's not necessary that we need to define them everytime in each child class     |
| <4>. a good way is it only defined in the base class, and every child can call goToWork() |
| <5>. when different classes call goToWork(), they behave differently                      |
| <6>. teacher go to teach, student go to study, ...etc                                     |
---------------------------------------------------------------------------------------------

+ [ virtual function ]:

    => we can achieve that by making the "goToWork()" function virtual 
    => late (dynamic) binding <官方定义>

    ex).
    [ place virtual keyword in base class definition, not implementation ]
            
        § this tells the compiler to wait until runtime 
          then to determine the implemetation of the function 
          based on the object that calls it

        § if there is a derived class with a redefined version of the function 
          it will use that version instead of the original

```
### Composition

```
refer to below
```
# Error & Exception Management
### Define your own [Exception](http://peterforgacs.github.io/2017/06/25/Custom-C-Exceptions-For-Beginners/) 
```
Exception could be an user-defined class
```
### Try/throw/catch
**[pre-defined exception](./basic/Exception/preDefined.cpp)**
```
#include <iostream>
using namespace std;
 
class demoDemo {};                                  // this also works

class demo {                                        // create a class
public:
    void throwError();
};
 
void demo::throwError()                             // define a member function in the class
{
    cout << "My Exception Happens" << endl;
}

int main()
{
    try {
        throw demo();
    }
 
    catch (demo d) {                                // catch a class object d
        d.throwError();                             // execute d's method.throwError()
    }
}
```


# Algorithm
```
1. A logical sequence of discrete steps 
2. steps that describe a complete solution to a problem
3. computable in a finite amount of time (meaning it will terminate)
```
### Analysis of algorithm
```
The theoretical study of design and analysis of computer algorithms, not about programming
```
#### [+] Design
```
[1] design correct algorithms which minimize cost
[2] efficiency is the design criterion
```
#### [+] Analysis
```
+ predict the cost of an algorithm in terms of resource and performance
```
#### [+] Basic Goals for designing
```
[1] always correct
[2] always terminates
[3] always care about performance
```
#### [+] WHY?
```
Computers are always limited in the computational ability and memory
+ Resources are always limited
+ Efficiency is the center of algorithms
```
#### [+] Growth Rate 
##### &#x266f; Example 1 
```
[Question]: 
determine whether x is one of A[1], A[2],..., A[n], and retrieve information about x.

[Algorithm]: 
go through each number in order and compare it to x 

[pseudocode]:
i = 1;
while  (i <= n) and (A[i] != x) do
i = i + 1;
if (i > n) then i = 0;

[related questions]:
<1> Number of element comparisons?     --> from 1 to n
<2> Worst case?                        --> n
<3> Best case?                         --> 1
```
##### &#x266f; Example 2 
```
Square Matrix Multiplication 

---             ---          ---             ---         ---             ---
|   c11 ... c1n   |          |   a11 ... a1n   |         |   b11 ... b1n   |
|    . .     .    |          |    . .     .    |         |    . .     .    |
|    .   .   .    |     =    |    .   .   .    |    x    |    .   .   .    |
|    .     . .    |          |    .     . .    |         |    .     . .    |
|   cn1 ... cnn   |          |   an1 ... ann   |         |   bn1 ... bnn   |
---             ---          ---             ---         ---             ---
                                      n 
                                      ---
                                cij = \   aik • bkj
                                      / 
                                      ---
                                      k=1 

[pseudocode]:
for i = 1 to n do 
    for j = 1 to n do 
    {
        c[i, j] = 0;
        for k = 1 to n do 
            c[i, j] = c[i, j] + a[i, k] * b[k, j];
    }

[related questions]:
<1> What is the number of multiplications?     --> i * j * k = n^3
<2> What is the number of additions?           --> same? think that later
```
##### &#x266f; explain
```
further abstraction we use in algorithm analysis is to characterize in terms of growth 

[1] Matrix multiplication time grows as n^3 
[2] Linear search time grows as n 

[why is it important?]
input size   |    n    |   nlgn   |   n^2   |   n^3   |   2^n   |
    10       | 0.00001 |   ....   |   ...   |  0.001  |  < 0.01 |   => unit: sec
    100      | 0.0001  |   ....   |   ...   |  1 min  |    ∞    |
    1000     | 0.001   |   ....   |   ...   |  17.64  |    ∞    |   => unit: min
    10000    | 0.01    |   ....   |   ...   |  11.76  |    ∞    |   => unit: days
```
### Big O Notation 
```
The worst case (upper bound) of the algorithm execution time, use linked list as an exmaple
```
<!-- ![Big-O-Comparison](./pic/bigO.png) -->
<img src="./pic/bigO.png" width = 600>

### Comparison of algorithm
```
[Goal]: Compare the efficiency of different algorithm, efficiency is what matters!
```
#### [!] One problem Two Algorithm
```
[problem]: Calculate the sum of the integers from 1 to N, i.e. 1+2+3+...+(N-1)+N 

[Alg #1]:                           --> performs N addition/assignment operations 
sum = 0;
for (count=1; count<=N; count++)
     sum = sum + count;

[Alg #2]:                           --> one addition, one multiplication and one division
sum = (1+N)*(N/2);
```
#### [+] How to compare ?
```
[1] Compare the actual running time on a computer 
[2] Compare the number instructions/statements executed
     a) varies with languages used and programmer's style 
     b) count the number of passes through a "critical loop" in algorithm 
[3] Count representative operations performed in the algorithm
```
# Pointers
```
A pointer variable contains the memory address of another variable 

[for what]: for indirect addressing of data and for dynamic allocation of memory 
```
### Declaration
```
use an aterisk(*)
-----------------
int* intPointer;
```
### Manipulation (operation)
```
// ampersand(&) returns the address of a variable
int alpha = 10;
int* intPointer = &alpha;                       // return a address like this: 0x16ba0f49c

// accessing variables value through pointer 
*intPointer = 25;                               // alpha is now 25
```
### Pointer Ex).
```
#include <iostream>
using namespace std;

int main()
{
    int* intPtr_1 = new int;                // pointer of a single int value
    int* intPtr_2 = new int [10];           // pointer of an array of int
    int** intPtr_3 = new int* [10];         // pointer of an array of int pointers

    cout << *intPtr_1 << endl;              // since intPtr is an address
                                            // to access the value stored on this address
                                            // use asterisk: *(0x600003260040) = 0
    for (int i=0; i<10; i++)
    {
        cout << intPtr_2[i] << endl;        // other way of print element: *(intPtr_2+i)
    }                                       // all are int values on the following address
                                            // * = [] here I guess equivalent to below
                                            // *(0x600003260040+i) = 0x600003260040[i]
    for (int i=0; i<10; i++)
    {
        cout << intPtr_3[i] << endl;        // all are int pointers on the following address
    }

    // deletion
    delete intPtr_1;                        // deleting the value on that pointer address
    delete [] intPtr_2;                     // same 
    delete [] intPtr_3;                     // same

    return 0;
}
```
# Dynamic Memory Allocation
### Memory Allocation
#### [+] Static Memory allocation
```
(when): compile time
allocates a fixed amount of memory during compile time, pre-specify in declaration 
```
#### [+] Dynamic memory allocation 
```
(when): runtime
Allocation of memory space for a variable at run time, as opposed to static one

(where):
Dynamic allocation creates variables on heap (or free store),
a section of memory reserved for dynamic allocation
```
### Use cases
Dynamic allocation uses the keyword **new**
```
int* ptr = new int;
// new returns a pointer to the newly allocated int on the heap
// and the value can only be accessed via this pointer

(new):
      • pointers can point to nothing using NULL 
      • if no memory is available on the heap, new operator returns NULL (for check memory)
```
### Memory Leak Issue
```
A memory leak is the loss of available memory space 
that occurs when some "dynamically" allocated memory is never deallocated, called garbage
```
#### [+] Ex).
```
float* money = new float;
*money = 33.46;
float* myMoney = new float;
```
<img src="./pic/memoryLeak1.png" width=200>
<br>

```
•myMoney = *money;                  // set the value of myMoney = the value of money
```
<img src="./pic/memoryLeak2.png" width=200>
<br>

```
myMoney = money;                    // set the memory address of myMoney = money's
```
<img src="./pic/memoryLeak3.png" width=200>
<br>

```
The memory cell originally used by myMoney is now inaccessible.
Since there's no way to collect the garbage, it is small memory leak
```
#### [+] Delete Operation 
```
[1] If it is single variables 
     >> delete myMoney;              // safely clean up the memory allocated to myMoney

[2] If it is array variables
     >> delete [] myArray;           // deleting array
```
# List (in C++)
**a collection of homogeneous items**


### Linked List 

#### [+] Circular Linked List
#### [+] Reverse Linked List

### Unsorted list
#### [+] Array based 
##### &#x266f; static & dynamic (refer to [SortedType](./basic/List/))
```
The length field must be present in order to define the extent of the list within the array

• differences 
1) GetItem() 
    > for SortedType you can use binary search, 
    > but for UnsortedType you had to loop through whole list
2) PutItem()
    > SortedType had to maintain the order, after find the location for inserting
    > UnsortedType put anywhere that require less computing power
3) DeleteItem()
    > SortedType need to maintain order, move item a space up after deletion
    > UnsortedType can just place the last item to where an item is deleted and decrement length
```
#### [+] Linked-List based
A collection of **node** that are linked toegther by **pointer** in a chain
##### &#x266f; Node
```
[1] basic component of a linked list, store data and a pointer to the next node
[2] Nodes are created when needed using dynamically allocated memory 
[3] The last node in the list has a NULL pointer
```
##### &#x266f; Header file [(.h)](./basic/List/UnsortedType_LL.h)
##### &#x266f; Implementation file [(.cpp)](./basic/List/UnsortedType_LL.cpp)
##### • *struct*
*creating a type using strcut*
```
struct NodeType
{
    ItemType info;
    NodeType* next;
}
```
##### &#x266f; *constructor*
##### &#x266f; *destructor*
```
// version 2:

UnsortedType::~UnsortedType()
{
    MakeEmpty();
}
```
##### &#x266f; *IsFull*
##### &#x266f; *GetLength*
##### &#x266f; *MakeEmpty*
```
100% sure this one is an iterator
-----------------------------------------------------------------------------------------------
| ! delete always start from the head                                                         |
| 1) makeEmpty() must deallocate each node individually in order to empty the list            |
| 2) This is accomplished using a while loop                                                  |
| 3) Iteration starts at listData, the head of the list, and continues using listData->next   |
| 4) Iteration stops when listData is NULL                                                    |
-----------------------------------------------------------------------------------------------

void UnsortedType::MakeEmpty()
{
    NodeType* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;             // point to listData(head)
        listData = listData->next;      // listData point to next node
        delete tempPtr;                 // delete first node pointed by tempPtr
    }
    length = 0;
}
```
##### &#x266f; *PutItem*
```
! Order Matter, do step 4 over step 3 will cause memory leak
------------------------------------------------------------
1) Create a new node 
2) Set the node's info to the input data 
3) Set the node's next pointer to the listData, the first item in the list
4) Set listData to point to the new node
```
<img src="./pic/putItem.png">

```
Put into Empty list 
1) create new node 
2) make new node point to NULL 
3) make listData point to NULL 
```

##### &#x266f; *GetItem*
<img src="./pic/getItem.png" width=500>

```
1) Linear Search through the list to find the desired item
2) same as searching if item exist
3) check the input boolean value found after passing it into the search function
```
<br>

##### &#x266f; *DeleteItem*
```
1) tempPtr to locate the item that need to be deleted, link it; 
2) predecessor(previous pointer) point to location->next 
3) delete the tempPtr
```
<img src="./pic/deleteItem.png" width=500>

##### &#x266f; *ResetList*
##### &#x266f; *GetNextItem*
<br>


#### [+] Comparing Implementations 
<img src="./pic/compareTimeComplexity.png" width=700>

### SortedType
##### • Logical Level (no changes)
```
1) Only change from unsorted list is guaranteeing list elements are sorted
2) Order is determined by ItemType's CompareTo method 
3) PutItem and DeleteItem pre- and post- condition: list is sorted and remains sorted
```
##### • Application Level (no changes)
```
1) Nothing has changed for the user, list interface is exactly the same
2) GetNextItem will return the next item in key order
```
##### • Imlementation Level (few changes)
```
-----------------------------------------------------------------
|   1) PutItem, DeleteItem: Ensure list remains Sorted <br>     |
|   2) GetItem can be improved                                  |
-----------------------------------------------------------------
```
#### [+] Array-based (static) 
```
the length field must be present in order to define the extent of the list within the array
```
##### &#x266f; Header File [(.h)](./basic/List/SortedType_aBased.h)
##### &#x266f; Implementation File [(.cpp)](./basic/List/SortedType_aBased.cpp)
##### &#x266f; *constructor*
##### &#x266f; *MakeEmpty*
##### &#x266f; *IsFull*
##### &#x266f; *GetLength*

##### &#x266f; *GetItem (binary search)*
```
// Apply Binary Search: time complexity = O(log2N)
// assume item exist

ItemType SortedType::GetItem(ItemType item, bool& found)
{
    int midpoint;
    int first = 0;                                          // index of first item
    int last = length - 1;                                  // index of last item

    bool moreToSearch = (first <= last);
    found = false;
    while (moreToSearch && !found)
    {
        midPoint = ( first + last ) / 2;                    // set midPoint
        switch (item.ComparedTo(info[midpoint]))
        {
            case LESS:      last = midPoint - 1;            // if less, select LHS
                            moreToSearch = (first <= last);
                            break;
            case GREATER:   first = midPoint + 1;           // if greater, select RHS
                            moreToSearch = (first <= last);
                            break;
            case EQUAL:     found = true;
                            item = info[midPoint];
                            break;
        }
    }
    return item;
}
```
<img src="./pic/binarySearch.png">

##### &#x266f; *PutItem*
```
(Linear Search is required)
1) Find the space where new element should go
2) create space for new element, by moving all subsequent elements down one space
3) insert the element in the space
4) increment the length by 1

// assume item exist

void SortedType::PutItem(ItemType item) 
{
  bool moreToSearch;
  int location = 0;

  moreToSearch = (location < length);
  while (moreToSearch) 
  {
    if (info[location] < item) {
        moreToSearch = false;
    }
    elif (info[location] > item) {
        location ++;
        moreToSearch = (location < length);
    }
    else
    {
        break;
    }
  } 

  for (int i = length; i > location; i--)   // looping from the end, need to shift item back
    info[i] = info[i - 1];                  // length = max_index + 1, so is able to shift 
  info[location] = item;                    // let item = where the location lays
  length++;                                 // increment length
}
```
<img src="./pic/arrayBased.png">

##### &#x266f; *DeleteItem*
```
1) assume item for deletion is in the list, simple linear search find them
2) when found, move subsequent element up one space (overwritting)
3) decrement the length by 1

//
void SortedType::DeleteItem(ItemType item) 
{
  int location = 0;

  while (item.ComparedTo(info[location]) != EQUAL)
    location++;
  for (int index = location + 1; index < length; index++)
    info[index - 1] = info[index];
  length--;
}
```
##### &#x266f; *ResetList*
#### [+] Array-based (dynamic) 
```
few changes:

1) Parameteried constructor: allows user to specify max number of items
2) Defafult constructor: ____you_know_what_to_do_____
3) Destructor: cleans up the memory on the heap when the rest of the list is removed
4) store the max list size instead of using a constant: 
    >> length == maxList;
```
<img src="./pic/dynamicArrayBased.png" width=500>

##### &#x266f; *Destructor*
```
! object is deallocated when it leavs scope, but any data it points to is not -> memory leak

1) class destructor is a needed to implicitly invoked when a object leave scope
2) ~UnsortedList() => clean up memory by deallocating all the nodes in the list

--------------------------------------------------------------------------------------------
// for array-based destructor 
// we create a pointer of an array, which stores the address of first location in array
// delete that is enough

UnsortedType::~UnsortType()
{
    delete [] arrayPtr;
    cout << "destructor called" << endl;
}
```

#### [+] Linked-List based
##### &#x266f; Header File[(.h)](./basic/List/SortedType_LL.h)
##### &#x266f; Implementation File[(.cpp)](./basic/List/SortedType_LL.cpp)
```
functions to change compare to array-based sort list:
-> GetItem()
-> PutItem()
-> DeleteItem()
```
##### &#x266f; *NodeType* 
##### &#x266f; *Constructor*
##### &#x266f; *IsFull*
##### &#x266f; *MakeEmpty*
##### &#x266f; **GetItem*
```
-------------------------------------------------------------------------------------
|                                                                                   |
|   loop through the linked list:                                                   |
|   if (CompareTo == Equal) { returm item };                                        |
|   elif (CompareTo == Less) { cout << "Item is not in the list" << endl; };        |
|                                                                                   |
|-----------------------------------------------------------------------------------|
|                                                                                   |
|   ! Cannot use Binary Search int this case                                        |
|   1) binary search require being able to randomly access elements of the list     |
|   2) Linked lists can only access directly linked nodes one by one                |
|                                                                                   |
-------------------------------------------------------------------------------------

// here we need to compare 3 situations, because the list is sorted (in order)
ItemType SortedType::GetItem(ItemType item, bool& found) 
{
    bool moreToSearch;
    NodeType* location;

    location = listData;
    fount = false;
    moreToSearch = (location != NULL);
    
    while (moreToSearch && !found)
    {
        switch(item.ComparedTo(location->info))
        {
            case GREATER: location = location->next;
                          moreToSearch = (location != NULL);
                          break;
            case EQUAL:   found = true;
                          item = location->info;
                          break;
            case LESS:    moreToSearch = false;
                          break;
        }
    }
    return item;
}
```
##### &#x266f; **PutItem*
```
Can't always look a head (location->next)->info, because exception will happen in the end  

solution. two poitners, recording previous and current Node
1) predLoc
2) location 

// code
void SortedType::PutItem(ItemType item)
{
  NodeType* newNode;  	// pointer to node being inserted
  NodeType* predLoc;  	// trailing pointer
  NodeType* location; 	// traveling pointer
  bool moreToSearch;

  location = listData;
  predLoc = NULL;
  moreToSearch = (location != NULL);

  // Find insertion point.
  while (moreToSearch)
  {
    switch(item.ComparedTo(location->info))
    {
      case GREATER: predLoc = location;
      	           location = location->next;
                    moreToSearch = (location != NULL);
                    break;
      case LESS:    moreToSearch = false;
                    break;
    }
    
  }

  // Prepare node for insertion
  newNode = new NodeType;
  newNode->info = item;
  // Insert node into list.
  if (predLoc == NULL)         // Insert as first
  {
    newNode->next = listData;
    listData = newNode;
  }
  else
  {
    newNode->next = location;
    predLoc->next = newNode;
  }
  length++;
}
```
<img src="./pic/putItemLinkedList1.png" width=400>
<br>
<br>
<img src="./pic/putItemLinkedList2.png" width=650>
<br>
<br>

##### &#x266f; **DeleteItem*
```
linear way: compare against "(location->next)->info" to find the item to delete

void SortedType::DeleteItem(ItemType item)
{
  NodeType* location = listData;
  NodeType* tempLocation;

  // Locate node to be deleted.
  if (item.ComparedTo(location->info) == EQUAL)
  {
    tempLocation = location;
    listData = location->next;	                        // listData point to next location 
  }                                                     // same as saying deleting this node
  else
  {
    while (item.ComparedTo((location->next)->info) != EQUAL)    // assume item exist 
      location = location->next;

    // Delete node at location->next
    tempLocation = location->next;
    location->next = (location->next)->next;
  }
  delete tempLocation;                                  // because delete tempLocation here
  length--;
}
```
<img src="./pic/delelteItemLinkedList.png" width=400>

##### &#x266f; *ResetList*
##### &#x266f; *GetNextItem* 
##### &#x266f; *Destructor (Linked List)*


#### [+] Time Complexity/order of magnitude
<img src="./pic/sortListCompareTimeComplexity.png">

```
>> memory handle difference

1). Static Array:   specify size at compile time 
2). Dynamic Array:  sepcify size at run-time 
3). Linked likst:   as long as computer has memory
```

#### [+] Bounded and Unbounded ADTs
##### &#x266f; Bounded 
```
There is a logical limit on the number of items in the structure
----------------------------------------------------------------
>> array-based list is bounded, but you can modify it into dynamic memory allocated version 
>> so that storage can be expanded as long as there are space in the heap
```
##### &#x266f; Unbounded
```
no logical limit on the number of items in ths structure
---------------------------
>> Linked list is Unbounded
```






# Stacks (ADT)
```
Last in First Out (LIFO)
```
### Properties
#### • Logical Level
```
A stack is an ADT in which elements are added and removed from only the top of the stack


    class StackType
    {                                                   Push     Pop
    public:                                               |       ^
        StackType();                                      v       |
        bool IsFull() const;                            |           |
        bool IsEmpty() const;                           |           |   ---> Top 
                                                        |-----------|
        void Push( ItemType item);                      |           |
        void Pop();                                     |-----------|
        ItemType Top() const;                           |           |
                                                        |-----------|
    private:                                            |           |
        int top;                                        |-----------|
        ItemType *items[MAX_ITEMS];                     |           |
    };                                                  -------------

```
#### • Application Level 
```
1) Palindorome 
2) Any kind of reversing data work, etc

// code
```
### Implementation 
#### [+] Array-based 
##### &#x266f; Header file [(.h)](./basic/Stack/StackType.h)
##### &#x266f; Implementation file [(.cpp)](./basic/Stack/StackType.cpp)

<img src="./pic/tracingStack.png" width=600>


#### [+] Linked list-based 
##### &#x266f; Header File [(.h)](./basic/Stack/StackType_LL.h)
```
struct NodeType;

class StackType
{
	
public:
  StackType();

  ~StackType();
  
  void Push(int newItem);
  
  void Pop();
  
  int Top();

  bool IsFull() const;

  bool IsEmpty() const;

public:
  NodeType* topPtr;

};
```
##### &#x266f; Implementation File [(.cpp)](./basic/Stack/StackType_LL.cpp)

<img src="./pic/deleteStack.png">

#### [+] Complexity Comparison 
<img src="./pic/stackImplementationCompare.png">

# Queues
```
First in, First Out (FIFO)
```
### Properties 
#### [+] Logical Level 
```
A queue is an ADT in which elements are added to the rear and removed from the front

class QueueType
{
public:
    QueueType(int max);
    QueueType();
    ~QueueType();

    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(ItemType item);    // add newItem to the rear of the queue 
    void Dequeue(ItemType& item);   // remove front item from queue

private:
    ItemType* items;                // Dynamically allocated array 
    int maxQue;                     // max length 
};


                   Front                             Rear 
                  _________________________________________
                  |       |       |       |       |       |
    Dequeue -->   |       |       |  ...  |       |       |   <-- Enqueue
                  -----------------------------------------

```
#### [+] Implementation Level
##### &#x266f; Fixed-Front Queue 
```
(no efficient, waste a lots of memory space)
```
<img src="./pic/fixFrontQueue.png">

##### &#x266f; Floating Queue (focus on this)
```
1) more efficiient
2) when rear is the indeed the last item in the queue => wrap around => use modulus(mod %)

// (rear+1) % length, in this case 5
```
<img src="./pic/floatingQueue.png" width=800>

```
3) Issue with set front and rear directly

=> in the following situation, cannot distinguish Empty Queue & Full Queue
```
<img src="./pic/floatingQueueIssue.png" width=500>

```
4) Fix this Issue
----------------------------
Solution [1]: more intuitive
{...count the length...}

------------------------------------------------------------------------
Solution [2]: less intuitive, but cooler and efficient, go with this one
```
<img src="./pic/floatingQueueIssuesFix.png" width=600>

```
[empty queue]:
1) according to figure 1 above, when Dequeue 
2) front += 1 
3) since front is the index before actual front item, front == rear gives empty queue

-------------------------------------------------------------------------------------

[full queue]:
1) according to figure 2 above, when front = 2 while the actual front is at index = 3
2) rear + 1 = front, indicates Full

-------------------------------------------------------------------------------------

// front = index of the array slot "preceding" the front element in the queue
// always reserve this slot to be empty(never store queue element here)
// if we initialize a queue with 100, what we actually use is 99 space
```
#### [+] Application Level
```
// For users simplicity, maxQue = max + 1;
// because by adopting the solution 2, we will have empty space in the queue
```
### Implementation 
#### [+] Array-based [(.cpp)](./basic/Queue/QueueType.cpp)
##### &#x266f; constructor
##### &#x266f; destructor
##### &#x266f; MakeEmpty()
##### &#x266f; IsEmpty()
##### &#x266f; IsFull()
##### &#x266f; Enqueue()
```
// Post: If (queue is not full) newItem is at the rear of the queue; 
// otherwise a FullQueue exception is thrown.  
void QueType::Enqueue(int newItem) 
{
  if (IsFull())
    throw FullQueue();
  else
  {
    rear = (rear +1) % maxQue;                     // include % in the calculation
    items[rear] = newItem;                         // deal with the situation rear is the end
  }
}

        ____________________________________________
        |       |       |          |       |       |    front = 2 
        |   C   |       | reserved |   A   |   B   |
        |       |       |          |       |       |    rear = 0
        --------------------------------------------
           [0]     [1]      [2]       [3]     [4]

           // rear is 0, plus 1 will result in 1
           // add item at there
```
##### &#x266f; Dequeue()
```
// Post: If (queue is not empty) the front of the queue has been removed 
// and a copy returned in item; othersiwe a EmptyQueue exception has been thrown.
void QueType::Dequeue(int& item)
{
  if (IsEmpty())
    throw EmptyQueue();
  else
  {
    front = (front + 1) % maxQue;
    item = items[front];
  }
}

        ____________________________________________
        |       |       |          |       |       |    front = 2 
        |   C   |       | reserved |   A   |   B   |
        |       |       |          |       |       |    rear = 0
        --------------------------------------------
           [0]     [1]      [2]       [3]     [4]

        // since we preserve the index before actual front item as "front"
        // use front + 1 to locate actual front item
```

#### [+] Linked list-based 
##### &#x266f; Header File [(.h)](./basic/Queue/QueueType_LL.h)
##### &#x266f; Implementation File [(.cpp)](./basic/Queue/QueueType_LL.cpp)
##### &#x266f; NodeType
##### &#x266f; constructor
##### &#x266f; destructor
##### &#x266f; MakeEmpty()
##### &#x266f; IsFull()
##### &#x266f; IsEmpty()
##### &#x266f; Enqueue()
```
// add newItem to the rear of the queue
// pre:  Queue has been initialized
// post: If (queue is not full), newItem is at the rear of the queue, otherwise FullQueue()

void QueType::Enqueue(ItemType newItem)
{
    if (IsFull())
        throw FullQueue();
    else
    {
        NodeType* newNode;              // create newNode for storing newItem into info

        newNode = new NodeType;
        newNode->info = newItem;
        newNode->next = NULL;           // item is added from the rear, it points to NULL
        if (rear == NULL)               // check if this is the first node
            front = newNode;
        else
            rear->next == newNode;      // rear originally point to second last node
                                        // rear->next make the second last point to newNode
                                        // remember newNode here is a pointer (address)
        rear = newNode;                 // directly make rear pointer = newNode pointer
    }
}

```
##### &#x266f; Dequeue()
```
// remove front item from the queue and returns(store) it in item variable
// pre:  Queue has been initialized
// post: If (queue is not empty), the front of the queue has been removed 
//       and a copy returned in item, otherwise EmptypQueue() exception

void QueType::Dequeue(ItemType& item)
{
    if (IsEmpty())
        throw EmptyQueue();
    else
    {
        NodeType* tempPtr;

        tempPtr = front;
        item = front->info;
        front = front->next;

        if (front == NULL)          // if the one deleted is the only node
            rear = NULL;            // make both pointer point to NULL
        delete tempPtr;
    }
}
---------------------------------------------------------------------------------------------
```
# Templates 
```
making a C++ function a template can let it apply to variables of all types 
```
### Ex).
#### [+] without Class 
##### &#x266f; Format 
```
template<class T>

1) class T: T refers to a type you will apply later, can be substitute with typename 
2) T:       just a place holder, you can use any name, but "class" this keyword must be consistent
3) ADT:     

for example.
>> template<class ItemType>
>> template<class COOL>
```
##### &#x266f; Normal Situation 
```
void swapValues(int& variable1, int& variable2)
{
    int temp;
    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}
```
##### &#x266f; With Template
```
template<class T>
void swapValues(T& variable1, T& variable2)
{
    T temp;
    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}
```
##### &#x266f; Test Code
```
int main() 
{
    int numOne = 5, numTwo = 3;
    char letterOne = 'a', letterTwo = 'b';

    cout << "Before Swap" << endl;
    cout << "=== num ===" << endl;
    cout << "The first number: " << numOne << " The second number: " << numTwo << endl;
    cout << "=== letter ===" << endl;
    cout << "The first letter: " << letterOne << " The second letter: " << letterTqo << endl;

    // performing swap 
    swapValues(numOne, numTwo);
    swapValues(letterOne, letterTwo);
    cout << " =========================== " << endl;

    cout << "After Swap" << endl;
    cout << "=== num ===" << endl;
    cout << "The first number: " << numOne << " The second number: " << numTwo << endl;
    cout << "=== letter ===" << endl;
    cout << "The first letter: " << letterOne << " The second letter: " << letterTqo << endl;

}
```
#### [+] with Class
##### &#x266f; Format 
```
=> className<dataType> classObject;

|
V
className<int> classObject;
className<string> classObject;
className<ItemType> classObject;
```
##### &#x266f; Normal Situation 
##### &#x266f; With Template 
```
#include <iostream>
using namespace std;

template <class T>              // class template
class Number {
   private:
    T num;                      // variable of type T

   public:
    Number(T n) : num(n) {}     // constructor

    T getNum()
    {
        return num;
    }
};
```
##### &#x266f; Test Code
```
int main() {

    Number<int> numberInt(7);                            // create object with int type

    Number<double> numberDouble(7.7);                    // create object with double type

    cout << "int Number = " << numberInt.getNum() << endl;
    cout << "double Number = " << numberDouble.getNum() << endl;

    return 0;
}
```
##### &#x266f; Template with ADT Class

###### [StackType Example](./basic/Template/Template_Stack.cpp)
```
ex) delcare array with template class, using <> brackets

1). if template<class ItemType>, 
    declaring array with ItemType will be like ItemType<size>;

2). if ADT like class PQType {}, under private data member use class from other library 
    from LTS heap library 
    private:
            HeapType<ItemType> items;

reminder). 

    + inside the HeapType from other library, while in the PQType definition, HeapType also use this template
    + every member function inside PQType class need to have this 
    ------------------ format ------------------
            tempalte<class ItemType>
            PQType<ItemType>::PQType(int max)
            {
                maxItems = max;
                items.elements = new ItemType[max];
                length = 0;
            }

    * template<class ItemType> at the top 
    * <ItemType> before scope resolution
```
###### refer to [PQType](./dataStructureAdvanced.md) for more info

