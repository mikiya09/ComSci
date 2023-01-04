
#include "stringVar.h"
#include <cstdlib>
#include <cstddef>
#include <cstring>


// default constructor
StringVar::StringVar() : maxLength(100)
{
    // value is a pointer
    value = new char[maxLength + 1];    
    // +1 because char array will need to add null value '/0' in the array
    // +1 so that we can have our string in full size
    value[0] = '\0';
}


// custom constructor
StringVar::StringVar(int size) : maxLength(size)
{
    value = new char[maxLength + 1];    // +1 for '\0'
    value[0] = '\0';
}


StringVar::StringVar(const char a[]) : maxLength(strlen(a))
{
    value = new char[maxLength + 1]; 
    strcpy(value, a);                   // copy the value from a[] to value
}

// copy constructor
// it just a copy of result that originally a constructor will do
// so it's still a constructor, don't return any value 
StringVar::StringVar(const StringVar& stringObject) : maxLength(stringObject.length())
{
    value = new char[maxLength + 1];    // +1 for '\0'
    strcpy(value, stringObject.value);  // you are doing a deep copy
}


// destructor
StringVar::~StringVar()
{
    delete [] value;
}


// return size of cstring
int StringVar::length() const
{
    return strlen(value);
}


// use iostream
void StringVar::inputLine(istream& ins)
{
    ins.getline(value, maxLength + 1);
}


// insertion operator overloading
ostream& operator <<(ostream& outs, const StringVar& theString)
{
    outs << theString.value;
    return outs;
}


// assignment operator overloading
// goal: is to implement copy constructor mannully
// because assignment operatpr won't do that
void StringVar::operator =(const StringVar& rightSide)
{
    // make should the private value are set correctly
    int newLength = strlen(rightSide.value);
    if (newLength > maxLength)
    {
        // in our case we have private pointer of an array
        // if the size is not match with the right side
        // set the rightSide's length as the one
        // and then the same procedure
        delete [] value;
        maxLength = newLength;
        value = new char[maxLength + 1];
    }
    // here is just a different of copying all elements 
    for (int i=0; i < newLength; i++) {
        value[i] = rightSide.value[i];
    value[newLength] = '\0';
    }
}
