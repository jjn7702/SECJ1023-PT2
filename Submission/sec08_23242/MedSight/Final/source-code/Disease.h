#ifndef DISEASE_H
#define DISEASE_H
#include "Symptom.h"
#include "Suggested_Medicines.h"
#include "Clinic.h"
#include <iostream>
#include <string>
using namespace std;

class Disease {
    private:
        string nameDisease;
        string desc;
        Symptom *symptom [100];
        Suggested_Medicines *medicine;
        int symptomCount;

    public: 
    Disease () ;
    Disease(string nd, string des);
    Disease(string nd, string des, string med, string dur);

    void setDiseaseName (string);
    void setDiseaseDesc (string);

    string getDiseaseName ();
    string getDiseaseDesc();

    void addDisease ();
    void addSymptom (Symptom*);
    void printSymptoms ();
    void display();

    bool hasSymptom(const string& symptomName); 

};

#endif