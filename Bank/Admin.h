                                       //Devoloper: Mahmoud Abdo//

#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

class Admin : public Employee
{
public:
    // Constructors
    Admin() : Employee() {}

    Admin(string name, int id, string password, double salary)
        : Employee(name, id, password, salary) {}

    // Methods
    void display()
    {
        cout << "--- Admin Data ---" << endl;
        Employee::display(); 
        cout << "-----------------------" << endl << endl;
    }
};
