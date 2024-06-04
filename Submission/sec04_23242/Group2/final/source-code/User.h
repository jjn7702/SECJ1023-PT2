#ifndef USER_H
#define USER_H

#include "Schedule.h"
#include <string>
using namespace std;

class User {
protected:
    string username;
    string password;
    Schedule schedule;
    int id;

public:
    User();
    User(string, string, Schedule, int);

    //accessor
    bool checkPassword(string);
    string getUsername() const;
    int getID() const;
    Schedule getSchedule() const;
    
    //mutators
    void newUser();
    void setUsername(string);
    void setPassword(string);
    void setSchedule(Schedule);
    void setID(int);
};

#endif