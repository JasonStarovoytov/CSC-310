This is my implementation of binomial heaps!!

Meet the team:

insert(key) --> as the name suggests, it inserts a node into the tree and cleans it up afterwards

merge(heap) --> merge two heaps together in O(logn) time!

findMin() ----> returns the minimum value from the heap

<---- and now for the new methods ---->

deleteMin() --> deletes the minimum value from the tree and returns the true if successful

decreaseKey(oldKey, newKey) --> replaces the value of the oldKey with the newKey, then 
                                brings it up to the right spot in the tree

deleteKey(key) --> finds the key in the heap, decrease key to -infinity, then deleteMin



I hope you have 'heaps' of fun going over my implementation!  :D




How do binomial heaps improve the efficiency of merge operations compared 
to binary heaps?

binary heaps merge in O(n) time, since it has to go through every node. This is not true for 
binomial heaps. Since it is a binomial heap, it is a heap of a bunch of binomial trees. It is
possible to merge them really fast since they resemble binary, and you only have to worry about
the roots of the subtrees.


Explain the time complexity of various operations in binomial heaps.

insert: O(1) since it just adds it to the tree as its own subtree. This is amortized since it has
        to merge the trees as well, so it is actually O(logn)

deleteMin: O(logn) since it has to go through all of the roots of the subtrees, and there are logn of them.

findMin: O(logn) for the same reasons as above.


Why do we use the left-child right-sibling representation in binomial heaps 
instead of traditional tree structures? How does it help with efficiency? 

We use this representation rather than regular tree structures because it would just get too complicated
over time. If every tree had so many pointers to children nodes, it would just be a hastle to do anything.
That is why we use l-c and r-s pointers. It uses a lot less pointers, so each node takes up less space. This
representation basically allows us to use linked lists, and everyone knows how to use those.


What is your opinion on this 
https://ieeexplore.ieee.org/abstract/document/7275881 

I thought was an interesting paper for sure. It is cool to see where data structures are used in the wild,
and how much they can affect the outcome of a program. In this case, I do not think that the memory will
change a lot, since both types of nodes have 3 pointers. While more testing does have to take place, I think
it is a good idea to look into binomial trees. Over the course of this project, I have seen how useful they
can be, and this paper just proves how much faster they are. 