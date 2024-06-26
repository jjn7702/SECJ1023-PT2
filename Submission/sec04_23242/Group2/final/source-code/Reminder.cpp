#include "Reminder.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
using namespace std;

Reminder :: Reminder() : Organiser(){
    eventType = 1;
}

Reminder :: Reminder(const Organiser &o){
    eventName = o.getEventName();
    eventDesc = o.getEventDesc();
    eventType = 1;
    start = o.getTime();
    eventStatus = o.getStatus();
}

Reminder :: Reminder(Time s , string n, string d, bool st = NULL): Organiser(s, n, d, st){
    eventType = 1;
}

void Reminder :: notify(){
    Time current;
    Time diff;
    Time temp = start;
    current.getCurrentTime();

    diff = temp - current;
    cout << eventName << " is starting in: " << endl;
    diff.diffPrint();
}

void Reminder :: readInput(){
    cout << "Input Reminder Name: ";
    getline(cin, eventName);

    cout << "Enter Starting Time of Reminder:\n";
    start.readInput();

    cout << "Enter Reminder Description:";
    getline(cin, eventDesc);

    eventStatus = true;
}

ostream& operator<<(ostream &strm, const Reminder &r){
    Organiser o = r;
    Time startTime = r.start;
    strm << o;
    strm << left << setw(20) << "Event Type" << ":" << "Reminder" << endl;
    strm << left << setw(20) << "Starting Time" << ":\n";
    startTime.print();
    
    return strm;
}