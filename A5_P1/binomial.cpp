#include "binomial.h"
#include "customErrorClass.h"

#include <climits>

binomialNode::binomialNode(int k)
{
    key = k;
    degree = 0;
    parent = nullptr;
    sibling = nullptr;
    child = nullptr;

}

// ---------------------- PRIVATE FUNCTIONS ------------------------------
binomialNode* BinomialHeap::unionHeap(binomialNode* heap1, binomialNode* heap2)
{
    if(!heap1)
        return heap2;
    if(!heap2)
        return heap1;

    binomialNode* newHead = nullptr;
    binomialNode** pos = &newHead;

    while(heap1 && heap2){
        if(heap1->degree <= heap2->degree){
            *pos = heap1;
            heap1 = heap1->sibling;
        }else{
            *pos = heap2;
            heap2 = heap2->sibling;
        }
        pos = &((*pos)->sibling);
    }

    // add remaining trees, if any
    *pos = (heap1) ? heap1 : heap2;

    return newHead;
}


binomialNode* BinomialHeap::mergeTrees(binomialNode* tree1, binomialNode* tree2)
{
    // assume tree1 is the parent (smallest root) to keep min heap property.
    if(tree1->key > tree2->key){
        swap(tree1, tree2);
    }

    tree2->parent = tree1;
    tree2->sibling = tree1->child;
    tree1->child = tree2;
    tree1->degree++;

    return tree1;
}

void BinomialHeap::linkTrees(binomialNode*& prev, binomialNode*& cur, binomialNode*& next)
{
    if(cur->degree != next->degree || next->sibling && next->sibling->degree == cur->degree){
        prev = cur;
        cur = next;
    }else{
        if(cur->key <= next->key){
            cur->sibling = next->sibling;
            mergeTrees(cur, next);
        }else{
            if(!prev)
                head = next;
            else
                prev->sibling = next;

            mergeTrees(next, cur);
            cur = next;
        }
    }

}

// ---------------- PUBLIC FUNCTIONS ------------------------------
BinomialHeap::BinomialHeap()
{
    head = nullptr;
}

void BinomialHeap::insert(int key)
{
    BinomialHeap tempHeap;
    tempHeap.head = new binomialNode(key);
    head = unionHeap(head, tempHeap.head);

    if(!head || !head->sibling)
        return; 

    binomialNode* prev = nullptr;
    binomialNode* cur = head;
    binomialNode* next = cur->sibling;

    while(next){
        linkTrees(prev, cur, next);
        next = cur->sibling;
    }
}

void BinomialHeap::merge(BinomialHeap& other)
{
    head = unionHeap(head, other.head);

    if(!head || !head->sibling)
        return; 

    binomialNode* prev = nullptr;
    binomialNode* cur = head;
    binomialNode* next = cur->sibling;

    while(next){
        linkTrees(prev, cur, next);
        next = cur->sibling;
    }
}

int BinomialHeap::findMin(){
    if(!head)
        throw MyException("Heap is empty");

    binomialNode* minNode = head;
    int minKey = head->key;

    binomialNode* temp = head->sibling;

    while(temp){
        if(temp->key < minKey){
            minKey = temp->key;
            minNode = temp;
        }
        temp = temp->sibling;
    }

    return minKey;
}

void BinomialHeap::printHeap() {
    cout << "Binomial Heap:\n";
    binomialNode* current = head;


    while (current != nullptr) {
        cout << endl << "Tree of degree " << current->degree << endl;
        printTree(current, 0);
        current = current->sibling;
    }

}

void BinomialHeap::printTree(binomialNode* node, int space) 
{
    if (node == nullptr) 
        return;

    cout << setw(space * 2) << node->key << endl;

    binomialNode* child = node->child;
    while (child) {
        printTree(child, space + 3);
        child = child->sibling;
    }
}

bool BinomialHeap::deleteMin(){

    if(!head)
        throw MyException("Heap is empty");
        //return false;

    int minKey = findMin();
    binomialNode* current = head;
    binomialNode* prev = nullptr;


    while(current->key != minKey){
        prev = current;
        current = current->sibling;
    }

    if(prev){
        prev->sibling = current->sibling;
    }else{
        head = current->sibling;
    }

    binomialNode* child = current->child;
    binomialNode* temp = child;

    while (temp) {
        temp->parent = nullptr;
        temp = temp->sibling;
    }

    binomialNode* reversed = nullptr;
    if (child)
        reversed = reverseList(child);

    head = unionHeap(head, reversed);

    if (head && head->sibling) {
        binomialNode* prev = nullptr;
        binomialNode* cur = head;
        binomialNode* next = cur->sibling;

        while (next) {
            linkTrees(prev, cur, next);
            next = cur->sibling;
        }
    }


    delete current;

    return true;
}

binomialNode* BinomialHeap::reverseList(binomialNode* l) {
    if (l->sibling)
    {
        binomialNode* head = reverseList(l->sibling);
        l->sibling->sibling = l;
        l->sibling = NULL;
        return head;
    }
    return l;
}

bool BinomialHeap::decreaseKey(int oldKey, int newKey){
    binomialNode* current = findNode(head, oldKey);
    if(!current)
        throw MyException("Key not found in heap");
    if(newKey > current->key)
        throw MyException("New key is greater than current key");

    current->key = newKey;
    binomialNode* parent = current->parent;

    while(parent && current->key < parent->key){
        swap(current->key, parent->key);
            current = parent;
            parent = current->parent;
    }
    return true;
}

binomialNode* BinomialHeap::findNode(binomialNode* node, int key) {
    if (!node) return nullptr;

    if (node->key == key)
        return node;

    binomialNode* found = findNode(node->child, key);
    if (found) return found;

    return findNode(node->sibling, key);
}

bool BinomialHeap::deleteKey(int key){
    if(decreaseKey(key, INT_MIN)){
        return deleteMin();
    }
    return false;
}
