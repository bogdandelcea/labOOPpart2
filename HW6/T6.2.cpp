#include <iostream>
#include <cmath>

using namespace std;

class Complex {
private:
    double real;
    double imag;
public:
    Complex(double real, double imag) {
        this->real = real;
        this->imag = imag;
    }
    Complex operator + (Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }
    double getReal() {
        return this->real;
    }
    double getImag() {
        return this->imag;
    }
};

int main()
{
    Complex num1(7, 3);
    Complex num2(4, -6);
    Complex sum = num1 + num2;
    cout << "Sum: " << sum.getReal() << " + " << sum.getImag() << "i\n";
    return 0;
}
// This operator now makes the sum between this number reals and imags.