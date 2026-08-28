#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
using namespace std;


void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function (same as normal quicksort)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // Pivot is the last element
    int i = low;             // i will point to the correct place for smaller elements

    for (int j = low; j < high; j++) {
        // If current element is smaller than pivot
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]); // send smaller element to left side
            i++;                  // move i forward
        }
    }

    // Now place the pivot at its correct position
    swap(arr[i], arr[high]);

    return i; // return pivot index
}


// Function to pick a random pivot and put it at end
int randomizedPartition(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1); // random index
    swap(arr[randomIndex], arr[high]); // swap random pivot with last element
    return partition(arr, low, high);
}

// Randomized Quick Sort
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array using random pivot
        int pi = randomizedPartition(arr, low, high);

        // Recursively sort left and right parts
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

int main() {
    // rand() genertes the random numbers
    srand(time(0)); //  s sets the starting point for random number generation.time(0) ensures that we get a different pivot every time in seconds

    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    randomizedQuickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
