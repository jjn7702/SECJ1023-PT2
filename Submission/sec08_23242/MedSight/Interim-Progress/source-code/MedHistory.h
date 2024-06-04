#ifndef MEDHISTORY_H
#define MEDHISTORY_H
#include <string>
#include <iostream>
using namespace std;

class MedHistory{
    private:
    string existDisease, medicine, allergic;
    

    public:
    MedHistory(string, string, string);

    void setExistDisease (string);
    void setMedicine (string);
    void setAllergic (string);

    string getExistDisease ();
    string getMedicine ();
    string getAllergic ();

    void addMedHis();

};


#endif