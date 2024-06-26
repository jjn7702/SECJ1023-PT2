#ifndef REMINDER_H
#define REMINDER_H
#include "Organiser.h"

class Reminder: public virtual Organiser{
    public:
        Reminder();
        Reminder(const Organiser &);
        Reminder(Time , std::string, std::string, bool);

        void notify();
        void readInput();
        friend ostream& operator<<(ostream&, const Reminder&);
};

#endif