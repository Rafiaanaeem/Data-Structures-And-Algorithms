// evaluating prefix expresiion
#include <iostream>
#include <cmath>
using namespace std;

void reverse(string& str) {
    int start = 0, end = str.length() - 1;
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

class Stack {
private:
    int top;
    int size;
    int* arr;

public:
    Stack(int s) {
        size = s;
        top = -1;
        arr = new int[size];
    }

    void push(int val) {
        if (top == size - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    ~Stack() {
        delete[] arr;
    }
};


int evaluatePrefix(string prefix) {
    Stack s(prefix.length());

    for (int i = 0; i < prefix.length(); i++) {
        if (prefix[i]>='0' && prefix[i]<='9') {
            s.push(prefix[i] - '0');
        }
        else if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/' || prefix[i] == '^') {
            
            int A = s.pop();
            int B = s.pop();
            int res = 0;

            switch (prefix[i]) {
            case '+': res = A + B; break;
            case '-': res = A - B; break;
            case '*': res = A * B; break;
            case '/': res = A / B; break;
            case '^': res = pow(A, B); break;
            default: cout << "Invalid operator" << endl; 
                return -1;
            }
            s.push(res);
        }
    }
    return s.pop();
}

int main() {
    string prefix;
    cin >> prefix;

    reverse(prefix); 

    cout << "Reversed Expression: " << prefix << endl;

    int result = evaluatePrefix(prefix);
    cout << "Result: " << result << endl;

    return 0;
}
