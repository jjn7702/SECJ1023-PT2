#ifndef DATE_H
#define DATE_H
#include "Schedule.h"

class Date: public Schedule{
    protected:
        int year, month, day;

    public:
        Date();
        Date(bool, int, int, int);
        ~Date();

        //mutators
        void setYear(int);
        void setMonth(int);
        void setDay(int);

        //accessors
        int getYear() const;
        int getMonth() const;
        int getDay() const;

        void printDate();
};

#endif
