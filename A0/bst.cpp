#include "bst.h"
#include "customErrorClass.h"
#include <iostream>

using namespace std;


bst::bst(){ // make an empty bst
    root = NULL;
}

void bst::printBST(){
    printPreOrder(root);
    cout << endl;
}

void bst::printInOrder(node* base){      // prints tree recursivly (left, middle, right)
    if(base->L != NULL){
        printInOrder(base->L);
    }
    cout << base->val << endl;
    if(base->R != NULL){
        printInOrder(base->R);
    }
}
void bst::printPreOrder(node* base){      // prints tree recursivly (middle, left, right)
    cout << base->val << endl;
    if(base->L != NULL){
        printPreOrder(base->L);
    }

    if(base->R != NULL){
        printPreOrder(base->R);
    }
}
void bst::printPostOrder(node* base){      // prints tree recursivly (left, right, middle)
    if(base->L != NULL){
        printPostOrder(base->L);
    }
    if(base->R != NULL){
        printPostOrder(base->R);
    }
    cout << base->val << endl;
}

void bst::insert(int num){
    node* tmp = root;           
    node* n = new node(num);    

    if(root == NULL){   // if there is no root, make the current node the root
        root = n;
        return;
    }

    try{
        while(true){                    // loop until a valid location is found
            if(n->val > tmp->val){
                if(tmp->R == NULL){     // when space is found, set to correct child and return
                    tmp->R = n;
                    isBalanced();
                    return;
                }else{
                    tmp = tmp->R;
                }

            }else if(n->val == tmp->val){
                throw MyException("Cannot add node (" + to_string(n->val) + " is already in bst)");
            }else{
                if(tmp->L == NULL){
                    tmp->L = n;
                    isBalanced();
                    return;
                }else{
                    tmp = tmp->L;
                }    
            }
        }
    }catch(MyException &e){
        cerr<<e.what()<<endl;
        return;
    }
    
}

node* bst::findNode(int value){     // search for a node given a value
    node* tmp = root;
    while (tmp != NULL) {
        if (tmp->val == value) {
            return tmp;
        } else if (value < tmp->val) {
            tmp = tmp->L;
        } else {
            tmp = tmp->R;
        }
    }

    throw MyException("value is not in the bst");
    return NULL;
}

node* bst::findPrevNode(int value){     // find the parent of a node given a value
    node* tmp = root;
    if(root->val == value || root->L->val == value || root->R->val == value){
        return root;
    }
    while (tmp != NULL) {

        if ((tmp->L != NULL && tmp->L->val == value) || (tmp->R != NULL && tmp->R->val == value)) {
            return tmp;
        } else if (value < tmp->val) {
            tmp = tmp->L;
        } else {
            tmp = tmp->R;
        }
    }

    throw MyException("value is not in the bst");
    return NULL;
}

int bst::hight(node* tree){
    if(tree == NULL){
        return 0;
    }
    int left = hight(tree->L);
    int right = hight(tree->R);

    return 1 + max(left, right);
    
}

bool bst::isBalanced(){
    //cout << "tree hight: " << hight(root) << endl;
    //cout << "Left: " << hight(root->L) << endl << "Right: " << hight(root->R) << endl;

    if(abs(hight(root->L) - hight(root->R)) <= 1){
        return true;
    }

    cout << "The tree is out of balance" << endl;
    return false;
}


void bst::remove(int value){
    node* prev;
    node* mov;
    node* target;

    try{
        target = findNode(value);
        prev = findPrevNode(target->val);
    } catch( MyException &e){
        cerr<<e.what()<<endl;
        return;
    }
    //cout << "Prev: " << prev->val << endl << "Target: " << target->val << endl;


    if(root->val == value){
        bool skip = false;

        if(root->R != NULL){
            mov = root->R;
        }else if(root->L != NULL){
            root = root->L;
            skip = true;
        }else{
            skip = true;
            root = NULL;
            cout << "No more elements in bst" << endl;
        }

        if(!skip){
            while(mov->L != NULL){
                prev = mov;
                mov = mov->L;
            }
            
            if(prev == root){
                prev->R = mov->R;
            }else{
                prev->L = mov->R;
            }

            mov->L = root->L;
            mov->R = root->R;

            root = mov;
        }
        
        
    }else if(target->L == NULL && target->R == NULL){
        if(prev->L == target){
            prev->L = NULL;
        }else{
            prev->R = NULL;
        }
    }else if((target->L != NULL && target->R == NULL) || (target->L == NULL && target->R != NULL)){
        if(target->L != NULL){
            if(prev->L == target){
                prev->L = target->L;
            }else{
                prev->R = target->L;
            }
        }else{     
            if(prev->R == target){
                prev->L = target->R;
            }else{
                prev->R = target->R;
            }
        }

    }else if(target->L != NULL && target->R != NULL){
        bool skip = false;

        if(target->R != NULL){
            mov = target->R;
        }else if(target->L != NULL){
            prev = target->L;
            skip = true;
        }else{
            skip = true;
            root = NULL;
            cout << "No more elements in bst" << endl;
        }

        if(!skip){
            node* tmpPrev = prev;
            prev = mov;
            while(mov->L != NULL){
                prev = mov;
                mov = mov->L;
            }
            
            //if(prev->R != NULL){
            prev->L = mov->R;
            //}
        
            mov->L = target->L;

            if(target->R != mov){
                mov->R = target->R;
            }

            if(tmpPrev->R == target){
                tmpPrev->R = mov;
            }else{
                tmpPrev->L = mov;
            }
        }

    }

    isBalanced();

    delete target;


}


