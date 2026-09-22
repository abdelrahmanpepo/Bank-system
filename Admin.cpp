#include <iostream>
#include <string>
#include "Admin.h"
#include <vector>
Admin::Admin(int id, string name, string password, double salary) :Employee(id, name, password, salary) {}
void Admin::display() const{
    cout << "=== Admin Details ===" << endl;
    Employee::display();
}
void Admin::addEmployee(Employee& employee) {
    employees.push_back(employee);
}
Employee* Admin::searchEmployee(int id) {
    for (int i = 0;i < employees.size();i++) {
        if (employees[i].getId() == id) {
            return employees[i];
        }
    }
    return nullptr;
}
void Admin::editEmployee(int id, string name, string password, double salary) {
    Employee* employee = searchEmployee(id); 
    if (employee != nullptr) {
        employee->setName(name);
        employee->setPassword(password);
        employee->setSalary(salary); 
    }
}
void Admin::listEmployee() {
    for (int i = 0;i < employees.size();i++) {
        employees[i].display();
    }
}
