#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
class Parser {
public:
    static vector<string> split(string line);
    static Client parseToClient(string line);
    static Employee parseToEmployee(string line);
    static Admin parseToAdmin(string line);
};
