#include <iostream>
using namespace std;

void insertionSort(int array[], int size) {

    for (int i = 1; i < size; i++) {

        int key = array[i];
        int j = i - 1;

        // Move elements greater than key one position ahead
        while (j >= 0 && array[j] > key) {

            array[j + 1] = array[j];
            j--;
        }

        // Insert key at correct position
        array[j + 1] = key;
    }
}

int main() {

    int array[10];

    cout << "Enter 10 elements: ";

    for (int i = 0; i < 10; i++) {
        cin >> array[i];
    }

    insertionSort(array, 10);

    cout << "Sorted array: ";

    for (int i = 0; i < 10; i++) {
        cout << array[i] << "\t";
    }

    cout << endl;

    return 0;
}