

#include <iostream>
using namespace std;


class Test {
public:

    // default constructor: same name with class
    Test();
    // custom constructor
    Test(int n);
     
    // getter 
    void getNumerator();
    void getDenominator();


private:
    int numerator;
    int denominator;
};
    
    
