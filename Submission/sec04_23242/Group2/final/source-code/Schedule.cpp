#include "Schedule.h"
#include <iostream>
#include <iomanip>
using namespace std;

Schedule :: Schedule(bool s = true): status(s){}
Schedule :: ~Schedule() {}

void Schedule :: setStatus(bool s){status = s;}

void Schedule :: printStatus(){
    cout << "Status: ";
    if(status)
        cout << "Occupied\n";
    else    
        cout << "Free\n";
}
