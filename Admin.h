#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <cctype>
#include "Person.h"
#include "Employee.h"
using namespace std;
class Admin : public Employee {
public:
	Admin(int id, string name, string password, double salary);

};



