
#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Client.h"
#include "Employee.h"
#include "Admin.h"

using namespace std;

class FilesHelper
{
public:
    static void saveLast(string fileName, int id);
    static int getLast(string fileName);

    static void saveEmployee(string fileName, string lastIdFile, Employee e);
    static void saveAdmin(Admin a);
};
