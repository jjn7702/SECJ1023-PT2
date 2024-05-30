#ifndef ORGANISER_H
#define ORGANISER_H
#include "Time.h"
#include <string>

class Organiser{
    protected:
        Time *start;
        std :: string eventName;
        std :: string eventDesc;
        bool eventStatus;

    public:
        Organiser();
        Organiser(Time *, std::string, std::string, bool);
        void setEventStatus(int);
        int getStatus();
        
        friend ostream& operator<<(ostream&, const Organiser&);
};


#endif