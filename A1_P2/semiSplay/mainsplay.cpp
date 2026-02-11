#include "Includes/splay.h"

int main() {
    SplayTree tree;

    tree.insert(57);
    tree.insert(31);
    tree.insert(72);
    tree.insert(44);
    tree.insert(69);
    tree.insert(83);

    cout << "Tree after insertions: " << endl;
    tree.display();

    cout << "___________________" << endl;
    tree.semiSplay(31, 2);
    tree.display();

    cout << "___________________" << endl;
    tree.semiSplay(69, 10);
    tree.display();


    return 0;
}
