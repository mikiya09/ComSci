
#include "stringVar.h"
#include <iostream>
using namespace std;


// carries on a conversation with the user
void conversation(int maxNameSize);

int main()
{
    StringVar line(20);
    cout << "Enter a string of length 20 or less" << endl;
    line.inputLine(cin);

    // initialized by the copy constructor
    StringVar temp(line);
    cout << temp << endl;

    conversation(30);
    cout << "End of demonstration" << endl;
    return 0;
}


void conversation(int maxNameSize)
{
    StringVar yourName(maxNameSize), myName("the student");

    cout << "What is your name" << endl;
    yourName.inputLine(cin);
    cout << "I am " << myName << '.' << endl;
    cout << "We will meet again, " << yourName << '.' << endl;
}
