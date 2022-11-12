


# Recursion
```
A function calls itself in order to divide work into smaller portions

1) base case:               when the program stops
2) general case:            how should the program calls itself
3) recursive algorithm:     an algorithm described in terms of base cases and general cases
```
### Ex). Factorial Code
```
recursive definition:
---------------------
> n! = 1 if n = 0;
> n! = n * (n-1)! if n > 0
-> 4! = 4*3! = 4*3*2! = 4*3*2*1! = 4*3*2*1*0! = 4*3*2*1*1 = 24
```
**code**
```
// Iterative solution 
int Factorial(int number) {
    int fact = 1;
    for (int count = 2; count <= number; count ++) {
        fact = fact * count;
    }
    return fact;
}

// Recursive solution 
int Factorial(int number) {
    if (number == 0)            // Base Case
    {
        return 1;
    }
    else                        // General Case 
    {
        return number * Factorial(number-1);
    }
}
```
*1) iterative solution uses a looping construct (for loop)* <br>
*2) recursive solution uses a **branching** construct (the if-else statement)*


### Verifying Recursive Functions
#### [+] method 1: walking through the whole execution --> tedious but useful
#### [+] method 2: Three-Question Method
##### • Base-Case Question
*Is there a non-recursive case in the method, and does it work correctly?*
##### • Smaller-Caller Question 
*Does each recursive call involve a smaller case of the problem*
##### • General-Case Question
*Assuming the recursive calls work correctly, does the rest of the function work correctly?*
#### [+] Analysis Recursion
*Ex 1). Factorial*
```
1) base-case question: 
    > the base case occurs when n=1
    > and it returns 1 with no further recursion
2) smaller-caller question:
    > each recursive call subtract 1 from n
    > which will eventually reach 0
3) general-case question:
    > assuming factorial (n-1) returns the correct answer
    > n * factorial(n-1) corresponds with the mathematical formula
```
#### [+] Design Recursion 1
*Ex 2). Searching in a List*
```
Q: Check if a particular value is in a list?

1) base-case one:
    > the item is at the given index, return true
    x the item is at the given index, return true: because item can also not in the list
2) base-case two:
    > the end of the list has been reached (index == length -1), return false
3) general-case:
    > the item is in the rest of the list, recursively call itself

----------------------------------------------------------------------------------------
// list a abstract data type here
bool ValueInList(ListType list, int value, int startIndex)
{
    if (list.info[startIndex] == value) {
        return true;                                        // base case 1
    }
    else if (startIndex == list.length - 1) {               // base case 2
        return false;
    }
    else {
        return ValueInList(list, value, startIndex+1);
    }
}
```
#### [+] Design Recursion 2
```
Q: How many combinations of 5 books can be made from a group of 20 books? (n choose k)
Size: size of the group (n) and number of members in each group (k)

1) base-case:
    > if members == 1, return group
    > if members == group, return 1
2) general-case:
    > return combinations (group-1, members-1) + combinations (group-1, members)

----------------------------------------------------------------------------------------
int Combinations(int group, int members)
{
    if (members == 1) {
        return group;
    }
    else if (members == group) {
        return 1;
    }
    else {
        return (Combinations(group-1, members-1) + Combinations(group-1, members));
    }
}
```

<img src="./pic/Combinations.png" width=500>

#### [+] Recursive Binary Search 
```
• pseudocode

FUNCTION binary_search(array, start, end, x) 

WHILE start < end Do 
            
            mid:= (start + end) / 2 

            IF x == array[mid] THEN 
                RETURN mid 

            ELSE IF x > array[mid] THEN 
                RETURN binary_search(array, mid+1, end, x)

            ELSE RETURN binary_search(array, start, mid-1, x)

    END WHILE 
END FUNCTION
```


### How Recursion Works? 

#### [+] Binding 
```
associating a memory address with a variable name
```
##### &#x23f5; Static Binding 
*occurs at compile time*
```
1) When a program is compiled, each variable is entered into a symbol table and bound to a memory address
                                                               ------------
2) Each reference to the variable name is replaced by the memory address
        ---------                                         --------------
3) Function parameters and local variables are also bound to memory addresses at this time
   -------------------     ---------------      
```
*Symbol Table*
```
Three variables are declared: int a, b, c -> The compiler binds them in the symbol table:
                            ---------------------------
                            |   Symbol      Address   |
                            |     a           0001    |
                            |     b           0002    |
                            |     c           0003    |
                            ---------------------------
                            A statement such as: a = b + c 
    -> "get value started at 0002, get the value stored at 0003, store the sum in 0001" (assembly language)
```

<img src="./pic/staticBinding.png">

*issues*
```
1) each parameter and local variable has a single, fixed memory address associated with it
*2) a recursive function call would overwrite the variables of the previous call
*3) each recursive call needs memory to store its own variables
4) Therefore, langauges that only have static storage allocation cannot support recursion
```

##### &#x23f5; Dynamic Binding
*occurs at run time*
```
1) Variable names are bound to memory addresses at run time
                                                -----------
2) The compiler references variables by their offsets instead of by exact addresses. 
    + The correct addresses are calculated during execution using these offsets.
                                                                        ---------> 偏移量
3) variables and parameters for function stored in the Activation Record
                                                       -----------------
```
# Binary Search Tree (BST)

### [incorrect way of thinking BST](https://www.enjoyalgorithms.com/blog/validate-binary-search-tree)

### BST properties 
**code[[1]](./advanced/BST/TreeType.h)[[2]](./advanced/BST/TreeType.cpp)[[3]](./advanced/BST/main.cpp)** 
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

====================================== algorithm walk through ============================================
• checkBST function will end when reach the bottom line, no iteration inside, no "loop" inside
• code is executed one line by one line, from top to down


                                    [ complete binary tree ]

                                                e
                     down to up ^             /   \
                                |            c     g
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


# Heap

# Hash
