#include <iostream>
using namespace std;

void input(int* ptr, int size) {
    for (int i = 0; i < size; i++) {
        cin >> ptr[i];
    }
}

void insertAtStart(int*& ptr, int& size, int ele) {
    for (int i = size; i > 0; i--) {
        *(ptr + i) = *(ptr + i - 1);
    }
    *(ptr) = ele;
    size++;
}

void display(int* ptr, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(ptr + i) << "\t";
    }
    cout << endl;
}

void insertAtLast(int*& ptr, int& size, int element) {
    *(ptr + size) = element;
    size++;
}

void insertAtIndex(int*& ptr, int& size, int index, int element) {
    for (int i = size; i > index; i--) {
        *(ptr + i) = *(ptr + i - 1);
    }
    *(ptr + index) = element;
    size++;
}

int main() {
    int arr[10];
    int size = 5;
    int* ptr = arr;  

    cout << "Enter the array elements: " << endl;
    input(ptr, size);

    cout << "Your array is: " << endl;
    display(ptr, size);

    int el1;
    cout << "Enter the element you want to insert at the start of the array: ";
    cin >> el1;
    insertAtStart(ptr, size, el1);
    cout << "Element inserted at the start of the array: " << endl;
    display(ptr, size);

    int el2;
    cout << "Enter the element you want to insert at the end of the array: ";
    cin >> el2;
    insertAtLast(ptr, size, el2);
    cout << "Element inserted at the end of the array: " << endl;
    display(ptr, size);

    int index, el3;
    cout << "Enter the index at which you want to insert an element: ";
    cin >> index;
    cout << "Enter the element: ";
    cin >> el3;

    insertAtIndex(ptr, size, index, el3);
    cout << "Element inserted at index " << index << " of the array: " << endl;
    display(ptr, size);

    return 0;
}
