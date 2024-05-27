#include "Schedule.h"
#include <iostream>
#include <iomanip>
using namespace std;

Schedule :: Schedule(bool s = true):status(s){}

void Schedule :: setStatus(bool s){status = s;}

void Schedule :: printStatus(){
    cout << "status: " << status << endl;
}