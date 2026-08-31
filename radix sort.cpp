#include <iostream>
#include <string>
using namespace std;

int find_index_of_alph(const string& str, int pos) {
    int s = str.size();
    int size=int(s);
    if (pos >= size) {  // when there is no character in string
        return 0;  // bin 0 for missing letter
    } else{
        return (str[pos] - 'a') + 1;
    }
}
void counting_sort(string arr[], int n, int pos) {
    const int total_bins = 27;     // for alphabets .. there are always 27 bins. 
    string bins[total_bins][100];   // total 27 rows and each row can get max 100 strings
    int count[total_bins] = { 0 };
    for (int i = 0; i < n; i++) {
        int index = find_index_of_alph(arr[i], pos);
        int c = count[index];   
        bins[index][c] = arr[i]; 
        count[index] = c + 1;    
    }
    int k = 0;
    for (int b = 0; b < total_bins; b++)
        for (int j = 0; j < count[b]; j++)
            arr[k++] = bins[b][j];
}

void radix_sort(string arr[], int n) {
    int maxLen = 0;
    int len;
    for (int i = 0; i < n; i++)
        len = arr[i].size();  
    if (len > maxLen)          
        maxLen = len;        
    for (int pos = maxLen - 1; pos >= 0; pos--)
        counting_sort(arr, n, pos);
}

int main() {
    int size;
    cout << "Enter number of strings u want to enter: "<<endl;  
    cin >> size;
    string* array = new string[size];
   // string array[100];
    cout << "Enter " << size << " strings:"<<endl;
    for (int i = 0; i < size; i++)
        cin >> array[i];

    cout << "your input strings array is:"<<endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    radix_sort(array, size);
    cout << "After lexicographical sorting, your input strings are as follows:" << endl;
    for (int i = 0; i < size; i++) 
    { cout << array[i] << " ";
    }
    cout << endl;
    delete[]array;
}