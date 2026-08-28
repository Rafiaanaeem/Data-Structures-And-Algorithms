#include<iostream>
#include<string>
using namespace std;
void reverse(string& str,int len) {
	int start = 0, end = len - 1;
	char temp;
	while (start < end) {
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	for (int i = 0; i < len; i++) {
		if (str[i] == '(')
			str[i] = ')';
		else if (str[i] == ')')
			str[i] = '(';
	}
}

class stack {
private:
	int top;
	int size;
	char* arr;
public:
	stack(int s) {
		size = s;
		top = -1;
		arr = new char[size];
	}
	void push(char val) {
		if (top == size - 1) {
			cout << "Stack Overflow" << endl;
			return;
		}
		top++;
		arr[top] = val;
	}
	char pop() {
		if (top == -1) {
			cout << "Stack Underflow!" << endl;
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
	stack s(infix.length()+2);
	s.push('(');
	infix += ')';
	string prefix;
	for (int i = 0;i < infix.length();i++) {
		if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z' || infix[i] >= '0' && infix[i] <= '9') {
			prefix += infix[i];
		}
		else if (infix[i] == '(') {
			s.push(infix[i]);
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
			while (!s.isEmpty() && precedence(s.peek()) >= precedence(infix[i])) {
				prefix += s.pop();
			}
			s.push(infix[i]);
		}
		else if (infix[i] == ')') {
			while (!s.isEmpty() && s.peek() != '(') {
				prefix += s.pop();
			}
			s.pop();
		}

	}
	while (!s.isEmpty()) {
		prefix += s.pop();
	}
	return prefix;
}
int main() {

	string infix;
	cin >> infix;
	cout << "Infix :" << infix << endl;
	int y = infix.length();
	reverse(infix, y);
	cout << "Infix after reversing : " << infix << endl;

	string prefix = function(infix);
	int len = prefix.length();
	reverse(prefix, len);
	cout << "Prefix " <<prefix << endl;

}