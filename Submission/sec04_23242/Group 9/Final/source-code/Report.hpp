#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

//Include all neccessary files
#include "Medication.hpp"
#include "MedType.hpp"
#include "frequency.hpp"
#include "Daily_Frequency.hpp"
#include "Weekly_Frequency.hpp"
#include "Patient.hpp"
#include "RegularPatient.hpp"
#include "SpecialPatient.hpp"

#ifndef REPORT_H
#define REPORT_H
using namespace std;


class Report
{
    double startDate, endDate;
    Medication *med = new Medication[50];
    Patient *patient;           
    MedType *medtype = new MedType[50];
    Frequency *freq = new Frequency[50];

   public:
    Report() : startDate(0), endDate(0){}
    Report(double s, double e) : startDate(s), endDate(e) {}

    // MUTATORS
    int setSdate()
    {
        cout << "End Date and Time (YYMMDD.HHMM): ";
        cin >> startDate;
        cin.ignore();

    }

    void setEdate()
    {cout << "End Date and Time (YYMMDD.HHMM): ";
     cin >> endDate;
     cin.ignore();}


    // ACCESSORS
    double getSdate(){return startDate;}
    double getEdate(){return endDate;}

     void displayReport(Patient *p)
    { 

        cout << "\n\n" << setw(35) << 2024 << " MEDICATION REPORT SCHEDULE\n\n";

        p->printDetails();
    }

    // Display medication (Aggregation)
    void displayMedSchedule(Medication *m, MedType *mt, int medCount, double currentDateTime) {
    cout << "\t\tBelow is your past medicine(s): \n";
    for (int i = 0; i < medCount; ++i) {
        if (startDate < currentDateTime) {
            cout << "Name" << setw(10) << ":  " << m->getMedName() << "\n";
            cout << "Dosage" << setw(8) << ":  " << m->getMedDosage() << "\n";

            if (mt!=NULL) m->medtypeOutput();
        
            m->freqOutput();
            cout << endl;
        }
    }

    cout << "\n\t\tCurrent list of medicines:\n";
    for (int i = 0; i < medCount; ++i) {
        if (startDate >= currentDateTime) {
            cout << "Name" << setw(10) << ":  " << m->getMedName() << "\n";
            cout << "Dosage" << setw(8) << ":  " << m->getMedDosage() << "\n";

            if (mt!=NULL) m->medtypeOutput();
        
            m->freqOutput();
            cout << endl;
        }
    }
}
    ~Report(){}
    
};

#endif
