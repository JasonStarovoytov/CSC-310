This is my implementation of the DSW tree described in the assignment:

The only new method added was a subtreeSize() function
what this does is find the amount of nodes in the subtree,
and it is used in the vine function to check if it should
be rotated. 

Other than that new function, some other functions were
modified, but it was just a little bit of logic.

Here are the public functions that are useful for a user
if they were to try to use this DSW:

BST() ---> to create the DSW tree

deleteTree(node) ---> helps delete the tree

insert(value) ---> inserts the 'value' into the proper spot in the tree

dswBalance() ---> balances the tree by creating a left skewed vine with small
                  subtrees, and then balances the tree with an algorithm similar
                  to the standard DSW algorithm.

display() ---> displays the tree, with the root being on the left, and the tree
               grows to the right (leaf nodes on the right)

enjoy :)