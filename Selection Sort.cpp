#include <iostream>
using namespace std;

void selectionSort(int array[], int size) {

    for (int i = 0; i < size - 1; i++) {

        int minIndex = i;

        // Find the smallest element
        for (int j = i + 1; j < size; j++) {

            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }

        // Swap
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

int main() {

    int array[10];

    cout << "Enter 10 elements: ";

    for (int i = 0; i < 10; i++) {
        cin >> array[i];
    }

    selectionSort(array, 10);

    cout << "Sorted array: ";

    for (int i = 0; i < 10; i++) {
        cout << array[i] << "\t";
    }

    cout << endl;

    return 0;
}