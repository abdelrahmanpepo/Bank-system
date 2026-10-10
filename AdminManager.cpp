
#include "AdminManager.h"
#include "FileManager.h"
#include <iostream>
#include <vector>

using namespace std;

void AdminManager::printEmployeeMenu() {
    cout << "\n===== Employee Management =====\n";
    cout << "1. Search Employee\n";
    cout << "2. Edit Employee\n";
    cout << "3. List Employees\n";
    cout << "0. Logout\n";
    cout << "Choose: ";
}

Admin* AdminManager::login(int id, string password) {
    vector<Admin> allAdmins = FileManager::getAllAdmins();

    for (int i = 0; i < allAdmins.size(); i++) {
        if (allAdmins[i].getId() == id &&
            allAdmins[i].getPassword() == password) {
            return new Admin(allAdmins[i]);
        }
    }

    return nullptr;
}

bool AdminManager::AdminOptions(Admin* admin) {
    if (admin == nullptr)
        return false;

    int choice;

    while (true) {
        printEmployeeMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            cout << "Enter Employee ID: ";
            cin >> id;

            Employee* employee = admin->searchEmployee(id);

            if (employee != nullptr)
                employee->display();
            else
                cout << "Employee not found.\n";

            break;
        }

        case 2: {
            int id;
            string name, password;
            double salary;

            cout << "Enter Employee ID: ";
            cin >> id;

            cout << "Enter new name: ";
            cin >> name;
            if (!Validation::validName(name)) {
                throw invalid_argument( "Invalid name. Name must be 3-20 characters");
                break;
            }


            cout << "Enter new password: ";
            cin >> password;

            if (!Validation::validPassword(password)) {
               throw invalid_argument("Invalid password. Password must be 8-20 characters with no spaces");
                break;
            }


            cout << "Enter new salary: ";
            cin >> salary;

            admin->editEmployee(id, name, password, salary);
            break;
        }

        case 3:
            admin->listEmployee();
            break;
            
        case 4:
           admin->addEmployee(employee);
           break;
  
       if (!Validation::validPassword(password)) {
                throw invalid_argument("Invalid password. Password must be 8-20 characters with no spaces.");
                break;
       }
          return employee(id, name, password, salary);
            break;
       }

        case 0:
            return false;

        default:
            cout << "Invalid choice.\n";
        }
    }
}
