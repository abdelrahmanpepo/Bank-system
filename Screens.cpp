#include <iostream>
using namespace std;

#include "Screens.h"

void Screens::bankName()
{
    cout << "==============================" << endl;
    cout << "        BANK SYSTEM            " << endl;
    cout << "==============================" << endl;
}

void Screens::welcome()
{
    cout << "Welcome to Bank System!" << endl;
}

void Screens::loginOptions()
{
    cout << endl;
    cout << "1. Login" << endl;
    cout << "2. Exit" << endl;
}

int Screens::loginAs()
{
    int choice;

    cout << endl;
    cout << "Login As:" << endl;
    cout << "1. Client" << endl;
    cout << "2. Employee" << endl;
    cout << "3. Admin" << endl;
    cout << "Enter your choice: ";

    cin >> choice;

    return choice;
}

void Screens::invalid(int c)
{
    cout << "Invalid choice: " << c << endl;
}

void Screens::logout()
{
    cout << "You have been logged out successfully." << endl;
}

void Screens::loginScreen(int c)
{
    if (c == 1)
    {
        cout << endl;
        cout << "========== CLIENT LOGIN ==========" << endl;
    }
    else if (c == 2)
    {
        cout << endl;
        cout << "========= EMPLOYEE LOGIN =========" << endl;
    }
    else if (c == 3)
    {
        cout << endl;
        cout << "=========== ADMIN LOGIN ==========" << endl;
    }
    else
    {
        invalid(c);
    }
}

void Screens::runApp()
{
    bankName();
    welcome();

    int choice;

    do
    {
        loginOptions();

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int userType = loginAs();

            if (userType >= 1 && userType <= 3)
            {
                loginScreen(userType);
            }
            else
            {
                invalid(userType);
            }
        }
        else if (choice == 2)
        {
            cout << "Goodbye!" << endl;
        }
        else
        {
            invalid(choice);
        }

    } while (choice != 2);
}