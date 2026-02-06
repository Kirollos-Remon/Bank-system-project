#include <iostream>
#include <string>
using namespace std;

class Validation
{
public:
    // methods
    static bool Name(const string &name)
    {

        if (name.length() < 5 || name.length() > 20)
            return false;

        for (int i = 0; i < name.length(); i++)
        {
            if (!((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || name[i] == ' '))
            {
                return false;
            }
        }
        return true;
    }

    static bool balance(double balance)
    {
        if (balance >= 1500)
            return true;
        else
            return false;
    }

    static bool password(const string &pass)
    {
        if (pass.length() >= 8 && pass.length() <= 20)
            return true;
        else
            return false;
    }

    static bool salary(double salary)
    {
        if (salary >= 5000)
            return true;
        else
            return false;
    }

    static bool id(int id)
    {
        if (id > 0)
            return true;
        else
            return false;
    }
};

class Person
{
protected:
    // Attributes
    string name;
    int id;
    string password;

public:
    // constructors
    Person()
    {
        id = 0;
    }
    Person(const string &name, int id, const string &password)
    {
        Set_Person(name, id, password);
    }

    // Setters
    void Set_Name(const string &name)
    {
        if (Validation::Name(name))
            this->name = name;
        else
            cout << "Invalid Name" << endl;
    }

    void Set_Id(int id)
    {
        if (Validation::id(id))
            this->id = id;
        else
            cout << "Invalid ID" << endl;
    }

    void Set_Password(const string &password)
    {
        if (Validation::password(password))
            this->password = password;
        else
            cout << "Invalid Password" << endl;
    }

    void Set_Person(const string &name, int id, const string &password)
    {
        Set_Name(name);
        Set_Id(id);
        Set_Password(password);
    }

    // Getters
    string Get_Name() const
    {
        return this->name;
    }
    int Get_Id() const
    {
        return this->id;
    }
    string Get_Password() const
    {
        return this->password;
    }

    // methods
    void display() const
    {
        cout << "Name: " << Get_Name() << endl;
        cout << "ID: " << Get_Id() << endl;
        cout << "Password: " << Get_Password() << endl;
    }

    // destructor
    ~Person()
    {
    }
};

class Employee : public Person
{

protected:
    double salary;

public:
    // 1. Constructors
    Employee() : Person()
    {
        this->salary = 0;
    }

    Employee(const string &name, int id, const string &password, double salary) : Person(name, id, password)
    {
        setSalary(salary);
    }

    // 2. Setter with Validation
    void setSalary(double salary)
    {
        if (Validation::salary(salary))
        {
            this->salary = salary;
        }
        else
        {
            cout << "Invalid Salary! Minimum salary is 5000." << endl;
            this->salary = 0;
        }
    }

    // 3. Getter
    double getSalary() const
    {
        return this->salary;
    }

    // 4. Methods
    void display() const
    {

        Person::display();
        cout << "Salary: " << this->salary << endl;
        cout << "----------------------" << endl;
    }
};

int main()
{
    return 0;
}
