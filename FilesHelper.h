#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"

using namespace std;

class FilesHelper {
public:
    static void saveLast(string fileName, int id);
    static int getLast(string fileName);
    static void saveClient(string fileName, string lastIdFile, Client c);
    static void saveEmployee(string fileName, string lastIdFile, Employee e);
    static void saveAdmin(string fileName, string lastIdFile, Admin a);
    static void getClients();
    static void getEmployees();
    static void getAdmins();
    static void clearFile(string fileName, string lastIdFile);
};
