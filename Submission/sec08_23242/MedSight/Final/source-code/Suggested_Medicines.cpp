#include "Suggested_Medicines.h"
#include<iostream>
#include<string>
using namespace std;

Suggested_Medicines :: Suggested_Medicines () 
{
    medicines = " ";
    duration = " "; 
}

Suggested_Medicines :: Suggested_Medicines(string med=" ", string dur=" ")
{
    medicines = med;
    duration = dur;
}

void Suggested_Medicines :: setMedicines(string med)
{
    medicines = med;
}

void Suggested_Medicines :: setDuration(string dur)
{
    duration = dur;
}

string Suggested_Medicines :: getMedicines() const
{
    return medicines;
}

string Suggested_Medicines :: getDuration() const
{
    return duration;
}

void Suggested_Medicines :: displayMed() const
{
    cout << "Medicine: " << getMedicines() << ", Duration: " << getDuration() << " days" << endl;
}