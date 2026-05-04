// persistent BST
// path copying

#include <iostream>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    // int refcount;  it is not thread-safe 

    Node(int k, Node* l = nullptr, Node* r = nullptr)
    {
        key = k;
        left = l;
        right = r;
    }
};

class persistentBST {
    private:
        Node* root;

        Node* insert(Node* node, int key)
        {
            if(!node)
                return new Node(key);
            
            if(key < node->key)
            {
                return new Node(node->key, insert(node->left, key), node->right);
            } else if (key > node->key)
            {
                return new Node(node->key, node->left, insert(node->right, key));
            } else {
                return node;
            }
        }

        Node* remove(Node* node, int key){
            if(node == nullptr)
                return nullptr;

            if(node->key > key)
                return new Node(node->key, remove(node->left, key), node->right);
            else if(node->key < key)
                return new Node(node->key, node->left, remove(node->right, key));
            else{

                // no left child
                if(node->left == nullptr)
                    return node->right;

                // no right child
                if(node->right == nullptr)
                    return node->left;

                // two children

                Node* tmp = findMin(node->right);

                return new Node(tmp->key, node->left, remove(node->right, tmp->key));
                
            }
        }

        Node* findMin(Node* node){
            while(node->left != nullptr){
                node = node->left;
            }
            return node;
        }

        bool search(Node* node, int key){
            if (!node)
                return false;
            if(key == node->key)
                return true;
            if (key < node->key)
                return search (node->left, key);
            return search(node->right, key);
        }


        void inorder(Node* node)
        {
            if(!node)
                return;
            inorder(node->left);
            cout << node->key << " ";
            inorder(node->right);
        }

    public:
        persistentBST(){
            root = nullptr;
        }
        persistentBST(Node* r){
            root = r;
        }

        persistentBST insert(int key)
        {
            return persistentBST(insert(root, key));
        }

        persistentBST remove(int key)
        {
            return persistentBST(remove(root, key));
        }

        bool search(int key)
        {
            return search(root, key);
        }

        void inorder()
        {
            inorder(root);
            cout<<endl;
        }
};

int main()
{
    persistentBST t1;

    auto t2 = t1.insert(10);
    auto t3 = t2.insert(20);
    auto t4 = t3.insert(30);
    auto t5 = t4.insert(40);
    auto t6 = t5.remove(30);

    cout << "t3: ";
    t3.inorder();

    cout << "t5: ";
    t5.inorder();

    cout << "t6: ";
    t6.inorder();

return 0;
}