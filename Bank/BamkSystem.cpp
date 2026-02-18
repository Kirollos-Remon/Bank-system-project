#include <iostream>
#include <string>
#include "Employee.h"
#include "Admin.h"
#include "Validation.h"
#include "Person.h"
#include "Client.h"

int main()
{
    Admin admin1("Mahmoud Abdo", 101, "87654321", 6000);
    admin1.display();
    system("pause");
    system("cls");  

    Employee emp1("Mohamed Amr", 201,"12345678", 5500);
    cout << "--- Employee Data ---" << endl;
    emp1.display();
    system("pause");
    system("cls");


    Client client1(301, "Ganna Ayman", "43215678", 200000);
    client1.display();
    client1.deposit(500);
    system("pause");
    system("cls");

    Client client2(301, "Ahmed Mohamed", "12332145", 30000); 
    client2.display();
    client2.deposit(500);
    client2.transferTo(300,client1);
    system("pause");
    system("cls");
}
