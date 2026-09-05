#include<iostream>
#include<string>
#include "Client.h"
#include"Person.h"
#include"Validation.h"
#include<exception>
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
        throw invalid_argument("Invalid Name");
    }
}
void Client::setPassword(string password) {
    if (Validation::isValidPassword(password)) {
        this->password = password;
    }
    else {
        throw invalid_argument(" Invalid Password");
    }
}
void Client::setBalance(double balance) {
    if (Validation::isValidBalance(balance)) {
        this->balance = balance;
    }
    else {
        throw invalid_argument(" Invalid Balance");
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
        throw invalid_argument("Invalid Amount");
    }
}

void Client::withdraw(double amount) {
    if (amount > 0&& amount<=balance) {
        balance -= amount;
    }
    else {
        throw invalid_argument("Invalid Amount");
    }
}
void Client::transferTo(Client& receiver, double amount) {
   
