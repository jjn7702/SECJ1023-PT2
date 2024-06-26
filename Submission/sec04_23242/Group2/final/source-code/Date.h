#ifndef DATE_H
#define DATE_H
#include "Schedule.h"
#include <iostream>
using namespace std;

class Date: public Schedule{
    protected:
        int year, month, day;

    public:
        Date();
        Date(bool, int, int, int);

        //mutators
        void setYear(int);
        void setMonth(int);
        void setDay(int);

        //accessors
        int getYear() const;
        int getMonth() const;
        int getDay() const;

        virtual void readInput();
        void printDate();

        friend ostream& operator<<(ostream&, Date);
};

#endif
