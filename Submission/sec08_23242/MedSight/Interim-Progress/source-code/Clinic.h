#ifndef CLINIC_H
#define CLINIC_H

#include<iostream>
#include<string>
using namespace std;

class Clinic
{
private:
    string stateName;
    string clinicName;
    string availability;
    string ClinicNo;
public:
    Clinic();
    Clinic(string,string,string,string);

    void setState(string);
    void setClinicName(string);
    void setAvailability(string);
    void setClinicNo(string);

    string getState() const;
    string getClinicName() const;
    string getAvailability() const;
    string getClinicNo() const;
    void displayclinic() const;
};

#endif