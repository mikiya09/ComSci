
#include "Operation.h"

Operation::Operation() : count(1)
{
    // default constructor
}

Operation::Operation(int newCount)
{
    // custom constructor
    count = newCount;
}

// getter
int Operation::getCount()
{
    return count;
}

// friend function, overloading addition operator
// return Operation class object
Operation operator +(const Operation& o1, const Operation& o2)
{
    Operation temp;

    temp.count = o1.count + o2.count;
    return temp;
}


// overload division
// since I declare temp as int, 
// therefore if fraction gets, 0 might be expected
Operation operator /(const Operation& o1, const Operation& o2)
{
    Operation temp;

    temp.count = o1.count / o2.count;
    return temp;
}


// unary overload
Operation operator -(const Operation& o)
{
    Operation temp;

    temp.count = -o.count;
    return temp;
}

bool operator >(const Operation& o1, const Operation& o2)
{
    return o1.count > o2.count;
}


// insertion operator overload
istream& operator >>(istream& ins, Operation& o)
{
    int temp;
    ins >> temp;

    if(temp < 5) {
        o.count = temp + 5;
    } 
    else
    {
        o.count = temp - 5;
    }

    return ins;
}


// extraction operator overload
ostream& operator <<(ostream& outs, const Operation& o)
{
    outs << o.count;

    return outs;
}
