#include <iostream>
using namespace std;

// Heapify for Max Heap
void maxHeapify(int a[], int n, int i) {
    int big = i;          // Initialize largest as root
    int left = 2 * i + 1; // left child
    int right = 2 * i + 2; // right child

    if (left < n && a[left] > a[big])
        big = left;

    if (right < n && a[right] > a[big])
        big = right;

    if (big != i) {
        swap(a[i], a[big]);
        maxHeapify(a, n, big);
    }
}

void heapSortMax(int a[], int n) {
    // Build max heap
    for (int i = (n / 2) - 1; i >= 0; i--)
        maxHeapify(a, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);         // Move current root to end
        maxHeapify(a, i, 0);      // Heapify the reduced heap
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[] = { 4, 10, 3, 5, 1 };
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Original array: ";
    printArray(a, n);

    heapSortMax(a, n);

    cout << "Sorted (Max-Heap / Ascending): ";
    printArray(a, n);

    return 0;
}
