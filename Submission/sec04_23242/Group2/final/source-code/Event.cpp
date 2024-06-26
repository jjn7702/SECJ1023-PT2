#include "Event.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
using namespace std;

Event :: Event(): Organiser(){
    eventType = 2;
}

Event :: Event(Organiser o){
    eventName = o.getEventName();
    eventDesc = o.getEventDesc();
    eventType = 2;
    start = o.getTime();
    eventStatus = o.getStatus();
}

Event :: Event(Time s, Time e, string n, string d, bool st = NULL): Organiser(s, n, d, st){
    end = e;
    eventType = 2;
}

//mutators
void Event :: setEndTime(Time e) { end = e;}

Time Event :: getEndTime()const{
    return end;
}

void Event :: readInput(){
    cout << "Input Event Name: ";
    getline(cin, eventName);

    cout << "Enter Starting Time of Event:\n";
    start.readInput();

    cout << "Enter Ending Time of Event:\n";
    end.readInput();

    cout << "Enter Event Description:";
    getline(cin, eventDesc);

    eventStatus = true;
}

ostream& operator<<(ostream &strm, const Event& e){
    Organiser temp = e;
    Time startTime = e.start;
    Time endTime = e.end;
    strm << temp;
    strm << left << setw(20) << "Event Type" << ":" << "Event" << endl;
    strm << left << setw(20) << "Starting Time" << ":";
    startTime.print();
    strm << left << setw(20) << "Ending Time:" << ":";
    endTime.print();
    
    return strm;
}