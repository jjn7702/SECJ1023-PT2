#ifndef SYMPTOM_H
#define SYMPTOM_H
#include <string>
#include <iostream>
using namespace std;

class Symptom {
    private : 
    string nameSym;

    public : 

    Symptom (string);
    void setNameSym(string);
    string getNameSym();
};


#endif