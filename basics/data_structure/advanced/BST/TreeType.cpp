
#include "TreeType.h"


// define node using struct 
struct TreeNode
{
    ItemType info;
    TreeNode* left;
    TreeNode* right;
};


// default constructor, setup root point to NULL
TreeType::TreeType()
{
    root = NULL;
}

// custom constructor, taking a TreeType as an input, and set root = input tree's
TreeType::TreeType(const TreeType& originalTree)
{
    root = originalTree.root;
}

// check if the tree is empty, by checking if root == NULL
bool TreeType::IsEmpty() const 
{
    return root == NULL;
}

// check if the there are still memory space for pointer(heap), using bad_alloc()
bool TreeType::IsFull() const 
{
    TreeNode* location;
    try {
        location = new TreeNode;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception) {
        return true;
    }
}


// GetLength()
int countNodes(TreeNode* tree);
// ----------------------------
// call a function that resursively count the root, left and right
int TreeType::GetLength() const 
{
    return countNodes(root);
}
// countNodes
// the number of node in a tree
// the reason of writing GetLength and countNodes seperately might because that 
// member function cannot call themselves during definition, or other reason
int countNodes(TreeNode* tree)
{
    if (tree == NULL) {
        return 0;
    }
    else { 
        // plus 1 because if root != NULL for each check, and it should be counted once
        // then check the left and right
        return countNodes(tree->left) + countNodes(tree->right) + 1;
    }
}



// GetItem()
void Retrieve(TreeNode* tree, ItemType& item, bool& found);
// we pass found here so that we don't need to write repeition code in Retrieve function 
// otherwise we had to check inside Restrieve once, and GetItem once
ItemType TreeType::GetItem(ItemType& item, bool& found)
{
    Retrieve(root, item, found);                            // item is being modified during the calling of Retrieve
    return item;
}
// get item from the tree, given an input(info) check if there are nodes store that value 
// although here we use char as ItemType, but char type in C++ can compare with each in alphabetical order
// the reason we need boolean value found is because there are two siutations exist for GetItem function 
// 1. if found, return found item 
// 2. if not found, we still need to return some item type, then how to make sure we correctly found it?
// solution: passing a global variable, if true as a result then found, otherwise not found
// retrieve function()
// -------------------------------------------
// modify the item that passing into this function,
void Retrieve(TreeNode* tree, ItemType& item, bool& found)
{
    if (tree == NULL) {
        found = false;                                      // modify global variable because pass by reference
    }
    else if (item < tree->info) {
        Retrieve(tree->left, item, found);                  // search left subtree if less then root node(info)
    }
    else if (item > tree->info) {
        Retrieve(tree->right, item, found);                 // search right subtree if greater than root node(info)
    }
    else 
    {
        item = tree->info;                                  // item if found, foudn = true
        found = true;
    }
}

// PutItem()
void Insert(TreeNode*& tree, ItemType item);
// PutItem function: because binary search tree is sorted in order 
// so only need to check node from one by one from the root with the order of: root -> left -> right
// helper function: insert(), not need to modify, so passing by value
// but what is this *&? => see below explanation
// simply call it
void TreeType::PutItem(ItemType item)
{
    Insert(root, item);
}
// Insert()
// ---------------------------------------
// maintain the search property(binary search order), and the item is in the tree
// type* = the variable that store the address of a certain type 
// type*& = the pointer variable also have an address, 
// -- if we pass the address of the pointer we are going to modify this pointer, instead of the type value
// -- when pass TreeNode in the above function(Retrieve), pointer is just for comparison, nothing had been done on it
// -- the pointer will always store the address of that type, address is not changed 
// here we need to modify the address that certain pointers store, because tree TreeNode itself need to be modified
void Insert(TreeNode*& tree, ItemType item)
{
    if (tree == NULL) {             // insertion place found
        tree = new TreeNode;
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    }
    else if (item < tree->info) {
        Insert(tree->left, item);   // insert in left subtree
    }
    else {
        Insert(tree->right, item);  // insert in right subtree
    }
}



// DeleteItem()
// few things need to be secure with delete operation 
// 1. maintain search properties (order) when deleting nodes 
// 2. different method when deleting nodes with different location 
// 3. how to find the predecessor of a node with subtree
// member function only need to call the resursive helper function 
// DeleteNode() 
void DeleteNode(TreeNode*& tree);
// Delete() 
void Delete(TreeNode*& tree, ItemType item);
// GetPredecssor() 
void GetPredecessor(TreeNode* tree, ItemType& data);
// -----------------------------------------------
void TreeType::DeleteItem(ItemType item)
{
    Delete(root, item);
}


// Delete()
// ------------------------------
// every three nodes(left, root, right) form a subtree for searching 
// check if target item is less than, greater than or equal to the any of them 
void Delete(TreeNode*& tree, ItemType item)
{
    if (item < tree->info) {
        Delete(tree->left, item);
    }
    else if (item > tree->info) {
        Delete(tree->right, item);
    }
    else {
        DeleteNode(tree);
    }
}
// DeleteNode()
// ------------------------------
// 1) nodes with only one non-NULL child, use temporary pointer to delete 
// 2) leaf node delete directly(but since inside one function, still need to create tempPtr)
// 3) find the rightmost node in the left subtree, 
// -- replace the value with the target node and call delete() for predecessor
void DeleteNode(TreeNode*& tree)
{
    ItemType data;                          // create data later to store predecessor for replacing
    TreeNode* tempPtr;
    tempPtr = tree;                         // copy the target node's address
                                            // the same as creating a pointer pointing to it (think of listdata)
    if (tree->left == NULL) {
        tree = tree->right;                 // if no left child or no child at all, set current pointer = child(right or null)
        delete tempPtr;                     // remember that the current pointer is either left or right pointer from its parent
    }                                       // since we are passing the address of a pointer with *&, address stored in the 
                                            // pointer could be modified, so we are changing the value store in previous pointer
    else if (tree->right == NULL) {
        tree = tree->left;                  // same for the other side, so same as let the parent pointing to grandchild
        delete tempPtr;                     // and with that we can savely delete tempPtr
    }
    else {
        GetPredecessor(tree->left, data);   // find out the Logical Predecessor, and get the item inside stored in data
        tree->info = data;                  // data is passing by reference, which now storing the predecessor item
                                            // tree is passing by value, so when get out of GetPredecessor() still the target
                                            // store the item from predecessor to the target node, successfully swap
        Delete(tree->left, data);           // Delete predecessor node
    }
}
// GetPredecessor() 
// -------------------------------------------------
// specifically for finding roots with subtrees
// give the left subtree, keeping finding the rightmost node 
void GetPredecessor(TreeNode* tree, ItemType& data)
{
    while (tree->right != NULL) {
        tree = tree->right;
    }
    data = tree->info;
}




// Print()
// first check if the tree has nodes
// cout and outFile they all are instances of ofstream class, in this case we store value into ofstream instance 
// use << for printing them out recursively with the order of: left - root - right
// PrintTree()
// --------------------------------------------------
void PrintTree(TreeNode* tree)
{
    if (tree != NULL)
    {
        PrintTree(tree->left);
        cout << tree->info << endl;
        PrintTree(tree->right);
    }
}
// call it 
void TreeType::Print() const 
{
    PrintTree(root);
}


// ~Destructor()
// call recursively, delete with order of: left - right - root
// Destroy()
// --------------------------
// think of the printing order
void Destroy(TreeNode*& tree)
{
    if (tree != NULL)
    {
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
    }
}
// call it
TreeType::~TreeType()
{
    cout << "Destructor is called\n";
    Destroy(root);
}


// clear up the whole tree
void TreeType::MakeEmpty() 
{
    Destroy(root);
    root = NULL;
}



// question 2
// bool checkBST(TreeNode* tree, ItemType& prev)
// {
//     if (tree) {
//         if (!checkBST(tree->left, prev))
//             return false;
//         
//         if (tree->info < prev)
//             return false;
//
//         prev = tree->info;
//
//         return checkBST(tree->right, prev);
//     }
//     return true;
// }


// recursively check the nodes while recording the previous node
// since this is recursion, so it starts from bottom to top 
// the pervious node we refer to is the smaller one if the BST properties maintain
bool checkBST(TreeNode* tree, ItemType& prevNode)
{
    if (tree == NULL) {
        return true;
    }
    bool left = checkBST(tree->left, prevNode);         // first check all the way to left bottom
    if (prevNode && tree->info < prevNode) {            // make sure BST properties maintain
        return false;                                   // otherwise return false
    }
    prevNode = tree->info;                              // update the nodes
    bool right = checkBST(tree->right, prevNode);       // for each left recursion, check the right as well
    if (left == true && right == true) {                // if both subtree maintain properties 
        return true;                                    // then the whole tree maintain
    }
    else {
        return false;                                   // otherwise false
    }


}

bool TreeType::IsBST()
{
    ItemType prev = '1';
    return checkBST(root, prev);
}



// question 3
// delete root 
void TreeType::DeleteRoot()
{
    Delete(root, root->info);
}



void findLeaf(TreeNode* tree, vector<ItemType>& leaf)
{
    if (!tree) {
        // do nothing
    }
    // when value = NULL is the same as saying false
    // when left and right node both has NULL value, then the ! make condition true
    if (!tree->left && !tree->right) {
        // cout << tree->info << " ";
        leaf.push_back(tree->info);
    }

    // if left child exist, continue search down
    if (tree->left)
        findLeaf(tree->left, leaf);

    // if right child exist, continue search down
    if (tree->right)
        findLeaf(tree->right, leaf);
}



// question 4 
void TreeType::DeleteSmallest()
{
    vector<ItemType> vect;
    findLeaf(root, vect);
    Delete(root, vect[0]);
}


// question 5

// method 1
ItemType* TreeType::GetNodes()
{
    vector<ItemType> vect;
    ItemType* itemPtr = new ItemType;
    findLeaf(root, vect);
    // cout << vect.size() << endl;
    // cout << vect[0] << " " << vect[1] << " " << vect[2] << " " << vect[3] << endl;
    for (int i=0; i<vect.size(); i++) {
        itemPtr[i] = vect[i];
    }

    return itemPtr;
}

// method 2
