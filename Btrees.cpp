#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int* keys; // array to hold the keys of node
    int t; // for order
    Node** children; // array to store child pointers
    int n; // total number of keys in the node
    bool isLeafNode; // to check  if node is a leaf

    
    Node(int _t, bool _isLeaf) {
        t = _t;
        isLeafNode = _isLeaf;
        keys = new int[2 * t - 1];
        children = new Node * [2 * t];
        n = 0;
    }

  
    void traverse() {
        for (int i = 0; i < n; i++) {
            if (!isLeafNode)
                children[i]->traverse();
            cout << " " << keys[i];
        }
        if (!isLeafNode)
            children[n]->traverse();
    }

    
    void insertNF(int k) {
        int i = n - 1;
        if (isLeafNode) {
            while (i >= 0 && keys[i] > k) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = k;
            n++;
        }
        else {
            while (i >= 0 && keys[i] > k)
                i--;
            if (children[i + 1]->n == 2 * t - 1) {
                splitChild(i + 1, children[i + 1]);
                if (keys[i + 1] < k)
                    i++;
            }
            children[i + 1]->insertNF(k);
        }
    }

    void splitChild(int i, Node* y) {
        Node* z = new Node(y->t, y->isLeafNode);
        z->n = t - 1;
        for (int j = 0; j < t - 1; j++)
            z->keys[j] = y->keys[j + t];
        if (!y->isLeafNode) {
            for (int j = 0; j < t; j++)
                z->children[j] = y->children[j + t];
        }
        y->n = t - 1;
        for (int j = n; j >= i + 1; j--)
            children[j + 1] = children[j];
        children[i + 1] = z;
        for (int j = n - 1; j >= i; j--)
            keys[j + 1] = keys[j];
        keys[i] = y->keys[t - 1];
        n++;
    }
};

class BTree {
    Node* root;
    int t;

public:
    BTree(int _t) {
        root = NULL;
        t = _t;
    }

    void traverse() {
        if (root != NULL)
            root->traverse();
    }

    void insert(int k) {
        if (root == NULL) {
            root = new Node(t, true);
            root->keys[0] = k;
            root->n = 1;
        }
        else {
            if (root->n == 2 * t - 1) {
                Node* s = new Node(t, false);
                s->children[0] = root;
                s->splitChild(0, root);
                int i = 0;
                if (s->keys[0] < k)
                    i++;
                s->children[i]->insertNF(k);
                root = s;
            }
            else
                root->insertNF(k);
        }
    }
    void searchInFirstLevel(int key) {
        if (root == nullptr) {
            cout << "The tree is empty.\n";
            return;
        }

      
        for (int i = 0; i < root->n; i++) {
            if (root->keys[i] == key) {
                cout << "Key " << key << " found in the first level (root).\n";
                return;
            }
        }

        cout << "Key " << key << " NOT found in the first level.\n";
    }
};


int main() {
    BTree t(3); //order is 3
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "Traversal of B-tree is: ";
    t.traverse();


    cout << "\n\nSearch tests:\n";
    t.searchInFirstLevel(10); 
    t.searchInFirstLevel(6);  
    t.searchInFirstLevel(30);  

    return 0;
}
