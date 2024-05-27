#include "Date.h"
#include <iostream>
#include <iomanip>
using namespace std;

Date :: Date(bool s = true, int y = 0, int m = 0, int d = 0): year(y), month(m), day(d), Schedule(status){}

void Date :: printDate(){
    cout << "Date: ";
        if (day < 10)
            cout << "0";

        cout << day << "/";

        if (month < 10)
            cout << "0";       

        cout << month << "/" << year << endl;
}