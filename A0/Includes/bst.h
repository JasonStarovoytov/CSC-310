#include <exception>
#include <string>
using namespace std;

class node{
    public:
        int val;
        node* L;
        node* R;
        node(){
            val = NULL;
        };
        node(int num){
            val = num;
        }
};

class bst{
    public:
        
        bst();

        node* root;
        void insert(int);
        void remove(int);
        void printBST();
        bool isBalanced();
        
    private:

        void printInOrder(node*);
        void printPreOrder(node*);
        void printPostOrder(node*);
        int hight(node*);
        node* findNode(int);
        node* findPrevNode(int);

};