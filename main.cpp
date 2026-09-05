#include <iostream>
#include <vector>
#include <exception>

#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Validation.h"

using namespace std;

int main() {
    cout << "============ BANK SYSTEM DEMO ============\n\n";

    cout << "[SCENARIO 1] Testing Client Operations\n";
    cout << "--------------------------------------\n";
    
    Client client1(101, "Abdelrahman", "pass12345", 5000);
    Client client2(102, "Mohamed", "pass67890", 2000);

    cout << "Initial Client 1 Balance: " << client1.getBalance() << endl;
    cout << "Initial Client 2 Balance: " << client2.getBalance() << endl;

    cout << "\n-> Depositing 1000 to Client 1...\n";
    client1.deposit(1000);
    cout << "New Balance: " << client1.getBalance() << endl;

    cout << "\n-> Withdrawing 500 from Client 1...\n";
    client1.withdraw(500);
    cout << "New Balance: " << client1.getBalance() << endl;

    cout << "\n-> Transferring 1500 from Client 1 to Client 2...\n";
    client1.transferTo(client2, 1500);
    cout << "Client 1 Balance after transfer: " << client1.getBalance() << endl;
    cout << "Client 2 Balance after transfer: " << client2.getBalance() << endl;
    cout << "\n";

    cout << "[SCENARIO 2] Testing Employee Class & Exception Handling\n";
    cout << "--------------------------------------------------------\n";
    try {
        cout << "Trying to create an Employee with invalid salary (3000 EGP)...\n";
        Employee empInvalid(201, "Ahmed", "empPass123", 3000);
    }
    catch (const invalid_argument& e) {
        cout << "--> Caught Exception successfully: " << e.what() << "\n";
    }

    Employee validEmp(202, "Mostafa", "empPass123", 7000);
    cout << "\nDisplaying Valid Employee Details:\n";
    validEmp.display();
    cout << "\n";

    cout << "[SCENARIO 3] Testing Admin Class\n";
    cout << "--------------------------------\n";
    try {
        Admin admin1(301, "Kareem", "adminPass123", 12000);
        admin1.display();
    }
    catch (const invalid_argument& e) {
        cout << "--> Admin Exception: " << e.what() << "\n";
    }
    cout << "\n";

    cout << "[SCENARIO 4] Testing Polymorphism with Base Class (Person*)\n";
    cout << "----------------------------------------------------------\n";
    
    vector<Person*> bankUsers;
    bankUsers.push_back(new Client(1, "Ali", "clientPass1", 3000));
    bankUsers.push_back(new Employee(2, "Hassan", "empPass1234", 8000));
    bankUsers.push_back(new Admin(3, "Omar", "adminPass123", 15000));

    for (size_t i = 0; i < bankUsers.size(); ++i) {
        cout << "User #" << i + 1 << ":\n";
        bankUsers[i]->display();
        cout << "-----------------------\n";
    }

    for (Person* user : bankUsers) {
        delete user;
    }
    bankUsers.clear();

    cout << "\n================ ALL TESTS PASSED ================\n";

    return 0;
}
