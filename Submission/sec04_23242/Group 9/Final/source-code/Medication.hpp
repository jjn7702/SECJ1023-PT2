
#ifndef MEDICATION_H
#define MEDICATION_H

#include "MedType.hpp"
#include "Frequency.hpp"
#include "dailyFreq.hpp"
#include "weeklyFreq.hpp"

#include <iostream>
using namespace std;

class Medication {
    string medName, dosage;
    MedType medType;//composition
    Frequency frequency; //composition
    dailyFreq dFreq;
    weeklyFreq wFreq;

    public:
    //constructor
    Medication(){}
    //Medication(string n, string d): medName(n), dosage(d) {}
    Medication(string n, string d, string s, string c, string f): medName(n), dosage(d), medType(s,c,f){}

    //accessors
    string getMedName() {return medName;}
    string getMedDosage() {return dosage;}

    //functions
    void input()
    {
        cout << "Enter medication name: ";
        cin.ignore();
        getline(cin, medName); 
        cout << "Enter dosage(500mg, 5ml): ";
        getline(cin, dosage);
        medType.read();
        frequency.setFreq();
        dFreq.setdailyIntake();
        wFreq.setdayPerWeek();
    }

    void freqOutput() 
    {
        wFreq.printFreq();
        dFreq.printFreq();
        cout << "\n\n";
    }

    void medtypeOutput()
    {
        medType.printMedType();
    }

    void output(int num)
    {
        if(num==0){
            cout << "No medication available.\n" << endl;
        }else{
            cout << left;
            cout << setw(20) << "MEDICATION"<< setw(10) << "DOSAGE" << setw(10) << "FORM" << setw(10) << "SHAPE" << setw(10) << "COLOR" << endl;
        }
    }
    void outputMed(){
        cout << setw(20) << medName << setw(10) << dosage << setw(10) << medType.getMedForm() << setw(10)<< medType.getMedShape() << setw(10) << medType.getMedColor() << "\n";
    }

    void addtoFile(string filename) {
        ofstream outfile(filename, ios::app);
        if (outfile.is_open()) {
            outfile << medName << " " << dosage << " " << medType.getMedForm() << " " << medType.getMedColor() << " " << medType.getMedShape() << endl;
            outfile.close();
        } else {
            cout << "Error opening file for writing patient data." << endl;
        }
    }

    //destructor
    ~Medication(){}
};

#ENDIF
