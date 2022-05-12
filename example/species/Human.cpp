
#include "Human.h"


// constructor is not inherited
Human::Human() : Species(), name("human")
{
    // default constructor
}

// customed constructor
Human::Human(string sName) : Species(3, 5)
{
    name = sName;
}


// getter
string Human::getName()
{
    return name;
}


// redefinition of printType
void Human::printType(Species s)
{
    cout << "TYPE: " << s.getType() << " STAGE: " << s.getStage() 
         << " NAME: " << name << " EXISTENCE: " << existence << endl;
}

// virutal function
void Human::eat()
{
    cout << "eat fast food" << endl;
}


