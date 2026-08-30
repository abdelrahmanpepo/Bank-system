#include <iostream>
#include <string>
#include <exception>
#include <cctype>
#include "Person.h"
using namespace std;
Person::Person(int id, string name, string password) : id(id), name(name), password(password) {}
int Person::getId() const { return id; }
string Person::getName() const { return name; }
string Person::getPassword() const { return password; }
void Person::setId(int id) { this->id = id; }
void Person::display() const {
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Password: " << password << endl;
}