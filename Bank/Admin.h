#pragma once
#include "Employee.h"

using namespace std;

class FilesHelper;

class Admin : public Employee
{
private:
    vector<Employee> employees;

public:
    Admin() : Employee() {}
    Admin(string name, int id, string password, double salary)
        : Employee(name, id, password, salary) {}

    void addEmployee(Employee &e)
    {
        int lastId = FilesHelper::getLast("LastEmpId.txt");
        e.Set_Id(lastId + 1);
        FilesHelper::saveEmployee("Employees.txt", "LastEmpId.txt", e);
        cout << "Employee added with ID: " << e.Get_Id() << endl;
    }

    Employee *searchEmployee(int id)
    {
        employees = FilesHelper::getAllEmployees();
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
        employees = FilesHelper::getAllEmployees();
        bool found = false;
        for (int i = 0; i < employees.size(); i++)
        {
            if (employees[i].Get_Id() == id)
            {
                employees[i].Set_Name(name);
                employees[i].Set_Password(password);
                employees[i].setSalary(salary);

                FilesHelper::clearFile("Employees.txt", "LastEmpId.txt");
                int lastId = 0;
                for (auto &e : employees)
                {
                    FilesHelper::saveEmployee("Employees.txt", "LastEmpId.txt", e);
                    lastId = e.Get_Id();
                }
                FilesHelper::saveLast("LastEmpId.txt", lastId);

                found = true;
                cout << "Employee ID " << id << " updated successfully." << endl;
                break;
            }
        }
        if (!found)
            cout << "Employee not found." << endl;
    }

    void listEmployee()
    {
        employees = FilesHelper::getAllEmployees();
        cout << "--- Listing All Employees ---" << endl;
        if (employees.empty())
            cout << "No employees found." << endl;
        for (auto &emp : employees)
            emp.display();
    }

    void display()
    {
        cout << "--- Admin Data ---" << endl;
        Employee::display();
        cout << "-----------------------" << endl
             << endl;
    }

   
};