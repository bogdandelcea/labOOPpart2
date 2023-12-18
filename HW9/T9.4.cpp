#include <iostream>
#include <vector>

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
		return 3.14159 * radius * radius;
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
	Square(double side) {
		this->side = side;
	}
	double area() override {
		return side * side; 
	}
};

int main() {
	vector<Shape*> shapes;
	shapes.push_back(new Circle(5.0));
	shapes.push_back(new Rectangle(4.0, 6.0));
	shapes.push_back(new Square(5.0));
	double totalArea = 0.0;
	for (auto& shape : shapes) {
		totalArea += shape->area();
	}
	cout << "Sum of areas of shapes: " << totalArea << endl;
	for (auto shape : shapes) {
		delete shape;
	}
	shapes.clear();
	return 0;
}
// Without using OOP or classes and inheritance, you might use a more procedural approach,
// such as storing the dimensions of shapes in variables and writing separate functions to calculate areas for different shapes. 
// This would not benefit from polymorphism or the reuse of common behavior among shapes.