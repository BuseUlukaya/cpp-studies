#include <iostream>
#include <string>

using namespace std;

class  Polynomial {
    private:
        int a;  
        int b;
        int c;
    public:
        Polynomial() {}
        Polynomial (int _a, int _b, int _c){
            a = _a;
            b = _b;
            c = _c;
        }
        Polynomial& operator+(const Polynomial& p1) {
            a = a + p1.a;
            b = b + p1.b;
            c = c + p1.c;
            return *this;
        }
        friend ostream& operator<<(ostream& os, const Polynomial& p);

};

ostream& operator<<(ostream& os, const Polynomial& p){
    if(p.a < 0){
         os  << p.a << "x^2 + " << p.b << "x + " << p.c;
    }
    else if(p.a >0){
        if(p.b < 0 && p.c < 0){
             os << p.a << "x^2 " << p.b << "x " << p.c ;
        }
    }
    return os;
}

int main(){
    Polynomial p1(-1, 2, 5);
    Polynomial p2(3, -4, -6);
    Polynomial p3;

    cout << p1 << " -> Polynomial 1 " << endl;
    cout << p2 << " -> Polynomial 2 " << endl;

    p3 = p1 + p2;

    cout << p3 << " -> Polynomial Summation Result " << endl;

    return 0;
}
