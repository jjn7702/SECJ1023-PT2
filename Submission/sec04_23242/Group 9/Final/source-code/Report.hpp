#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

//Include all neccessary files
#include "Medication.h"
#include "MedType.h"
#include "frequency.h"
#include "Daily_Frequency.h"
#include "Weekly_Frequency.h"
#include "Patient.h"
#include "RegularPatient.h"
#include "SpecialPatient.h"

#ifndef REPORT_H
#define REPORT_H
using namespace std;


class Report
{
    string startDate, endDate;
    Medication *medication[20]; 
    Patient *patient;           
    MedType *medtype[20];
    Frequency *freq[20];

   public:
    Report() : startDate(""), endDate(""){}
    Report(string s, string e) : startDate(s), endDate(e) {}

    // MUTATORS
    int setSdate()
    {
        int m,d;
        string sD;
        
        // Extract month from user
        do{
        cout << "(DD-MM) : ";
        cin.ignore();
        getline (cin, sD);
        startDate = sD;
        string a = startDate.substr(3,2);
        m = stoi(a);

        string b = startDate.substr(0,2);
        d = stoi(b);
        
        if(m > 12 || d > 31 || m <= 0 || d <= 0) // notification pop up if month/day entered is invalid
        cout << "Oops! It seems like there's a typo on your date.\n Enter again.";
        } while(m > 12 || d > 31 || m <= 0 || d <= 0);
        return m;

    }


    void setEdate()
    {
        int n, e;
        string eD;
        
        do{
        cout << "(DD-MM) : ";
        getline (cin, eD);
        endDate = eD;
        string c = endDate.substr(3,2);
        n = stoi(c);

        string f = endDate.substr(0,2);
        e = stoi(f);
        
        if(n > 12 || e > 31 || n <= 0 || e <= 0 ) // notification pop up if month entered is invalid
        cout << "Oops! It seems like there's a typo on your date.\n Enter again.";
        } while(n > 12 || e > 31 || n <= 0 || e <= 0);
        endDate = eD;
    }


    // ACCESSORS
    string getSdate(){return startDate;}
    string getEdate(){return endDate;}


     void displayReport(Patient *p)
    { 

        cout << "\n\n" << setw(35) << 2024 << " MEDICATION REPORT SCHEDULE\n\n";

        p->printDetails();
    }

    // Display medication (Aggregation)
    void displayMed(Medication *m, MedType *mt) const 
    {
        
        cout << "Date Start - Date End : " << startDate << " - " <<  endDate << "\n";
        cout << "Name" << setw(10) << ":  " << m->getMedName() << "\n";
        cout << "Dosage" << setw(8) << ":  " << m->getMedDosage() << "\n";

        if (mt!=NULL) m->medtypeOutput();
        
        m->freqOutput();
    }

    ~Report(){}
    
};

#endif
