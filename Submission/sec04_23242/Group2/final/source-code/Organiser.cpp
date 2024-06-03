#include "Organiser.h"
#include "Time.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Organiser :: Organiser(){
    start = new Time();
    eventName = "";
    eventDesc = "";
    eventStatus = NULL;

}

Organiser :: Organiser(Time *s , string name, string desc, bool status = NULL){
    start = s;
    eventName = name;
    eventDesc = desc;
    eventStatus = status;
}

Organiser :: ~Organiser()
{
    delete start;
}

//mutators
void Organiser :: setEventStatus(int s){eventStatus = s;}
void Organiser :: setEventName(string n) { eventName = n;}
void Organiser :: setEventDesc(string d) { eventDesc = d;}
void Organiser :: setStartTime( Time *s) { start = s;}

//accessors
int Organiser :: getStatus() const {return eventStatus;}
string Organiser :: getEventName() const { return eventName;}
string Organiser :: getEventDesc() const {return eventDesc;}

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