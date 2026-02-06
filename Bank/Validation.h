#pragma once
#include <iostream>
#include <string>
using namespace std;

class Validation
{
public:
    // methods
    static bool Name(const string &name)
    {

        if (name.length() < 5 || name.length() > 20)
            return false;

        for (int i = 0; i < name.length(); i++)
        {
            if (!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || name[i] == ' '))
            {
                return false;
            }
        }
        return true;
    }

    static bool balance(double balance)
    {
        if (balance >= 1500)
            return true;
        else
            return false;
    }

    static bool password(const string &pass)
    {
        if (pass.length() >= 8 && pass.length() <= 20)
            return true;
        else
            return false;
    }

    static bool salary(double salary)
    {
        if (salary >= 5000)
            return true;
        else
            return false;
    }

    static bool id(int id)
    {
        if (id > 0)
            return true;
        else
            return false;
    }
};