#include "Includes/splay.h"
#include "customErrorClass.h"


SplayTree::SplayTree() 
{
    root = nullptr; 
}

// aka Zig
SplayTree::Node* SplayTree::rotateRight(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    //-------------------
    if(y->right)
        y->right->parent = x;

    y->parent = x->parent;

    if(x->parent){
        if(x->parent->left == x){
            x->parent->left = y;
        }else{
            x->parent->right = y;
        }
    }
    
    //-------------------
    y->right = x;

    //-------------------
    x->parent = y;
    //-------------------

    return y;
}

// aka Zag
SplayTree::Node* SplayTree::rotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left;

    //-------------------
    if(y->left)
        y->left->parent = x;

    y->parent = x->parent;

    if(x->parent){
        if(x->parent->left == x){
            x->parent->left = y;
        }else{
            x->parent->right = y;
        }
    }
    
    //-------------------
    y->left = x;

    //-------------------
    x->parent = y;
    //-------------------
    return y;
}

// Splaying :)
// Bottom up
SplayTree:: Node* SplayTree::splay(Node* x) {
    if(!x)
        return x;

    while(x->parent != nullptr){
        Node* p = x->parent;
        Node* g = p->parent;

        if(!g){     // parent is the root
            if(p->left == x)
                rotateRight(p);
            else
                rotateLeft(p);
        }

        // zig-zig or zag-zag

        else if(g->left == p && p->left == x){
            rotateRight(g);
            rotateRight(p);
        }else if(g->right == p && p->right == x){
            rotateLeft(g);
            rotateLeft(p);
        }

        // zig-zag or zag-zig

        else if(g->left == p && p->right == x){
            rotateLeft(p);
            rotateRight(g);
        }else if(g->right == p && p->left == x){
            rotateRight(p);
            rotateLeft(g);

        }

    }

    root = x;
    return x;
}


SplayTree:: Node* SplayTree::insertNode(int key) {
    if(!root){
        root = new Node(key);
        return root;
    }

    Node* curr = root;
    Node* parent = nullptr;

    while(curr){
        parent = curr;

        if(key == curr->key){
            throw MyException("Cannot add duplicate values");
        }

        if(key < curr->key){
            curr = curr->left;
        }else{
            curr = curr->right;
        }
    }

    Node* n = new Node(key);
    n->parent = parent;

    if(key < parent->key){
        parent->left = n;
    }else{
        parent->right = n;
    }

    splay(n);

}


SplayTree::Node* SplayTree::deleteNode( int key) {
    Node* tmp = root;

    while(tmp != nullptr){
        if(key < tmp->key)
            tmp = tmp->left;
        else if(key > tmp->key)
            tmp = tmp->right;
        else
            break;

    }

    splay(tmp);

    Node* tmpDelete = root;

    Node* leftTree = root->left;
    Node* rightTree = root->right;

    if(leftTree != nullptr && rightTree != nullptr){
        tmp = leftTree;
        while(tmp->right != nullptr)
            tmp = tmp->right;
        
        root = leftTree;
        root->parent = nullptr;

        splay(tmp);

        root->right = rightTree;

    }else{
        if(leftTree != nullptr)
            root = leftTree;
        else
            root = rightTree;

        root->parent = nullptr;

    }

    delete tmpDelete;
}


void SplayTree::insert(int key) {
    cout << key << endl;

    insertNode(key);
}


void SplayTree::remove(int key) {
    deleteNode(key);
}


bool SplayTree::search(int key) {
    Node* tmp = root;

    while(tmp != nullptr){
        if(key < tmp->key)
            tmp = tmp->left;
        else if(key > tmp->key)
            tmp = tmp->right;
        else
            break;

    }

    splay(tmp);
    return (root && root->key == key);
}


void SplayTree::printTree(Node* root, int space) {
    const int COUNT = 10; 

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
