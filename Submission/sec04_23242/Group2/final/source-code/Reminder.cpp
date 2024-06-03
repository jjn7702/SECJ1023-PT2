#include "Reminder.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
using namespace std;

Reminder :: Reminder() : Organiser(){}

Reminder :: Reminder(Time *s , string n, string d, bool st = NULL): Organiser(s, n, d, st){}

Reminder :: ~Reminder() {}
void Reminder :: notify(){
    Time current;
    Time diff;
    Time temp = *start;
    current.getCurrentTime();

    diff = temp - current;
    cout << eventName << " is starting in: " << endl;
    diff.diffPrint();
}

ostream& operator<<(ostream &strm, const Reminder &r){
    Organiser o = r;
    strm << o;
    strm << left << setw(20) << "Event Type" << ":" << "Reminder" << endl;
    strm << left << setw(20) << "Starting Time" << ":\n";
    r.start->print();
    
    return strm;
}