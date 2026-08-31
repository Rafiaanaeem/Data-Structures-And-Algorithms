#include <iostream>
using namespace std;

void bubbleSort(int array[], int size) {

    for (int i = 0; i < size - 1; i++) {

        for (int j = 0; j < size - 1 - i; j++) {

            if (array[j] > array[j + 1]) {

                // Swap elements
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {

    int array[10];

    cout << "Enter 10 elements: ";

    for (int i = 0; i < 10; i++) {
        cin >> array[i];
    }

    // Sort the array
    bubbleSort(array, 10);

    cout << "Sorted array: ";

    for (int i = 0; i < 10; i++) {
        cout << array[i] << "\t";
    }

    cout << endl;

    return 0;
}