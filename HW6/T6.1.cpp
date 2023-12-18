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
	double getReal() {
		return this->real;
	}
	double getImag() {
		return this->imag;
	}
	Complex operator + (Complex const& obj) {
		return Complex(this->real + obj.real, this->imag + obj.imag);
	}
	double operator ~ () {
		return sqrt(real * real + imag * imag);
	}
	Complex operator ^ (int power) {
		if (power == 2) {
			double newReal = real * real - imag * imag;
			double newImag = 2 * real * imag;
			return Complex(newReal, newImag);
		}
		else {
			cout << "Power != 2 isn't supported" << endl;
			return Complex(0, 0);
		}
	}
};

int main()
{
	Complex a(3, 4);
	Complex b(1, -2);
	Complex sum = a + b;
	cout << "Sum:" << sum.getReal() << " + " << sum.getImag() << "i\n";
	double absA = ~a;
	double absB = ~b;
	cout << "Absolute value of a: " << absA << endl;
	cout << "Absolute value of b: " << absB << endl;
	Complex squaredA = a ^ 2;
	Complex squaredB = b ^ 2;
	cout << "Square of a: " << squaredA.getReal() << " + " << squaredA.getImag() << "i\n";
	cout << "Square of b: " << squaredB.getReal() << " + " << squaredB.getImag() << "i\n";
	return 0;

}
