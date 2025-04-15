#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int NAME_SIZE = 51, ADDR_SIZE = 51, PHONE_SIZE = 14;
struct Info
{
    char name[NAME_SIZE];
    int age;
    char address1[ADDR_SIZE];
    char address2[ADDR_SIZE];
    char phone[PHONE_SIZE];
};

long byteNum(int);
void showRec(Info);

int main() 
{
    Info person;
    fstream people;
    string name;

    cout << "Which file do you want to open? ";
    cin >> name;
    people.open(name, ios::in | ios::binary);
    
    if (!people) {
    cout << "Error opening file. Program aborting.\n";
    return 0;
    }
    
    int nRecord;
    string cont;
    do 
    {
        cout << "Which record do you want to read? ";
        cin >> nRecord;

        people.seekg(byteNum((nRecord - 1)), ios::beg);
        if(!people.read(reinterpret_cast<char *>(&person), sizeof(person)))
        {
            cout << "No record\n";
            people.clear();
        } else {
            showRec(person);
        }
        cout << "Do you want to continue? (Yes/No)";
        cin >> cont;
        cont[0] = toupper(cont[0]);
    } while(cont == "Y" || cont == "Yes");

    people.close();
    return 0;
}


long byteNum(int recNum) 
{
    return sizeof(Info) * recNum;
}

void showRec(Info record) 
{
    cout << "Name: ";
    cout << record.name << endl;
    cout << "Age: ";
    cout << record.age << endl;
    cout << "Address line 1: ";
    cout << record.address1 << endl;
    cout << "Address line 2: ";
    cout << record.address2 << endl;
    cout << "Phone: ";
    cout << record.phone << endl;
}