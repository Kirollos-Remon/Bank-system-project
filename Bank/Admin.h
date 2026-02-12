#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Admin : public Employee
{
public:
    Admin(string name, int id, string password, double salary)
        : Employee(name, id, password, salary) {}
    Admin(int id , string paswword)
        : Employee("Admin", id, paswword, 0) {}
    void searchEmployee(const vector<Employee> &Employees, int EmployeeID) const
    {
        for (const auto &emp : Employees)
        {
            if (emp.Get_Id() == EmployeeID)
            {
                cout << "\n[+] Employee Found:\n";
                emp.display();
                return;
            }
        }
        cout << "\n[-] Error: Employee ID " << EmployeeID << " not found.\n";
    }

    void addEmployee(vector<Employee> &Employees)
    {
        string name, password;
        int id;
        double salary;
        cout << "\n--- Adding New Employee ---\n";
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter password: ";
        cin >> password;
        cout << "Enter salary: ";
        cin >> salary;

        Employees.push_back(Employee(name, id, password, salary));
        cout << "[+] Employee added successfully!\n";
    }

    void editEmployee(vector<Employee> &Employees, int EmployeeID)
    {
        for (auto &emp : Employees)
        {
            if (emp.Get_Id() == EmployeeID)
            {
                string newName, newPass;
                double newSalary;
                cout << "\n--- Editing ID: " << EmployeeID << " ---\n";
                cout << "New name: ";
                cin >> newName;
                cout << "New password: ";
                cin >> newPass;
                cout << "New salary: ";
                cin >> newSalary;

                emp.Set_Name(newName);
                emp.Set_Password(newPass);
                emp.Set_Salary(newSalary);
                cout << "[!] Updated successfully!\n";
                return;
            }
        }
        cout << "[-] Error: Employee not found!\n";
    }

    void deleteEmployee(vector<Employee> &Employees, int EmployeeID)
    {
        for (size_t i = 0; i < Employees.size(); i++)
        {
            if (Employees[i].Get_Id() == EmployeeID)
            {
                Employees.erase(Employees.begin() + i);
                cout << "[!] Employee deleted successfully!\n";
                return;
            }
        }
        cout << "[-] Error: Not found!\n";
    }

    void viewAllEmployees(const vector<Employee> &Employees) const
    {
        if (Employees.empty())
        {
            cout << "\n[!] No employees in the system.\n";
            return;
        }
        cout << "\n--- Current Employee List ---\n";
        for (const auto &emp : Employees)
            emp.display();
    }
};

