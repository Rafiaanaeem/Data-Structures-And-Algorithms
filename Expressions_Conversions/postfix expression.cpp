#include<iostream>   //evaluating postfix expression
#include<cmath>
using namespace std; 
class stack {
private:
	int top;
	int size;
	int* arr;
public:
	stack(int s) {
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
		else {
			int value = arr[top];
			top--;
			return value;
		}
	}
	
	~stack() {
		delete[]arr;
	}

};

int function(string postfix) {
	postfix += ')';
	int l = postfix.length();
	stack s(l);

	string exp;
	int i = 0;
		while (postfix[i] != ')') {
			if (postfix[i] >= '0' && postfix[i] <= '9') {
				s.push(postfix[i] - '0');
			}
			else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
				char op = postfix[i];
				int A = s.pop();
				int B = s.pop();
				int res = 0;
				switch (op) {
				case '+': res = B + A; break;
				case '-': res = B - A; break;
				case '*': res = B * A; break;
				case '/': res = B / A; break;
				case '^': res = pow(B, A); break;
				default: cout << "Invalid operator" << endl; return -1;
				}
				s.push(res);
			}
			i++;
		}
	return s.pop();
}
int main() {
	string postfix;
	cin >> postfix;
	int result=function(postfix);
	cout << "result : " << result << endl;
	return 0;
}