#include <iostream>
#include <string>

using namespace std;

class Shape {
public:
	virtual void draw() = 0;
	virtual ~Shape() = default;
};

class Circle : public Shape {
public:
	void draw() override { cout << "Circle\n"; }
};

class Triangle : public Shape {
public:
	void draw() override { cout << "Triangle\n"; }
};

class Drawing {
private:
	Shape* shape;
public:
	Drawing(Shape* shape) {
		this->shape = shape;
	}
	void drawShape() {
		if (shape) {
			shape->draw();
		}
		else cout << "No shape provided\n";
	}
};

int main() {
	Circle circle;
	Triangle triangle;
	Drawing drawingWithCircle(&circle);
	Drawing drawingWithTriangle(&triangle);
	drawingWithCircle.drawShape();
	drawingWithTriangle.drawShape();
	return 0;
}
