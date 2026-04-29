#include "binomialHeap.h"

#include <climits>

binomialNode::binomialNode(Edge e)
{
    edge = e;
    degree = 0;
    parent = nullptr;
    sibling = nullptr;
    child = nullptr;

}

// ---------------------- PRIVATE FUNCTIONS ------------------------------
binomialNode* BinomialHeap::unionHeaps(binomialNode* heap1, binomialNode* heap2)
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
    if(tree1->edge.weight > tree2->edge.weight){
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
        if(cur->edge.weight <= next->edge.weight){
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

void BinomialHeap::insert(Edge edge)
{
    BinomialHeap tempHeap;
    tempHeap.head = new binomialNode(edge);
    head = unionHeaps(head, tempHeap.head);

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
    head = unionHeaps(head, other.head);

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

Edge BinomialHeap::findMin(){
    if(!head){return Edge{-1, -1, -1};}
        //throw MyException("Heap is empty");

    binomialNode* minNode = head;
    Edge minEdge = head->edge;

    binomialNode* temp = head->sibling;

    while(temp){
        if(temp->edge.weight < minEdge.weight){
            minEdge = temp->edge;
            minNode = temp;
        }
        temp = temp->sibling;
    }

    return minEdge;
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

    cout << setw(space * 2) << node->edge.weight << endl;

    binomialNode* child = node->child;
    while (child) {
        printTree(child, space + 3);
        child = child->sibling;
    }
}

void BinomialHeap::deleteMin(){

    if(!head)
        //throw MyException("Heap is empty");
        return;

    Edge minEdge = findMin();
    binomialNode* current = head;
    binomialNode* prev = nullptr;


    while(current->edge.weight != minEdge.weight){
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

    head = unionHeaps(head, reversed);

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

    return;
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

void BinomialHeap::decreaseKey(Edge oldEdge, Edge newEdge){
    binomialNode* current = findNode(head, oldEdge);
    if(!current)
        return;//throw MyException("Key not found in heap");
    if(newEdge.weight > current->edge.weight)
        return;//throw MyException("New key is greater than current key");

    current->edge.weight = newEdge.weight;
    binomialNode* parent = current->parent;

    while(parent && current->edge.weight < parent->edge.weight){
        swap(current->edge.weight, parent->edge.weight);
            current = parent;
            parent = current->parent;
    }
    return;
}

binomialNode* BinomialHeap::findNode(binomialNode* node, Edge edge) {
    if (!node) return nullptr;

    if (node->edge.weight == edge.weight && node->edge.src == edge.src && node->edge.dest == edge.dest)
        return node;

    binomialNode* found = findNode(node->child, edge);
    if (found) return found;

    return findNode(node->sibling, edge);
}

void BinomialHeap::deleteKey(Edge edge){
    decreaseKey(edge, {0, 0, INT_MIN});
    if(head->edge.weight == 0){
        return deleteMin();
    }
    return;
}
