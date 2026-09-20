#pragma once
#include <iostream>
#include "Validation.h"
#include "Client.h"
#include "Employee.h"
#include <vector>

using namespace std;
class Admin : public Employee{
private:
    vector<Employee> employees;
public:
    Admin(int id, string name, string password, double salary);
    void display() const override;
    void addEmployee(Employee& employee);
    Employee* searchEmployee(int id);
    void editEmployee(int id, string name, string password, double salary);
    void listEmployee();

};




