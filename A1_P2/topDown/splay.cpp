#include "Includes/splay.h"
#include "customErrorClass.h"

SplayTree::SplayTree() 
{
    root = nullptr; 
}

// aka Zig
SplayTree::Node* SplayTree::rotateRight(Node* x) {
    swaps++;
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// aka Zag
SplayTree::Node* SplayTree::rotateLeft(Node* x) {
    swaps++;
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

SplayTree::Node* SplayTree::splay(Node* root, int key) {
    if (root == nullptr || root->key == key)
        return root;

    if (key < root->key) {
        if (root->left == nullptr)
            return root;

        // Zig-Zig
        if (key < root->left->key) {
            root->left->left = splay(root->left->left, key);
            root = rotateRight(root);
        }
        // Zig-Zag
        else if (key > root->left->key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != nullptr)
                root->left = rotateLeft(root->left);
        }

        if(root->left == nullptr)
            return root;
        else
            return rotateRight(root);
    } 
    else {
        if (root->right == nullptr) return root;

        // Zag-Zag
        if (key > root->right->key) {
            root->right->right = splay(root->right->right, key);
            root = rotateLeft(root);
        }
        // Zag-Zig
        else if (key < root->right->key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != nullptr)
                root->right = rotateRight(root->right);
        }

        if(root->right == nullptr)
            return root;
        else
            return rotateLeft(root);
    }
}

SplayTree::Node* SplayTree::insertNode(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    root = splay(root, key);

    if (root->key == key)
        return root;

    Node* newNode = new Node(key);

    if (key < root->key) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = nullptr;
    } else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = nullptr; 
    }

    return newNode;
}


SplayTree::Node* SplayTree::deleteNode(Node* root, int key) {
    if(root == nullptr)
        throw MyException("Tree is empty");

    root = splay(root, key);

    Node* tmp;
    Node* deleteMe = root;
    Node* leftTree = root->left;
    Node* rightTree = root->right;

    if(root->key == key){
        if(leftTree != nullptr && rightTree != nullptr){
            tmp = leftTree;
            while(tmp->right != nullptr)
                tmp = tmp->right;
            
            root = leftTree;

            root = splay(root, tmp->key);

            root->right = rightTree;
        }else{
            if(leftTree != nullptr)
                root = leftTree;
            else
                root = rightTree;

        }
    }else{
        cout << "value is not in the tree";
        return root;
    }

}


void SplayTree::insert(int key) {
    root = insertNode(root, key);
}


void SplayTree::remove(int key) {
    root = deleteNode(root, key);
}


bool SplayTree::search(int key) {
    root = splay(root, key);
    //cout << root->key;
    return (root && root->key == key);
}


void SplayTree::printTree(Node* root, int space) {
    const int COUNT = 5; 

    if (root == nullptr) {
        return;
    }

    // Increase the distance between levels
    space += COUNT;

    // Print the right child first (to appear on top)
    printTree(root->right, space);

    // Print the current node after right child

    for (int i = COUNT; i < space; i++) {
        cout << " "; // Indentation for tree depth
    }
    cout << root->key << endl;

    // Print the left child
    printTree(root->left, space);
}

void SplayTree::display() {
    printTree(root, 0);
    cout << endl;
}
