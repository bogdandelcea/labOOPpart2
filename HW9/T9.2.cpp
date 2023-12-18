#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vehicle {
public:
	virtual void start() = 0;
};

class Rocket : public Vehicle {
private:
	string name;
public:
	Rocket(string name) {
		this->name = name;
	}
	void start() override {
		cout << "start " << name << " rocket" << endl;
	}
};

class Car : public Vehicle {
private:
	string name;
public:
	Car(string name) {
		this->name = name;
	}
	void start() override {
		cout << "start " << name << " car" << endl;
	}
};

int main() {
	vector<Vehicle*> vehicles;
	vehicles.push_back(new Car("Toyota"));
	vehicles.push_back(new Car("Opel"));
	vehicles.push_back(new Rocket("NASA"));
	for (auto element : vehicles) {
		element->start();
	}
	for (auto vehicle : vehicles) {
		delete vehicle;
	}
	vehicles.clear();
	return 0;
}