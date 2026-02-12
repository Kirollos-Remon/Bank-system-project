#pragma once
#include <iostream>
#include <string>
#include "Validation.h"
#include "Person.h"
#include "Employee.h"
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

    Client(string name, int id, string password, double balance) : Person(name, id, password)
    {
        setBalance(balance);
    }
    Client( int id, string password) 
    {
    }

    void setBalance(double balance)
    {
        if (Validation::balance(balance))
        {
            this->balance = balance;
        }
        else
        {
            cout << "Invalid Balance! Minimum balance is 1500." << endl;
            this->balance = 0;
        }
    }

    double getBalance() const
    {
        return this->balance;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            this->balance += amount;
            cout << "Transaction successful! New balance: " << this->balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= this->balance)
        {
            this->balance -= amount;
            cout << "Transaction successful! New balance: " << this->balance << endl;
        }
        else
        {
            cout << "Invalid." << endl;
        }
    }

    void transferTo(double amount, Client &anotheracc)
    {
        if (amount > 0 && amount <= this->balance)
        {
            this->balance -= amount;
            anotheracc.deposit(amount);
            cout << "Transfer successful! Amount transferred: " << amount << endl;
        }
        else
        {
            cout << "Transfer failed." << endl;
        }
    }

    void checkBalance() const
    {
        cout << "Current Balance: " << this->balance << endl;
    }

    void display() const
    {
        Person::display();
        cout << "Balance: " << this->balance << endl;
    }
};