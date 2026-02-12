#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <iostream>
using namespace std;

class SplayTree {
    private:
        struct Node {
            int key;
            int weight;
            Node* left;
            Node* right;
            Node(int k) {
                key = k;
                weight = 0;
                left = nullptr;
                right = nullptr; 
            }
        };

        Node* root;

        Node* rotateRight(Node* x);
        Node* rotateLeft(Node* x);
        Node* splay(Node* root, int key);
        Node* insertNode(Node* root, int key);
        Node* deleteNode(Node* root, int key);

        void printTree(Node* root, int space);

    public:
        int swaps = 0;
        SplayTree();
        void insert(int key);
        void remove(int key);
        bool search(int key);
        void display();
};

#endif 
