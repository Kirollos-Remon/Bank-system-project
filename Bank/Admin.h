#pragma once
#include "Employee.h"
#include <vector>
#include <iomanip> 

class Admin : public Employee
{
public:
    Admin(int id, string name, string password, double salary)
        : Employee(id, name, password, salary) {}

    Admin(int id, string password)
        : Employee(id, "", password, 0)
    {
    }

    void addEmployee(vector<Employee> &employees)
    {
        string name, password;
        int id;
        double salary;

        cout << "\n[New Employee Entry]\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "ID: ";
        cin >> id;
        cout << "Password: ";
        cin >> password;
        cout << "Salary: ";
        cin >> salary;

        if (Validation::Name(name) && Validation::password(password) &&
            Validation::salary(salary) && Validation::id(id))
        {

            employees.emplace_back(id, name, password, salary);
            cout << "\n>>> Success: Employee [" << name << "] added.\n";
        }
        else
        {
            cout << "\n>>> Error: Invalid data! Please check requirements.\n";
        }
    }

    void viewAllEmployees(const vector<Employee> &employees) const
    {
        if (employees.empty())
        {
            cout << "\n[!] Database is empty.\n";
            return;
        }

        cout << "\n"
            << string(50, '=') << "\n";
        cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(15) << "Salary" << endl;
        cout << string(50, '-') << "\n";

        for (const auto &emp : employees)
        {
            cout << left << setw(10) << emp.Get_Id()
                << setw(20) << emp.Get_Name()
                << setw(15) << emp.getSalary() << endl;
        }
        cout << string(50, '=') << endl;
    }

    Employee *findEmployee(vector<Employee> &employees, int id)
    {
        for (auto &emp : employees)
        {
            if (emp.Get_Id() == id)
                return &emp;
        }
        return nullptr;
    }

    void deleteEmployee(vector<Employee> &employees, int id)
    {
        for (auto it = employees.begin(); it != employees.end(); ++it)
        {
            if (it->Get_Id() == id)
            {
                employees.erase(it);
                cout << "\n>>> Success: Employee with ID " << id << " removed.\n";
                return;
            }
        }
        cout << "\n>>> Error: ID not found.\n";
    }
};