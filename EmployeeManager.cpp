class EmployeeManager
{
public:
    static void printEmployeeMenu()
    {
        cout << "========= Employee Menu =========" << endl;
        cout << "1. Add New Client" << endl;
        cout << "2. List All Clients" << endl;
        cout << "3. Search For Client" << endl;
        cout << "4. Edit Client" << endl;
        cout << "5. Logout" << endl;
    }
    static void newClient(Employee* employee)
    {
        int id;
        string name, password;
        double balance;
        cout << "Enter Client ID: ";
        cin >> id;
        cout << "Enter Client Name: ";
        cin >> name;
        cout << "Enter Client Password: ";
        cin >> password;
        cout << "Enter Client Balance: ";
        cin >> balance;
        Client c(id, name, password, balance);
        FileManager fm;
        fm.addClient(c);
        cout << "Client added successfully!" << endl;
    }
    static void listAllClients(Employee* employee)
    {
        FileManager fm;
        vector<Client> clients = fm.getAllClients();
        for (int i = 0; i < clients.size(); i++)
        {
            clients[i].printinfo();
        }
    }
    static void searchForClient(Employee* employee)
    {
        int id;
        cout << "Enter Client ID: ";
        cin >> id;
        FileManager fm;
        vector<Client> clients = fm.getAllClients();
        bool found = false;
        for (int i = 0; i < clients.size(); i++)
        {
            if (clients[i].getId() == id)
            {
                clients[i].printinfo();
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Client not found!" << endl;
        }
    }
    static void editClientInfo(Employee* employee)
    {
        int id;
        cout << "Enter Client ID: ";
        cin >> id;
        FileManager fm;
        vector<Client> clients = fm.getAllClients();
        bool found = false;
        for (int i = 0; i < clients.size(); i++)
        {
            if (clients[i].getId() == id)
            {
                string name, password;
                double balance;
                cout << "Enter New Name: ";
                cin >> name;
                cout << "Enter New Password: ";
                cin >> password;
                cout << "Enter New Balance: ";
                cin >> balance;
                clients[i].setName(name);
                clients[i].setPassword(password);
                clients[i].setBalance(balance);
                fm.removeAllClients();
                for (int j = 0; j < clients.size(); j++)
                {
                    fm.addClient(clients[j]);
                }
                cout << "Client updated successfully!" << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Client not found!" << endl;
        }
    }
    static Employee* login(int id, string password)
    {
        FileManager fm;
        vector<Employee> employees = fm.getAllEmployees();
        for (int i = 0; i < employees.size(); i++)
        {
            if (employees[i].getId() == id && employees[i].getPassword() == password)
            {
                Employee* employee = new Employee(employees[i]);
                return employee;
            }
        }
        return nullptr;
    }
    static bool employeeOptions(Employee* employee)
    {
        int choice;
        do
        {
            printEmployeeMenu();
            cout << "Enter Choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                newClient(employee);
                break;
            case 2:
                listAllClients(employee);
                break;
            case 3:
                searchForClient(employee);
                break;
            case 4:
                editClientInfo(employee);
                break;
            case 5:
                cout << "Logging out..." << endl;
                return false;
            }
        } while (choice != 5);
        return true;
    }
};
