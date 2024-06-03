#ifndef EVENT_H
#define EVENT_H
#include "Organiser.h"
#include <iostream>
using namespace std;

class Event: public virtual Organiser{
    protected:
        Time *end;
    
    public:
        Event();
        Event(Time*, Time*, string, string, bool);
        ~Event();

        void setEndTime(Time *);

        friend ostream& operator<<(ostream&, const Event&);
};

#endif