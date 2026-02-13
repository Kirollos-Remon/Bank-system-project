#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 
#include "Person.h"
#include "Client.h"
#include "Validation.h"

using namespace std;

class Employee : public Person
{
protected:
    double salary;

public:
    Employee() : Person(){
        salary = 0;
    }

    Employee(int id, string name, string password, double salary)
        : Person(name, id, password)
    {
        Set_Salary(salary);
    }

    void Set_Salary(double salary)
    {
        if (Validation::salary(salary))
            this->salary = salary;
        else
            cout << "[-] Invalid Salary! Minimum is 5000.\n";
    }
    double getSalary() const { return salary; }


    void addClient(vector<Client> &clients)
    {
        string name, password;
        int id;
        double balance;

        cout << "\n[New Client Entry]\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "ID: ";
        cin >> id;
        cout << "Password: ";
        cin >> password;
        cout << "Balance: ";
        cin >> balance;

        if (Validation::Name(name) && Validation::password(password) && Validation::balance(balance))
        {
            clients.emplace_back(id, name, password, balance);
            cout << "\n[+] Success: Client added.\n";
        }
        else
        {
            cout << "\n[-] Error: Invalid client data!\n";
        }
    }

    // (d) Search for Client by ID
    void searchClient(const vector<Client> &clients, int id) const
    {
        for (const auto &c : clients)
        {
            if (c.Get_Id() == id)
            {
                cout << "\n[Client Found]:\n";
                c.display();
                return;
            }
        }
        cout << "\n[-] Error: Client ID " << id << " not found.\n";
    }

    // (e) List All Clients
    void listAllClients(const vector<Client> &clients) const
    {
        if (clients.empty())
        {
            cout << "\n[!] No clients registered.\n";
            return;
        }
        cout << "\n"
             << string(50, '=') << "\n";
        cout << left << setw(10) << "ID" << setw(25) << "Name" << setw(15) << "Balance" << endl;
        cout << string(50, '-') << "\n";
        for (const auto &c : clients)
        {
            cout << left << setw(10) << c.Get_Id() << setw(25) << c.Get_Name() << setw(15) << c.getBalance() << endl;
        }
        cout << string(50, '=') << endl;
    }

    // (f) Edit Client Info
    void editClient(vector<Client> &clients, int id)
    {
        for (auto &c : clients)
        {
            if (c.Get_Id() == id)
            {
                string n, p;
                double b;
                cout << "\n--- Editing Client ID: " << id << " ---\n";
                cout << "New Name: ";
                cin.ignore();
                getline(cin, n);
                cout << "New Pass: ";
                cin >> p;
                cout << "New Balance: ";
                cin >> b;

                c.Set_Name(n);
                c.Set_Password(p);
                c.setBalance(b);
                cout << "[!] Client updated successfully.\n";
                return;
            }
        }
        cout << "[-] Error: Client not found.\n";
    }

    void display()
    {
        cout << "\n--- My Information ---\n";
        Person::display();
        cout << "Salary: " << salary << " EGP" << endl;
        cout << "----------------------" << endl;
    }
};