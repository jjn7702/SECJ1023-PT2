#include <iostream>
#include <string>
#include "Time.h"
using namespace std;

Time :: Time(bool s = true, int y = 0, int m = 0, int d = 0, int h = 0, int min = 0): hour(h), minute(m), Date(s, y, m, d) {}

void Time :: dateExtract(string d){
    string monthArr[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        string tempMonth;
        int tempDay, tempHour, tempMinute, tempYear, tempMonthInt;
        tempMonth = d.substr(4, 3);
        for (int i = 0; i < 12; i++)
        {
            if (tempMonth == monthArr[i])
            {
                month = i + 1;
                break;
            }
        }
        day = stoi(d.substr(8, ' '));
        hour = stoi(d.substr(11, ':'));
        minute = stoi(d.substr(14, ':'));
        year = stoi(d.substr(19, '\n'));
}

void Time :: readInput(){
    cout << "Enter date(DD MM YYYY): ";
        cin >> day >> month >> year;
        cout << "Enter time(HH MM): ";
        cin >> hour >> minute;
}

void Time :: print(){
    Date::printDate();
    printTime();
    Date::printStatus();
}

void Time :: diffPrint(){
    cout << "Difference: ";
        if (year)
            cout << year << " year(s) ";

        if (month)
            cout << month << " month(s) ";

        if (day)
            cout << day << " day(s) ";

        if (hour)
            cout << hour << " hour(s) ";

        if (minute)
            cout << minute << " minute(s) ";

        cout << endl;
}

Time Time :: operator-(const Time &t){
    Time temp;
        int dayCalc[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        temp.year = year - t.year;
        temp.month = month - t.month;
        temp.day = day - t.day;
        temp.hour = hour - t.hour;
        temp.minute = minute - t.minute;

        if (minute < t.minute)
        {
            temp.minute += 60;
            temp.hour--;
        }

        if (hour < t.hour)
        {
            temp.hour += 24;
            temp.day--;
        }

        if (day < t.day)
        {
            int dayCalcMonth = month - 2;
            if (dayCalcMonth < 0)
                dayCalcMonth += 12;
            
            temp.day += dayCalc[dayCalcMonth];
            temp.month--;
        }
        if (month < t.month)
        {
            temp.month += 12;
            temp.year--;
        }
        return temp;
}