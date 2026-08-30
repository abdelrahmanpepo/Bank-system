#include <iostream>
#include <string>
#include <exception>
#include <cctype>
#include "Person.h"
using namespace std;
class Person {
protected:
	int  id;
	string name, password;
public:
	Person::Person(int id, string name, string password) : id(id), name(name), password(password) {}
	Person::int getId() const { return id; }
	Person::string getName() const { return name; }
	Person::string getPassword() const { return password; }
	Person::void setId(int id) { this->id = id; }
	Person::virtual void setName(string name) = 0;
	Person::virtual void setPassword(string password) = 0;
	Person::void display() const {
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Password: " << password << endl;
	}
};