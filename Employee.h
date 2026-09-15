#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include "Validation.h"

class Employee : public Person
{
private:
    double salary;

public:
    Employee(int id, string name, string password, double salary);

    void setName(string name);
    void setPassword(string password);
    void setSalary(double salary);

    string getName();
    string getPassword();
    double getSalary();

    void display();
};

#endif