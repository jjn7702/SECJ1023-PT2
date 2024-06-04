#ifndef USERINFO_H
#define USERINFO_H
#include "MedHistory.h"
#include "Symptom.h" 
#include <iostream>
#include <string>
using namespace std;

class UserInfo {
    private:
    string name, gender, nophone, email;
    int age;
    MedHistory *med;
    Symptom *sym;
    

    public :
    UserInfo();
    UserInfo(string , string, string, string, int, MedHistory*, Symptom*);
    string getNoPhone ();
    void addUserInfo();
    void displayUserInfo ();

};

#endif