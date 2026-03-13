//Devoloper: Kirollos Remon//

#pragma once
#include <string>
#include <iostream>
#include "Validation.h"
using namespace std;

class Person
{
protected:
    // Attributes
    string name;
    int id;
    string password;

public:
    // constructors
    Person()
    {
        id = 0;
    }
    Person( string name, int id, string password)
    {
        Set_Person(name, id, password);
    }

    // Setters
    void Set_Name(string name)
    {
        if (Validation::Name(name))
            this->name = name;
        else
            cout << "Invalid Name" << endl;
    }

    void Set_Id(int id)
    {
        if (Validation::id(id))
            this->id = id;
        else
            cout << "Invalid ID" << endl;
    }

    void Set_Password(string password)
    {
        if (Validation::password(password))
            this->password = password;
        else
            cout << "Invalid Password" << endl;
    }

    void Set_Person(string name, int id,string password)
    {
        Set_Name(name);
        Set_Id(id);
        Set_Password(password);
    }

    // Getters
    string Get_Name() const
    {
        return this->name;
    }
    int Get_Id() const
    {
        return this->id;
    }
    string Get_Password() const
    {
        return this->password;
    }

    // methods
    virtual void display() const
    {
        cout << "Name: " << Get_Name() << endl;
        cout << "ID: " << Get_Id() << endl;
        cout << "Password: " << Get_Password() << endl;
    }

    // destructor
    virtual ~Person()
    {
    }
};