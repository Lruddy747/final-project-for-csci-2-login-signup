#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

#include "employee.h"
#include "signup.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;  /// this entire section is one big mess. I'm gonna be completely honest, some parts I forget how they even function all together since it's like detangling spaghetti

class managerLoginTransfer{   /// created new class so that I can store the file into it

public:
    string getMPassword()const{
        return password;
    }
    int getMId()const{
        return managerID;
    }
    string getMName()const{
        return name;
    }
managerLoginTransfer(string n, int i, int s, string p, string pass, int mi){
    name = n;
    idm = i;
    salary = s;
    position = p;
    managerID = mi;
    password = pass;
}

private:
    int managerID;
    int idm;
    string name;
    string position;
    int salary;
    string password;
};

class employeeLoginTransfer{ /// created a new class so that I can store the file into it

public:
employeeLoginTransfer(string n, int i, int s, string p, string pass){
    name = n;
    ide = i;
    salary = s;
    position = p;
    password = pass;
}

string getPassword()const{
    return password;
}
int getId()const{
    return ide;
}
string getName()const{
    return name;
}
int getSalary()const{
    return salary;
}
string getPosition()const{
    return position;
}

private:
    int ide;
    string name;
    string position;
    int salary;
    string password;
};

vector<managerLoginTransfer> loginTransferM;  /// new vectors for password validation
vector<employeeLoginTransfer> loginTransferE;
/// /////////////////////////////////////////////////////////////////////////////////////////////////
void loadManagerFile(ifstream& infileManager){  /// loads the login info for the manager txt file

    string lineM;
    while(getline(infileManager, lineM)){

        string name;
        string position;
        int salary;
        int id;
        string password;
        int managerIDTransfer;
        string* breakL = new string;

        name = lineM;

        if (!getline(infileManager, lineM)) break;
        id = stoi(lineM);

        if (!getline(infileManager, lineM)) break;
        salary = stoi(lineM);

        if (!getline(infileManager, lineM)) break;
        position = lineM;

        if (!getline(infileManager, lineM)) break;
        password = lineM;

        if (!getline(infileManager, lineM)) break;
        managerIDTransfer = stoi(lineM);

        if (!getline(infileManager, lineM)) break;
        *breakL = lineM;
        delete breakL;

        loginTransferM.push_back(managerLoginTransfer(name, id, salary, position, password, managerIDTransfer));

    }

}

void loadEmployeeFile(ifstream& infileEmployee){ /// same thing for this but employee file instead

    string line;
    while(getline(infileEmployee, line)){

        string name;
        string position;
        int salary;
        int id;
        string password;
        string* breakL = new string;

        name = line;

        if (!getline(infileEmployee, line)) break;
        id = stoi(line);

        if (!getline(infileEmployee, line)) break;
        salary = stoi(line);

        if (!getline(infileEmployee, line)) break;
        position = line;

        if (!getline(infileEmployee, line)) break;
        password = line;

        if (!getline(infileEmployee, line)) break;
        *breakL = line;
        delete breakL;

        loginTransferE.push_back(employeeLoginTransfer(name, id, salary, position, password));

    }
}
/// ///////////////////////////////////////////////////////////////////////////////////
void employeeLoginScreen(const vector<employeeLoginTransfer>& v, int& tp){ /// this is the login screen for employee. enter password and id and it tells you some stuff

    string passwordInput;
    int idInput;
    bool passwordValidation = true;

    do{
    cout << "enter your id: ";
    cin >> idInput;
    cout << "enter your password: ";
    cin >> passwordInput;

    for(auto &info : v){ /// this took a while to figure out
        if (info.getPassword() == passwordInput && info.getId() == idInput){
            cout<<endl << "welcome " + info.getName()<<endl;
            cout << "Your position is: " + info.getPosition()<<endl;
            cout << "Get to work"<<endl<<endl;
            tp = 3;
            return;
        }
        else if(info.getPassword() != passwordInput && info.getId() != idInput){
            cout <<endl<< "your password didn't match your id, try again"<<endl;
            passwordValidation = false;
        }
        }
    }while(passwordValidation == false);

}
/// /////////////////////////////////////////////////////////////////////////////////////////
void managerLoginScreen(const vector<managerLoginTransfer>& v, const vector<employeeLoginTransfer>& e){ /// samething with employee screen but I also include the vector for employe login info so that the manager can see the employees name and id

    string passwordInput;
    int idInput;
    bool passwordValidation = true;

    do{
    cout << "enter your manager id: ";
    cin >> idInput;
    cout << "enter your password: ";
    cin >> passwordInput;

    for(auto &info : v){
        if (info.getMPassword() == passwordInput && info.getMId() == idInput){
            cout<<endl << "welcome " + info.getMName()<<endl;
            passwordValidation = true;
            break;

        }
        else if(info.getMPassword() != passwordInput && info.getMId() != idInput){
            cout <<endl<< "your password didn't match your id, try again"<<endl;
            passwordValidation = false;
    }
    }
    }while(passwordValidation == false);
    if(passwordValidation != false){
    cout << "Here are all of your workers currently employed:"<<endl;
    for(auto &eInfo : e){
        cout << eInfo.getName() << " : " << eInfo.getId()<<endl;
            }
    }
    return;

}
/// /////////////////////////////////////////////////////////////////////////
void login(int& tp){

    ifstream infileEmployee("loginInfoE.txt");
    ifstream infileManager("loginInfoM.txt");

    loadEmployeeFile(infileEmployee);/// this loads the employee file into the employee class
    loadManagerFile(infileManager);/// this loads manager file into manager class (I have it like this so that a manager can log in as an employee)

    char decision;

    do{

        cout<<"Are you logging in as an employee or a manager"<<endl<< "e = employee, m = manager"<<endl;
        cin >> decision;

        switch(decision){
            case 'e':
                employeeLoginScreen(loginTransferE, tp);
                break;
            case 'm':
                managerLoginScreen(loginTransferM, loginTransferE);
                break;
            default:
                cout << "please type out 'employee' or 'manager'"<<endl<<endl;
        }

    }while(decision != 'e' && decision != 'm');

}

#endif // LOGIN_H_INCLUDED
