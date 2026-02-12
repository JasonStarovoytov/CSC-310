#include "Includes/splay.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
    SplayTree tree;

    // tree.insert(57);
    // tree.insert(31);
    // tree.insert(72);
    // tree.insert(44);
    // tree.insert(69);
    // tree.insert(83);

    // cout << "Tree after insertions: " << endl;
    // tree.display();

    // cout << tree.search(44) << endl;
    // cout << "Tree after splaying 40: " << endl;
    // tree.display();

    // tree.remove(31);
    // cout << "Tree after deleting 30: " << endl;
    // tree.display();

    ifstream file("../accessPattern/zipf_skewed.txt");
    string line;
    if (file.is_open()) {
        int i = 0;
        while (getline(file, line)) {
            if(i < 100000)
                tree.insert(stoi(line));
            else{
                tree.search(stoi(line));
            }
            i++;
        }
        file.close();
    } else {
        cout << "Unable to open file";
    }

    cout << "Swaps: " << tree.swaps << endl;
    cout << "Avg. depth: " << tree.swaps / 100000 << endl;

    return 0;
}
