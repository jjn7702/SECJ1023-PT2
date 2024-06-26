#ifndef TIME_H
#define TIME_H
#include <string>
#include <time.h>
#include <iostream>
#include "Date.h"
using namespace std;


class Time : public Date{
    protected:
        int hour, minute;

    public:
    Time();
    Time(bool, int, int ,int, int, int);

    //mutators
    void setHour(int);
    void setMinute(int);

    //accessors
    int getHour() const;
    int getMinute() const;

    void dateExtract(std::string);
    void readInputTime();
    void readInput();
    void printTime();
    void print();
    void diffPrint();
    void getCurrentTime();
    friend ostream& operator<< (ostream&, Time);
    friend bool timeCompareForEvent(Time &, Time &);
    friend bool timeCompareOneHour(Time &, Time &);


    Time operator-(const Time&);
    bool operator<(const Time&);
};

#endif
