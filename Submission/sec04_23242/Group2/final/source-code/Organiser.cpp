#include "Organiser.h"
#include "Time.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Organiser :: Organiser(){
    start = new Time;
    eventName = "";
    eventDesc = "";
    eventStatus = false;

}

Organiser :: Organiser(Time *s , string name, string desc, bool status = false){
    start = s;
    eventName = name;
    eventDesc = desc;
    eventStatus = status;
}

void Organiser :: setEventStatus(int s){eventStatus = s;}

int Organiser :: getStatus(){return eventStatus;}

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