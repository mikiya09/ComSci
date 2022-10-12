

#include "Operation.h"


int main() {

    Operation o1, o2(14), o3;
    o3 = o1 + o2;
    Operation o4 = o1 - o2;
    // ============== not overload << and >> ============
    // cout << o3.getCount() << endl;
    // cout << o4.getCount() << endl;
    // cout << o5.getCount() << endl;
    // cout << -o5.getCount() << endl;
    // cout << o6.getCount() << endl;
    // cout << (o3.getCount() > o5.getCount()) << endl;
    // ============== not overload << and >> ============

    Operation o5, o6;
    cout << "enter for o5: ";
    cin >> o5;

    cout << "enter for o6: ";
    cin >> o6;

    cout << "o3: " << o3 << endl;
    cout << "o4: " << o4 << endl;
    cout << "o5: " << o5 << endl;
    cout << "o6: " << o6 << endl;
}
