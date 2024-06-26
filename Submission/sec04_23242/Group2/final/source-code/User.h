#ifndef USER_H
#define USER_H

#include "Schedule.h"
#include "Organiser.h"
#include <string>
#include <vector>
#define maxOrganiser 50
using namespace std;

class User {
protected:
    string username;
    string password;
    vector <Organiser*> organiser;
    int numEvent;
    int id;

public:
    User();
    User(string, string, int);

    bool newUser(User[]);
    bool passCheck(string, int);

    //accessors
    string getUsername() const;
    string getPassword() const;
    int getID() const;
    Organiser getOrganiser(int ) const;
    Organiser* getOrganiserPointer(int ) const;
    string getOrganiserName(int ) const;
    int getEventType(int ) const;
    int getNumEvent()const;
    Time getTime(int ) const;
    Time getEndTime(int ) const;


    //mutators
    void setUsername(string);
    void setPassword(string);
    void setOrganiser(Organiser *);
    void setOrganiser(Organiser *, int);
    void setID(int);

    void removeEvent(int);
    void arrange();
};

#endif
