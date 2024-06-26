#ifndef SUGGESTIONS_H
#define SUGGESTIONS_H

#include<iostream>
#include<string>
using namespace std;

class Suggestions
{
public:
    virtual void display()
    {
        cout <<"Suggestions: General Suggestions"<< endl;
    }
};

class Suggested_Medicines : public Suggestions
{
private:
    string medicine;
    float duration;

public:
    Suggested_Medicines(string med=" ", float dur=0.0): medicine(med), duration(dur) {}
    void display()
    {
        Suggestions :: display();
        cout << "Medicine: " << medicine << ", Duration: " << duration << " days" << endl;
    }
};

class Nutritional_Advice : public Suggestions
{
private:
    string mealSuggest;
    string mealAvoid;

public:
    Nutritional_Advice(string sug=" ", string avd=" "):mealSuggest(sug),mealAvoid(avd) {}
    void display()
    {
        Suggestions::display();
        cout << "Meals suggested: " << mealSuggest << endl;
        cout << "Meals to avoid:  " << mealAvoid << endl;
    }
};

class Clinic : public Suggestions
{
private:
    string cityName;
    string stateName;
    string clinicName;
    string availability;
    int ClinicNo;
    
public:
    Clinic(string city=" ", string state=" ", string clinic=" ", string avl=" ", int phnNo=0):
    cityName(city), stateName(state), clinicName(clinic), availability(avl), ClinicNo(phnNo){}
    void display()
    {
        Suggestions :: display();
        cout << "Clinic Name: " << clinicName << endl;
        cout << "City: " << cityName << ", State: " << stateName << endl;
        cout << "Availablity: " << availability << endl;
        cout << "Contact no: " << ClinicNo << endl;
    }
};

#endif