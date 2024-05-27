
#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
using namespace std;
class Schedule
{
    protected:
    bool status;

    public:
    Schedule(bool s = true): status(s) {}
    void setStatus(bool s) {status = s;}
    void printStatus() {cout << "status: " << status << endl;}
};

class Date: public Schedule
{
    protected:
    int year, month, day;

    public:
    Date(bool s = true, int y = 0, int m = 0, int d = 0): year(y), month(m), day(d), Schedule(s) {}
    void printDate()
    {
        cout << "Date: ";
        if (day < 10)
            cout << "0";

        cout << day << "/";

        if (month < 10)
            cout << "0";       

        cout << month << "/" << year << endl;
    }
};

class Time:public Date
{
    protected:
    int hour, minute;

    public:
    Time(bool s = true, int y = 0, int m = 0, int d = 0, int h = 0, int min = 0): hour(h), minute(m), Date(s, y, m, d) {}
    
    Time operator- (const Time &t)
    {
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
    void dateExtract(string d)
    {
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

    void readInput()
    {
        cout << "Enter date(DD MM YYYY): ";
        cin >> day >> month >> year;
        cout << "Enter time(HH MM): ";
        cin >> hour >> minute;
    }   
    void printTime()
    {
        cout << "Time: ";
        if (hour < 10)
            cout << "0";

        cout << hour << ":";

        if (minute < 10)
            cout << "0";

        cout << minute << endl;
    }

    void print()
    {
        Date::printDate();
        printTime();
        Date::printStatus();
    }

    void diffPrint()
    {
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
};

int main ()
{
    Time current;
    Time event;
    Time diff;
    struct tm* ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);
    current.dateExtract(asctime(ptr));
    event.readInput();
    cout << "Current time: " << endl;
    current.print();
    cout << "\nEvent time: ";
    event.print();
    cout << endl;
    diff = event - current;
    diff.diffPrint();
}