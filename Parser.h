#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

using namespace std;

class Parser
{
    public: 
        static vector<string> SplitLine(string line ){
            vector<string> result;
            stringstream ss(line);
            string item;        
            while (getline(ss, item, '|')) {
                result.push_back(item);
            }
            return result;
        }

        static Client parseClients( string line) {
            Client clients;
                vector<string> parts = SplitLine(line);
                if (parts.size() == 4) {
                    int id = stoi(parts[0]);
                    string name = parts[1];
                    string password = parts[2];
                    double balance = stod(parts[3]);
                    clients = Client(id, name, password, balance);
                
            }
            return clients;
        }

        static Employee parseEmployees(string line) {
            Employee employee;
            vector<string> parts = SplitLine(line);
            if (parts.size() == 4) {
                int id = stoi(parts[0]);
                string name = parts[1];
                string password = parts[2];
                double salary = stod(parts[3]);
                employee = Employee(name, id, password, salary);
            }
            return employee;
        }

        static Admin parseAdmins(string line) {
            Admin admin;
            vector<string> parts = SplitLine(line);
            if (parts.size() == 4) {
                int id = stoi(parts[0]);
                string name = parts[1];
                string password = parts[2];
                double salary = stod(parts[3]);
                admin = Admin(name, id, password, salary);
            }
            return admin;
        }
};
