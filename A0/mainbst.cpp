#include <iostream>
#include "includes/bst.h"

int main(){

    // bst tree;

    // tree.insert(7);
    // tree.insert(5);
    // tree.insert(6);
    // tree.insert(4);
    // tree.insert(9);
    // tree.insert(8);
    // tree.insert(20);
    // tree.insert(20);
    // tree.insert(10);
    // tree.insert(15);





    // tree.printBST();

    // tree.remove(5);
    // tree.remove(9);
    // tree.remove(7);
    // tree.remove(6);
    // tree.remove(4);
    // tree.printBST();

    // cout << tree.isBalanced() << endl;


    // delete root
    bst test1;
    test1.insert(10);
    test1.printBST();
    test1.remove(10);
    test1.printBST();

    // delete value not in list
    bst test2;
    test2.printBST();
    test2.remove(10);
    test2.printBST();


    // delete root with 2 children
    bst test3;
    test3.insert(10);
    test3.insert(5);
    test3.insert(20);
    test3.printBST();
    test3.remove(10);
    test3.printBST();


    // delete left and right child
    bst test4;
    test4.insert(10);
    test4.insert(5);
    test4.insert(20);
    test4.printBST();
    test4.remove(5);
    test4.remove(20);

    test4.printBST();

    // delete root with only one child
    bst test5;
    test5.insert(10);
    test5.insert(5);
    test5.printBST();
    test5.remove(10);
    test5.printBST();


    test5.insert(20);
    test5.printBST();
    test5.remove(20);

    test5.printBST();

    
    // delete root right subtree
    bst test6;
    test6.insert(10);
    test6.insert(20);
    test6.insert(25);
    test6.insert(15);
    test6.printBST();
    test6.remove(10);
    test6.printBST();


    // delete node in right subtree
    bst test7;
    test7.insert(10);
    test7.insert(20);
    test7.insert(25);
    test7.insert(15);
    test7.printBST();
    test7.remove(20);
    test7.printBST();
    
    

    return 0;
}