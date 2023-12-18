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

class ShapeTester {
public:
	static void testShapes() {
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
	}
};

int main() {
	ShapeTester::testShapes();
	return 0;
}
// In this revised version, the ShapeTester class contains a static method testShapes() which performs the testing logic on the Shape hierarchy.
// The main() function then simply calls this method to run the tests.

// This allows you to organize test-related functionality into a separate class, making it easy to add additional tests or organize test suites in a real-world scenario.
// The testShapes() method creates shapes, calculates their total area, and cleans up memory allocated for the shapes.