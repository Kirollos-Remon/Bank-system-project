#pragma once
#include <iostream>
#include <string>
#include "Validation.h"
#include "Person.h"
#include "Client.h"
using namespace std;

class Employee : public Person
{

protected:
    double salary;

public:
    // 1. Constructors
    Employee() : Person()
    {
        this->salary = 0;
    }

    Employee(const string &name, int id, const string &password, double salary) : Person(name, id, password)
    {
        setSalary(salary);
    }

    // 2. Setter with Validation
    void setSalary(double salary)
    {
        if (Validation::salary(salary))
        {
            this->salary = salary;
        }
        else
        {
            cout << "Invalid Salary! Minimum salary is 5000." << endl;
            this->salary = 0;
        }
    }

    // 3. Getter
    double getSalary() const
    {
        return this->salary;
    }

    // 4. Methods
    void display() const
    {

        Person::display();
        cout << "Salary: " << this->salary << endl;
        cout << "----------------------" << endl;
    }
};