#include "User.h"
#include "Admin.h"
#include "Time.h"
#include "Organiser.h"
#include "Event.h"
#include "Reminder.h"
#include "Date.h"
#include "Schedule.h"
#include <iostream>
#include <string>
using namespace std;
/*
int main(){
    Time event;
    event.readInput();
    
    Reminder r(&event, "Lunch", "somewhere", false);
    r.notify();
    cout << r;

    system("pause");
    return 0;

}
*/
const int MAX_USERS = 100;

int main ()
{
    int userCount = 0;
    User users[MAX_USERS];
    for (int i=0; i<MAX_USERS; i++){
        cout << "----test for User.h----" << endl;
        cout << "**Register New User**"<< endl;
        users[i].newUser();
        users[i].setID(++userCount);
        string p;
        bool r = false;
        while (!r){
            cout << "\nRe-check password: " ;
            getline(cin, p);
            r = users[i].checkPassword(p);
        }
        cout << " User succesfully registered." << endl;
        break;
    }    
    system("pause");
    system("cls");
    
    cout << "----test for Admin.h----" << endl;
    Schedule s2(true), s3(true);
    users[1] = User("user2", "pass2", s2, 2);
    userCount++;
    users[2] = User("user3", "pass3", s3, 3);
    userCount++;
    Admin a("admin", "adminpass");
    cout << "All users:\n";
    for (int i = 0; i < userCount; i++) {
        cout << users[i].getID() << ". " << users[i].getUsername() << endl;
    }
    cout << "\n**Reset Password**" << endl;
    a.resetPassword(users);
    cout << "\n**Remove user**" << endl;
    a.removeUser(users, userCount);
    cout << "\nUpdated users:\n";
    for (int i = 0; i < 100; i++) {
        if (users[i].getID()!=0)
            cout << users[i].getID() << ". " << users[i].getUsername() << endl;
    }    
    cout << "\n**Edit username**" << endl;
    a.editUser(users);
    
    system("pause");
    system("cls");

    cout << "----test for Schedule.h----" << endl;
    Schedule s(true);
    s.printStatus();
    s.setStatus(false);
    s.printStatus();
    system("pause");
    system("cls");

    cout << "\n\n----test for Date.h----" << endl;
    Date d;
    cout << "default date:\n";
    d.printDate();
    d.printStatus();

    d.setDay(20);
    d.setMonth(2);
    d.setYear(2024);
    d.setStatus(true);
    cout << "\n\nedited date:\n";
    d.printDate();
    d.printStatus();
    d.setStatus(false);
    d.printStatus();
    system("pause");
    system("cls");

    cout << "\n\n----test for Time.h----" << endl;
    Time t, dt;
    cout << "default Time:\n";
    t.print();

    cout << "\n\nedited Time:\n";
    t.setYear(2025);
    t.setMonth(6);
    t.setDay(20);
    t.setHour(10);
    t.setMinute(20);
    t.setStatus(false);
    t.print();

    cout << "\n\ntime difference:\n";
    dt.getCurrentTime();
    dt.setStatus(true);
    dt.print();
    dt = t - dt;
    dt.diffPrint();

    system("pause");
    system("cls");
    
    cout << "\n\n ----test for Organiser.h----" << endl;
    Organiser o;
    cout << "\n\ndefault organiser:\n" << o;
    o.setEventDesc("description organiser");
    o.setEventStatus(true);
    o.setEventName("organiser name");
    o.setStartTime(&t);
    cout << "\n\nnew organiser: \n" << o;
    system("pause");
    system("cls");



    cout << "\n\n----test for Event.h----" << endl;
    Event e(new Time(), new Time(), "name", "description", true);
    cout << "default event: \n\n" << e;
    Time st(true, 2024, 7, 2, 13, 00);
    Time et(true, 2024, 6, 2, 14, 00);
    e.setStartTime(&st);
    e.setEndTime(&et);
    e.setEventName("name 2");
    e.setEventDesc("decription 2");
    e.setEventStatus(false);
    cout << "\n\nnew event: \n" << e;
    system("pause");
    system("cls");

    cout << "\n\n----test for Reminder.h:----\n";
    Reminder r;
    cout << "default reminder: \n";
    r.notify();
    r.setStartTime(&et);
    r.setEventDesc("reminder desc");
    r.setEventName("reminder name");
    r.setEventStatus(true);
    cout << "\n\nedited reminder: \n";
    r.notify();
    system("pause");
    system("cls");

    cout << "event array testing" << endl << endl;
    Time starttime(false, 2024, 6, 20, 13, 10);
    Time endtime(true, 2024, 7, 5, 11, 10);
    Event event[3]{{&starttime, &endtime, "event name1", "event description 1", true}, {}, {}};
    event[1].setEventStatus(1);
    event[1].setEventName("event name 2");
    event[1].setEventDesc("event desc 2");
    event[1].setStartTime(&starttime);
    event[1].setEndTime(&endtime);

    for (int i = 0; i < 3; i++)
    {
        cout << "Event "<< i+1 << ".\n" << event[i] << endl;
    }

    system("pause");
}
