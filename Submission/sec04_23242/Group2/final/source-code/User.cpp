#include "User.h"
#include"Schedule.h"
#include "Reminder.h"
#include "Event.h"
#include<iostream>
#include <algorithm>

User :: User() : username(""), password(""), id(0), numEvent(0) {}

User :: User(string n, string p, int _id) : username(n), password(p), id(_id), numEvent(0) {}

bool User :: newUser(User users[]) {
    //assume default
    int _id = 0; //default id
    string tempUsername, tempExistingUsername;
    start:
    cout << "Username\t: " ;
    getline(cin, tempUsername);
    for (int i = 0; i < username.length(); i++)
        tempUsername[i] = tolower(tempUsername[i]);

    if (username == "0")
    {
        username = "";
        return false;
    }
        

    for (int i = 0; i < 10; i++)
    {
        if (users[i].getUsername() == "")
            continue;

        tempExistingUsername = users[i].getUsername();

        for (int j = 0; j < tempExistingUsername.length(); j++)
            tempExistingUsername[j] = tolower(tempExistingUsername[j]);

        if (tempUsername == tempExistingUsername)
        {
            cout << "Similar username already taken, change another username please\n";
            goto start;
        }
    }

    cout << "Password\t: ";
    getline(cin, password);
    username = tempUsername;

    return true;
}

bool User :: passCheck(string p, int attempts)
{
    if (attempts == 5 && p != password)
    {
        cout << "Out of password attempts, proceeding back to main page\n";
        system("pause");
        return false;
    }
    if (p != password)
    {
        cout << "Password incorrect, try again ( " << attempts++ << " / 5 attempts remaining )\nPassword: ";
        getline(cin, p);
        return passCheck(p, attempts);
    }

    return true;
}

string User :: getUsername() const {
    return username;
}

string User :: getPassword() const {
    return password;
}

int User :: getID() const {
    return id;
}
Organiser User :: getOrganiser(int i) const {
    return *organiser[i];
}

Organiser* User :: getOrganiserPointer(int i) const {
    return organiser[i];
}

string User :: getOrganiserName(int i) const {
    return organiser[i]->getEventName();
}

int User :: getEventType(int i) const {
    return organiser[i]->getEventType();
}
int User :: getNumEvent()const{return numEvent;}

Time User :: getTime(int i ) const { return organiser[i]->getTime();}

Time User :: getEndTime(int i) const { return organiser[i]->getEndTime();}

void User :: setUsername(string n) {
    username = n;
}
void User :: setPassword(string p) {
    password = p;
}
void User :: setOrganiser(Organiser *o) {
    if (o->getDay() != 0)
    {
        organiser.push_back(o);
        numEvent++;
    }

}

void User :: setOrganiser(Organiser *o, int i){
    organiser[i] = o;
}

void User :: setID(int _id) {
    id = _id;
}

void User :: removeEvent(int index){
    organiser.erase(organiser.begin() + index);
    numEvent--;
}

void User :: arrange(){
    
    sort(*organiser.begin(), *organiser.end());

}
