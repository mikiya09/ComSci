
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


// setting ItemType as an alias for char 
typedef char ItemType;

// stuct a node 
struct TreeNode;


// class specification 
class TreeType {
public:
    // constructor
    TreeType();
    // custom constructor 
    TreeType(const TreeType& originalTree);
    
    // check if the tree is empty
    bool IsEmpty() const;
    // check if there are still memory for adding
    bool IsFull() const;
    // return the length of the tree, how many nodes are there in the tree
    int GetLength() const;
    // define my own, I don't wanna use bool = false/true for searching
    ItemType GetItem(ItemType& item, bool& found);
    // Insert nodes into the tree 
    void PutItem(ItemType item);
    // delete nodes from the tree
    void DeleteItem(ItemType item);
    // clean up all the nodes in the tree 
    void MakeEmpty();
    // display tree
    void Print() const;

    // check if the BST properties is maintained
    bool IsBST();
    // delete the root, the very top node of the tree and maintain the BST properties
    void DeleteRoot();
    // delete the smallest node, and main the BST properties 
    void DeleteSmallest();
    // return leaf value 
    // vector<ItemType> GetNodes();
    ItemType* GetNodes();

    // destructor
    ~TreeType();

private:
    TreeNode* root;
};


