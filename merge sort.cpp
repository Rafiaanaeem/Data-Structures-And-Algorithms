#include <iostream>
using namespace std;

// Merge two sorted parts
void merge(int array[], int left, int mid, int right) {

    int i = left;
    int j = mid + 1;
    int k = 0;

    int size = right - left + 1;
    int* temp = new int[size];

    // Compare elements from both parts
    while (i <= mid && j <= right) {

        if (array[i] <= array[j]) {
            temp[k] = array[i];
            i++;
        }
        else {
            temp[k] = array[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements from left part
    while (i <= mid) {
        temp[k] = array[i];
        i++;
        k++;
    }

    // Copy remaining elements from right part
    while (j <= right) {
        temp[k] = array[j];
        j++;
        k++;
    }

    // Copy sorted elements back to original array
    for (i = left, k = 0; i <= right; i++, k++) {
        array[i] = temp[k];
    }

    delete[] temp;
}


// Merge Sort function
void mergeSort(int array[], int left, int right) {

    if (left < right) {

        int mid = left + (right - left) / 2;

        // Sort left half
        mergeSort(array, left, mid);

        // Sort right half
        mergeSort(array, mid + 1, right);

        // Merge both sorted halves
        merge(array, left, mid, right);
    }
}


int main() {

    int array[10];

    cout << "Enter 10 elements: ";

    for (int i = 0; i < 10; i++) {
        cin >> array[i];
    }

    // Sort the array
    mergeSort(array, 0, 9);

    cout << "Sorted array: ";

    for (int i = 0; i < 10; i++) {
        cout << array[i] << "\t";
    }

    cout << endl;

    return 0;
}