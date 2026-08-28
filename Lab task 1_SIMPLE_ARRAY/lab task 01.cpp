// array size and elements initialization
#include <iostream>
using namespace std;
template <typename T>
class Array {
private:
   T size;
    T data;  
public:
    Array(T s, T dat) {
       
        size = s;
        data = dat;
    }
    void display() {
        cout <<"size "<<size << endl;
        cout << "data "<<data << endl;
    }
    ~Array() {
    }
};
int main() {
    Array<double> a1(3.4, 10.1);  
a1.display();
}
