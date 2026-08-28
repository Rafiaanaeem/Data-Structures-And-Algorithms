#include<iostream>
using namespace std;
const int SIZE = 10;
int binarysearch(int array[], int size, int ele) {
	int low = 0;
	int high = size - 1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (array[mid] == ele) {
			return mid;
		}
		else if (array[mid] < ele) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}
int main() {
	int array[SIZE];
	//input the array
	for (int i = 0;i < SIZE;i++) {
		cin >> array[i];
	}
	for (int i = 0;i < SIZE;i++) {
		cout << array[i] << "\t";
	}
	cout << endl;
	int element;
	cout << "enter the element which u want to search" << endl;
	cin >> element;
	int res = binarysearch(array, SIZE, element);
	if (res != -1) {
		cout << "element found at " << res << " index" << endl;
	}
	else {
		cout << "element not found" << endl;
	}
}