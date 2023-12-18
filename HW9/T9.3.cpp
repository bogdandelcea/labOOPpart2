#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

using namespace std;


class Shape {
public:
	virtual double area() = 0;
	virtual ~Shape() = default;
};

class Circle : public Shape {
private:
	double radius;
public:
	Circle(double radius) {
		this->radius = radius;
	}
	double area() override {
		return M_PI * radius * radius;
	}
};

class Rectangle : public Shape {
private:
	double width;
	double height;
public:
	Rectangle(double width, double height) {
		this->width = width;
		this->height = height;
	}
	double area() override {
		return width * height; 
	}
};

class Square : public Shape {
private:
	double side;
public:
	Square(double side){
		this->side = side;
	}
	double area() override {
		return side * side; 
	}
};

int main() {
	Circle circle(5.0);
	Rectangle rectangle(4.0, 6.0);
	Square square(5.0);
	cout << "Area of the circle: " << circle.area() << endl;
	cout << "Area of the rectangle: " << rectangle.area() << endl;
	cout << "Area of the square: " << square.area() << endl;
	return 0;
}