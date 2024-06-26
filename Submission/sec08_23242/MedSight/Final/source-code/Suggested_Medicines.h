#ifndef SUGGESTEDMEDICINES_H
#define SUGGESTEDMEDICINES_H

#include<iostream>
#include<string>
using namespace std;

class Suggested_Medicines
{
private:
    string medicines;
    string duration;
public:
    Suggested_Medicines();
    Suggested_Medicines(string,string);

    void setMedicines(string);
    void setDuration(string);

    string getMedicines() const;
    string getDuration() const;

    void displayMed() const;
};

#endif