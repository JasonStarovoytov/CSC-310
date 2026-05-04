#include <iostream>
#include <memory>
#include <vector>

using namespace std;
struct Node;
struct Change {
        int version;
        shared_ptr<Node> left;
        shared_ptr<Node> right;

        
    };
struct Node {
    int key;
    vector<Change> history;

    Node(int k)
    {
        key = k;
        //history.push_back(c);
    }
};

class persistentBST {
    private:

        vector<shared_ptr<Node>> roots;


        shared_ptr<Node> insert(shared_ptr<Node> node, int key, int version)
        {
            if(!node){
                auto n = make_shared<Node>(key);
                n->history.push_back({version, nullptr, nullptr});
                return n;
            }

            auto state = getState(node, version);
            
            if(key < node->key)
            {
                auto newLeft = insert(state.left, key, version);

                node->history.push_back({version, newLeft, state.right});

            } else if (key > node->key)
            {
                auto newRight = insert(state.right, key, version);

                node->history.push_back({version, state.left, newRight});
            }

            return node;
            
        }


        Change getState(shared_ptr<Node> node, int version){
            Change best = node->history[0];

            for(Change c : node->history){
                if(c.version <= version)
                    best = c;
                else
                    break;
            }

            return best;
        }


        bool search(shared_ptr<Node> node, int key, int version){
            if (!node)
                return false;
            if(key == node->key)
                return true;

            Change state = getState(node, version);

            if (key < node->key)
                return search(state.left, key, version);

            return search(state.right, key, version);
        }

        void inorder(shared_ptr<Node> node, int version)
        {
            if(!node)
                return;

            auto state = getState(node, version);
            inorder(state.left, version);
            cout << node->key << " ";
            inorder(state.right, version);
        }

    public:
        int globalVersion;

        persistentBST(){
            globalVersion = 0;
        }
        

        void insert(int key)
        {
            shared_ptr<Node> newRoot;
            
            if(roots.empty())
                newRoot = insert(nullptr, key, globalVersion);
            else
                newRoot = insert(roots.back(), key, globalVersion);

            roots.push_back(newRoot);
            globalVersion++;
        }

        bool search(int key, int version)
        {
            return search(roots[version], key, version);
        }

        void inorder(int version)
        {
            //cout << globalVersion << endl;
            inorder(roots[version], version);
            cout<<endl;
        }
};

int main()
{
    persistentBST t1;

    t1.insert(10);
    t1.insert(20);
    t1.insert(30);
    t1.insert(40);

    for(int i = 0; i < t1.globalVersion; i++){
        cout << "Version " << i << ": ";
        t1.inorder(i);
    }


return 0;
}