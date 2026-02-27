#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"

class FileManager : public DataSourceInterface
{
public:
    void addClient(Client c) 
    {
        FilesHelper::saveClient(c);
    }

    void addEmployee(Employee e) 
    {
        FilesHelper::saveEmployee("Employees.txt", "LastIds.txt", e);
    }

    void addAdmin(Admin a) 
    {
        FilesHelper::saveEmployee("Admins.txt", "LastIds.txt", a);
    }

    void displayClients() 
    {
        vector<Client> all = FilesHelper::getAllClients();
        for (auto &c : all)
            c.display();
    }

    void displayEmployees() 
    {
        vector<Employee> all = FilesHelper::getAllEmployees();
        for (auto &e : all)
            e.display();
    }

    void displayAdmins() 
    {
        vector<Admin> all = FilesHelper::getAllAdmins();
        for (auto &a : all)
            a.display();
    }

    void AllClient() 
    {
        vector<Client> clients = FilesHelper::getAllClients();
    }

    void AllEmployee() 
    {
        vector<Employee> emps = FilesHelper::getAllEmployees();
    }

    void AllAdmin() 
    {
        vector<Admin> admins = FilesHelper::getAllAdmins();
    }
};