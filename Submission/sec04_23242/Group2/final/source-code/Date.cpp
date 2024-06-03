#include "Date.h"
#include <iostream>
#include <iomanip>
using namespace std;

Date :: Date(): Schedule(NULL), year(0), month(0), day(0) {}
Date :: Date(bool s = false, int y = 0, int m = 0, int d = 0): year(y), month(m), day(d), Schedule(s){}
Date :: ~Date() {}

void Date :: setDay(int d) { day = d;}
void Date :: setMonth(int m) { month = m;}
void Date :: setYear(int y) { year = y;}

int Date :: getDay() const { return day;}
int Date :: getMonth() const { return month;}
int Date :: getYear() const { return year;}

void Date :: printDate(){
    cout << "Date: ";
        if (day < 10)
            cout << "0";

        cout << day << "/";

        if (month < 10)
            cout << "0";       

        cout << month << "/" << year << endl;
}
