#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;

class Animal {
public:
	virtual string getName() = 0;
	virtual void chase(Animal* animal) = 0;
	virtual ~Animal() = default;
};

class Mouse : public Animal {
private:
	string name;
public:
	Mouse(string name) {
		this->name = name;
	}
	string getName() override {
		return name + " as " + typeid(*this).name();
	}
	void chase(Animal* animal) override {
		cout << "Me, " << getName() << " I chase " << animal->getName() << endl;
	}
};

class Cat : public Animal {
private:
	string name;
public:
	Cat(string name) {
		this->name = name;
	}
	string getName() override {
		return name + " as " + typeid(*this).name();
	}
	void chase(Animal* animal) override {
		cout << "Me, " << getName() << " I chase " << animal->getName() << endl;
	}
};

class Dog : public Animal {
private:
	string name;
public:
	Dog(string name) {
		this->name = name;
	}
	string getName() override {
		return name + " as " + typeid(*this).name();
	}
	void chase(Animal* animal) override {
		cout << "Me, " << getName() << " I chase " << animal->getName() << endl;
	}
};

int main() {
	vector<Animal*> animalsChasingList;
	animalsChasingList.push_back(new Cat("Old Tom"));
	animalsChasingList.push_back(new Cat("Rusty"));
	animalsChasingList.push_back(new Mouse("Rodent"));
	animalsChasingList.push_back(new Cat("Tom"));
	animalsChasingList.push_back(new Dog("Buddy"));
	animalsChasingList.push_back(new Dog("Max"));
	for (size_t animalIndex = 0; animalIndex < animalsChasingList.size() - 1; ++animalIndex) {
		animalsChasingList.at(animalIndex)->chase(animalsChasingList.at(animalIndex + 1));
	}
	cout << endl << "New hunter in town!" << endl;
	Mouse* hunter = new Mouse("Tiny");
	for (auto& animal : animalsChasingList) {
		hunter->chase(animal);
	}
	for (auto animal : animalsChasingList) {
		delete animal;
	}
	animalsChasingList.clear();
	delete hunter;
	return 0;
}