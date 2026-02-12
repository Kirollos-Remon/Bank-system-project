#pragma once
#include <iostream>
#include <string>
#include "Validation.h"
#include "Person.h"
#include "Employee.h"
#include "Admin.h"
#include "Employee.h"
#include "Client.h"
#include <vector>
using namespace std;

class System
    {
        public:
            static int choice;
            static void mainMenu()
            {
            while (true)
            {
                cout << "\n======= BANK SYSTEM =======" << endl;
                cout << "Login as:" << endl;
                cout << "1. Client" << endl;
                cout << "2. Employee" << endl;
                cout << "3. Admin" << endl;
                cout << "0. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                cin.ignore();

                if (choice == 0)
                    break;

                switch (choice)
                {
                case 1:
                    clientLogin();
                    break;
                case 2:
                    employeeLogin();
                    break;
                case 3:
                    adminLogin();
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                }
            }
        }
        static bool adminLogin()
        {
            Admin a(10,"Kirollos Remon"); 
            const int staticID = a.Get_Id();
            const string staticPass = a.Get_Password();
            int id;
            string pass;
            cout << "ID: ";
            cin >> id;
            cin.ignore();
            cout << "Pass: ";
            getline(cin,pass);
            if (id == staticID && pass == staticPass)
            {
                cout << "Admin login successful!" << endl;
                return true;
            }
            else
            {
                cout << "Admin login failed!" << endl;
                return false;
            }
        }
        static bool employeeLogin()
        {
            Employee e(111,"Mohamed Amr");
            const int staticID = e.Get_Id();
            const string staticPass = e.Get_Password();
            int id;
            string pass;
            cout << "ID: ";
            cin >> id;
            cin.ignore();
            cout << "Pass: ";
            getline(cin, pass);
            if (id == staticID && pass == staticPass)
            {
                cout << "Employee login successful!" << endl;
                return true;
            }
            else
            {
                cout << "Employee login failed!" << endl;
                return false;
            }
        }
        static bool clientLogin()
        {
            Client c(222,"Ganna Ayman");
            const int staticID = c.Get_Id();
            const string staticPass = c.Get_Password();
            int id;
            string pass;
            cout << "ID: ";
            cin >> id;
            cin.ignore();
            cout << "Pass: ";
            getline(cin, pass);
            if (id == staticID && pass == staticPass)
            {
                cout << "Client login successful!" << endl;
                return true;
            }
            else
            {
                cout << "Client login failed!" << endl;
                return false;
            }
        }

        private:
            vector<Employee> Employees;
            vector<Client> Clients;
            vector<Admin> Admins;

    };