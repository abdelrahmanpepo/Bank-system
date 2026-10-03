#pragma once
#include "Parser.h"

class FilesHelper
{
public:
    static void saveLast(string fileName, int id)
    {
        ofstream file(fileName);
        file << id;
        file.close();
    }

    static int getLast(string fileName)
    {
        ifstream file(fileName);
        file >> id;
        file.close();
        return id;
    }
    static void saveClient(Client c)
    {
        int id = getLast("ClientsLastId.txt");
        id++;
        
        string data = to_string(c.getId()) + '&' + c.getName() + '&' + c.getPassword() + '&' + to_string(c.getBalance());
        
        fstream file("Clients.txt", ios::app);
        file << data << "\n";
        
        saveLast("ClientsLastId.txt", id);
        file.close();
    }

    static void saveEmployee(string fileName, string lastIdFile, Employee& e)
    {
        int id = getLast(lastIdFile);
        id++;
        
        string data = to_string(e.getId()) + '&' + e.getName() + '&' + e.getPassword() + '&' + to_string(e.getSalary());
        fstream file(fileName, ios::app);
        
        file << data << "\n";
        
        saveLast(lastIdFile, id);
        file.close();
    }

    static void ClientsToVector()
    {
        fstream file("Clients.txt");
        string line;
        
        while (getline(file, line))
        {
            Client::setAllClients(Parser::parseToClient(line));
        }
        
        file.close();
    }

    static void EmployeesToVector()
    {
        fstream file("Employees.txt");
        string line;
        
        while (getline(file, line))
        {
            Employee::setAllEmployees(Parser::parseToEmployee(line));
        }
        
        file.close();
    }

    static void AdminToVector()
    {
        fstream file("Admins.txt");
        string line;
        
        while (getline(file, line))
        {
            Admin::setAllAdmins(Parser::parseToAdmin(line));
        }
        
        file.close();
    }

    static void clearFile(string fileName, string lastIdFile)
    {
        ofstream file1(fileName, ios::trunc);
        ofstream file2(lastIdFile, ios::trunc);
        
        file2 << "0";
        file2.close();
        file1.close();
    }
};
