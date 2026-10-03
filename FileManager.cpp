#include "FileManager.h"

void FileManager::addClient(Client client)
{
    FilesHelper::saveClient(client);
}

void FileManager::addEmployee(Employee employee)
{
    FilesHelper::saveEmployee("employees.txt", "employeesLastId.txt", employee);
}

void FileManager::addAdmin(Admin admin)
{
    FilesHelper::saveEmployee("admins.txt", "adminsLastId.txt", admin);
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
    FilesHelper::clearFile("clients.txt", "clientsLastId.txt");
}

void FileManager::removeAllEmployees()
{
    FilesHelper::clearFile("employees.txt", "employeesLastId.txt");
}

void FileManager::removeAllAdmins()
{
    FilesHelper::clearFile("admins.txt", "adminsLastId.txt");
}
