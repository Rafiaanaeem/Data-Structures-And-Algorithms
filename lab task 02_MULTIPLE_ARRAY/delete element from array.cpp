#include <iostream>
using namespace std;

void input(int* ptr, int& size) {
    for (int i = 0; i < size; i++) {
        cin >> ptr[i];
    }
}

void display(int* ptr, int size) {
    for (int i = 0; i < size; i++) {
        cout << ptr[i] << "\t";
    }
    cout << endl;
}

void deleteFromStart(int* ptr, int& size) {
    for (int i = 0; i < size - 1; i++) {
        ptr[i] = ptr[i + 1];
    }
    size--;
}

void deleteFromEnd(int& size) {
    size--;
}

void deleteFromIndex(int* ptr, int& size, int index) {
   
    for (int i = index; i < size - 1; i++) {
        ptr[i] = ptr[i + 1];
    }
    size--;
}

int main() {
    int arr[10];
    int size = 8;
    int* ptr = arr; 

    cout << "Enter the array elements: " << endl;
    input(ptr, size);

    cout << "Your array is: " << endl;
    display(ptr, size);

    deleteFromStart(ptr, size);
    cout << "After deleting the first element, your array is: " << endl;
    display(ptr, size);

    deleteFromEnd(size);
    cout << "After deleting the last element, your array is: " << endl;
    display(ptr, size);

    int index;
    cout << "Enter the index from which you want to delete an element: ";
    cin >> index;

    deleteFromIndex(ptr, size, index);
    cout << "Element deleted from index " << index << "." << endl;
    display(ptr, size);
    return 0;
}
