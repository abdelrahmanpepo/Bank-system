#include "Validation.h"

bool Validation::isValidName(string name)
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

bool Validation::isValidPassword(string password)
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

bool Validation::isValidBalance(double balance)
{
    return balance >= 1500;
}

bool Validation::isValidSalary(double salary)
{
    return salary >= 5000;
}
