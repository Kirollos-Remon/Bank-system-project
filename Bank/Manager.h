#pragma once
#include<iostream>
#include "Client.h"
using namespace std;

class clientMamager
{   
    public:
        static void printClientMenu()
        {
            system("cls");
            cout << "============================================" << endl;
            cout << "           CUSTOMER SERVICE MENU            " << endl;
            cout << "============================================" << endl;
            cout << "  [1] Display My Info" << endl; 
            cout << "  [2] Check Balance" << endl;
            cout << "  [3] Withdraw" << endl;
            cout << "  [4] Deposit" << endl;
            cout << "  [5] Transfer Money" << endl;
            cout << "  [6] Change Password" << endl;
            cout << "  [7] Logout" << endl;
            cout << "============================================" << endl;
            cout << ">> Please enter your choice (1-7): ";
        }

        static void updatePassword(Person *person)
        {
            if (person == nullptr)
                return;

            string newPass;
            system("cls");
            cout << "============================================" << endl;
            cout << "             CHANGE PASSWORD                " << endl;
            cout << "============================================" << endl;
            cout << "Current User ID: " << person->Get_Id() << endl;
            cout << "Enter new password: ";
            cin >> newPass;

            Client *clientPtr = dynamic_cast<Client *>(person);
            if (clientPtr != nullptr)
            {
                clientPtr->Set_Password(newPass); 

                vector<Client> clients = FilesHelper::getAllClients();
                for (int i = 0; i < clients.size(); i++)
                {
                    if (clients[i].Get_Id() == person->Get_Id())
                    {
                        clients[i].Set_Password(newPass);
                        break;
                    }
                }
                FilesHelper::saveAllClients(clients);
                cout << "\n[+] Password updated in Clients database." << endl;
            }

            else if (Admin *adminPtr = dynamic_cast<Admin *>(person))
            {
                adminPtr->Set_Password(newPass);

                vector<Admin> admins = FilesHelper::getAllAdmins();
                for (int i = 0; i < admins.size(); i++)
                {
                    if (admins[i].Get_Id() == person->Get_Id())
                    {
                        admins[i].Set_Password(newPass);
                        break;
                    }
                }
                FilesHelper::clearFile("Admins.txt", "LastAdminId.txt");
                for (auto &a : admins)
                {
                    FilesHelper::saveEmployee("Admins.txt", "LastAdminId.txt", a);
                }
                cout << "\n[+] Password updated in Admins database." << endl;
            }

            else if (Employee *empPtr = dynamic_cast<Employee *>(person))
            {
                empPtr->Set_Password(newPass);

                vector<Employee> emps = FilesHelper::getAllEmployees();
                for (int i = 0; i < emps.size(); i++)
                {
                    if (emps[i].Get_Id() == person->Get_Id())
                    {
                        emps[i].Set_Password(newPass);
                        break;
                    }
                }
                FilesHelper::clearFile("Employees.txt", "LastEmpId.txt");
                for (auto &e : emps)
                {
                    FilesHelper::saveEmployee("Employees.txt", "LastEmpId.txt", e);
                }
                cout << "\n[+] Password updated in Employees database." << endl;
            }

            cout << "============================================" << endl;
        }

        static Client *login(int id, string password)
        {
            vector<Client> clients = FilesHelper::getAllClients();
            for (int i = 0; i < clients.size(); i++)
            {
                if (clients[i].Get_Id() == id && clients[i].Get_Password() == password)
                {
                    return new Client(clients[i]);
                }
            }
            return nullptr;
        }

        static bool clientOptions(Client *client)
        {
            printClientMenu();
            int choice;
            cin >> choice;

            switch (choice)
            {
            case 1:
                client->display();
                system("pause");
                break;
            case 2:
                cout << "Balance: " << client->getBalance() << endl;
                system("pause");
                break;
            case 3:
                double withdrawAmount;
                cout << "Enter amount to withdraw: ";
                cin >> withdrawAmount;
                client->withdraw(withdrawAmount);
                system("pause");
                break;
            case 4:
                double depositAmount;
                cout << "Enter amount to deposit: ";
                cin >> depositAmount;
                client->deposit(depositAmount);
                system("pause");
                break;
            case 5:
                system("pause");
                break;
            case 6:
                updatePassword(client);
                system("pause");
                break;
            case 7:
                return false;
            default:
                cout << "Invalid choice!" << endl;
                system("pause");
            }
            return true;
        }
};

class EmployeeManager {
    public:
        static void printEmployeeMenu()
        {
            system("cls");
            cout << "============================================" << endl;
            cout << "             EMPLOYEE CONTROL MENU          " << endl;
            cout << "============================================" << endl;
            cout << "  [1] Display My Info" << endl;
            cout << "  [2] Add New Client" << endl;
            cout << "  [3] List All Clients" << endl;
            cout << "  [4] Search For Client" << endl;
            cout << "  [5] Edit Client Info" << endl;
            cout << "  [6] Change Password" << endl;
            cout << "  [7] Logout" << endl;
            cout << "============================================" << endl;
            cout << ">> Please enter your choice (1-7): ";
        }

        static void newClient(Employee *employee)
        {
            system("cls");
            string name, password;
            double balance;

            cout << "============================================" << endl;
            cout << "              ADD NEW CLIENT                " << endl;
            cout << "============================================" << endl;

            cout << "Enter Client Name: ";
            cin >> name;
            cout << "Enter Password: ";
            cin >> password;
            cout << "Enter Initial Balance: ";
            cin >> balance;

            Client c(0, name, password, balance);

            employee->addClient(c);

            cout << "\n[+] Client Added Successfully!" << endl;
            system("pause");
        }

        static void listAllClients(Employee *employee)
        {
            system("cls");
            cout << "============================================" << endl;
            cout << "              ALL CLIENTS LIST              " << endl;
            cout << "============================================" << endl;

            vector<Client> clients = FilesHelper::getAllClients();

            if (clients.empty())
            {
                cout << "No clients found in the system." << endl;
            }
            else
            {
                for (int i = 0; i < clients.size(); i++)
                {
                    clients[i].display();
                }
            }

            cout << "============================================" << endl;
            system("pause");
        }

        static void searchForClient(Employee *employee)
        {
            system("cls");
            int id;
            cout << "============================================" << endl;
            cout << "              SEARCH FOR CLIENT             " << endl;
            cout << "============================================" << endl;

            cout << ">> Enter Client ID to search: ";
            cin >> id;

            Client *c = employee->searchClient(id);

            if (c != nullptr)
            {
                cout << "\n[+] Client Found Successfully:" << endl;
                c->display();
            }
            else
            {
                cout << "\n[!] Client Not Found! Please check the ID." << endl;
            }

            cout << "============================================" << endl;
            system("pause");
        }

        static void editClientInfo(Employee *employee)
        {
            system("cls");
            int id;
            cout << "============================================" << endl;
            cout << "              EDIT CLIENT INFO              " << endl;
            cout << "============================================" << endl;

            cout << ">> Enter Client ID to Edit: ";
            cin >> id;

            Client *c = employee->searchClient(id);

            if (c != nullptr)
            {
                string name, password;
                double balance;

                cout << "\n[+] Client Found! Enter New Data:" << endl;
                cout << "New Name: ";
                cin >> name;
                cout << "New Password: ";
                cin >> password;
                cout << "New Balance: ";
                cin >> balance;

                employee->editClient(id, name, password, balance);

                cout << "\n[+] Client Info Updated Successfully!" << endl;
            }
            else
            {
                cout << "\n[!] Client Not Found! Edit Cancelled." << endl;
            }

            cout << "============================================" << endl;
            system("pause");
        }

        static Employee *login(int id, string password)
        {
            vector<Employee> allEmployees = FilesHelper::getAllEmployees();

            for (int i = 0; i < allEmployees.size(); i++)
            {
                if (allEmployees[i].Get_Id() == id && allEmployees[i].Get_Password() == password)
                {
                    return new Employee(allEmployees[i]);
                }
            }

            return nullptr;
        }

        static bool employeeOptions(Employee *employee)
        {
            printEmployeeMenu();
            int choice;
            cin >> choice;

            switch (choice)
            {
            case 1:
                system("cls");
                cout << "--- My Info ---" << endl;
                employee->display();
                system("pause");
                break;
            case 2:
                newClient(employee);
                break;
            case 3:
                listAllClients(employee);
                break;
            case 4:
                searchForClient(employee);
                break;
            case 5:
                editClientInfo(employee);
                break;
            case 6:
                system("cls");
                clientMamager::updatePassword(employee);
                system("pause");
                break;
            case 7:
                return false;
            default:
                cout << "\n[!] Invalid choice! Please try again." << endl;
                system("pause");
            }

            return true;
        }
};

class AdminManager : public EmployeeManager
{
public:
    static void printAdminMenu()
    {
        system("cls");
        cout << "============================================" << endl;
        cout << "                ADMIN MENU                  " << endl;
        cout << "============================================" << endl;
        cout << "  [1] Display My Info" << endl;
        cout << "  [2] Add New Employee" << endl;
        cout << "  [3] List All Employees" << endl;
        cout << "  [4] Search For Employee" << endl;
        cout << "  [5] Edit Employee Info" << endl;
        cout << "  [6] Change Password" << endl;
        cout << "  [7] Logout" << endl;
        cout << "============================================" << endl;
        cout << ">> Please enter your choice (1-7): ";
    }

    static Admin *login(int id, string password)
    {
        vector<Admin> admins = FilesHelper::getAllAdmins();
        for (int i = 0; i < admins.size(); i++)
        {
            if (admins[i].Get_Id() == id && admins[i].Get_Password() == password)
            {
                return new Admin(admins[i]);
            }
        }
        return nullptr;
    }

    static void newEmployee(Admin *admin)
    {
        system("cls");
        string name, password;
        double salary;

        cout << "============================================" << endl;
        cout << "             ADD NEW EMPLOYEE               " << endl;
        cout << "============================================" << endl;

        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter Password: ";
        cin >> password;
        cout << "Enter Salary: ";
        cin >> salary;

        Employee e(name,0, password, salary);
        admin->addEmployee(e);
        cout << "\n[+] Employee Added Successfully!" << endl;
    }

    static void searchForEmployee(Admin *admin)
    {
        system("cls");
        int id;
        cout << "============================================" << endl;
        cout << "            SEARCH FOR EMPLOYEE             " << endl;
        cout << "============================================" << endl;

        cout << ">> Enter Employee ID to search: ";
        cin >> id;

        Employee *e = admin->searchEmployee(id);

        if (e != nullptr)
        {
            cout << "\n[+] Employee Found Successfully:" << endl;
            e->display();
            delete e; 
        }
        else
        {
            cout << "\n[!] Employee Not Found!" << endl;
        }
    }

    static void editEmployeeInfo(Admin *admin)
    {
        system("cls");
        int id;
        cout << "Enter Employee ID to Edit: ";
        cin >> id;

        Employee *e = admin->searchEmployee(id);
        if (e != nullptr)
        {
            string name, pass;
            double sal;
            cout << "New Name: ";
            cin >> name;
            cout << "New Password: ";
            cin >> pass;
            cout << "New Salary: ";
            cin >> sal;

            admin->editEmployee(id, name, pass, sal);
            cout << "\n[+] Employee Updated!" << endl;
            delete e;
        }
        else
        {
            cout << "\n[!] Not Found!" << endl;
        }
    }

    static bool AdminOptions(Admin *admin)
    {
        printAdminMenu();
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            admin->display();
            system("pause");
            break;
        case 2:
            newEmployee(admin); 
            system("pause");
            break;
        case 3:
            admin->listEmployee();
            system("pause");
            break;
        case 4:
            searchForEmployee(admin);
            system("pause");
            break;
        case 5:
            editEmployeeInfo(admin); 
            system("pause");
            break;
        case 6:
            clientMamager::updatePassword(admin);
            system("pause");
            break;
        case 7:
            return false;
        default:
            cout << "Invalid choice!" << endl;
            system("pause");
        }
        return true;
    }
};

#include <thread>
#include <chrono>
class Screen{
    public:
        static void bankName()
        {
            cout << "\n\t==========================================" << endl;
            cout << "\t      WELCOME TO ROUTE BANK SYSTEM        " << endl;
            cout << "\t==========================================" << endl;
        }

        static void welcome()
        {
            system("cls");
            system("color 04"); 

            bankName();

            cout << "\n\n";
            cout << "\t       >> System Initializing...           " << endl;
            cout << "\t       >> Loading Databases...             " << endl;
            cout << "\t       >> Securing Connection...           " << endl;

            this_thread::sleep_for(chrono::seconds(3));

            system("cls");
            system("color 07"); 
        }

        static void loginOptions()
        {
            cout << "\n\t--- LOGIN AS ---" << endl;
            cout << "\t[1] Client" << endl;
            cout << "\t[2] Employee" << endl;
            cout << "\t[3] Admin" << endl;
            cout << "\t[4] Exit" << endl;
            cout << "\n\t>> Choice: ";
        }

        static int loginAs()
        {
            int choice;
            cin >> choice;
            return choice;
        }

        static void invalid(int c)
        {
            system("color 0C");
            cout << "\n\t [!] Invalid choice: " << c << " [!]" << endl;
            cout << "\t Please enter a number between 1 and 4." << endl;

            this_thread::sleep_for(chrono::seconds(2));
            system("color 07"); 
        }

        static void logout()
        {
            system("cls");
            bankName();
            cout << "\n\n\t Thank you for using ROUTE Bank System!" << endl;
            cout << "\t Logging out safely..." << endl;

            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
        }

        

        static void loginScreen(int c)
        {
            int id;
            string pass;
            bool flag = false;

            do
            {
                system("cls");
                bankName();

                string type = (c == 1) ? "Client" : (c == 2) ? "Employee": "Admin";
                cout << "\n\t--- " << type << " Login ---" << endl;

                cout << "\n\tID: ";
                cin >> id;
                cout << "\tPassword: ";
                cin >> pass;

                if (c == 1)
                {
                    Client *cl = clientMamager::login(id, pass);
                    if (cl != nullptr)
                    {
                        flag = true;
                        while (clientMamager::clientOptions(cl))
                            ;
                        delete cl;
                    }
                }
                else if (c == 2)
                {
                    Employee *emp = EmployeeManager::login(id, pass);
                    if (emp != nullptr)
                    {
                        flag = true;
                        while (EmployeeManager::employeeOptions(emp))
                            ;
                        delete emp;
                    }
                }
                else if (c == 3)
                {
                    Admin *ad = AdminManager::login(id, pass);
                    if (ad != nullptr)
                    {
                        flag = true;
                        while (AdminManager::AdminOptions(ad))
                            ;
                        delete ad;
                    }
                }

                if (!flag)
                {
                    system("color 0C"); 
                    cout << "\n\t [!] Invalid ID or Password! Try again." << endl;
                    this_thread::sleep_for(chrono::seconds(2));
                    system("color 07"); 
                }

            } while (!flag);
        }

        static void runApp()
        {
            welcome();
            while (true)
            {
                system("cls");
                bankName();
                loginOptions();
                int choice = loginAs();

                if (choice >= 1 && choice <= 3)
                {
                    loginScreen(choice);
                }
                else if (choice == 4)
                {
                    logout();
                    break;
                }
                else
                {
                    invalid(choice);
                }
            }
        }
};

