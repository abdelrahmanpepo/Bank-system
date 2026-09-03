#include <iostream>
#include <string>
#include <exception>

#include "Person.h"
#include "Employee.h"
#include "Validation.h"

using namespace std;

Employee::Employee(int id, string name, string password, double salary)
    : Person(id, name, password)
{
    setName(name);
    setPassword(password);
    setSalary(salary);
}

double Employee::getSalary() const
{
    return salary;
}

void Employee::setSalary(double salary)
{
    if (!Validation::isValidSalary(salary))
    {
        throw invalid_argument("Salary must be at least 5000.");
    }

    this->salary = salary;
}

void Employee::setName(string name)
{
    if (!Validation::isValidName(name))
    {
        throw invalid_argument("Invalid name.");
    }

    this->name = name;
}

void Employee::setPassword(string password)
{
    if (!Validation::isValidPassword(password))
    {
        throw invalid_argument("Invalid password.");
    }

    this->password = password;
}

void Employee::display() const
{
    cout << "Employee Details:" << endl;

    Person::display();

    cout << "Salary: " << salary << endl;
}