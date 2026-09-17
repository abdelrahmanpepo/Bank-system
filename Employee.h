#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include "Validation.h"
#include "Client.h"
#include <vector>

using namespace std;

class Employee : public Person
{
private:
    double salary;
    vector<Client> clients;

public:
    Employee(int id, string name, string password, double salary);

    void setName(string name);
    void setPassword(string password);
    void setSalary(double salary);

    string getName();
    string getPassword();
    double getSalary();

    void display();

    void addClient(Client& client);
    Client* searchClient(int id);
    void listClient();
    void editClient(int id, string name, string password, double salary);
};

#endif