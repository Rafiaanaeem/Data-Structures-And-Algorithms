#include <iostream>
#include <string>
using namespace std;

struct student {
    string name;
    int rollno;
    int semester;
};

class node {
public:
    student data;
    node* link;
};

class circularlinkedlist {
private:
    node* head;
public:
    circularlinkedlist() {
        head = NULL;
    }

    void insert_at_start(int rollno, string name, int semester) {
        node* temp = new node;
        temp->data.rollno = rollno;
        temp->data.name = name;
        temp->data.semester = semester;

        if (head == NULL) {
            temp->link = temp;
            head = temp;
        }
        else {
            node* p = head;
            while (p->link != head) {
                p = p->link;
            }
            temp->link = head;
            p->link = temp;
            head = temp;
        }
        cout << "NODE ADDED SUCCESSFULLY" << endl;
    }

    void insert_at_last(int rollno, string name, int semester) {
        node* temp = new node;
        temp->data.rollno = rollno;
        temp->data.name = name;
        temp->data.semester = semester;

        if (head == NULL) {
            temp->link = temp;
            head = temp;
        }
        else {
            node* p = head;
            while (p->link != head) {
                p = p->link;
            }
            p->link = temp;
            temp->link = head;
        }
        cout << "NODE ADDED SUCCESSFULLY" << endl;
    }

    void insert_at_position(int rollno, string name, int semester, int value) {
        node* p = head;
        bool found = false;
        do {
            if (p->data.rollno == value) {
                found = true;
                break;
            }
            p = p->link;
        } while (p != head);

        if (found) {
            node* temp = new node;
            temp->data.rollno = rollno;
            temp->data.name = name;
            temp->data.semester = semester;
            temp->link = p->link;
            p->link = temp;
            cout << "NODE ADDED SUCCESSFULLY" << endl;
        }
        else {
            cout << "CANT INSERT NODE AS VALID POSITION NOT FOUND" << endl;
        }
    }

    void delete_from_start() {
        if (head == NULL) {
            cout << "circular list is empty---cant delete any node" << endl;
        }
        else if (head->link == head) {
            delete head;
            head = NULL;
        }
        else {
            node* current = head;
            node* p = head;
            while (p->link != head) {
                p = p->link;
            }
            p->link = head->link;
            head = head->link;
            delete current;
        }
        cout << "NODE DELETED SUCCESSFULLY" << endl;
    }

    void delete_from_end() {
        if (head == NULL) {
            cout << "circular list is empty---cant delete any node" << endl;
        }
        else if (head->link == head) {
            delete head;
            head = NULL;
        }
        else {
            node* p = head;
            node* prev = NULL;
            while (p->link != head) {
                prev = p;
                p = p->link;
            }
            prev->link = head;
            delete p;
        }
        cout << "NODE DELETED SUCCESSFULLY" << endl;
    }

    void delete_from_position(int rollno) {
        if (head == NULL) {
            cout << "circular list is empty---cant delete any node" << endl;
        }
        else if (head->link == head && head->data.rollno == rollno) {
            delete head;
            head = NULL;
        }
        else {
            node* temp = head;
            node* prev = NULL;
            bool found = false;
            do {
                if (temp->data.rollno == rollno) {
                    found = true;
                    break;
                }
                prev = temp;
                temp = temp->link;
            } while (temp != head);

            if (found) {
                if (temp == head) {
                    // deleting head
                    node* p = head;
                    while (p->link != head) {
                        p = p->link;
                    }
                    p->link = head->link;
                    head = head->link;
                }
                else {
                    prev->link = temp->link;
                }
                delete temp;
                cout << "NODE DELETED SUCCESSFULLY" << endl;
            }
            else {
                cout << "CANT DELETE NODE AS VALID POSITION NOT FOUND" << endl;
            }
        }
    }

    void search(int rollno) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        node* temp = head;
        bool found = false;
        do {
            if (temp->data.rollno == rollno) {
                found = true;
                break;
            }
            temp = temp->link;
        } while (temp != head);

        if (found) {
            cout << "NODE FOUND SUCCESSFULLY" << endl;
            cout << "Roll no: " << temp->data.rollno << "\t";
            cout << "Name: " << temp->data.name << "\t";
            cout << "Semester: " << temp->data.semester << endl;
        }
        else {
            cout << "Node not found" << endl;
        }
    }

    void modify(int rollno, string name, int semester, int position) {
        if (head == NULL) return;

        node* temp = head;
        bool found = false;
        do {
            if (temp->data.rollno == position) {
                found = true;
                break;
            }
            temp = temp->link;
        } while (temp != head);

        if (found) {
            temp->data.rollno = rollno;
            temp->data.name = name;
            temp->data.semester = semester;
            cout << "NODE MODIFIED" << endl;
        }
        else {
            cout << "NODE CANT BE MODIFIED AS NOT FOUND" << endl;
        }
    }

    void sort() {
        if (head == NULL || head->link == head) {
            cout << "list too short to sort." << endl;
            return;
        }

        bool swapped;
        node* end = NULL;
        do {
            node* current = head;
            swapped = false;
            while (current->link != head && current->link != end) {
                node* nextNode = current->link;
                if (current->data.rollno > nextNode->data.rollno) {
                    swap(current->data, nextNode->data);
                    swapped = true;
                }
                current = current->link;
            }
            end = current;
        } while (swapped);

        cout << "LIST SORTED BY ROLLNO\n";
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        node* temp = head;
        do {
            cout << "Roll no: " << temp->data.rollno << "  ";
            cout << "Name: " << temp->data.name << "  ";
            cout << "Semester: " << temp->data.semester << "   ->   ";
            temp = temp->link;
        } while (temp != head);
    }

    ~circularlinkedlist() {
        if (head == NULL) return;

        node* temp = head;
        node* nextNode;
        do {
            nextNode = temp->link;
            delete temp;
            temp = nextNode;
        } while (temp != head);

        head = NULL;
    }
};

int main() {
    circularlinkedlist l1;
    int option;

    do {
        cout << "\n---- MENU ----\n";
        cout << "1. Insert at start\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete from start\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete by roll number\n";
        cout << "7. Search for a student\n";
        cout << "8. Modify a student\n";
        cout << "9. Sort the list\n";
        cout << "10. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> option;

        string name;
        int semester, rollno, value;

        switch (option) {
        case 1:
            cout << "Enter roll no: "; cin >> rollno;
            cout << "Enter name: "; cin >> name;
            cout << "Enter semester: "; cin >> semester;
            l1.insert_at_start(rollno, name, semester);
            break;
        case 2:
            cout << "Enter roll no: "; cin >> rollno;
            cout << "Enter name: "; cin >> name;
            cout << "Enter semester: "; cin >> semester;
            l1.insert_at_last(rollno, name, semester);
            break;
        case 3:
            cout << "Enter roll no: "; cin >> rollno;
            cout << "Enter name: "; cin >> name;
            cout << "Enter semester: "; cin >> semester;
            cout << "Enter roll no after which to insert: "; cin >> value;
            l1.insert_at_position(rollno, name, semester, value);
            break;
        case 4:
            l1.delete_from_start();
            break;
        case 5:
            l1.delete_from_end();
            break;
        case 6:
            cout << "Enter roll no to delete: "; cin >> rollno;
            l1.delete_from_position(rollno);
            break;
        case 7:
            cout << "Enter roll no to search: "; cin >> rollno;
            l1.search(rollno);
            break;
        case 8:
            cout << "Enter roll no to modify: "; cin >> value;
            cout << "Enter new roll no: "; cin >> rollno;
            cout << "Enter new name: "; cin >> name;
            cout << "Enter new semester: "; cin >> semester;
            l1.modify(rollno, name, semester, value);
            break;
        case 9:
            l1.sort();
            break;
        case 10:
            l1.display();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid option.\n";
        }

    } while (option != 0);

    return 0;
}
