#pragma once

#include "Client.h"
#include "Admin.h"

class Parser
{
private:

    static vector<string> split(string line)
    {
        vector<string> data;
        stringstream ss(line);
        string token;

        int i = 0;

        while (getline(ss, token, '&'))
        {
            data.push_back(token);
        }

        return data;
    }

public:

    static Client parseToClient(string line)
    {
        vector<string> v = split(line);

        try
        {
            Client c(stoi(v[0]), v[1], v[2], stod(v[3]));
            return c;
        }
        catch (exception e)
        {
            cout << e.what();
        }
    }

    static Employee parseToEmployee(string line)
    {
        vector<string> v = split(line);

        try
        {
            Employee e(stoi(v[0]), v[1], v[2], stod(v[3]));
            return e;
        }
        catch (exception e)
        {
            cout << e.what();
        }
    }

    static Admin parseToAdmin(string line)
    {
        vector<string> v = split(line);

        try
        {
            Admin a(stoi(v[0]), v[1], v[2], stod(v[3]));
            return a;
        }
        catch (exception e)
        {
            cout << e.what();
        }
    }
};
