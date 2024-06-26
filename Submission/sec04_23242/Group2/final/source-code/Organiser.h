#ifndef ORGANISER_H
#define ORGANISER_H
#include "Time.h"
#include <iostream>
#include <string>
using namespace std;

class Organiser{
    protected:
        Time start;
        std :: string eventName;
        std :: string eventDesc;
        bool eventStatus;
        int eventType;//0 = organiser, 1 = reminder, 2 = event
    public:
        Organiser();
        Organiser(Time , std::string, std::string, bool);

        //mutators
        void setEventStatus(int);
        void setEventName( string);
        void setEventDesc (string);
        void setEventDate(Date);
        void setStartTime(Time );
        virtual void setEndTime(Time );
        void eventDone();
    
        //accessors
        int getStatus() const;
        int getEventType()const;
        int getDay() const;
        string getEventName() const;
        string getEventDesc() const;
        virtual Time getEndTime() const;
        Date getDate() const;
        Time getTime()const;
        void readInput();

        friend ostream& operator<<(ostream&, const Organiser&);
        bool operator<(const Organiser&);
};


#endif