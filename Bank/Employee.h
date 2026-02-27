#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Validation.h"
#include "Client.h"

using namespace std;

class Employee : public Person
{
private:
    double salary;
    vector<Client> clients;

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

    void addClient(Client &client)
    {
        clients.push_back(client);
        cout << "Client added successfully." << endl;
    }

    Client *searchClient(int id)
    {
        for (int i = 0; i < clients.size(); i++)
        {
            if (clients[i].Get_Id() == id)
            {
                return &clients[i];
            }
        }
        return nullptr;
    }

    void listClient()
    {
        cout << "--- Listing All Clients Managed by " << Get_Name() << " ---" << endl;
        if (clients.empty())
        {
            cout << "No clients found." << endl;
        }
        for (const auto &client : clients)
        {
            client.display();
        }
    }

    void editClient(int id, string name, string password, double balance)
    {
        Client *client = searchClient(id);
        if (client != nullptr)
        {
            client->Set_Name(name);
            client->Set_Password(password);
            client->setBalance(balance);
            cout << "Client ID " << id << " updated successfully." << endl;
        }
        else
        {
            cout << "Client with ID " << id << " not found." << endl;
        }
    }

    void display()
    {
        Person::display();
        cout << "Salary: " << salary << endl;
        cout << "Clients Managed: " << clients.size() << endl;
        cout << "-----------------------" << endl
             << endl;
    }
};
