#include<iostream>
using namespace std;
void input(int* p, int* p2) {
	for (int i = 0;i < 5;i++) {
		cin >> p[i];
	}
	for (int j = 0;j < 5;j++) {
		cin >> p2[j];
	}
}
void display(int* p, int* p2) {
	cout << "1st arary is " << endl;
	for (int i = 0;i < 5;i++) {
		cout << p[i] << "\t";
	}
	cout << endl;
	cout << "2nd array is " << endl;
	for (int j = 0;j < 5;j++) {
		cout << p2[j] << "\t";
	}
	cout << endl;
}
void swap(int* p, int* p2) {
	for (int i = 0;i < 5;i++) {
		int temp = p[i];
		p[i] = p2[i];
		p2[i] = temp;
	}
}
int main() {
	int arr1[5], arr2[5];
	int* p = arr1;
	int* p2 = arr2;
	cout << "enter array elements" << endl;
	input(p, p2);
	display(p, p2);
	swap(p, p2);
	cout << "swapped arrays are" << endl;
	display(p, p2);
	return 0;
}