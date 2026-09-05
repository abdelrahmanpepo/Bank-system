#include <iostream>
#include <string>
#include <exception>
#include <cctype>
#include "Admin.h"
Admin::Admin(int id, string name, string password, double salary) :Employee(id, name, passeord, salary) {}
void Admin::display() const{
    cout << "=== Admin Details ===" << endl;
    Employee::display();
}