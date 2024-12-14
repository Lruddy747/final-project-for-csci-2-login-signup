#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

#include "signup.h"
#include "login.h"

using namespace std;

int main(){

    vector <employee*> loginList;

    int decision;
    int *p = &decision; /// this was a failsafe for when earlier I had it stuck in an infinite loop

    do{

    cout << "Hello, are you logging in or signing up"<<endl<<"(1 = logging in, 0 = signing up, 3 = exit program)"<<endl;
    cin >> *p;
    cout<<endl<<endl;

    switch(decision){
            case 1:
                login(*p);
                break;
            case 0:
                signup(loginList, *p);
                break;
            case 3:
                exit(0);
            default:
                cout << "please input 1 or 0"<<endl<<endl;
        }

    }while(decision != 1 || decision != 0 || decision != 3); /// have it like this so that when you are done, you can go back to this screen

    return 0;

}
