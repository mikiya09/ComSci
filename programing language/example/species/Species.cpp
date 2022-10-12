

#include "Species.h"

Species::Species() : type(0), stage(0)
{
    //
}


Species::Species(int type, int stage) 
{
    if (type >= 0) {
        this->type = type;
    }

    this->stage = stage;
}

// testing for redefinition that takes same paraemter list
void Species::printType(Species s)
{
    cout << "TYPE: " << s.type << " STAGE: " << s.stage << endl;
}


// getter
int Species::getType()
{
    return type;
}


int Species::getStage()
{
    return stage;
}


// implementation of virtual function
// you don't need the keyword virtual here
void Species::eat()
{
    cout << "could possibly eat anything" << endl;
}

