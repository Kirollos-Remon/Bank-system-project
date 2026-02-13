#include "System.h"

int System::choice = 0;
vector<Employee> System::allEmployees;
vector<Client> System::allClients;
vector<Admin> System::allAdmins;

int main()
{
    System::mainMenu();
    return 0;
}
