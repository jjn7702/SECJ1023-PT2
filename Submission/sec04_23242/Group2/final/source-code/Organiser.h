#ifndef ORGANISER_H
#define ORGANISER_H
#include "Time.h"
#include <iostream>
#include <string>
using namespace std;

class Organiser{
    protected:
        Time *start;
        std :: string eventName;
        std :: string eventDesc;
        bool eventStatus;

    public:
        Organiser();
        Organiser(Time *, std::string, std::string, bool);
        ~Organiser();

        //mutators
        void setEventStatus(int);
        void setEventName( string);
        void setEventDesc (string);
        void setStartTime(Time *);

        //accessors
        int getStatus() const;
        string getEventName() const;
        string getEventDesc() const;

        friend ostream& operator<<(ostream&, const Organiser&);
};


#endif