#include <iostream>
#include <string>
#include <time.h>
#include "Time.h"
using namespace std;

Time :: Time(): hour(0), minute(0), Date(true,0,0,0) {}

Time :: Time(bool s, int y, int m, int d, int h, int min): hour(h), minute(min), Date(s, y, m, d) {}

//mutators
void Time :: setHour(int h) { hour = h;}
void Time :: setMinute(int m) { minute = m;}

//accessors
int Time :: getHour() const { return hour;}
int Time :: getMinute() const { return minute;}


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

void Time :: readInputTime()
{
    string time;
    cout << "Enter time in 24h format(HH MM): ";
    cin >> hour >> minute;
}

void Time :: readInput(){
    cout << "Enter date(DD MM YYYY) or press 0 for all values to return to previous menu(does not work for end time input)\nInput: ";
    cin >> day >> month >> year;
    
    readInputTime();
}
void Time :: printTime()
    {
        cout << "Time: ";
        if (hour < 10)
            cout << "0";

        cout << hour << ":";

        if (minute < 10)
            cout << "0";

        cout << minute << "\t";
}

void Time :: print() {
    printDate();
    printTime();
    printStatus();
}

void Time :: diffPrint(){
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

        if (temp.minute < 0)
        {
            temp.minute += 60;
            temp.hour--;
        }

        if (temp.hour < 0)
        {
            temp.hour += 24;
            temp.day--;
        }

        if (temp.day < 0)
        {
            int dayCalcMonth = month - 2;
            if (dayCalcMonth < 0)
                dayCalcMonth += 12;
            
            temp.day += dayCalc[dayCalcMonth];
            temp.month--;
        }
        if (temp.month < 0)
        {
            temp.month += 12;
            temp.year--;
        }
        temp.setStatus(status);
        return temp;
}

void Time :: getCurrentTime()
{
    struct tm* ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);
    dateExtract(asctime(ptr));
}

bool Time :: operator<(const Time &t){
    if((year - t.year) < 0)
        return true;

    if((month - t.month) < 0)
        return true;

    if((day - t.day) < 0)
        return true;
    
    if((hour - t.hour) < 0)
        return true;

    if((minute - t.minute) < 0)
        return true;

    return false;
}

bool timeCompareForEvent(Time &a, Time &t)
{
    if((a.year - t.year) < 0)
        return true;

    else if (a.year - t.year > 0)
        return false;

    if((a.month - t.month) < 0)
        return true;

    else if (a.month - t.month > 0)
        return false;

    if((a.day - t.day) < 0)
        return true;

    else if (a.day - t.day > 0)
        return false;
    
    if((a.hour - t.hour) < 0)
        return true;

    else if (a.hour - t.hour > 0)
        return false;

    if((a.minute - t.minute) < 0)
        return true;

    return false;    
}

bool timeCompareOneHour(Time &a, Time &t)
{
    if((a.year - t.year) > 0)
        return true;

    if((a.month - t.month) > 0)
        return true;

    if((a.day - t.day) > 0)
        return true;
    
    if((a.hour - t.hour) >= 1)
        return true;

    return false;   
}
ostream& operator<< (ostream& out, Time t)
{
        out << "Date: ";
        if (t.day < 10)
            out << "0";

        out << t.day << "/";

        if (t.month < 10)
            out << "0";       

        out << t.month << "/" << t.year << "\t";
        out << "\nTime: ";
        if (t.hour < 10)
            out << "0";

        out << t.hour << ":";

        if (t.minute < 10)
            out << "0";

        out << t.minute << "\t";
       
        out << "\nStatus: ";
        if(t.status)
            out << "Occupied\n";
        else    
            out << "Free\n";
        return out;
}

