#ifndef CLIENT_H
#define CLIENT_H

#include <string>
using namespace std;

class Client
{
private:
    string name;
    string accountNumber;
    double balance;

public:
    Client();
    Client(string name, string accountNumber, double balance);

    void setName(string name);
    string getName();

    void setAccountNumber(string accountNumber);
    string getAccountNumber();

    void setBalance(double balance);
    double getBalance();

    void deposit(double amount);
    void withdraw(double amount);
    void display();
};

#endif
