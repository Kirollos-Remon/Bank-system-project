#pragma once
#include <fstream>
#include "Parser.h"

class FilesHelper
{
public:
    static void saveLast(string fileName, int id)
    {
        ofstream file(fileName);
        if (file.is_open())
        {
            file << id;
            file.close();
        }
    }

    static int getLast(string fileName)
    {
        ifstream file(fileName);
        int id = 0;
        if (file.is_open())
        {
            file >> id;
            file.close();
        }
        return id;
    }

    static void saveClient(Client c)
    {
        ofstream file("Clients.txt", ios::app);
        if (file.is_open())
        {
            file << c.Get_Id() << "|" << c.Get_Name() << "|" << c.Get_Password() << "|" << c.getBalance() << endl;
            file.close();
        }
    }

    static void saveAllClients(vector<Client> clients)
    {
        ofstream file("Clients.txt", ios::trunc);
        for (int i = 0; i < clients.size(); i++)
        {
            file << clients[i].Get_Id() << "|" << clients[i].Get_Name() << "|" << clients[i].Get_Password() << "|" << clients[i].getBalance() << endl;
        }
        file.close();
    }

    static void saveEmployee(string fileName, string lastIdFile, Employee e)
    {
        ofstream file(fileName, ios::app);
        if (file.is_open())
        {
            file << e.Get_Id() << "|" << e.Get_Name() << "|" << e.Get_Password() << "|" << e.getSalary() << endl;
            file.close();
            saveLast(lastIdFile, e.Get_Id());
        }
    }

    static void clearFile(string fileName, string lastIdFile)
    {
        ofstream file1(fileName, ios::trunc);
        file1.close();

        ofstream file2(lastIdFile, ios::trunc);
        file2 << 0;
        file2.close();
    }

    static vector<Client> getAllClients()
    {
        vector<Client> clients;
        ifstream file("Clients.txt");
        string line;
        while (getline(file, line))
        {
            if (!line.empty())
                clients.push_back(Parser::parseClients(line));
        }
        file.close();
        return clients;
    }

    static vector<Employee> getAllEmployees()
    {
        vector<Employee> emps;
        ifstream file("Employees.txt");
        string line;
        while (getline(file, line))
        {
            if (!line.empty())
                emps.push_back(Parser::parseEmployees(line));
        }
        file.close();
        return emps;
    }

    static vector<Admin> getAllAdmins()
    {
        vector<Admin> admins;
        ifstream file("Admins.txt");
        string line;
        while (getline(file, line))
        {
            if (!line.empty())
                admins.push_back(Parser::parseAdmins(line));
        }
        file.close();
        return admins;
    }
};