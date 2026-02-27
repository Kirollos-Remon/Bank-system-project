#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Validation.h"
#include "Person.h"
#include "FilesHelper.h"
#include "FileManager.h"

using namespace std;

class Client : public Person
{
private:
    double balance;

public:
    Client() : Person()
    {
        this->balance = 0;
    }

    Client(int id, string name, string password, double balance)
        : Person(name, id, password)
    {
        setBalance(balance);
    }

    void setBalance(double balance)
    {
        if (Validation::balance(balance))
        {
            this->balance = balance;
        }
        else
        {
            cout << "[!] Invalid Balance! Minimum balance is 1500." << endl
                 << endl;
            this->balance = 1500;
        }
    }

    double getBalance() const
    {
        return this->balance;
    }

    void updateInFile()
    {
        vector<Client> allClients = FilesHelper::getAllClients();
        for (int i = 0; i < allClients.size(); i++)
        {
            if (allClients[i].Get_Id() == this->Get_Id())
            {
                allClients[i].balance = this->balance;
                allClients[i].Set_Name(this->Get_Name());
                allClients[i].Set_Password(this->Get_Password());
                break;
            }
        }
        FilesHelper::clearFile("Clients.txt", "ClientLastId.txt");
        int lastId = 0;
        for (auto &c : allClients)
        {
            FilesHelper::saveClient(c);
            lastId = c.Get_Id();
        }
        FilesHelper::saveLast("ClientLastId.txt", lastId);
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            this->balance += amount;
            updateInFile();
            cout << "[+] Transaction successful! New balance: " << this->balance << endl
                 << endl;
        }
        else
        {
            cout << "[!] Invalid deposit amount." << endl
                 << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= this->balance)
        {
            this->balance -= amount;
            updateInFile();
            cout << "[+] Transaction successful! New balance: " << this->balance << endl
                 << endl;
        }
        else
        {
            cout << "[!] Invalid or insufficient funds." << endl;
        }
    }

    void transferTo(double amount, Client &anotheracc)
    {
        if (amount > 0 && amount <= this->balance)
        {
            this->balance -= amount;
            anotheracc.balance += amount;

            this->updateInFile();
            anotheracc.updateInFile();

            cout << "[+] Transfer successful! Amount transferred: " << amount << endl
                 << endl;
        }
        else
        {
            cout << "[!] Transfer failed." << endl
                 << endl;
        }
    }

    void checkBalance() const
    {
        cout << "Current Balance: " << this->balance << endl;
    }

    void display() const
    {
        cout << "--- Client Data ---" << endl;
        Person::display();
        cout << "Balance: " << this->balance << endl;
        cout << "-----------------------" << endl
             << endl;
    }
};