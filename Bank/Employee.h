#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Validation.h"
#include "Client.h"
#include "FilesHelper.h"
#include "FileManager.h"

using namespace std;

class Employee : public Person
{
private:
    double salary;
    vector<Client> clients;

public:
    Employee() : Person()
    {
        this->salary = 0;
    }

    Employee(string name, int id, string password, double salary) : Person(name, id, password)
    {
        setSalary(salary);
    }

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

    double getSalary()
    {
        return salary;
    }

    void addClient(Client &client)
    {
        int lastId = FilesHelper::getLast("ClientLastId.txt");
        client.Set_Id(lastId + 1);
        FilesHelper::saveClient(client);
        FilesHelper::saveLast("ClientLastId.txt", client.Get_Id());
        cout << "Client added with ID: " << client.Get_Id() << endl;
    }

    Client *searchClient(int id)
    {
        clients = FilesHelper::getAllClients();
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
        clients = FilesHelper::getAllClients();
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
        clients = FilesHelper::getAllClients();
        bool found = false;
        for (int i = 0; i < clients.size(); i++)
        {
            if (clients[i].Get_Id() == id)
            {
                clients[i].Set_Name(name);
                clients[i].Set_Password(password);
                clients[i].setBalance(balance);

                FilesHelper::clearFile("Clients.txt", "ClientLastId.txt");
                int lastId = 0;
                for (auto &c : clients)
                {
                    FilesHelper::saveClient(c);
                    lastId = c.Get_Id();
                }
                FilesHelper::saveLast("ClientLastId.txt", lastId);

                found = true;
                cout << "Client ID " << id << " updated successfully." << endl;
                break;
            }
        }
        if (!found)
            cout << "Client with ID " << id << " not found." << endl;
    }

    void display()
    {
        Person::display();
        cout << "Salary: " << salary << endl;
        cout << "-----------------------" << endl
             << endl;
    }
};