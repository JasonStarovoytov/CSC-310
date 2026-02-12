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

    cout << tree.search(44) << endl;
    cout << "Tree after splaying 40: " << endl;
    tree.display();

    tree.remove(31);
    cout << "Tree after deleting 30: " << endl;
    tree.display();

    cout << tree.search(72) << endl;
    cout << "Tree after splaying 70: " << endl;
    tree.display();

    cout << tree.search(72) << endl;
    cout << "Tree after splaying 70: " << endl;
    tree.display();

    cout << tree.search(72) << endl;
    cout << "Tree after splaying 70: " << endl;
    tree.display();

    cout << tree.search(44) << endl;
    cout << "Tree after splaying 40: " << endl;
    tree.display();

    return 0;
}
