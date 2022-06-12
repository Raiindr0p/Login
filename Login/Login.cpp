// Login.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void staffLogin()
{
    string staffID, pw;
    cout << "Enter Staff ID: ";
    cin >> staffID;

    cout << "Enter password: ";
    cin >> pw;
}

bool userLogin()
{
    string userID, password, id, pw;

    cout << "Enter User ID: ";
    cin >> userID;

    cout << "Enter password: ";
    cin >> password;

    ifstream read("D:/repos/Login/myLogin.txt"); 

    getline(read, id);
    getline(read, pw);
    
    if (id == userID && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int choice;

    cout << "1:Register\n2:Student Login\n3:Staff Login\nYour choice: ";
    cin >> choice;
    if (choice == 1)
    {
        string userID, password, staffID, pw;
        int n;
        cout << "1:Staff\n2:Student:"<<endl;
        cin >> n;
        if (n == 1)
        {
            cout << "Select staff ID: ";
            cin >> staffID;
            cout << "Select a password: ";
            cin >> pw;
            ofstream file;

            file.open("D:/repos/Login/myLogin.txt", ios::out);
            string myData = staffID;
            string myData1 = pw;

            file << myData << myData1 << endl;
            file.close();
            main();
        }
        else if (n == 2)
        {
            cout << "Select ID: ";
            cin >> userID;
            cout << "Select a password: ";
            cin >> password;


            ofstream file;

            file.open("D:/repos/Login/myLogin.txt", ios::out);
            string myData = userID;
            string myData1 = password;

            file << myData << myData1 << endl;
            file.close();
            main();
        }
           
        
    }
    else if (choice == 2)
    {
        bool status = userLogin();

        if (status)
        {
            cout << "Invalid userID & password" << endl;
            system("pause");
            return 0;
        }
        else
        {
            cout << "Successfully Loggin in " << endl;
            system("Pause");
            return 1;
        }
    }
    else if (choice == 3)
    {
        staffLogin();
    }

}

