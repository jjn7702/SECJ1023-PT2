#ifndef TIME_H
#define TIME_H
#include <string>
#include "Date.h"

class Time : public Date{
    protected:
        int hour, minute;

    public:
    Time();
    Time(bool, int, int ,int, int, int);

    void dateExtract(std::string);
    void readInput();
    void printTime();
    void print();
    void diffPrint();
    Time getCurrentTime();

    Time operator-(const Time&);
};

#endif
