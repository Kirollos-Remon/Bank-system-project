#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
#include <vector>
#include "Client.h"
using namespace std;

class Admin : public Employee
{
    private:
    vector<Employee> employees;
public:
    // Constructors
    Admin() : Employee() {}

    Admin(string name, int id, string password, double salary)
        : Employee(name, id, password, salary) {}

    // Methods

    void addEmployee(Employee &employee)
    {
        employees.push_back(employee);
        cout << "Employee added successfully." << endl;
    }

    Employee *searchEmployee(int id)
    {
        for (int i = 0; i < employees.size(); i++)
        {
            if (employees[i].Get_Id() == id)
            {
                return &employees[i];
            }
        }
        return nullptr;
    }

    void editEmployee(int id, string name, string password, double salary)
    {
        Employee *emp = searchEmployee(id);
        if (emp != nullptr)
        {
            emp->Set_Name(name);
            emp->Set_Password(password);
            emp->setSalary(salary);
            cout << "Employee ID " << id << " updated successfully." << endl;
        }
        else
        {
            cout << "Employee with ID " << id << " not found." << endl;
        }
    }

    void listEmployee()
    {
        cout << "--- Listing All Employees ---" << endl;
        if (employees.empty())
        {
            cout << "No employees found in the system." << endl;
        }
        for (auto &emp : employees)
        {
            emp.display();
        }
    }
    void display()
    {
        cout << "--- Admin Data ---" << endl;
        Employee::display();
        cout << "-----------------------" << endl
             << endl;
    }
};