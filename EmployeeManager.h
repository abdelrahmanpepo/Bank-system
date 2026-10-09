#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"
#include "Client.h"
#include "Validation.h"
using namespace std;

class EmployeeManager {
public:
    static void printEmployeeMenu();
    static void updatePassword(Employee& employee);
    static void addClient(vector<Client>& clients);
    static Client* searchClient(int id, vector<Client>& clients);
    static void listClients(const vector<Client>& clients);
    static void editClient(int id, vector<Client>& clients);
    static Employee* login(int id, string password, vector<Employee>& employees);
};
