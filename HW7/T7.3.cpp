#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Car {
private:
    string model;
    string licensePlate;

public:
    Car(const string& model, const string& licensePlate) {
        this->model = model;
        this->licensePlate = licensePlate;
    }
    string getModel() const {
        return model;
    }
    string getLicensePlate() const {
        return licensePlate;
    }
};

class Driver {
private:
    string name;
    int age;
    Car* car;  // Reference to a Car object
public:
    Driver(const string& n, int a) {
        this->name = n;
        this->age = a;
        this->car = nullptr;
    }
    void assignCar(Car* c) {
        car = c;
    }
    string getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
    Car* getCar() const {
        return car;
    }
};

class Fleet {
private:
    vector<Driver> drivers;

public:
    void addDriver(const string& name, int age) {
        drivers.push_back(Driver(name, age));
    }
    void addCarToDriver(const string& driverName, const string& modelName, const string& licensePlate) {
        for (Driver& driver : drivers) {
            if (driver.getName() == driverName) {
                driver.assignCar(new Car(modelName, licensePlate));
                break;
            }
        }
    }
    void removeDriver(const string& name) {
        auto it = remove_if(drivers.begin(), drivers.end(), [name](const Driver& d) {
            return d.getName() == name;
            });
        drivers.erase(it, drivers.end());
    }
    void showFleet() const {
        cout << "Fleet Information:\n";
        for (const Driver& driver : drivers) {
            cout << "Driver: " << driver.getName() << ", Age: " << driver.getAge();
            if (driver.getCar()) {
                cout << ", Car: " << driver.getCar()->getModel() << " (License Plate: " << driver.getCar()->getLicensePlate() << ")";
            }
            cout << "\n";
        }
    }
    int getNumberOfDrivers() const {
        return drivers.size();
    }
};

int main() {
    Fleet fleet;
    fleet.addDriver("Daniel", 30);
    fleet.addDriver("Anna-Maria", 25);
    fleet.addCarToDriver("Daniel", "Toyota", "DJ22DSS");
    fleet.addCarToDriver("Anna-Maria", "Opel", "DJ78DNS");
    fleet.showFleet();
    fleet.removeDriver("Daniel");
    fleet.showFleet();
    cout << "Number of drivers: " << fleet.getNumberOfDrivers() << std::endl;
    return 0;
}
