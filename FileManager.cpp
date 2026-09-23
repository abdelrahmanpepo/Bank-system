#include "FileManager.h"

void FileManager::addClient(Client obj)
{
    FilesHelper::saveClient(obj);
}

void FileManager::addEmployee(Employee obj)
{
    FilesHelper::saveEmployee(
        "Employee.txt",
        "LastEmployeeId.txt",
        obj
    );
}

void FileManager::addAdmin(Admin obj)
{
    FilesHelper::saveEmployee(
        "Admin.txt",
        "LastAdminId.txt",
        obj
    );
}

void FileManager::getAllClients()
{
    FilesHelper::getClients();
}

void FileManager::getAllEmployees()
{
    FilesHelper::getEmployees();
}

void FileManager::getAllAdmins()
{
    FilesHelper::getAdmins();
}

void FileManager::removeAllClients()
{
    FilesHelper::clearFile(
        "Clients.txt",
        "LastClientId.txt"
    );
}

void FileManager::removeAllEmployees()
{
    FilesHelper::clearFile(
        "Employee.txt",
        "LastEmployeeId.txt"
    );
}

void FileManager::removeAllAdmins()
{
    FilesHelper::clearFile(
        "Admin.txt",
        "LastAdminId.txt"
    );
}