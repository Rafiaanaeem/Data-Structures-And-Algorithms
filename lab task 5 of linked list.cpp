
#include<iostream>
using namespace std;
const int SIZE = 6; 

class node {
public:
    int data;
    node* link;
};

class forwardlist {
public:
    int count;
    node* head;

    forwardlist() {
        count = 0;
        head = NULL;
    }

    void push_at_front(int value) {
        if (full()) {
            cout << "List is full.\n";
            return;
        }
        node* temp = new node;
        temp->data = value;
        temp->link = head;
        head = temp;
        count++;
    }

    void push_at_back(int value) {
        if (full()) {
            cout << "List is full.\n";
            return;
        }
        node* temp = new node;
        temp->data = value;
        temp->link = NULL;

        if (head == NULL) {
            head = temp;
        }
        else {
            node* p = head;
            while (p->link != NULL) {
                p = p->link;
            }
            p->link = temp;
        }
        count++;
    }

    void push_at_position(int afterValue, int newValue) {
        if (full()) {
            cout << "List is full.\n";
            return;
        }

        node* temp = head;
        while (temp != NULL && temp->data != afterValue) {
            temp = temp->link;
        }

        if (temp == NULL) {
            cout << "Value " << afterValue << " not found in list.\n";
            return;
        }

        node* newNode = new node;
        newNode->data = newValue;
        newNode->link = temp->link;
        temp->link = newNode;
        count++;
    }

    void pop_front() {
        if (head == NULL) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }
        node* temp = head;
        head = head->link;
        delete temp;
        count--;
    }

    void pop_last() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        if (head->link == NULL) {
            delete head;
            head = NULL;
        }
        else {
            node* prev = NULL;
            node* curr = head;
            while (curr->link != NULL) {
                prev = curr;
                curr = curr->link;
            }
            prev->link = NULL;
            delete curr;
        }
        count--;
    }

    void pop_at_position(int value) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        node* current = head;
        node* previous = NULL;

        while (current != NULL && current->data != value) {
            previous = current;
            current = current->link;
        }

        if (current == NULL) {
            cout << "Value " << value << " not found in list.\n";
            return;
        }

        if (previous == NULL) { 
            head = head->link;
        }
        else {
            previous->link = current->link;
        }

        delete current;
        count--;
    }

    bool empty() {
        return count == 0;
    }

    bool full() {
        return count == SIZE;
    }

    bool makempty() {
      /*  while (head != NULL) {
            pop_front();
        }
        cout << "Whole list is empty now.\n";*/
       return head = NULL;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "\t";
            temp = temp->link;
        }
        cout << endl;
    }
    ~forwardlist() {
        while (head != NULL) {
            pop_front();
        }
        cout << "Whole list is empty now.\n";
    }
};

int main() {
    forwardlist l;
    int option;

    do {
        cout << "\n------ Forward Linked List Menu -----\n";
        cout << "1. PUSH AT FRONT\n";
        cout << "2. PUSH AT BACK\n";
        cout << "3. PUSH IN BETWEEN\n";
        cout << "4. POP AT FRONT\n";
        cout << "5. POP AT END\n";
        cout << "6. POP IN BETWEEN\n";
        cout << "7. CHECK IF LIST IS EMPTY\n";
        cout << "8. CHECK IF LIST IS FULL\n";
        cout << "9. MAKE WHOLE LIST EMPTY\n";
        cout << "10. DISPLAY LIST\n";
        cout << "0. EXIT\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
        case 1: {
            int val;
            cout << "Enter value to insert at front: ";
            cin >> val;
            l.push_at_front(val);
            break;
        }
        case 2: {
            int val;
            cout << "Enter value to insert at back: ";
            cin >> val;
            l.push_at_back(val);
            break;
        }
        case 3: {
            int after, val;
            cout << "Enter value after which to insert: ";
            cin >> after;
            cout << "Enter new value to insert: ";
            cin >> val;
            l.push_at_position(after, val);
            break;
        }
        case 4: {
            l.pop_front();
            break;
        }
        case 5: {
            l.pop_last();
            break;
        }
        case 6: {
            int val;
            cout << "Enter value to delete: ";
            cin >> val;
            l.pop_at_position(val);
            break;
        }
        case 7: {
            cout << (l.empty() ? "List is empty.\n" : "List is not empty.\n");
            break;
        }
        case 8: {
            cout << (l.full() ? "List is full.\n" : "List is not full.\n");
            break;
        }
        case 9: {
            l.makempty();
            break;
        }
        case 10: {
            l.display();
            break;
        }
        case 0: {
            cout << "Exiting...\n";
            break;
        }
        default:
            cout << "Invalid option. Try again.\n";
        }

        if (option >= 1 && option <= 10)
            l.display();

    } while (option != 0);

    return 0;
}
