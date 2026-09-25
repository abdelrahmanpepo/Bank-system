#include "FilesHelper.h"

void FilesHelper::saveLast(string fileName, int id)
{
    fstream file(fileName, ios::out);

    if (file.is_open())
    {
        file << id << endl;
        file.close();
    }
}

int FilesHelper::getLast(string fileName)
{
    fstream file(fileName, ios::in);

    int id = 0;

    if (file.is_open())
    {
        file >> id;
        file.close();
    }

    return id;
}

void FilesHelper::saveEmployee(string fileName, string lastIdFile, Employee e)
{
    fstream file(fileName, ios::app);

    if (file.is_open())
    {
        file << e.getId() << ","
            << e.getName() << ","
            << e.getPassword() << ","
            << e.getSalary() << endl;

        file.close();
    }

    int lastId = getLast(lastIdFile);

    if (e.getId() > lastId)
    {
        saveLast(lastIdFile, e.getId());
    }
}

void FilesHelper::saveAdmin(Admin a)
{
    fstream file("Admin.txt", ios::app);

    if (file.is_open())
    {
        file << a.getId() << ","
            << a.getName() << ","
            << a.getPassword() << ","
            << a.getSalary() << endl;

        file.close();
    }
}
