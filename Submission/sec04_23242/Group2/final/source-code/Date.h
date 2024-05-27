#ifndef DATE_H
#define DATE_H
#include "Schedule.h"

class Date: public Schedule{
    protected:
        int year, month, day;

    public:
        Date(bool, int, int, int);
        void printDate();
};

#endif