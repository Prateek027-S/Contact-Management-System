#include<iostream>
#include<fstream>
#include<regex>
#include<sstream>
#include<unistd.h>
using namespace std;

class Person
{
    string name, mobile, address;
public:
    Person(string Name, string Mobile, string Address)
    {
        name = Name;
        mobile = Mobile;
        address = Address;
    }
    void add_contacts();
};

void Person::add_contacts()
{
    fstream file1;
    file1.open("Contacts.txt", ios::app | ios::out);
    file1<<"Name: "<<name<<endl;
    file1<<"Mobile: +91"<<mobile<<endl;
    file1<<"Address: "<<address<<endl;
    file1<<endl;
    cout<<"Contact Details added successfully!!"<<endl;
    usleep(1000000);
    file1.close();
}

void get_input()
{
    string name, mobile, address;
    cout<<"\nEnter Name: ";
    getline(cin, name);
    while(true)
    {
        cout<<"Enter Mobile no.: +91 ";
        getline(cin, mobile);
        const regex pattern("[0-9]{10}");

        if(regex_match(mobile, pattern))
            break;
        else{
            cout<<"Please enter valid mobile number."<<endl;
            continue;
        }
    }
    cout<<"Enter Address: ";
    getline(cin, address);
    Person p1(name, mobile, address);
    p1.add_contacts();
}

int main()
{
    string choice;
    int ch = 0;
    cout<<"****"<<endl;
    cout<<"Menu"<<endl;
    cout<<"****"<<endl;
    cout<<"You can perform following operations:-\n1. Add a new Contact\n2. Show all Contacts\n3. Search a Contact\n4. Edit a Contact\n5. Delete a Contact\n6. Exit"<<endl;
    cout<<"\nEnter the S.No. of the operation you want to perform: ";
    getline(cin, choice);
    stringstream stream(choice);
    stream>>ch;
    switch(ch)
    {
        case 1:{
            get_input();
            break;
        }
        case 2:{
            //showContacts();
            break;
        }
        case 3:{
            //searchContact();
            break;
        }
        case 4:{
            //editContact();
            break;
        }
        case 5:{
            //delContact();
            break;
        }
        case 6:{
            cout<<"\nThank you for using the program!";
            exit(0);
            break;
        }
        default:{
            cout<<"Please enter valid S.No.!!"<<endl;
            usleep(1000000);
            system("CLS");
        }
    }
    system("CLS");
    main();
    return 0;
}
