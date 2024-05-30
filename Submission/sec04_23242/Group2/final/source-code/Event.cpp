#include "Event.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
using namespace std;

Event :: Event(): Organiser(){
    end = new Time();
}

Event :: Event(Time *s, Time *e, string name, string desc, bool status = false): Organiser(s, name, desc, status){
    end = e;
}

ostream& operator<<(ostream &strm, const Event& e){
    strm << e;
    strm << left << setw(20) << "Event Type" << ":" << "Event" << endl;
    strm << left << setw(20) << "Starting Time" << ":";
    e.start->print();
    strm << left << setw(20) << "Ending Time:" << ":";
    e.end->print();
    
    return strm;
}