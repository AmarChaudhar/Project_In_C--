#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int choice;
    string name, password0, age, user, mobile, pass, old, password1, password2;

    cout << "Security System " << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Change Password" << endl;
    cout << "4. End Program" << endl << endl;

    do
    {
        cout << endl << endl;
        cout << "Enter Your Choice:- ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "----------Register----------" << endl;
            cout << "Please Enter Username:- ";
            cin >> name;
            cout << "Please Enter the Password:- ";
            cin >> password0;
            cout << "Please Enter Your age:- ";
            cin >> age;
            cout << "Please Enter The Mobile Number:- ";
            cin >> mobile;
            ofstream of1("file.txt", ios::app); // Open file in append mode
            if (of1.is_open())
            {
                of1 << name << "\n";
                of1 << password0 << "\n";
                of1 << age << "\n";
                of1 << mobile << "\n";
                of1.close();
                cout << "Registration Successful" << endl;
            }
            else
            {
                cout << "Error: Unable to open the file." << endl;
            }
            break;
        }
        case 2:
        {
            cout << "|----------Login----------|" << endl;
            ifstream of2("file.txt");
            cout << "Please Enter Username:- ";
            cin >> user;
            cout << "Please Enter the Password:- ";
            cin >> pass;

            bool loginSuccessful = false;

            if (of2.is_open())
            {
                string storedUser, storedPass, storedAge, storedMobile;

                while (of2 >> storedUser >> storedPass >> storedAge >> storedMobile)
                {
                    if (user == storedUser && pass == storedPass)
                    {
                        loginSuccessful = true;
                        cout << "--Login Successful--" << endl;
                        cout << "Profil: " << endl;
                        cout << "Username: " << storedUser << endl;
                        cout << "Password: " << storedPass << endl;
                        cout << "Age: " << storedAge << endl;
                        cout << "Phone Number: " << storedMobile << endl;
                        break;
                    }
                }

                if (!loginSuccessful)
                {
                    cout << "Incorrect Credentials" << endl;
                }

                of2.close();
            }
            else
            {
                cout << "Error: Unable to open the file." << endl;
            }
            break;
        }
        case 3:
        {
            cout << "-----------Change Password------------" << endl;
            ifstream of0("file.txt");
            cout << "Enter the old Password:- ";
            cin >> old;
            bool passwordChanged = false;

            if (of0.is_open())
            {
                ofstream of1("temp.txt");

                string storedUser, storedPass, storedAge, storedMobile;

                while (of0 >> storedUser >> storedPass >> storedAge >> storedMobile)
                {
                    if (user == storedUser && old == storedPass)
                    {
                        cout << "Enter Your new Password:- ";
                        cin >> password1;
                        cout << "Enter Your Password again:- ";
                        cin >> password2;

                        if (password1 == password2)
                        {
                            of1 << storedUser << "\n";
                            of1 << password1 << "\n";
                            of1 << storedAge << "\n";
                            of1 << storedMobile << "\n";
                            passwordChanged = true;
                            cout << "Password Changed Successfully" << endl;
                        }
                        else
                        {
                            cout << "Password do not match" << endl;
                            of1 << storedUser << "\n";
                            of1 << storedPass << "\n";
                            of1 << storedAge << "\n";
                            of1 << storedMobile << "\n";
                        }
                    }
                    else
                    {
                        of1 << storedUser << "\n";
                        of1 << storedPass << "\n";
                        of1 << storedAge << "\n";
                        of1 << storedMobile << "\n";
                    }
                }

                of0.close();
                of1.close();

                if (passwordChanged)
                {
                    remove("file.txt");
                    rename("temp.txt", "file.txt");
                }
                else
                {
                    remove("temp.txt");
                }
            }
            else
            {
                cout << "Error: Unable to open the file." << endl;
            }
            break;
        }
        case 4:
            cout << "Thank you!" << endl;
            break;
        default:
            cout << "Enter a valid Choice" << endl;
        }
    } while (choice != 4);

    return 0;
}
