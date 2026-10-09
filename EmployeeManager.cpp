#include "EmployeeManager.h"
#include <exception>

void EmployeeManager::printEmployeeMenu() {
    cout << "1. Display my info\n"
         << "2. Add new client\n"
         << "3. Search for client\n"
         << "4. List all clients\n"
         << "5. Edit client\n"
         << "6. Update password\n"
         << "7. Logout\n";
}

void EmployeeManager::updatePassword(Employee& employee) {
    string newPass;
    cout << "New password: ";
    cin >> newPass;
    try {
        employee.setPassword(newPass);
        cout << "Password updated\n";
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void EmployeeManager::addClient(vector<Client>& clients) {
    string name, password;
    double balance;

    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Password: ";
    cin >> password;
    cout << "Balance: ";
    cin >> balance;

    if (!Validation::isValidName(name)) {
        cout << "Invalid name\n";
        return;
    }
    if (!Validation::isValidPassword(password)) {
        cout << "Invalid password\n";
        return;
    }
    if (balance < 0) {
        cout << "Invalid balance\n";
        return;
    }

    int id = clients.empty() ? 1 : clients.back().getId() + 1;
    clients.push_back(Client(id, name, password, balance));
    cout << "Client added with ID " << id << endl;
}

Client* EmployeeManager::searchClient(int id, vector<Client>& clients) {
    for (Client& c : clients) {
        if (c.getId() == id) {
            return &c;
        }
    }
    return nullptr;
}

void EmployeeManager::listClients(const vector<Client>& clients) {
    if (clients.empty()) {
        cout << "No clients\n";
        return;
    }
    for (const Client& c : clients) {
        c.display();
        cout << "---------------\n";
    }
}

void EmployeeManager::editClient(int id, vector<Client>& clients) {
    Client* client = searchClient(id, clients);
    if (client == nullptr) {
        cout << "Client not found\n";
        return;
    }

    string name, password;
    double balance;

    cout << "New name: ";
    cin.ignore();
    getline(cin, name);
    cout << "New password: ";
    cin >> password;
    cout << "New balance: ";
    cin >> balance;

    try {
        client->setName(name);
        client->setPassword(password);
        client->setBalance(balance);
        cout << "Client updated\n";
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

Employee* EmployeeManager::login(int id, string password, vector<Employee>& employees) {
    for (Employee& e : employees) {
        if (e.getId() == id && e.getPassword() == password) {
            return &e;
        }
    }
    return nullptr;
}
