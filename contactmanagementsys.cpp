#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <regex>
#include <sstream>
#include <unistd.h>
#include <cstring>
using namespace std;
void showContacts();  // displays all contacts from the file
void get_input();   // takes new contact from user
void searchContact();  // search contacts from file
class Person
{
    string name, mobile, address;
public:
    /* constructor to initialize data members*/
    Person(string Name, string Mobile, string Address)
    {
        name = Name;
        mobile = Mobile;
        address = Address;
    }
    bool chk_contact();  // checks already existing contact
    void edit_contact(); // edit contact details
    void add_contacts(); // adds new contact to file
};

bool Person::chk_contact()
{
    fstream file0;
    string st, st2;
    bool no_match = true;
    file0.open("ContactBook.txt", ios::in);
    while (file0.eof() == 0)
    {
        getline(file0, st);
        getline(file0, st2);

        if ((st.find(name, 0) != string::npos) || (st2.find(mobile, 0) != string::npos))
        {
            no_match = false;
            break;
        }
    }
    file0.close();
    return no_match;
}

void Person::add_contacts()
{
    bool no_match = chk_contact();
    if (no_match)
    {
        fstream file1;
        file1.open("ContactBook.txt", ios::app | ios::out);
        file1 << "Name: " << name << endl;
        file1 << "Mobile: " << mobile << endl;
        file1 << "Address: " << address << endl;
        file1 << endl;
        cout << "Contact Details added successfully!!" << endl;
        file1.close();
    }
    else
    {
        char yes_no;
        cout << "A contact with this name and mobile no. already exists in your Contact Book." << endl;
        cout << "Do you want to edit the entered contact details in your Contact Book?(Y/N)";
        cin >> yes_no;
        if (yes_no == 'Y' || yes_no == 'y')
            edit_contact();
    }
    cout<<endl<<"Enter any key to continue : ";
    getchar();
}
void Person::edit_contact()
{
    cout << "Edit_contact opened" << endl;
    // we can call get_input() for edit_contact() function
    exit(0);
}
void showContacts(){
    system("cls");
    cout<<setw(50)<<endl<<"Contact Details"<<endl<<endl;
    fstream file1;
    file1.open("ContactBook.txt", ios::in);
    string str=" ";
    while(file1.eof()==0)
    {
        getline(file1,str);
        cout<<str<<endl;
    }
    file1.close();
    cout<<"\nEnter any key to Continue : ";
    getchar();
}
void get_input()
{   system("cls");
    string name, mobile, address;
    cout<<setw(60)<<"Add Contacts"<<endl<<endl;
    cout << "\nEnter Name: ";
    getline(cin, name);
    while (true)
    {
        cout << "Enter Mobile no.(along with country code): ";
        getline(cin, mobile);
        const regex pattern("^[+]{1}[0-9]+");

        if (regex_match(mobile, pattern))
            break;
        else
            cout << "Please enter valid mobile number." << endl;
    }
    cout << "Enter Address: ";
    getline(cin, address);
    Person p1(name, mobile, address);
    p1.add_contacts();
}
void searchContact()
{
    system("cls");
    cout<<setw(60)<<"Search by Name || Number ||  Address"<<endl<<endl;
    int chk = 0;
    string search_str= " ";
    string name,number,address;
    cout<<"Enter Name/Number/Address you want to search : ";
    getline(cin,search_str);
    cout<<endl;
    fstream file1;
    file1.open("ContactBook.txt", ios::in);
    while (file1.eof()==0)
    {
        getline(file1,name);
        string name2 = name;
        getline(file1,number);
        getline(file1,address);
        string address2 = address;
        transform(search_str.begin(), search_str.end(), search_str.begin(), ::tolower); //Converting to lowercase string
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        transform(address.begin(), address.end(), address.begin(), ::tolower);
        if((name.find(search_str,0)!=string::npos) || (number.find(search_str,0)!=string::npos)|| (address.find(search_str,0)!=string::npos))
        {
            chk++;
            cout<<name2<<endl;
            cout<<number<<endl;
            cout<<address2<<endl;
            cout<<endl;
        }
        getline(file1,name2);
        address=" ";number=" ";name=" ";
    }
    file1.close();
    if (chk < 1)
        cout<<"No contacts were found having this contact detail."<<endl;
    cout<<endl<<"Enter any key to continue : ";
    getchar();
}

int main()
{
    system("cls");
    /* to create a new file*/
    fstream file;
    file.open("ContactBook.txt", ios::app);
    file.close();
    /* infinite while loop*/
    while (true)
    {
        string choice;
        int ch = 0;
        cout << setw(50) << "****" << endl;
        cout <<setw(50)<< "Menu" << endl;
        cout << setw(50) << "****" << endl;

        cout << "You can perform following operations:-\n1. Add a new Contact\n2. Show all Contacts\n3. Search a Contact\n4. Edit a Contact\n5. Delete a Contact\n6. Exit" << endl;
        cout << "\nEnter the S.No. of the operation you want to perform: ";
        getline(cin, choice);
        stringstream stream(choice);
        stream >> ch; // takes first integer from entered string choice
        switch (ch)
        {
        case 1:
        {
            get_input();
            break;
        }
        case 2:
        {
            showContacts();
            break;
        }
        case 3:
        {
            searchContact();
            break;
        }
        case 4:
        {
            //editContact();
            break;
        }
        case 5:
        {
            //delContact();
            break;
        }
        case 6:
        {
            cout << "\nThank you for using the program!";
            exit(0);
        }
        default:
        {
            cout << "Please enter valid S.No.!!" << endl;
            usleep(1000000);  // to take a pause
        }
        }
        system("cls");
    }
    return 0;
}
