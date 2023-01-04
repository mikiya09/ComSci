
#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>
using namespace std;



class Operation {
public:

    // default constructor
    Operation();

    // custom constructor
    Operation(int count);

    // getter
    int getCount();
    
    // (no overload): 
    // friend Operation add(const Operation& o1, const Operation& o2);
    friend Operation operator +(const Operation& o1, const Operation& o2);

    friend Operation operator -(const Operation& o1, const Operation& o2);

    friend Operation operator *(const Operation& o1, const Operation& o2);

    friend Operation operator /(const Operation& o1, const Operation& o2);

    // unary overload
    friend Operation operator -(const Operation& o);

    friend bool operator >(const Operation& o1, const Operation& o2);

    // insertion
    friend istream& operator >>(istream& ins, Operation& o);

    // extraction, have here because output cannot be modified
    friend ostream& operator <<(ostream& outs, const Operation& o);

private:
    int count;
};


#endif

