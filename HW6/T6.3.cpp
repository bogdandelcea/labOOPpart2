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
    bool operator < (Complex const& other){
        double mod1 = sqrt(real * real + imag * imag);
        double mod2 = sqrt(other.real * other.real + other.imag * other.imag);
        return mod1 < mod2;
    }
    double getReal() {
        return this->real;
    }
    double getImag() {
        return this->imag;
    }
};

int main() {
    Complex num1(2, 1);
    Complex num2(4, 3);
    if (num1 < num2) {
        cout << "Magnitude of num1 is less than magnitude of num2\n";
    }
    else {
        cout << "Magnitude of num1 is greater than or equal to magnitude of num2\n";
    }

    return 0;
}
// This operator now compares the numbers by their magnitude that is calculated with sqrt.