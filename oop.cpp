#include <iostream>
#include <ostream>
#include <string>
using namespace std;

class AbstractEmployee // contract, whatever class signes this contract will need to provide implementation for the function AskForPromotion();
{
    virtual void AskForPromotion() = 0;
};


class Employee:AbstractEmployee //  is a blueprint, a model for each employee, signes the contract AbstractEmployee ^
{
    private:
    string company;
    int age;
    protected:
    string name;
    public:
    void setName(string Name) //setter
    {
        name = Name;
    }
    string getName() //getter
    {
        return name;
    }

    void setCompany (string Company)
    {
        company = Company;
    }
    string getCompany()
    {
        return company;
    }

    void setAge(int Age)
    {
        if(Age >= 18)
            age = Age;
    }
    int getAge()
    {
        return age;
    }
    void IntroduceYourself()
    {
        cout << "Name - " << name << endl;
        cout << "Company - " << company << endl;
        cout << "Age - " << age << endl;
    }

    Employee(string Name, string Company, int Age)
    {
        name = Name;
        company = Company;
        age = Age;
    }

    void AskForPromotion()
    {
        if (age >= 30)
            cout << name << " got promoted!" << endl;
        else
            cout << name << ", sorry you need more experience" << endl;
    }

    // the keyword virtual checks before executing Work() if in the child class there is a implementation of Work(), if yes execute it
    // if not go on and execute the defult implementation.

    virtual void Work()
    {
        cout << name << " is checking emails, task backlog, performing task...\n";
    }
};

class Developer:public Employee //now developer is a child class of the parent class Employee, it will inherit all the methods 
{
    public:
    string FavProgrammingLanguage;
    Developer(string Name, string Company, int Age, string favProgrammingLanguage)
        :Employee(Name, Company, Age)
    {
        FavProgrammingLanguage = favProgrammingLanguage;
    }
    
    void fixBug()
    {
        // I can use name since is protected so the child can access it
        cout << name << " fixed bug using " << FavProgrammingLanguage << endl;
    }

    void Work()
    {
        cout << name << " is writing code in" << FavProgrammingLanguage << endl;
    }
};

class Teacher:public Employee
{
    public:
    string subject;

    Teacher(string name, string company, int age, string Subject)
        :Employee(name, company, age)
    {
        subject = Subject;
    }

    void prepareLesson()
    {
        cout << name << " is preparing the lesson of " << subject << endl;
    }

    void Work()
    {
        cout << name << " is teaching " << subject << endl;
    }
};

int main ()
{
    /*
    The most common use of polymorphism is when a parent class reference
    is used to refer to a child class object
    */
    Developer d = Developer("Francesco", "Tesla", 20, "Python");
    Teacher t = Teacher("Jack", "Malpighi", 30, "Math");

    Employee *e1 = &d;
    Employee *e2 = &t;

    e1->Work();
    e2->Work();
}    