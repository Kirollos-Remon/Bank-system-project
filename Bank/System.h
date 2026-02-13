#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Admin.h"
#include "Employee.h"
#include "Client.h"

using namespace std;

class System
{
private:
    static vector<Employee> allEmployees;
    static vector<Client> allClients;
    static vector<Admin> allAdmins;

public:
    static int choice;

    static void mainMenu()
    {
        while (true)
        {
            cout << "\n===============================" << endl;
            cout << "       BANK MANAGEMENT SYSTEM     " << endl;
            cout << "===============================" << endl;
            cout << "Login as:" << endl;
            cout << "1. Client" << endl;
            cout << "2. Employee" << endl;
            cout << "3. Admin" << endl;
            cout << "0. Exit" << endl;
            cout << "-------------------------------" << endl;
            cout << "Enter your choice: ";

            if (!(cin >> choice))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            cin.ignore();

            if (choice == 0)
                break;

            switch (choice)
            {
            case 1:
                if (clientLogin())
                {
                    Client c(30, "123321456");
                    clientOptions(c);
                };
                break;
            case 2:
                if (employeeLogin())
                {
                    Employee e(20, "John Doe", "87654321", 6000);
                    employeeOptions(e);
                }
                break;
            case 3:
                if (adminLogin())
                {
                    Admin a(10, "Kirollos Remon", "12345678", 50000);
                    adminOptions(a);
                }
                break;
            default:
                cout << "[-] Invalid choice! Try again." << endl;
            }
        }
    }

    static bool adminLogin()
    {
        int id;
        string pass;
        cout << "\n>>> ADMIN LOGIN" << endl;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Pass: ";
        cin.ignore();
        getline(cin, pass);

        if (id == 10 && pass == "12345678")
        {
            cout << "[+] Welcome back, Admin!" << endl;
            return true;
        }
        cout << "[-] Access Denied: Wrong ID or Password." << endl;
        return false;
    }

    static bool employeeLogin()
    {
        int id;
        string pass;
        cout << "\n>>> Employee LOGIN" << endl;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Pass: ";
        cin.ignore();
        getline(cin, pass);

        if (id == 20 && pass == "87654321")
        {
            cout << "[+] Welcome back, Employee!" << endl;
            return true;
        }
        cout << "[-] Access Denied: Wrong ID or Password." << endl;
        return false;
    }

    static bool clientLogin()
    {
        int id;
        string pass;
        cout << "\n>>> Client LOGIN" << endl;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Pass: ";
        cin.ignore();
        getline(cin, pass);

        if (id == 30 && pass == "123321456")
        {
            cout << "[+] Welcome back, Client!" << endl;
            return true;
        }
        cout << "[-] Access Denied: Wrong ID or Password." << endl;
        return false;
    }

    static void adminOptions(Admin &a)
    {
        int adminChoice;
        while (true)
        {
            cout << "\n======= ADMIN DASHBOARD =======" << endl;
            cout << "Active Admin: " << a.Get_Name() << endl;
            cout << "1. Add New Employee" << endl;
            cout << "2. View All Employees" << endl;
            cout << "3. Remove Employee" << endl;
            cout << "0. Logout" << endl;
            cout << "Enter choice: ";
            cin >> adminChoice;

            if (adminChoice == 0)
                break;

            switch (adminChoice)
            {
            case 1:
                a.addEmployee(allEmployees);
                break;
            case 2:
                a.viewAllEmployees(allEmployees);
                break;
            case 3:
            {
                int delID;
                cout << "Enter ID to delete: ";
                cin >> delID;
                a.deleteEmployee(allEmployees, delID);
                break;
            }
            default:
                cout << "[-] Invalid option." << endl;
            }
        }
    }

    

    static void employeeOptions(Employee &e)
    {
        int choice;
        while (true)
        {
            cout << "======= EMPLOYEE DASHBOARD =======" << endl;
            cout << "Welcome, " << e.Get_Name() << " (ID: " << e.Get_Id() << ")" << endl;
            cout << "----------------------------------" << endl;
            cout << "1. Add New Client" << endl;
            cout << "2. List All Clients" << endl;
            cout << "3. Search for Client" << endl;
            cout << "4. Edit Client Info" << endl;
            cout << "5. Display My Info" << endl;
            cout << "0. Logout" << endl;
            cout << "----------------------------------" << endl;
            cout << "Enter choice: ";
            cin >> choice;

            if (choice == 0)
                break;

            switch (choice)
            {
            case 1:
                e.addClient(allClients);
                break;
            case 2:
                e.listAllClients(allClients);
                break;
            case 3:
            {
                int id;
                cout << "\nEnter Client ID to search: ";
                cin >> id;
                e.searchClient(allClients, id);
                break;
            }
            case 4:
            {
                int id;
                cout << "\nEnter Client ID to edit: ";
                cin >> id;
                e.editClient(allClients, id);
                break;
            }
            case 5:
                e.display();
                break;
            default:
                cout << "\n[-] Invalid choice! Please try again." << endl;
            }

            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
    }

    static void clientOptions(Client &c)
    {
        int choice;
        while (true)
        {
            system("cls");
            cout << "======= CLIENT DASHBOARD =======" << endl;
            cout << "Welcome back, " << c.Get_Name() << endl;
            cout << "Current Balance: " << c.getBalance() << " EGP" << endl;
            cout << "----------------------------------" << endl;
            cout << "1. Deposit Money" << endl;
            cout << "2. Withdraw Money" << endl;
            cout << "3. Transfer Money" << endl;
            cout << "4. Check Balance" << endl;
            cout << "5. Display My Info" << endl;
            cout << "0. Logout" << endl;
            cout << "----------------------------------" << endl;
            cout << "Enter choice: ";
            cin >> choice;

            if (choice == 0)
                break;

            switch (choice)
            {
            case 1:
            {
                double amount;
                cout << "\nEnter amount to deposit: ";
                cin >> amount;
                c.deposit(amount);
                break;
            }
            case 2:
            {
                double amount;
                cout << "\nEnter amount to withdraw: ";
                cin >> amount;
                c.withdraw(amount);
                break;
            }
            case 3:
            {
                int targetId;
                double amount;
                cout << "\nEnter Destination Account ID: ";
                cin >> targetId;

                Client *recipient = nullptr;
                for (auto &client : allClients)
                {
                    if (client.Get_Id() == targetId)
                    {
                        recipient = &client;
                        break;
                    }
                }

                if (recipient != nullptr)
                {
                    if (recipient->Get_Id() == c.Get_Id())
                    {
                        cout << "\n[-] Error: You cannot transfer money to yourself!" << endl;
                    }
                    else
                    {
                        cout << "Enter amount to transfer: ";
                        cin >> amount;
                        c.transferTo(amount, *recipient);
                    }
                }
                else
                {
                    cout << "\n[-] Error: Account ID not found!" << endl;
                }
                break;
            }
            case 4:
                cout << "\n";
                c.checkBalance();
                break;
            case 5:
                c.display();
                break;
            default:
                cout << "\n[-] Invalid option!" << endl;
            }

            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
    }
};