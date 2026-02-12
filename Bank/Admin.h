#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee
{
protected:
    string name;
    int id;
    string password;
    double salary;

public:
    Employee(string n, int i, string p, double s)
        : name(n), id(i), password(p), salary(s) {}

    // Getters
    int Get_Id() const { return id; }
    string Get_Name() const { return name; }

    // Setters
    void SetName(string n) { name = n; }
    void SetPassword(string p) { password = p; }
    void SetSalary(double s) { salary = s; }

    void display() const
    {
        cout << "ID: " << id << " | Name: " << name
             << " | Salary: " << salary << " EGP" << endl;
    }
};

class Admin : public Employee
{
public:
    Admin(string name, int id, string password, double salary)
        : Employee(name, id, password, salary) {}

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

                emp.SetName(newName);
                emp.SetPassword(newPass);
                emp.SetSalary(newSalary);
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

int main()
{
    Admin myAdmin("Ahmed", 1, "admin123", 15000);
    vector<Employee> db; // قاعدة بيانات الموظفين

    int choice;
    do
    {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. Add Employee\n2. View All\n3. Search\n4. Edit\n5. Delete\n0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        int id;
        switch (choice)
        {
        case 1:
            myAdmin.addEmployee(db);
            break;
        case 2:
            myAdmin.viewAllEmployees(db);
            break;
        case 3:
            cout << "Enter ID to search: ";
            cin >> id;
            myAdmin.searchEmployee(db, id);
            break;
        case 4:
            cout << "Enter ID to edit: ";
            cin >> id;
            myAdmin.editEmployee(db, id);
            break;
        case 5:
            cout << "Enter ID to delete: ";
            cin >> id;
            myAdmin.deleteEmployee(db, id);
            break;
        }
    } while (choice != 0);

    return 0;
}