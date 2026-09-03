#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "Person.h"
#include "validation.h"

using namespace std;

class Client : public Person {
private:
    double balance;

public:
    Client(int id, string name, string password, double balance);

    double getBalance() const;
    void setBalance(double balance);

    void setName(string name) override;
    void setPassword(string password) override;
    void display() const override;

    void deposit(double amount);
    void withdraw(double amount);
    void transferTo(Client &receiver, double amount);
};
