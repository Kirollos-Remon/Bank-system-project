#pragma once
#include <fstream>
#include <string>
#include <vector>
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
};