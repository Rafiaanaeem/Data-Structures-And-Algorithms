// expression coversion from infix to postfix

#include<iostream>
#include<string>
using namespace std;
class stack {
private:
	int top;
	int size;
	char* arr;
public:
	stack(int s) {
		size = s;
		arr = new char[size];
		top = -1;
	}
	void push(int val) {
		if (top == size - 1) {
			cout << "Stack Overflow!" << endl;
			
		}
			top++;
			arr[top] = val;
	}
	char pop() {
		if (top == -1) {
			cout << "Stack Underflow!" << endl;
			return '\0'; 
		}
		else {
			char value = arr[top];
			top--;
			return value;
		}
	}
	char peek() { 
		if (top == -1) return '\0';
		else return arr[top];
	}

	bool isEmpty() {
		return top == -1;
	}
};
int precedence(char op) {
	if (op == '^') {
		return 3;
	}
	else if (op == '/' || op == '*') {
		return 2;
	}
	else if (op == '+' || op == '-') {
		return 1;
	}
	else 
		return -1;
}
string function(string infix) {
	stack s(infix.length());
	s.push('(');
	infix += ')';
	string postfix;
	for (int i = 0;i < infix.length();i++) {
		if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z' || infix[i]>='0' && infix[i]<='9') {
			postfix += infix[i];
		}
		else if (infix[i] == '(') {
			s.push(infix[i]);
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
			while (!s.isEmpty() &&precedence(s.peek()) >= precedence(infix[i])) {
				postfix += s.pop();
			}
			s.push(infix[i]);
		}
		else if (infix[i] == ')') {
			while (!s.isEmpty() && s.peek() != '(') {
				postfix += s.pop();
			}
			s.pop();
		}
		
	}
	while (!s.isEmpty()) {
		postfix += s.pop();
	}
	return postfix;
}

int main() {
	
	string infix;
	cout << "infix string : ";
	cin >> infix;
	
	string postfix =function(infix);
	cout << "Postfix: " << postfix << endl;
	return 0;
}