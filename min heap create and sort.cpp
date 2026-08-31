#include <iostream>
using namespace std;

// Heapify for Min Heap
void minHeapify(int a[], int n, int i) {
    int small = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] < a[small])
        small = left;

    if (right < n && a[right] < a[small])
        small = right;

    if (small != i) {
        swap(a[i], a[small]);
        minHeapify(a, n, small);
    }
}

void heapSortMin(int a[], int n) {
    // Build min heap
    for (int i = (n / 2) - 1; i >= 0; i--)
        minHeapify(a, n, i);

    // Extract elements one by one (gives descending order)
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        minHeapify(a, i, 0);
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

    heapSortMin(a, n);

    cout << "Sorted (Min-Heap / Descending): ";
    printArray(a, n);

    return 0;
}
