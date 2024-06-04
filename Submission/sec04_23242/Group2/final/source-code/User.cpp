#include "User.h"
#include "Schedule.h"
#include <iostream>

User :: User() : username(""), password(""), id(0) {}

User :: User(string n, string p, Schedule s, int _id) : username(n), password(p), schedule(s), id(_id) {}

void User :: newUser() {
    cin.ignore();
    Schedule s(true); //assume default
    int _id = 0; //default id
    cout << "Username\t: " ;
    getline(cin, username);
    cout << "Password\t: ";
    getline(cin, password);
}

bool User :: checkPassword(string p) {
    if(p == password ){
        cout << "Password matched.";        
        return true;
    }else
        cout << "Password did not match. Try again.";
        return false;
}

string User :: getUsername() const {return username;}
int User :: getID() const {return id;}
Schedule User :: getSchedule() const {return schedule;}

void User :: setUsername(string n) {username = n;}
void User :: setPassword(string p) {password = p;}
void User :: setSchedule(Schedule s) {schedule = s;}
void User :: setID(int _id) {id = _id;}
