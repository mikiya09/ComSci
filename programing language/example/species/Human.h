
#ifndef HUMAN_H
#define HUMAN_H

#include "Species.h"    // iostream has already been include
#include <string>

// derived class from species
class Human : public Species {
public:

    // derived class default constructor
    Human();

    // custom constructor
    Human(string sName);

    // getter
    string getName(); 

    // redefinition
    void printType(Species s);

    // virtual function from base class
    // you don't have to include keyword virtual here, but better do for clarity
    virtual void eat();

private:
    string name;
};


#endif
