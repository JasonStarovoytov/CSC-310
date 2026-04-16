#include "binomial.h"

int main() {
    BinomialHeap bh;
    bh.insert(10);
    bh.insert(20);
    bh.insert(5);
    bh.insert(30);
    bh.insert(1);
    bh.insert(14);
    bh.insert(27);
    bh.insert(8);
    bh.insert(3);
    bh.insert(12);
    
    cout << "Heap after insertions:" << endl;
    bh.printHeap();
    

    bh.deleteMin();
    cout << "Heap after deleting minimum:" << endl;
    bh.printHeap();
    cout << "Heap after deleting 5:" << endl;
    bh.deleteKey(5);
    bh.printHeap();
    return 0;
}