#pragma once
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Validation {
public:
    static bool validName(string name) {
        if (name.length() < 3 || name.length() > 20) return false;
        for (char c : name) {
            if (!isalpha(c) && c != ' ') return false;
        }
        return true;
    }

    static bool validPassword(string password) {
        if (password.length() < 8 || password.length() > 20) return false;
        for (char c : password) {
            if (c == ' ') return false;
        }
        return true;
    }

    static bool validBalance(double balance) {
        return balance >= 1500;
    }

    static bool validSalary(double salary) {
        return salary >= 5000;
    }
};
