#include<iostream>
using namespace std;
class node {
public:
    int data;
    node* left;
    node* right;
    int height;
    node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
        height = 1;
    }
};
int evaluate_height(node* root) {
    if (root == NULL) {
        return 0;
    }
    else
        return root->height;
}
int evaluate_balance(node* root) {
    int b_f = evaluate_height(root->left) - evaluate_height(root->right);
    return b_f;
}
node* right_rotation(node* root) {
    node* child = root->left;
    node* child_right = child->right;
    child->right = root;
    root->left = child_right;

    root->height = 1 + max(evaluate_height(root->left), evaluate_height(root->right));
    child->height = 1 + max(evaluate_height(child->left), evaluate_height(child->right));
    return child;
}
node* left_rotation(node* root) {
    node* child = root->right;
    node* child_left = child->left;
    child->left = root;
    root->right = child_left;

    root->height = 1 + max(evaluate_height(root->left), evaluate_height(root->right));
    child->height = 1 + max(evaluate_height(child->left), evaluate_height(child->right));
    return child;
}
class AVL_tree{
public:
    node* root;
    AVL_tree() {
        root = NULL;
    }
    node* insertion(node* root, int value) {
        if(root == NULL){
          
            return new node(value);
    }
        if (value > root->data) {  //means at right side
            root->right = insertion(root->right, value);
        }
        else if (value < root->data) {  // means move to left side
            root->left = insertion(root->left, value);
        }
        else {
            cout << "Duplicate value not allowed in AVL Tree."<<endl;
            return root;
        }
          
        //to evaluate height which is either 1 or 2
        root->height = 1 + max(evaluate_height(root->left), evaluate_height(root->right));
        // to check balancing factor
        int balance_factor = evaluate_balance(root);
        //left left case
        if (balance_factor > 1 && value < root->left->data) {
            return right_rotation(root);
        }
        //right right case
        else if (balance_factor<-1 && value>root->right->data) {
            return left_rotation(root);
        }
        //left right case
        else if (balance_factor > 1 && value > root->left->data) {
            root->left = left_rotation(root);
            return right_rotation(root);
        }
        //right left case 
        else if (balance_factor < -1 && value < root->right->data) {
            root->right = right_rotation(root);
            return left_rotation(root);
        }
        else
            return root;
    }
    node* deletion(node* root, int value) {
        if (root == NULL) {
            cout << "Can't delete, node not found." << endl;
            return NULL;
        }
        else if (value < root->data) {//left side 
            root->left = deletion(root->left, value);
        }
        else if (value > root->data) {  // move to right side
            root->right = deletion(root->right, value);
        }
        else {
            if (root->left == NULL && root->right == NULL) {  //both left right chinld dont exists
                cout << "Node deleted successfully: " << endl;
                delete root;
             
                return NULL;
            }
            else if (root->left == NULL && root->right != NULL) { // right child exists
                node* temp = root->right;
                cout << "Node deleted successfully: " << endl;
                delete root;
               
                return temp;

            }
            else if (root->left != NULL && root->right == NULL) { // left child exists
                node* temp = root->left;
                cout << "Node deleted successfully: " << endl;
                delete root;
               
                return temp;
            }
            else {
                node* curr = root->right;   // in order successor case
                while (curr->left != NULL) {
                    curr = curr->left;
                }
                root->data = curr->data;
                root->right=deletion(root->right, curr->data);

            }
 
        }
        root->height = 1 + max(evaluate_height(root->left), evaluate_height(root->right));
        int balance_factor = evaluate_balance(root);

        // Left Left Case
        if (balance_factor > 1 && evaluate_balance(root->left) >= 0)
            return right_rotation(root);

        // Left Right Case
        if (balance_factor > 1 && evaluate_balance(root->left) < 0) {
            root->left = left_rotation(root->left);
            return right_rotation(root);
        }

        // Right Right Case
        if (balance_factor < -1 && evaluate_balance(root->right) <= 0)
            return left_rotation(root);

        // Right Left Case
        if (balance_factor < -1 && evaluate_balance(root->right) > 0) {
            root->right = right_rotation(root->right);
            return left_rotation(root);
        }
        return root;
    }
    void inorder(node* root) {
        if (root == nullptr)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    void deleteTree(node* root) {
        if (root == nullptr) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
  
};
int main() {
    AVL_tree a1; 
    int choice;

    do {
        cout << "--- AVL Tree Menu ---\n";
        cout << "1. Insert into AVL Tree\n";
        cout << "2. Delete from AVL Tree\n";
        cout << "3. Display AVL Tree (inorder)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int el;
            cout << "Enter the element you want to insert: ";
            cin >> el;
            a1.root = a1.insertion(a1.root, el); 
            break;
        }
        case 2: {
            int del;
            cout << "Enter the element you want to delete: ";
            cin >> del;
            a1.root = a1.deletion(a1.root, del); 
            break;
        }
        case 3: {
            cout << "Inorder Traversal of AVL Tree: ";
            a1.inorder(a1.root); 
            cout << endl;
            break;
        }
        case 0: {
            cout << "Exiting through code...." << endl;
            break;
        }
        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    //to avoid memory leakage
    a1.deleteTree(a1.root);
    return 0;

}