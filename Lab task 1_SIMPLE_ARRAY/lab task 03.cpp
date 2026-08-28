#include<iostream>
using namespace std;
class Array {
private:
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
public:
	Array() {}
	void at_function(int pos) {
		if (pos >= 0 && pos < 10) {
			cout << "element at " << pos << " is : " << endl;
			cout << arr[pos] << endl;
		}
		else {
			cout << "out of bound" << endl;
		}
	}
	void operator_function(int pos) {
		cout << arr[pos] << endl;
	}
	void front_function() {
		cout << "1st element is " << endl;
		cout << arr[0] << endl;
	}
	void back_function() {
		cout << "last element is " << endl;
		cout << arr[9] << endl;
	}
	int l = 0;
	void size_function() {
		
		for (int i = 0;i < 10;i++) {
			l++;
		}
		cout << "size is " <<l<< endl;
	}
	void empty_function() {
		if (l == 0) {
			cout << "array is empty" << endl;
		}
		else {
			cout << "array is not empty" << endl;
		}
	}
};
int main() {
	cout << "enter the index for at function" << endl;
	int ind;
	cin >> ind;
	int index;
	cout << "enter the index for operator function" << endl;
	cin >> index;
	Array a1;
	a1.at_function(ind);
	a1.operator_function(index);
	a1.front_function();
	a1.back_function();
	a1.size_function();
	a1.empty_function();
	return 0;
}