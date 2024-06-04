#include "Clinic.h"
#include<iostream>
#include<string>
using namespace std;

Clinic :: Clinic () : stateName(" "), clinicName(" "), availability(" "), ClinicNo("") {}

Clinic :: Clinic(string st,string clna ,string avl ,string clno )
{
    stateName = st;
    clinicName = clna;
    availability = avl;
    ClinicNo = clno;
}

void Clinic :: setState(string st)
{
    stateName = st;
}

void Clinic :: setClinicName(string clna)
{
    clinicName = clna;
}

void Clinic :: setAvailability(string avl)
{
    availability = avl;
}

void Clinic :: setClinicNo(string clno)
{
    ClinicNo = clno;
}

string Clinic :: getState() const
{
    return stateName;
}

string Clinic :: getClinicName() const
{
    return clinicName;
}

string Clinic :: getAvailability() const
{
    return availability;
}

string Clinic :: getClinicNo() const
{
    return ClinicNo;
}

void Clinic::displayclinic() const
{
    string clinicName, clinicNo;

    if (stateName == "Johor" || stateName == "johor")
    {
        clinicName = "Southern Medical Clinic";
        clinicNo = "07 336 1731";
    }
    else if (stateName == "Sarawak" || stateName == "sarawak")
    {
        clinicName = "Kotaraya Clinic";
        clinicNo = "08 223 2177";
    }
    else if (stateName == "Sabah" || stateName == "sabah")
    {
        clinicName = "Klinik Butiza Alamesra";
        clinicNo = "08 840 2613";
    }
    else if (stateName == "Penang" || stateName == "penang")
    {
        clinicName = "Klinik Metrocare";
        clinicNo = "04 505 4365";
    }
    else if (stateName == "Selangor" || stateName == "selangor")
    {
        clinicName = "Klinik Anda";
        clinicNo = "01 337 4398";
    }
    else if (stateName == "Kedah" || stateName == "kedah")
    {
        clinicName = "Klinik Metrocare";
        clinicNo = "04 771 5052";
    }
    else if (stateName == "Perak" || stateName == "perak")
    {
        clinicName = "Klinik Zabrina";
        clinicNo = "05 282 6771";
    }
    else if (stateName == "Kelantan" || stateName == "kelantan")
    {
        clinicName = "Klinik Ikhtiyar";
        clinicNo = "09 791 7117";
    }
    else if (stateName == "Pahang" || stateName == "pahang")
    {
        clinicName = "Klinik Famili";
        clinicNo = "01 256 93695";
    }
    else if (stateName == "Terengganu" || stateName == "terengganu")
    {
        clinicName = "Klinik Rohana & Seripah";
        clinicNo = "09 623 0369";
    }
    else if (stateName == "Negeri Sembilan" || stateName == "negeri sembilan")
    {
        clinicName = "Klinik Anda";
        clinicNo = "06 675 8668";
    }
    else if (stateName == "Melaka" || stateName == "melaka")
    {
        clinicName = "Klinik Bukit Katil";
        clinicNo = "06 252 2000";
    }
    else if (stateName == "Perlis" || stateName == "perlis")
    {
        clinicName = "Klinik Anda Kangar";
        clinicNo = "01 222 97831";
    }
    else if (stateName == "Kualalumpur" || stateName == "kualalumpur")
    {
        clinicName = "Klinik Damar";
        clinicNo = "03 414 6000";
    }
    else
    {
        cout << "No clinic found for the state: " << stateName << endl;
        return;
    }

    cout << "Clinic Name: " << clinicName << endl;
    cout << "State: " << stateName << endl;
    cout << "Availability: " << "24 hours" << endl;
    cout << "Contact no: " << clinicNo << endl;
}
