#include "Date.h"
#include <iostream>
#include <iomanip>
using namespace std;

Date :: Date(): Schedule(true), year(0), month(0), day(0) {}
Date :: Date(bool s = true, int y = 0, int m = 0, int d = 0): year(y), month(m), day(d), Schedule(s){}

void Date :: setDay(int d) { day = d;}
void Date :: setMonth(int m) { month = m;}
void Date :: setYear(int y) { year = y;}

int Date :: getDay() const { return day;}
int Date :: getMonth() const { return month;}
int Date :: getYear() const { return year;}

void Date :: readInput(){
    cout << "Enter date(DD MM YYYY): ";
    cin >> day >> month >> year;
}

void Date :: printDate(){
    cout << "Date: ";
        if (day < 10)
            cout << "0";

        cout << day << "/";

        if (month < 10)
            cout << "0";       

        cout << month << "/" << year << "\t";
}

ostream& operator<<(ostream& out, Date d){
    d.printDate();
    return out;
}
