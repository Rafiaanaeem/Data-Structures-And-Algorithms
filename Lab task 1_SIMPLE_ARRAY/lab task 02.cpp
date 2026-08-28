#include <iostream>
using namespace std;

class Array {
private:
    int arr[5] = { 1,2,3,4,5 };
    int arr2[5] = { 10,11,12,13,14 };

public:
    void isequal() {
        for (int i = 0;i < 5;i++) {
            arr[i] = arr2[i];
        }
   }
    void display() {
        for (int i = 0; i < 5; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Array a1;
    cout << "before override" << endl;
    a1.display();
    a1.isequal();
    cout << "after override" << endl;
    a1.display();
}
