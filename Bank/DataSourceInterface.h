#include<iostream>
#include<string>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;

class DataSourceInterface{
    public:
        virtual void addClient(Client c) = 0;
        virtual void addEmployee(Employee e) = 0;
        virtual void addAdmin(Admin a) = 0;
        virtual void displayClients() = 0;
        virtual void displayEmployees() = 0;
        virtual void displayAdmins() = 0;
        virtual void AllClient() = 0;
        virtual void AllEmployee() = 0;
        virtual void AllAdmin() = 0;
};