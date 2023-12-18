#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
class Number {
private:
	T value;
public:
	Number(T value) {
		this->value = value;
	}
	bool operator <(const Number<T>& other) {
		return abs(value) < abs(other.value);
	}
	bool operator >(const Number<T>& other) {
		return abs(value) > abs(other.value);
	}
};

int main() {
    Number<double> complexNum(3.0); 
    double floatNum = 4.0; 
    if (complexNum < Number<double>(floatNum)) {
        cout << "Complex number's module is smaller than the float number.\n";
    }
    else {
        cout << "Complex number's module is greater than or equal to the float number.\n";
    }
    if (complexNum > Number<double>(floatNum)) {
        cout << "Complex number's module is greater than the float number.\n";
    }
    else {
        cout << "Complex number's module is less than or equal to the float number.\n";
    }
    return 0;
}