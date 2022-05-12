
#include "Species.h"
#include "Human.h"

int main() {

    Species s;
    s.printType(s);
    // virtual
    s.eat();
    cout << "==========" << endl;

    Human h, h2("bird");
    cout << h2.getName() << endl;

    // call parent's function
    cout << h2.getType() << endl;
    cout << h2.getStage() << endl;

    // redefintion
    h2.printType(s);
    // virtual
    h2.eat();
    return 0;

}
