#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
private:
	int age;
public:
	Person(int age) {
		this->age = age;
	}
	int getAge() {
		return this->age;
	}
};

class Car {
private:
	string model;
	int year;
public:
	Car(string model, int year) {
		this->model = model;
		this->year = year;
	}
	int getYear() {
		return this->year;
	}
};

template <typename T>
class AverageCalculator {
private:
	vector<T> items;
public:
	void addItem(const T& item) {
		items.push_back(item);
	}
	double calculateAveragePerson() {
		if (items.empty()) return 0.0;
		double sum = 0.0;
		for (auto& item : items) {
			sum += item.getAge();
		}
		return sum / items.size();
	}
	double calculateAverageCar() {
		if (items.empty()) return 0.0;
		double sum = 0.0;
		for (auto& item : items) {
			sum += item.getYear();
		}
		return sum / items.size();
	}
};

int main() {
	vector<Person> persons;
	persons.emplace_back(25);
	persons.emplace_back(30);
	persons.emplace_back(22);
	vector<Car> cars;
	cars.emplace_back("Toyota", 2015);
	cars.emplace_back("Honda", 2018);
	AverageCalculator<Person> personAverage;
	for (auto& person : persons) {
		personAverage.addItem(person);
	}
	AverageCalculator<Car> carAverage;
	for (auto& car : cars) {
		carAverage.addItem(car);
	}
	cout << "Average age of persons: " << personAverage.calculateAveragePerson() << endl;
	cout << "Average age of cars (based on year): " << carAverage.calculateAverageCar() << endl;
	return 0;
}