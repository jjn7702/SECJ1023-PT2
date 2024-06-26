#include "Organiser.h"
#include "Time.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Organiser :: Organiser(){
    eventName = "";
    eventDesc = "";
    eventStatus = NULL;
    eventType = 0;

}

Organiser :: Organiser(Time s , string name, string desc, bool status = false){
    start = s;
    eventName = name;
    eventDesc = desc;
    eventStatus = status;
    eventType = 0;
}

//mutators
void Organiser :: setEventStatus(int s){eventStatus = s;}
void Organiser :: setEventName(string n) { eventName = n;}
void Organiser :: setEventDesc(string d) { eventDesc = d;}
void Organiser :: setEventDate(Date d){
    start.setYear(d.getYear());
    start.setMonth(d.getMonth());
    start.setDay(d.getDay());
}
void Organiser :: setStartTime(Time s) { start = s;}
void Organiser :: setEndTime(Time e){1+1;}
void Organiser :: eventDone(){eventStatus = true;}

//accessors
int Organiser :: getStatus() const {return eventStatus;}
int Organiser :: getEventType()const{return eventType;}
int Organiser :: getDay() const { return start.getDay();}

string Organiser :: getEventName() const { return eventName;}
string Organiser :: getEventDesc() const {return eventDesc;}
Time Organiser :: getEndTime() const {return Time();}
Date Organiser :: getDate()const{
    Date temp(false, start.getYear(), start.getMonth(), start.getDay());
    return temp;
}

Time Organiser :: getTime()const{
    return start;
}

void Organiser :: readInput(){
    cout << "Input Name: ";
    getline(cin, eventName);

    cout << "Enter Starting Time:\n";
    start.readInput();

    cout << "Enter Description:";
    getline(cin, eventDesc);

    eventStatus = true;
}

ostream& operator<<(ostream &out, const Organiser &o){
    out << left << setw(20) << "Event Name" << ":" << o.eventName << endl 
        << left << setw(20) << "Event Status" << ":";
    if(o.eventStatus)
        out << "Done";
    else
        out << "Not Done";
    out << endl;
    out << left << setw(20) << "Description" << ":" << o.eventDesc << endl;
    return out;
}

bool Organiser :: operator<(const Organiser &o){
    if((start.getYear() - o.start.getYear()) < 0)
        return true;

    if((start.getMonth() - o.start.getMonth()) < 0)
        return true;

    if((start.getDay() - o.start.getDay()) < 0)
        return true;
    
    if((start.getHour() - o.start.getHour()) < 0)
        return true;

    if((start.getMinute() - o.start.getMinute()) < 0)
        return true;

    return false;
}