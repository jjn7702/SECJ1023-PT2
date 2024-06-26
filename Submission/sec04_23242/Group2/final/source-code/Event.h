#ifndef EVENT_H
#define EVENT_H
#include "Organiser.h"
#include <iostream>
using namespace std;

class Event: public virtual Organiser{
    protected:
        Time end;
    
    public:
        Event();
        Event(Organiser);
        Event(Time, Time, string, string, bool);

        void setEndTime(Time );
        Time getEndTime() const;
        void readInput();

        friend ostream& operator<<(ostream&, const Event&);
};

#endif