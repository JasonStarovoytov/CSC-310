#include <iostream>
#include "bst.h"

int main(){

    bst tree;

    tree.insert(7);
    tree.insert(5);
    tree.insert(6);
    tree.insert(4);
    tree.insert(9);
    tree.insert(8);
    tree.insert(20);
    tree.insert(20);
    tree.insert(10);
    tree.insert(15);





    tree.printBST();

    tree.remove(5);
    tree.remove(9);
    tree.remove(7);
    tree.remove(6);
    tree.remove(4);
    tree.printBST();

    cout << tree.isBalanced() << endl;

    return 0;
}