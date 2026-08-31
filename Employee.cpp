#include <iostream>
#include <string>
#include <exception>
#include <cctype>
#include "Person.h"
#include "Employee.h"

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
    if (salary < 5000)
    {
        throw invalid_argument("Salary must be at least 5000.");
    }

    this->salary = salary;
}

void Employee::setName(string name)
{
    if (name.size() < 3 || name.size() > 20)
    {
        throw invalid_argument("Name must be between 3 and 20 characters.");
    }

    for (char c : name)
    {
        if (!isalpha(c))
        {
            throw invalid_argument("Name must contain alphabetic characters only.");
        }
    }

    this->name = name;
}

void Employee::setPassword(string password)
{
    if (password.size() < 8 || password.size() > 20)
    {
        throw invalid_argument("Password must be between 8 and 20 characters.");
    }

    for (char c : password)
    {
        if (c == ' ')
        {
            throw invalid_argument("Password must not contain spaces.");
        }
    }

    this->password = password;
}

void Employee::display() const
{
    cout << "Employee Details:" << endl;

    Person::display();

    cout << "Salary: " << salary << endl;
}