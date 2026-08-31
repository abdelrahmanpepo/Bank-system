#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "Person.h"

using namespace std;

class Employee : public Person
{
private:
    double salary;

public:
    Employee(int id, string name, string password, double salary);

    double getSalary() const;

    void setSalary(double salary);

    void setName(string name) override;

    void setPassword(string password) override;

    void display() const override;
};