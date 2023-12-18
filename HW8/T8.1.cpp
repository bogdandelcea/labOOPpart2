#include <iostream>
#include <cmath>

using namespace std;

class ComplexNumber {
private:
	double real;
	double imaginary;
public:
	ComplexNumber(double real, double imaginary) {
		this->real = real;
		this->imaginary = imaginary;
	}
	double getModule() {
		return sqrt(real * real + imaginary * imaginary);
	}
	static ComplexNumber minModule(ComplexNumber& num1, ComplexNumber& num2) {
		return (num1.getModule() < num2.getModule()) ? num1 : num2;
	}
};

int main()
{
	ComplexNumber num1(5, 9);
	ComplexNumber num2(-3, 6);
	ComplexNumber result = ComplexNumber::minModule(num1, num2);
	cout << "Complex number with minimum module: " << result.getModule() << endl;
	return 0;
}
