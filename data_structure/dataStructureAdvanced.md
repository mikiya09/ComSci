


# Recursion

### base case 
### general case
### recursive algorithm



# Binary Search Tree (BST)

### BST properties 
#### check 
```
// recursively comparing the current with the previous one
// recursion make the checking start from the leaf, so prevNode refer to smaller one (if BST)
bool checkBST(TreeNode* tree, ItemType& prevNode)
{
    if (tree == NULL) {
        return true;
    }
    bool left = checkBST(tree->left, prevNode);
    if (prevNode && tree->info < prevNode) {
        return false;
    }

    prevNode = tree->info;
    bool right = checkBST(tree->right, prevNode);
    if (left == true && right == true) {
        return true;
    }
    else {
        return false;
    }
}

bool TreeType::IsBST()
{
    ItemType prev = '1';
    return checkBST(root, prev);
}


============================== algorithm walk through ========================================
• checkBST function will end when reach the bottom line, no iteration inside, no "loop" inside
• code is executed one line by one line, from top to down
• use an exmaple 

                            [ complete binary tree ]

                                        e
                        ^             /   \
             down to up |            c     g
                                    / \   / \
                        start -->  a   d f   z 
    
                    
    1) when first time going into the function, root == NULL automatically maintain properties
    2) then meet the recursive call of checkBST(), compiler will finish this line then go down
        > in our example, c as TreeNode and 1 as prevNode will be given into sub call
        > sub call will let c meet if (tree == NULL) first 
        > c is not NULL, and again meet checkBST(), this time a and 1 goes into checkBST()
            > because this time a->left is NULL 
            > so when it first meet if (tree == NULL), the sub function call will return false
            > the recursion stop, and boolean value will be stored into "left" variable
        > process when tree=a, prevNode exist and tree->info is not less than it right now
        > then assign prevNode with current tree info
        > then check recursively on the right side, checkBST(tree->right, prevNode);
            > because a is already a leaf, so right==NULL, "right" will also return true
            > first left recursion return true, on the c level "left=checkBST()" evaluate to true
        > continue on c, prevNode was a previously, now assign c to it
            > again meet checkBST() for right child, in this case is d
            > because d doesn't have child, left = true, and prevNode will be assigned with d
            > why? because item at d's position is greater than c by BST property
            > we are checking the tree in order (small->large)
            > since d is leaf node, so that "right" evaluate to true
        > finish checking the right child of c, go back to root node e
    3) same process as those in the sub tree, e is graeter than d, so property no violated
    4) prevNode is assigned with e right now, and start checking for the right subtree
    5) each time goes into checkBST(), all the process will be done again
        > ...
            > ....
        > ...
    6) at e level, both c and g maintain the property, so the whole tree is BST

```
