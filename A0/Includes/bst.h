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
            L = NULL;
            R = NULL;
        };
        node(int num){
            val = num;
            L = NULL;
            R = NULL;
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
        node* findNode(int);
        
    private:

        void printInOrder(node*);
        void printPreOrder(node*);
        void printPostOrder(node*);
        int hight(node*);
        node* findPrevNode(int);

};