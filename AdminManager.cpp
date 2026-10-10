#include "AdminManager.h"
#include "FileManager.h"
#include <iostream>
#include <vector>

using namespace std;

void AdminManager::printAdminMenu() {
    cout << "\n===== Admin Management =====\n";
    cout << "1. Add Employee\n";
    cout << "2. Search Employee\n";
    cout << "3. Edit Employee\n";
    cout << "4. List Employees\n";
    cout << "0. Logout\n";
    cout << "Choose: ";
}

Admin* AdminManager::login(int id, string password) {
    vector<Admin> allAdmins = FileManager::getAllAdmins();

    for (int i = 0; i < allAdmins.size(); i++) {
        if (allAdmins[i].getId() == id && allAdmins[i].getPassword() == password) {
            return new Admin(allAdmins[i]);
        }
    }
    return nullptr;
}

bool AdminManager::AdminOptions(Admin* admin) {
    if (admin == nullptr) {
        return false;
    }

    int choice;

    while (true) {
        printAdminMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, password;
            double salary;

            cout << "Enter Employee Name: ";
            cin >> name;
            while (!Validation::isValidName(name)) {
                cout << "Invalid name! Enter valid name: ";
                cin >> name;
            }

            cout << "Enter Employee Password: ";
            cin >> password;
            while (!Validation::isValidPassword(password)) {
                cout << "Invalid password! Enter valid password: ";
                cin >> password;
            }

            cout << "Enter Employee Salary: ";
            cin >> salary;
            while (!Validation::isValidSalary(salary)) {
                cout << "Invalid salary! Enter valid salary: ";
                cin >> salary;
            }

            Employee e(FileManager::getEmployeeLastId() + 1, name, password, salary);
            admin->addEmployee(e);
            FileManager::updateEmployees();
            cout << "Employee added successfully!\n";
            break;
        }
        case 2: {
            int id;
            cout << "Enter Employee ID: ";
            cin >> id;

            Employee* employee = admin->searchEmployee(id);

            if (employee != nullptr) {
                employee->display();
            } else {
                cout << "Employee not found.\n";
            }
            break;
        }
        case 3: {
            int id;
            string name, password;
            double salary;

            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter new name: ";
            cin >> name;
            cout << "Enter new password: ";
            cin >> password;
            cout << "Enter new salary: ";
            cin >> salary;

            admin->editEmployee(id, name, password, salary);
            FileManager::updateEmployees(); // حفظ التعديل في الملفات
            cout << "Employee updated successfully!\n";
            break;
        }
        case 4: {
            admin->listEmployee();
            break;
        }
        case 0: {
            return false;
        }
        default:
            cout << "Invalid choice.\n";
        }
    }
}
