#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HummerWheel {
private:
    string wheelDesign;
public:
    HummerWheel(string wheelDesign) {
        this->wheelDesign = wheelDesign;
    }
    void setDesign(string design) {
        this->wheelDesign = design;
    }
    string getDesign() {
        return this->wheelDesign;
    }
};

class Hummer {
private:
    vector<HummerWheel> wheels;
public:
    Hummer(string const& design) {
        for (int i = 0; i < 4; i++) {
            wheels.push_back(HummerWheel(design));
        }
    }
    void removeWheel(int wheelNumber) {
        if (wheelNumber >= 0 && wheelNumber < 4) {
            wheels[wheelNumber].setDesign("No Wheel");
        }
        else {
            cout << "Invalid wheel number!\n";
        }
    }
    void replaceWheel(int wheelNumber, string const& newDesign) {
        if (wheelNumber >= 0 && wheelNumber < 4) {
            wheels[wheelNumber].setDesign(newDesign);
        }
        else {
            cout << "Invalid wheel number!\n";
        }
    }
    void displayWheels() {
        cout << "Hummer Wheels:\n";
        for (int i = 0; i < 4; ++i) {
            cout << "Wheel " << i + 1 << ": " << wheels[i].getDesign() << endl;
        }
    }
};

int main() {
    Hummer hummer("Hummer Design");
    hummer.displayWheels();
    hummer.removeWheel(2);
    hummer.replaceWheel(1, "New Design");
    hummer.displayWheels();
    return 0;
}
