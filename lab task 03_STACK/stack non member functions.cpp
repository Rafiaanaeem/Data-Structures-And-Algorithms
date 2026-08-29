#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    int top;
    T* array;
    int size;

public:
    Stack(int s) {
        size = s;
        array = new T[size];
        top = -1;
    }

    void push(T val) {
        if (top == size - 1) {
            cout << "Stack Overflow" << endl;
        }
        else {
            top++;
            array[top] = val;
        }
    }

    T pop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return array[top];
        top--;
    }

    bool empty() { 
        return top == -1; 
    }
    bool full() { 
        return top == size - 1;
    }

    T getTop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return array[top];
    }

    int getSize() {
        return top + 1;
    }

    T getElement(int index) {
        if (index >= 0 && index <= top) {
            return array[index];
        }
        return -1;
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

template <typename T>
bool operator ==(Stack<T>& s1, Stack<T>& s2) {
    if (s1.getSize() != s2.getSize()) return false;
    for (int i = 0; i < s1.getSize(); i++) {
        if (s1.getElement(i) != s2.getElement(i)) return false;
    }
    return true;
}

template <typename T>
bool operator !=(Stack<T>& s1, Stack<T>& s2) {
    return !(s1 == s2);
}

template <typename T>
bool operator >(Stack<T>& s1, Stack<T>& s2) {
    if (s1.getSize() != s2.getSize()) return false;
    for (int i = 0; i < s1.getSize(); i++) {
        if (s1.getElement(i) < s2.getElement(i)) return false;
    }
    return true;
}

template <typename T>
bool operator <(Stack<T>& s1, Stack<T>& s2) {
    if (s1.getSize() != s2.getSize()) return false;
    for (int i = 0; i < s1.getSize(); i++) {
        if (s1.getElement(i) > s2.getElement(i)) return false;
    }
    return true;
}

template <typename T>
bool operator >=(Stack<T>& s1, Stack<T>& s2) {
    return (s1 > s2) || (s1 == s2);
}

template <typename T>
bool operator <=(Stack<T>& s1, Stack<T>& s2) {
    return (s1 < s2) || (s1 == s2);
}

int main() {
    int size1;
    cout << "Enter size of stack 1: ";
    cin >> size1;
    Stack<int> s1(size1);

    cout << "Enter elements for stack 1:\n";
    for (int i = 0; i < size1; i++) {
        int val;
        cin >> val;
        s1.push(val);
    }

    int size2;
    cout << "Enter size of stack 2: ";
    cin >> size2;
    Stack<int> s2(size2);

    cout << "Enter elements for stack 2:\n";
    for (int i = 0; i < size2; i++) {
        int val;
        cin >> val;
        s2.push(val);
    }

    cout << "\nStack 1: ";
    s1.display();
    cout << "Stack 2: ";
    s2.display();

    cout << "\nComparing stacks:\n";
    cout << "Stacks are equal? " << (s1 == s2 ? "Yes" : "No") << endl;
    cout << "Stacks are not equal? " << (s1 != s2 ? "Yes" : "No") << endl;
    cout << "Stack 1 is greater? " << (s1 > s2 ? "Yes" : "No") << endl;
    cout << "Stack 1 is less? " << (s1 < s2 ? "Yes" : "No") << endl;
    cout << "Stack 1 is greater or equal? " << (s1 >= s2 ? "Yes" : "No") << endl;
    cout << "Stack 1 is less or equal? " << (s1 <= s2 ? "Yes" : "No") << endl;
    return 0;
}
