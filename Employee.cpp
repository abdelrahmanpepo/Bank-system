#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee(int id, string name, string password, double salary)
    : Person(id, name, password)
{
    setSalary(salary);
}

void Employee::setName(string name)
{
    if (Validation::isValidName(name))
    {
        this->name = name;
    }
}

void Employee::setPassword(string password)
{
    if (Validation::isValidPassword(password))
    {
        this->password = password;
    }
}

void Employee::setSalary(double salary)
{
    if (salary >= 5000)
    {
        this->salary = salary;
    }
}

string Employee::getName()
{
    return name;
}

string Employee::getPassword()
{
    return password;
}

double Employee::getSalary()
{
    return salary;
}

void Employee::display()
{
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Password: " << password << endl;
    cout << "Salary: " << salary << endl;
}

void Employee::addClient(Client& client)
{
    clients.push_back(client);
}

Client* Employee::searchClient(int id)
{
    for (int i = 0; i < clients.size(); i++)
    {
        if (clients[i].getId() == id)
        {
            return &clients[i];
        }
    }

    return nullptr;
}

void Employee::listClient()
{
    for (int i = 0; i < clients.size(); i++)
    {
        clients[i].display();
    }
}

void Employee::editClient(int id, string name, string password, double salary)
{
    Client* client = searchClient(id);

    if (client != nullptr)
    {
        client->setName(name);
        client->setPassword(password);
        client->setBalance(salary);
    }
}