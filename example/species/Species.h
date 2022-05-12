
#ifndef SPECIES_H
#define SPECIES_H


#include <iostream>
using namespace std;


class Species {
public:
    // default constructor
    Species();

    // customed constructor
    Species(int type, int stage);

    // print type - for redefinition
    void printType(Species s);

    // getter
    int getType();
    int getStage();

    // virtual is under public 
    virtual void eat();

private:
    int type;
    int stage;

protected:
    bool existence;

};

#endif
