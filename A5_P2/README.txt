This program is my implementation of different heaps and different unions with 
a goal of having a fast implementation of kruskals algorithm.

Here are the functions that I had to implement:

QuickUnion:
    union(int a, int b) --> links together 2 different nodes.
    find(int a) --> finds the root of the subtree that the node 'a' is in

UnionFind (with path compression and ranks):
    union(int a, int b) --> same as QuickUnion, but smaller ranks become children of larger ones
    find(int a) --> same as QuickUnion, but path compression makes intermediate nodes 
                    point to the root.


MST:
    kruskalV1() --> this uses binary heaps and QuickUnion to run kruskals algorithm
    kruskalV2() --> this uses binomial heaps and UnionFind to run kruskals algorithm


A makefile is provided at your leasure, use it wisely ;P

Below are the results of my program:

=== Small Graph Test ===
Running Baseline MST...
Heap is empty!
MST Cost: 14
Time taken: 4.22e-06 seconds

Running Optimized MST...
MST Cost: 14
Time taken: 4.466e-06 seconds

=== Large Graph Test (100000 nodes, 500000 edges) ===
Running Baseline MST...
Heap is empty!
MST Cost: 3750795
Time taken: 21.5388 seconds

Running Optimized MST...
MST Cost: 3750795
Time taken: 0.494669 seconds



Task 8:

The binomial heap makes the program faster due to the fact the the time complexity
is O(1) [ammortized], the other operations are close to the same complexity. findMin()
is not the same, but insertions happen a lot, so it makes up for that fact.

I think the path compression is what made the union so fast. Rather than going up every node
to find the root, compress all the nodes in that path to make them point to the root. find()
runs very often, so path compression helps a lot.

V1 time complexity I think is O(NlogN + N^2) due to insertions and deletions, and due to the
fact that find() does not have any path compression.
V2 time complexity I think is O(NlogN) because of findMin() and deletions. Since the union 
has ranks and path compression, it makes it a lot faster.