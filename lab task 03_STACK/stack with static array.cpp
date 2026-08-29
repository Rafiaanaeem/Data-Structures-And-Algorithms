#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int array[6];

public:
    Stack() {
       
        top = -1;
    }


    void push(int val) {
        if (top == 6 - 1) {
            cout << "Stack Overflow" << endl;
        }
        else {
            top++;
            array[top] = val;
        }
    }

    int pop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else {
            int value = array[top];
            top--;
            return value;
        }
    }

    bool empty() {
        return top == -1;
    }

    bool full() {
        return top == 6 - 1;
    }

    int getTop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return array[top];
    }

    void makeEmpty() {
        top = -1;
    }

    void display() {
        if (empty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << array[i] << "\t";
        }
        cout << endl;
    }
    ~Stack() {
        delete[] array;
    }
};

int main() {

    Stack s;
    s.push(10);
    s.push(6);
    s.push(1);
    s.push(3);
    s.push(78);
    s.push(90);
    s.display();
    cout << "Is stack full? " << (s.full() ? "Yes" : "No") << endl;
    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;
    cout << "Top element: " << s.getTop() << "\n";

    s.pop();
    s.display();

    return 0;
}
