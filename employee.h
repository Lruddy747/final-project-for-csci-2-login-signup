#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

/// this is just the background class for employees and managers

class employee{
public:
    virtual void setEmployeePosition(string p) = 0;

    virtual void loginInfoToFile(ofstream &outfile) = 0;

    void setName(string n){
        name = n;
    }

    void setSalary(int s){
        salary = s;
    }

    void setEmployeeID(int id){
        employeeID = id;
    }
    void setPassword(string pass){
        password = pass;
    }

    employee(string n, int id, int s, string pass){
        setName(n);
        setSalary(s);
        setEmployeeID(id);
        setPassword(pass);
    }
    friend class rankAndFile;
    friend class management;


private:
    string name;
    int employeeID;
    int salary;
    string password;

};

class rankAndFile : public employee{
public:

    void setEmployeePosition(string p){
        employeePosition = p;
    }
    void loginInfoToFile(ofstream &outfileEmployee){ /// this is what writes the employee info into the file
        outfileEmployee << name <<endl;
        outfileEmployee << employeeID <<endl;
        outfileEmployee << salary <<endl;
        outfileEmployee << employeePosition <<endl;
        outfileEmployee << password<<endl;
        outfileEmployee << "///"<<endl;

    }

    rankAndFile(string n, int id, int s, string p, string pass)
            :employee(n, id, s, pass){

            setEmployeePosition(p);
    }

private:
    string employeePosition;

};

class management : public employee{
public:

    void setEmployeePosition(string p){
        employeePosition = p;
    }

    void setManagerID(int mid){
        managerID = mid;
    }

    void loginInfoToFile(ofstream &outfileManager){ /// this is what writes the manager info into the file
        outfileManager << name <<endl;
        outfileManager << employeeID <<endl;
        outfileManager << salary <<endl;
        outfileManager << employeePosition <<endl;
        outfileManager << password <<endl;
        outfileManager << managerID<<endl;
        outfileManager << "///"<<endl;

    }


    management(string n, int id, int s, string p, string pass, int mid)
            :employee(n, id, s, pass){

            setEmployeePosition(p);
            setManagerID(mid);
    }

private:
    string employeePosition;
    int managerID;

};

ofstream outfileEmployee("loginInfoE.txt", std::ios::app);
ofstream outfileManager("loginInfoM.txt", std::ios::app);

#endif // EMPLOYEE_H_INCLUDED
