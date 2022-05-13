

#include <string>
#include <iostream>
using namespace std;


template<class T>
void swapValues(T& variable1, T& variable2)
{
    T temp;
    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}


int main() 
{
    int num_a = 5, num_b = 3;
    char letter_a = 'a', letter_b = 'b';

    cout << "-num-" << endl;
    cout << "a: " << num_a << " b: " << num_b << endl;
    cout << "-letter-" << endl;
    cout << "a: " << letter_a << " b: " << letter_b << endl;


    swapValues(num_a, num_b);
    swapValues(letter_a, letter_b);
    cout << "===========================" << endl;

    cout << "-num-" << endl;
    cout << "a: " << num_a << " b: " << num_b << endl;
    cout << "-letter-" << endl;
    cout << "a: " << letter_a << " b: " << letter_b << endl;


    return 0;

}
