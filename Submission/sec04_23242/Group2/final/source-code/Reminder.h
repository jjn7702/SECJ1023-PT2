#ifndef REMINDER_H
#define REMINDER_H
#include "Organiser.h"

class Reminder: public Organiser{
    public:
        Reminder();
        Reminder(Time *, std::string, std::string, bool);

        void notify();
        friend ostream& operator<<(ostream&, const Reminder&);
};

#endif