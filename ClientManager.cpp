#include "ClientManager.h"

void ClientManager::printClientMenu() {
    cout << "\n======================================" << endl;
    cout << "           Client Menu                " << endl;
    cout << "======================================" << endl;
    cout << "1. Display My Info" << endl;
    cout << "2. Check Balance" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Withdraw" << endl;
    cout << "5. Transfer Amount" << endl;
    cout << "6. Update Password" << endl;
    cout << "7. Logout" << endl;
    cout << "======================================" << endl;
    cout << "Enter your choice: ";
}

void ClientManager::updatePassword(Person* person) {
    string newPassword;
    cout << "Enter new password: ";
    cin >> newPassword;

    while (!Validation::isValidPassword(newPassword)) {
        cout << "Invalid password! Enter valid password: ";
        cin >> newPassword;
    }

    person->setPassword(newPassword);
    cout << "\nPassword updated successfully!" << endl;
}

Client* ClientManager::login(int id, string password) {
    vector<Client> allClients = FileManager::getAllClients();

    for (int i = 0; i < allClients.size(); i++) {
        if (allClients[i].getId() == id && allClients[i].getPassword() == password) {
            return new Client(allClients[i]);
        }
    }
    return nullptr;
}

bool ClientManager::clientOptions(Client* client) {
    printClientMenu();
    int choice;
    cin >> choice;

    switch (choice) {
    case 1: {
        cout << "\n--- Your Info ---" << endl;
        client->display();
        break;
    }
    case 2: {
        cout << "\nYour Balance: " << client->getBalance() << endl;
        break;
    }
    case 3: {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        client->deposit(amount);
        FileManager::updateClients();
        cout << "Deposit successful! New Balance: " << client->getBalance() << endl;
        break;
    }
    case 4: {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount <= client->getBalance()) {
            client->withdraw(amount);
            FileManager::updateClients();
            cout << "Withdrawal successful! New Balance: " << client->getBalance() << endl;
        } else {
            cout << "Error: Insufficient balance!" << endl;
        }
        break;
    }
    case 5: {
        int recipientId;
        double amount;
        cout << "Enter Recipient ID: ";
        cin >> recipientId;

        Client* recipient = FileManager::searchClient(recipientId);

        if (recipient != nullptr) {
            cout << "Enter amount: ";
            cin >> amount;
            if (client->transferTo(amount, *recipient)) {
                FileManager::updateClients();
                cout << "Transfer successful!" << endl;
            }
        } else {
            cout << "Error: Recipient not found!" << endl;
        }
        break;
    }
    case 6: {
        updatePassword(client);
        FileManager::updateClients();
        break;
    }
    case 7: {
        cout << "Logging out..." << endl;
        return false;
    }
    default:
        cout << "Invalid choice! Please try again." << endl;
    }

    return true;
}
