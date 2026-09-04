#include<iostream>
#include<string>
#include "Client.h"
#include"Person.h"
#include"Validation.h"
using namespace std;

//Constructor:
Client::Client(int id, string name, string password, double balance)
    : Person(id, name, password), balance(balance) {}

//Setters
void Client::setName(string name) {
    if (Validation::isValidName(name)) {
        this->name = name;
    }
    else {
        cout << "Invalid Name\n";
    }
}
void Client::setPassword(string password) {
    if (Validation::isValidPassword(password)) {
        this->password = password;
    }
    else {
        cout << "Invalid Password\n";
    }
}
void Client::setBalance(double balance) {
    if (Validation::isValidBalance(balance)) {
        this->balance = balance;
    }
    else {
        cout << "Invalid Balance\n";
    }
}

// Getter:
double Client :: getBalance() const{
    return balance;
}

//Other Methods:
void Client::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
    else {
        cout << "Invalid Amount\n";
    }
}

void Client::withdraw(double amount) {
    if (amount > 0&& amount<=balance) {
        balance -= amount;
    }
    else {
        cout << "Invalid Amount\n";
    }
}
void Client::transferTo(Client& receiver, double amount) {
   
