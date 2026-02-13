#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Validation.h"

using namespace std;

class Employee : public Person
{
private:
    // Attributes
    double salary;

public:
    // Constructors
    Employee() : Person()
    {
        this->salary = 0;
    }

    Employee(string name, int id, string password, double salary) : Person(name, id, password)
    {
        setSalary(salary);
    }

    // Setters
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

    // Getters
    double getSalary()
    {
        return salary;
    }

    // Methods
    void display()
    {
        Person::display();
        cout << "Salary: " << salary << endl;
        cout << "-----------------------" << endl;
    }
};