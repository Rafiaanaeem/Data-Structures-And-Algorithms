#include <iostream>
using namespace std;

const int SIZE = 6;

class node {
public:
    int data;
    node* link;
};

// iterator class outside forward_list class
class forward_list_iterator {
    node* ptr;
public:
    forward_list_iterator(node* p = nullptr) : ptr(p) {}

    forward_list_iterator& operator++() {
        if (ptr != nullptr) {
            ptr = ptr->link;
        }
        return *this;
    }

    bool operator!=(const forward_list_iterator& other) const {
        return ptr != other.ptr;
    }

    bool operator==(const forward_list_iterator& other) const {
        return ptr == other.ptr;
    }

    int& operator*() {
        return ptr->data;
    }

    // New function to access data at a specific position in the list
    int access_at_position(int pos) {
        node* temp = ptr;
        for (int i = 0; i < pos; ++i) {
            if (temp->link != nullptr) {
                temp = temp->link;
            }
            else {
                cout << "Invalid position!" << endl;
                return -1;
            }
        }
        return temp->data;
    }
};

class forward_list {
public:
    int count;
    node* head;

    forward_list() {
        count = 0;
        head = nullptr;
    }

    void push_at_front(int value) {
        node* temp = new node;
        temp->data = value;
        temp->link = head;
        head = temp;
        count++;
    }

    void push_at_back(int value) {
        node* temp = new node;
        temp->data = value;
        temp->link = nullptr;

        if (head == nullptr) {
            head = temp;
        }
        else {
            node* p = head;
            while (p->link != nullptr) {
                p = p->link;
            }
            p->link = temp;
        }
        count++;
    }

    void push_at_position(int afterValue, int newValue) {
        if (full()) {
            cout << "List is full." << endl;
            return;
        }

        node* temp = head;
        while (temp != nullptr && temp->data != afterValue) {
            temp = temp->link;
        }

        if (temp == nullptr) {
            cout << "Value " << afterValue << " not found in list." << endl;
            return;
        }

        node* newNode = new node;
        newNode->data = newValue;
        newNode->link = temp->link;
        temp->link = newNode;
        count++;
    }

    void pop_front() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }
        node* temp = head;
        head = head->link;
        delete temp;
        count--;
    }

    void pop_last() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->link == nullptr) {
            delete head;
            head = nullptr;
        }
        else {
            node* prev = nullptr;
            node* curr = head;
            while (curr->link != nullptr) {
                prev = curr;
                curr = curr->link;
            }
            prev->link = nullptr;
            delete curr;
        }
        count--;
    }

    void pop_at_position(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        node* current = head;
        node* previous = nullptr;

        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->link;
        }

        if (current == nullptr) {
            cout << "Value " << value << " not found in list." << endl;
            return;
        }

        if (previous == nullptr) { // deleting head
            head = head->link;
        }
        else {
            previous->link = current->link;
        }

        delete current;
        count--;
    }

    bool empty() const {
        return count == 0;
    }

    bool full() const {
        return count == SIZE;
    }

    void makempty() {
        while (head != nullptr) {
            pop_front();
        }
        cout << "Whole list is empty now." << endl;
    }

    void display() const {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        for (forward_list_iterator it = begin(); it != end(); ++it) {
            cout << *it << "\t";
        }
        cout << endl;
    }

    int totalvalues() const {
        return count;
    }

    forward_list_iterator begin() const {
        return forward_list_iterator(head);
    }

    forward_list_iterator end() const {
        return forward_list_iterator(nullptr);
    }
};

int main() {
    forward_list l;
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
        cout << "11. ACCESS ELEMENT AT POSITION\n";  // Option for accessing at position
        cout << "0. EXIT\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
        case 1: {
            int val;
            cout << "Enter value to insert at front: ";
            cin >> val;
            l.push_at_front(val);
            l.display();
            break;
        }
        case 2: {
            int val;
            cout << "Enter value to insert at back: ";
            cin >> val;
            l.push_at_back(val);
            l.display();
            break;
        }
        case 3: {
            int after, val;
            cout << "Enter value after which to insert: ";
            cin >> after;
            cout << "Enter new value to insert: ";
            cin >> val;
            l.push_at_position(after, val);
            l.display();
            break;
        }
        case 4: {
            l.pop_front();
            l.display();
            break;
        }
        case 5: {
            l.pop_last();
            l.display();
            break;
        }
        case 6: {
            int val;
            cout << "Enter value to delete: ";
            cin >> val;
            l.pop_at_position(val);
            l.display();
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
        case 11: {  // Access element at position using iterator
            int pos;
            cout << "Enter position to access: ";
            cin >> pos;
            forward_list_iterator it = l.begin(); // Get the iterator to the beginning of the list
            int value = it.access_at_position(pos); // Use the iterator's method
            if (value != -1) {
                cout << "Element at position " << pos << " is: " << value << endl;
            }
            break;
        }
        case 0: {
            cout << "Exiting...\n";
            break;
        }
        default:
            cout << "Invalid option. Try again.\n";
        }
    } while (option != 0);

    return 0;
}
