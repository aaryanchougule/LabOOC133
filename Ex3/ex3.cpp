//ex3
#include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;

public:
    // Constructor with default arguments
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Overloading the '+' operator
    Complex operator+(const Complex &c) const {
        cout<<real;
        cout<<imag;
        return Complex(real + c.real, imag + c.imag);
    }

    // Overloading the '-' operator
    Complex operator-(const Complex &c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    // Overloading the '<<' operator for direct printing using cout
    friend ostream& operator<<(ostream &out, const Complex &c) {
        out << c.real << " + i" << c.imag;
        return out;
    }
};

int main() {
    Complex c1(4, 5), c2(8, 9);

    // Using overloaded operators cleanly
    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "First Complex Number: " << c1 << endl;
    cout << "Second Complex Number: " << c2 << endl;
    cout << "Addition: " << sum << endl;
    cout << "Subtraction: " << diff << endl;

    return 0;
}
