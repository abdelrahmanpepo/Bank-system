#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <cctype>
#include "Employee.h"
using namespace std;
class Admin : public Employee {
public:
	Admin(int id, string name, string password, double salary);

};



