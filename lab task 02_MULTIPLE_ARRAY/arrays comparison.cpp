#include<iostream>
using namespace std;
class Array {
private:
	int arr[5] = { 23,34,67,90,89 };
	int arr2[5] = { 14,17,64,77,33 };
	int* p = arr;
	int* p2 = arr2;
public:
	Array(){}
	bool function_op_equal () {
		bool flag = false;
		for (int i = 0;i < 5;i++) {
			if (p[i] != p2[i]) {
				flag = true;
				break;
			}
		}
		if (flag == true) {
			return false;
		}
		else {
			return true;
		}
	}
	bool function_op_greater() {
		bool flag = false;
		for (int i = 0;i < 5;) {
			if (p[i] < p2[i]) {
				flag = true;
				break;
			}
			else {
				i++;
			}
		}
		if (flag == true) {
			return false;
		}
		else {
			return true;
		}
	}
	bool function_op_less() {
		bool flag = false;
		for (int i = 0;i < 5;) {
			if (p[i] > p2[i]) {
				flag = true;
				break;
			}
			else {
				i++;
			}
		}
		if (flag == true) {
			return false;
		}
		else {
			return true;
		}
	}
	bool function_op_greaterthan_equal() {
		bool flag = false;
		for (int i = 0;i < 5;) {
			if (p[i] < p2[i] && p[i]!=p2[i]) {
				flag = true;
				break;
			}
			else {
				i++;
			}
		}
		if (flag == true) {
			return false;
		}
		else {
			return true;
		}
	}
	bool function_op_lessthan_equal() {
		bool flag = false;
		for (int i = 0;i < 5;) {
			if (p[i] >p2[i] && p[i] != p2[i]) {
				flag = true;
				break;
			}
			else {
				i++;
			}
		}
		if (flag == true) {
			return false;
		}
		else {
			return true;
		}
	}
};
int main() {
	Array a1;
	bool r1=a1.function_op_equal();
	cout << "the result of equal operator is " << r1 << endl;
	bool r2=a1.function_op_greater();
	cout << "the result of greater than operator is " << r2 << endl;
	bool r3=a1.function_op_less();
	cout << "the result of less than operator is " << r3 << endl;
	/*bool r4 = a1.function_op_greaterthan_equal();
	cout << r4 << endl;
	bool r5= a1.function_op_lessthan_equal();
	cout << r5 << endl;*/
	cout << "The result of greater than or equal operator is " << a1.function_op_greaterthan_equal() << endl;
	cout << "The result of less than or equal operator is " << a1.function_op_lessthan_equal() << endl;
	return 0;
}