
#ifndef STRINGVAR_H
#define STRINGVAR_H


#include <iostream>
using namespace std;


class StringVar {
public:
    
    // default constructor
    StringVar();

    StringVar(int size);

    StringVar(const char a[]);

    // copy constructor
    StringVar(const StringVar& stringObject);

    // Destructor
    ~StringVar();

    // length of the current string value
    int length() const;

    // take string input
    void inputLine(istream& ins);

    // overload insertion operator with friend function
    friend ostream& operator <<(ostream& outs, const StringVar& theString);

    // assignment operator overload
    void operator =(const StringVar& rightSide);

private:
    char* value;
    int maxLength;

};

#endif
