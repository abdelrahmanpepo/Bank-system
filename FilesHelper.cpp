#include "FilesHelper.h"

void FilesHelper::saveLast(string fileName, int id) {
    fstream file(fileName, ios::out);
    if (file.is_open()) {
        file << id << endl;
        file.close();
    }
}

int FilesHelper::getLast(string fileName) {
    fstream file(fileName, ios::in);
    int id = 0;
    if (file.is_open()) {
        file >> id;
        file.close();
    }
    return id;
}

void FilesHelper::saveClient(string fileName, string lastIdFile, Client c) {
    fstream file(fileName, ios::app);
    if (file.is_open()) {
        file << c.getId() << "&"
             << c.getName() << "&"
             << c.getPassword() << "&"
             << c.getBalance() << endl;
        file.close();
    }
    int lastId = getLast(lastIdFile);
    if (c.getId() > lastId) {
        saveLast(lastIdFile, c.getId());
    }
}

void FilesHelper::saveEmployee(string fileName, string lastIdFile, Employee e) {
    fstream file(fileName, ios::app);
    if (file.is_open()) {
        file << e.getId() << "&"
             << e.getName() << "&"
             << e.getPassword() << "&"
             << e.getSalary() << endl;
        file.close();
    }
    int lastId = getLast(lastIdFile);
    if (e.getId() > lastId) {
        saveLast(lastIdFile, e.getId());
    }
}

void FilesHelper::saveAdmin(string fileName, string lastIdFile, Admin a) {
    fstream file(fileName, ios::app);
    if (file.is_open()) {
        file << a.getId() << "&"
             << a.getName() << "&"
             << a.getPassword() << "&"
             << a.getSalary() << endl; 
        file.close();
    }
    int lastId = getLast(lastIdFile);
    if (a.getId() > lastId) {
        saveLast(lastIdFile, a.getId());
    }
}
