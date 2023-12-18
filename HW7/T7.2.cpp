#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Group {
private:
	class Student {
	private:
		string name;
		int age;
	public:
		Student(string name, int age) {
			this->name = name;
			this->age = age;
		}
		string getName() {
			return this->name;
		}
		int getAge() {
			return this->age;
		}
	};
	string groupName;
	vector<Student> students;
public:
	Group(string groupName) {
		this->groupName = groupName;
	}
	void addStudent(string const& name, int age) {
		students.push_back(Student(name, age));
	}
	void displayGroup() {
		cout << groupName << "\n";
		cout << "Students:\n";
		for (auto& student : students) {
			cout << "Name: " << student.getName() << ", Age: " << student.getAge() << "\n";
		}
		cout << "---------------------\n";
	}
};

int main() {
	Group group1("Group 1");
	group1.addStudent("Sorina", 20);
	group1.addStudent("Bogdan", 22);
	Group group2("Group 2");
	group2.addStudent("Catalin", 21);
	group2.addStudent("Eduard", 19);
	group1.displayGroup();
	group2.displayGroup();
	return 0;
}