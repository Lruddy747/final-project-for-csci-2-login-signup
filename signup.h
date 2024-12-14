#ifndef SIGNUP_H_INCLUDED
#define SIGNUP_H_INCLUDED

#include "employee.h"
#include "login.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

void managerSignup(vector<employee*>& v){ /// this stores the manager credentials you make into a file

    char loginDecision;

    int tp;

    int idSignup;
    string nameSignup;
    int salarySignup;
    string positionSignup;
    string passwordSignup;
    int midSignup;

    cout<<"Enter your name, 6 ID, salary, position, and password that was issued to you by your employer"<<endl;
    cout << "(just assume you've been given one)"<<endl<<endl;
    cout << "Name: ";
    cin.ignore(1,'\n');
    getline(cin, nameSignup);
    cout << "ID: ";
    while(true){
    cin >> idSignup;
    if(cin.fail()){
        cout<< "please input a number for your id: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else{
        break;
    }
    }

    cout << "Salary: ";
    while(true){
    cin >> salarySignup;
    if(cin.fail()){
        cout<< "please input a number for your salary: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else{
        break;
    }
    }

    cout << "Position: ";
    cin.ignore(1,'\n');
    getline(cin, positionSignup);
    cout << "Password: ";
    getline(cin, passwordSignup);
    cout << "Manager ID: ";
    while(true){
    cin >> midSignup;
    if(cin.fail()){
        cout<< "please input a number for your manager id: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else{
        break;
    }
    }

    v.push_back(new management(nameSignup, idSignup, salarySignup, positionSignup, passwordSignup, midSignup));

    if(outfileManager.is_open()){
        for (auto &info : v){                  /// this is the code for writing it into a file
            info->loginInfoToFile(outfileManager);
        }
    }

    v.clear();

    v.push_back(new rankAndFile(nameSignup, idSignup, salarySignup, positionSignup, passwordSignup));

    if(outfileEmployee.is_open()){      /// managers are also employees so they can also login as just normal employees
        for (auto &info : v){
            info->loginInfoToFile(outfileEmployee);
        }
    }

    v.clear();

    cout <<endl<<endl<<"Do you want to login now?(y/n)";   /// for whether you want to login or go back to homescreen
    cin >> loginDecision;

    switch(loginDecision){
        case 'y':
            login(tp);
            break;
        case 'n':
            return;
        default:
            cout << "enter either y or n";
    }

}
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Manager^

 void rankAndFileSignup(vector<employee*>& v){  ///   same thing manager write file but with just employees

    char loginDecision;

    int tp;

    int idSignup;
    string nameSignup;
    int salarySignup;
    string positionSignup;
    string passwordSignup;

    cout<<"Enter your name, 6 ID, salary, position, and password that was issued to you by your employer"<<endl;
    cout << "(just assume you've been given one)"<<endl<<endl;
    cout << "Name: ";
    cin.ignore(1,'\n');
    getline(cin, nameSignup);
    cout << "ID: ";
    while(true){
    cin >> idSignup;
    if(cin.fail()){
        cout<< "please input a number for your id: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else{
        break;
    }
    }

    cout << "Salary: ";
    while(true){
    cin >> salarySignup;
    if(cin.fail()){
        cout<< "please input a number for your salary: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else{
        break;
    }
    }

    cout << "Position: ";
    cin.ignore(1,'\n');
    getline(cin, positionSignup);
    cout << "Password: ";
    getline(cin, passwordSignup);

    v.push_back(new rankAndFile(nameSignup, idSignup, salarySignup, positionSignup, passwordSignup));

    if(outfileEmployee.is_open()){
        for (auto &info : v){
            info->loginInfoToFile(outfileEmployee);
        }
    }

    v.clear();

    cout <<endl<<endl<<"Do you want to login now?(y/n)";
    cin >> loginDecision;

    switch(loginDecision){
        case 'y':
            login(tp);
            break;
        case 'n':
            return;
        default:
            cout << "enter either y or n";
    }

}
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// RankAndFile^
void signup(vector<employee*>& v, int &tp){  ///  this give you the decision to sign up as employee or manager

    char signupDecision;

    cout<< "Are you signing up as an employee or manager(e/m): ";
    cin >> signupDecision;

    switch(signupDecision){
        case 'e':
            rankAndFileSignup(v);
            break;
        case 'm':
            managerSignup(v);
            break;
        default:
            cout << "enter either e or m";
            tp=3; ///      funny story, this was the failsafe location to stop the infinite loop of logging in. took me about an hour to figure out why
    }


}

#endif // SIGNUP_H_INCLUDED
