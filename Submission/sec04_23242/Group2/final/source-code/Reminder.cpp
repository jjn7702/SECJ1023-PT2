#include "Reminder.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
using namespace std;

Reminder :: Reminder() : Organiser(){}

Reminder :: Reminder(Time *s , string name, string desc, bool status): Organiser(s, name, desc, status){}

void Reminder :: notify(){
    Time current;
    Time diff;
    current.getCurrentTime();

    diff = *start - current;
    cout << eventName << " is starting in: " << endl;
    diff.diffPrint();
}

ostream& operator<<(ostream &strm, const Reminder &r){
    strm << r;
    strm << left << setw(20) << "Event Type" << ":" << "Reminder" << endl;
    strm << left << setw(20) << "Starting Time" << ":";
    r.start->print();
    
    return strm;
}