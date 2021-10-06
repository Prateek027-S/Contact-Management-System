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
    int chk_contact();
    void edit_contact();
    void add_contacts();
};

int Person::chk_contact()
{
    fstream file0;
    string st, st2;
    int ans = -1;
    file0.open("ContactBook.txt", ios::in);
    while(file0.eof()==0)
    {
        getline(file0, st);
        getline(file0, st2);

        if((st.find(name, 0)!=string::npos)&&(st2.find(mobile, 0)!=string::npos))
        {
            ans = 1;
            break;
        }
    }
    file0.close();
    return ans;
}

void Person::edit_contact()
{
    cout<<"Edit_contact opened"<<endl;
    exit(0);
}

void Person::add_contacts()
{
    int chk = chk_contact();
    if(chk<0)
    {
        fstream file1;
        file1.open("ContactBook.txt", ios::app | ios::out);
        file1<<"Name: "<<name<<endl;
        file1<<"Mobile: "<<mobile<<endl;
        file1<<"Address: "<<address<<endl;
        file1<<endl;
        cout<<"Contact Details added successfully!!"<<endl;
        file1.close();
    }
    else
    {
        char yes_no;
        cout<<"A contact with this name and mobile no. already exists in your Contact Book."<<endl;
        cout<<"Do you want to edit the entered contact details in your Contact Book?(Y/N)";
        cin>>yes_no;
        if(yes_no == 'Y' || yes_no == 'y')
            edit_contact();
    }
    usleep(1000000);
    system("CLS");
}

void get_input()
{
    string name, mobile, address;
    cout<<"\nEnter Name: ";
    getline(cin, name);
    while(true)
    {
        cout<<"Enter Mobile no.(along with country code): ";
        getline(cin, mobile);
        const regex pattern("^[+]{1}[0-9]+");

        if(regex_match(mobile, pattern))
            break;
        else
            cout<<"Please enter valid mobile number."<<endl;
    }
    cout<<"Enter Address: ";
    getline(cin, address);
    Person p1(name, mobile, address);
    p1.add_contacts();
}

int main()
{
    fstream file;
    file.open("ContactBook.txt", ios::app);
    file.close();
    while (true){
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
            }
            default:{
                cout<<"Please enter valid S.No.!!"<<endl;
                usleep(1000000);
            }
        }
        system("CLS");
    }
    return 0;
}
