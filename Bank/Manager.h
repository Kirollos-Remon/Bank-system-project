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
            string newPass;
            cout << "Enter new password: ";
            cin >> newPass;
            person->Set_Password(newPass);

            vector<Client> clients = FilesHelper::getAllClients();
            bool found = false;

            for (int i = 0; i < clients.size(); i++)
            {
                if (clients[i].Get_Id() == person->Get_Id())
                {
                    clients[i].Set_Password(newPass);
                    found = true;
                    break;
                }
            }

            if (found)
            {
                FilesHelper::saveAllClients(clients);
                cout << "Password Updated Successfully!" << endl;
            }
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

