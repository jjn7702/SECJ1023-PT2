#ifndef TIME_H
#define TIME_H
#include <string>
#include <time.h>
#include "Date.h"

class Time : public Date{
    protected:
        int hour, minute;

    public:
    Time();
    Time(bool, int, int ,int, int, int);
    ~Time();

    //mutators
    void setHour(int);
    void setMinute(int);

    //accessors
    int getHour() const;
    int getMinute() const;

    void dateExtract(std::string);
    void readInput();
    void printTime();
    void print();
    void diffPrint();
    void getCurrentTime();

    Time operator-(const Time&);
};

#endif
