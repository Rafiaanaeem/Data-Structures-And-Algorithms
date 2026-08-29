#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* leftChild;
    node* rightChild;

    node() {
        leftChild = nullptr;
        rightChild = nullptr;
    }
};

class tree {
private:
    node* rootNode;
public:
    tree() {
        rootNode = nullptr;
    }

    node* insert(node* currentRoot, int value) {
        node* cnode = currentRoot;
        node* parentNode = nullptr;
        node* newNode = new node;
        newNode->data = value;
        newNode->leftChild = newNode->rightChild = nullptr;

        if (currentRoot == nullptr) {
            currentRoot = newNode;
        }
        else {
            while (cnode != nullptr) {
                parentNode = cnode;
                if (value < cnode->data) {
                    cnode = cnode->leftChild;
                }
                else if (value > cnode->data) {
                    cnode = cnode->rightChild;
                }
                else {
                    cout << "Duplicate value inserted!!" << endl;
                    delete newNode;
                    return currentRoot;
                }
            }
            if (value < parentNode->data) {
                parentNode->leftChild = newNode;
            }
            else {
                parentNode->rightChild = newNode;
            }
        }
        return currentRoot;
    }

    node* findMin(node* currentRoot) {
        if (currentRoot == nullptr)
            return nullptr;
        else if (currentRoot->leftChild == nullptr) 
            return currentRoot;
        else 
            return findMin(currentRoot->leftChild);
    }

    node* deleteNode(node* currentRoot, int value) {
        node* tempNode;
        if (currentRoot == nullptr) {
            cout << "Tree is empty or value not found!!" << endl;
            return nullptr;
        }

        if (value < currentRoot->data) {
            currentRoot->leftChild = deleteNode(currentRoot->leftChild, value);
        }
        else if (value > currentRoot->data) {
            currentRoot->rightChild = deleteNode(currentRoot->rightChild, value);
        }
        else {
            // Node found
            if (currentRoot->leftChild == nullptr && currentRoot->rightChild == nullptr) {
                delete currentRoot;
                return nullptr;
            }
            else if (currentRoot->leftChild != nullptr && currentRoot->rightChild != nullptr) {
                tempNode = findMin(currentRoot->rightChild);
                currentRoot->data = tempNode->data;
                currentRoot->rightChild = deleteNode(currentRoot->rightChild, tempNode->data);
            }
            else {
                tempNode = currentRoot;
                if (currentRoot->leftChild == nullptr) {
                    currentRoot = currentRoot->rightChild;
                }
                else {
                    currentRoot = currentRoot->leftChild;
                }
                delete tempNode;
            }
        }
        return currentRoot;
    }

    void inorder(node* currentRoot) {
        if (currentRoot == nullptr) 
            return;
        inorder(currentRoot->leftChild);
        cout << currentRoot->data << " ";
        inorder(currentRoot->rightChild);
    }

    void preorder(node* currentRoot) {
        if (currentRoot == nullptr) 
            return;
        cout << currentRoot->data << " ";
        preorder(currentRoot->leftChild);
        preorder(currentRoot->rightChild);
    }

    void postorder(node* currentRoot) {
        if (currentRoot == nullptr) 
            return;
        postorder(currentRoot->leftChild);
        postorder(currentRoot->rightChild);
        cout << currentRoot->data << " ";
    }
};

int main() {
    tree myTree;
    node* rootPtr = nullptr;
    int numElements, inputValue;

    cout << "Enter number of elements to insert: ";
    cin >> numElements;

    cout << "Enter " << numElements << " values:\n";
    for (int i = 0; i < numElements; ++i) {
        cin >> inputValue;
        rootPtr = myTree.insert(rootPtr, inputValue);
    }

    cout << "Inorder traversal: ";
    myTree.inorder(rootPtr);
    cout << endl;

    cout << "Preorder traversal: ";
    myTree.preorder(rootPtr);
    cout << endl;

    cout << "Postorder traversal: ";
    myTree.postorder(rootPtr);
    cout << endl;

    int valueToDelete;
    cout << "Enter the node value you want to delete: ";
    cin >> valueToDelete;
    rootPtr = myTree.deleteNode(rootPtr, valueToDelete);

    cout << "Inorder traversal after deletion: ";
    myTree.inorder(rootPtr);
    cout << endl;

    cout << "Preorder traversal after deletion: ";
    myTree.preorder(rootPtr);
    cout << endl;

    cout << "Postorder traversal after deletion: ";
    myTree.postorder(rootPtr);
    cout << endl;

    return 0;
}
