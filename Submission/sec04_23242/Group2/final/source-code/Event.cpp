#include "Event.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
using namespace std;

Event :: Event(): Organiser(){
    end = new Time();
}

Event :: Event(Time *s, Time *e, string n, string d, bool st = NULL): Organiser(s, n, d, st){
    end = e;
}

Event :: ~Event()
{
    delete end;
}

//mutators
void Event :: setEndTime(Time *e) { end = e;}

ostream& operator<<(ostream &strm, const Event& e){
    Organiser temp = e;
    strm << temp;
    strm << left << setw(20) << "Event Type" << ":" << "Event" << endl;
    strm << left << setw(20) << "Starting Time" << ":";
    e.start->print();
    strm << left << setw(20) << "Ending Time:" << ":";
    e.end->print();
    
    return strm;
}