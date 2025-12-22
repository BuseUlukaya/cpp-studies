#include <iostream>

using namespace std;

class Number{
    private:
        int size;
        int *arr;
    public:
        Number() {}
        Number(int s) {
            this->size = s;
            arr = new int[size];
        }
        Number(Number& n) {
            this->size = n.size;
            arr = new int[size];

            for(int i=0; i<size; i++) {
                arr[i] = n.arr[i];
            }
        }
        ~Number() {
            delete[] arr;
        }
        friend ostream& operator<<(ostream& os, const Number& n);
        friend istream& operator>>(istream& in, Number& n);
        Number& operator=(const Number& n) {
            arr = new int[size];
            this->size = n.size;

            for(int i=0; i<size; i++) {
                arr[i] = n.arr[i];
            }

            return *this;
        }
};

ostream& operator<<(ostream& os, const Number& n) {
    for(int i=0; i<n.size; i++) {
        os << n.arr[i] << " ";
    }

    return os;
}

istream& operator>>(istream& in, Number& n) {
    n.arr = new int[n.size];
    
    for(int i=0; i<n.size; i++) {
        in >> n.arr[i];
    }

    return in;
}

int main() {
    Number A(5);
    cin >> A;

    cout << "Array of object A: " << A << endl;

    Number B = A;
    cout << "Array of object B: " << B << endl;

    Number C(3);
    C = A;
    cout << "Array of object C: " << C << endl;

    return 0;
}