#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <cctype>
#include "Person.h"
using namespace std;
class Admin : public Person {
private:
	double salary;
public:
	Admin(int id, string name, string password, double salary);
	double getSalary() const;
	void setSalary(double salary);
	void setName(string name) override;
	void setPassword(string password) override;
	void display() const override;

};



