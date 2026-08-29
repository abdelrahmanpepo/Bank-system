#ifgndef VALIDATION_H
#define VALIDATION_H

#include <iostream>
#include <string>
#include <cctype>

using namespace std;


// ================= Validation Class =================

class Validation
{
public:

    static bool isValidName(string name)
    {
        if (name.length() < 3 || name.length() > 20)
            return false;

        for (char c : name)
        {
            if (!isalpha(c))
                return false;
        }

        return true;
    }


    static bool isValidPassword(string password)
    {
        if (password.length() < 8 || password.length() > 20)
            return false;

        for (char c : password)
        {
            if (c == ' ')
                return false;
        }

        return true;
    }


    static bool isValidBalance(double balance)
    {
        return balance >= 1500;
    }


    static bool isValidSalary(double salary)
    {
        return salary >= 5000;
    }
};
#endif