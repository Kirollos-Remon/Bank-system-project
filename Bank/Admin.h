#pragma once
#include <iostream>
#include <string>
#include "Validation.h"
#include "Person.h"
#include "Employee.h"
#include <vector>
using namespace std;


    class Admin : public Employee
    {
    public:
        // 1. Constructor
        Admin(string name, int id, string password, double salary)
            : Employee(name, id, password, salary) {}


        void addEmployee(vector<Employee> &Employees)
        {
            string name, password;
            int id;
            double salary;

            cout << "Enter Employee name: ";
            cin >> name;
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Employee password: "; 
            cin >> password;
            cout << "Enter Employee salary: ";
            cin >> salary;

            Employees.push_back(Employee(name, id, password, salary));
            cout << "Employee added successfully!\n";
        }

        void deleteEmployee(vector<Employee> &Employees, int EmployeeID)
        {
            for (size_t i = 0; i < Employees.size(); i++)
            {
                if (Employees[i].Get_Id() == EmployeeID)
                {
                    Employees.erase(Employees.begin() + i);
                    cout << "Employee deleted successfully!\n";
                    return;
                }
            }
            cout << "Employee not found!\n";
        }

        void viewAllEmployees(const vector<Employee> &Employees)
        {
            if (Employees.empty())
            {
                cout << "No Employees available.\n";
                return;
            }
            for (const auto &c : Employees)
            {
                c.display(); 
            }
        }
    };