
#include "Test.h"


Test::Test() : numerator(0), denominator(1)
{
    // default constructor
}


Test::Test(int n) : denominator(2)
{
    numerator = n;
}


void Test::getNumerator()
{
    cout << numerator << endl;
}



void Test::getDenominator()
{
    cout << denominator << endl;
}
