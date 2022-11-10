
#include "TreeType.h"
using namespace std;


int main() 
{
    TreeType t1, t2;
    ItemType e='e', g='g', f='f', c='c', a='a', d='d', z='z';
    // declare a found variable for checking if certain nodes is found
    bool found = false;

    // insert new nodes into the BST t1
    t1.PutItem(c);
    t1.PutItem(g);
    t1.PutItem(f);

    // insert new nodes into the BST t2
    t2.PutItem(e);
    t2.PutItem(g);
    t2.PutItem(f);
    t2.PutItem(c);
    t2.PutItem(a);
    t2.PutItem(d);
    t2.PutItem(z);

    // check if the BST properties is maintained
    cout << "======== Check Member Function ========" << endl;
    cout << "check IsBST() for t1: " << t1.IsBST() << endl;
    cout << "check IsBST() for t2: " << t2.IsBST() << endl;
    cout << endl;
    cout << "check IsEmpty() for t1: " << t1.IsEmpty() << endl;
    cout << "check IsEmpty() for t2: " << t2.IsEmpty() << endl;
    cout << endl;
    cout << "check IsFull() for t1: " << t1.IsFull() << endl;
    cout << "check IsFull() for t2: " << t2.IsFull() << endl;

    // check if certain item is in the tree
    t2.GetItem(z, found);
    cout << "get item for 'a', found? " << found << endl;

    // in order to return an array, we return a pointer of an array
    ItemType* ptr1 = t1.GetNodes();
    ItemType* ptr2 = t2.GetNodes();
    cout << "all leaf nodes for t1: " << ptr1 << endl;
    cout << "all leaf nodes for t2: " << ptr2 << endl;
    cout << endl;
    cout << "root for t1: " << c << endl;
    cout << "root for t2: " << e << endl;

    // delete the pointer after using them
    delete ptr1;
    delete ptr2;
    cout << endl;

    // display the original tree both for t1 and t2
    cout << "======== Original Tree ========" << endl;
    cout << "[t1]\nlength: " << t1.GetLength() << endl;
    t1.Print();
    cout << endl;
    cout << "[t2]\nlength: " << t2.GetLength() << endl;
    t2.Print();
    cout << endl;
    
    // deleting the root, and display 
    cout << "======== After Deleting Root ========" << endl;
    cout << "[t1]" << endl;
    t1.DeleteRoot();
    cout << "length: " << t1.GetLength() << endl;
    t1.Print();
    cout << endl;

    cout << "[t2]" << endl;
    t2.DeleteRoot();
    cout << "length: " << t2.GetLength() << endl;
    t2.Print();
    cout << endl;

    // deleting the smallest nodes and display
    cout << "======== After Deleting Smallest ========" << endl;
    cout << "[t1]" << endl;
    t1.DeleteSmallest();
    cout << "length: " << t1.GetLength() << endl;
    t1.Print();
    cout << endl;

    cout << "[t2]" << endl;
    t2.DeleteSmallest();
    cout << "length: " << t2.GetLength() << endl;
    t2.Print();
    cout << endl;

    return 0;
}


