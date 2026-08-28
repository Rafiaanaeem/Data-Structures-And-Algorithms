#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int* array;
    int size; 

public:
    Stack(int s) {
        size = s;
        array = new int[size];
        top = -1;
    }

  
    void push(int val) {
        if (top == size - 1) { 
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
        return top == size - 1;
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
    int size;
    cout << "Enter size of stack: ";
    cin >> size;

    Stack s(size);
    s.push(10);
    s.push(6);
    s.push(1);
    s.push(3);
    s.push(78);

    cout << "Is stack full? " << (s.full() ? "Yes" : "No") << endl;
    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;
    cout << "Top element: " << s.getTop() << "\n";

    s.pop();
    s.display();

    return 0;
}
