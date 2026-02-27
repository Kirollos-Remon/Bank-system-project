#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "Parser.h"

class FileManager
{
public:
    static void addClient(Client &c)
    {
        ofstream file("Clients.txt", ios::app); 
        if (file.is_open())
        {
            file << c.Get_Id() << "|" << c.Get_Name() << "|" << c.Get_Password() << "|" << c.getBalance() << endl;
            file.close();
        }
    }

    static void addEmployee(Employee &e)
    {
        ofstream file("Employees.txt", ios::app);
        if (file.is_open())
        {
            file << e.Get_Id() << "|" << e.Get_Name() << "|" << e.Get_Password() << "|" << e.getSalary() << endl;
            file.close();
        }
    }

    static vector<Client> getAllClients()
    {
        vector<Client> clients;
        ifstream file("Clients.txt");
        string line;
        if (file.is_open())
        {
            while (getline(file, line))
            {
                if (!line.empty())
                {
                    clients.push_back(Parser::parseClients(line));
                }
            }
            file.close();
        }
        return clients;
    }

    static void removeAllClients()
    {
        ofstream file("Clients.txt", ios::trunc);
        file.close();
    }
};