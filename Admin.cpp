#include <iostream>
#include <string>
#include <exception>
#include <cctype>
#include "Person.h"
#include "Admin.h"
Admin::Admin(int id, string name, string password, double salary) :Person(id, name, password) {
	setName(name);
	setPassword(password);
	setSalary(salary);
}
double Admin::getSalary() const { return salary; }
void Admin::setSalary(double salary) {
	if (salary < 5000) {
		throw invalid_argument("Salary must be at least 5000.");
	}
	else {
		this->salary = salary;
	}
}
void Admin::setName(string name){
	if (name.size() >= 3 && name.size() <= 20) {
		for (int i = 0; i < name.size(); i++) {
			if (!isalpha(name[i])) {
				throw invalid_argument("Name must contain alphabetic characters only.");
			}
		}
		this->name = name;
	}
	else {
		throw invalid_argument("Name must be between 3 and 20 characters.");
	}
}
void Admin::setPassword(string password) {
	if (password.size() >= 8 && password.size() <= 20) {
		for (int i = 0; i < password.size(); i++) {
			if (password[i] == ' ') {
				throw invalid_argument("Password must not contain spaces.");
			}
		}
		this->password = password;
	}
	else {
		throw invalid_argument("Password must be between 8 and 20 characters.");
	}
}
void Admin::display() const {
	cout << "Admin Details:" << endl;
	Person::display();
	cout << "Salary: " << salary << endl;
}


