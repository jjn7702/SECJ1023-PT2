#include "Disease.h"
#include "Symptom.h"
#include "Suggested_Medicines.h"
#include <iostream>
#include <string>

using namespace std;

Disease:: Disease () : nameDisease (""), desc(""),  medicine(nullptr), symptomCount(0){
    for (int i = 0; i < 100; i++) {
        symptom[i] = nullptr;
    }
}

Disease::Disease(string nd = "", string des = "") :  medicine(nullptr), symptomCount(0) 
{  
    nameDisease = nd;
    desc = des;
    symptomCount = 0;
    for (int i = 0; i < 100; i++) {
        symptom[i] = NULL;
    }
}

Disease::Disease(string nd , string des , string med, string dur ) 
{  
    nameDisease = nd;
    desc = des;
    medicine = new Suggested_Medicines(med, dur);
    symptomCount = 0;
    for (int i = 0; i < 100; i++) 
    {
        symptom[i] = NULL;
    }
}

void Disease :: setDiseaseName (string nd) 
{
        nameDisease = nd;
}

void Disease ::  setDiseaseDesc (string des) {
        desc = des;
}

string Disease ::  getDiseaseName () {
        return nameDisease;
}

string Disease ::  getDiseaseDesc () {
        return desc;
}

void Disease ::  addDisease (){
        cout << "Enter new disease: ";
        cin >> nameDisease;
} 

void Disease ::  addSymptom(Symptom *symp ) {
        if (symptomCount < 100) {
            symptom[symptomCount] = symp;
            symptomCount++;
        }
}

void Disease :: printSymptoms() {
        cout << "Symptoms for " << nameDisease << " (" << desc << "):" << endl;
        for (int i = 0; i < symptomCount; i++) {
            if (symptom[i]) {
                cout << "- " << symptom[i]->getNameSym() << endl;
            }
        }
}

bool Disease::hasSymptom(const string& symptomName) {
    for (int i = 0; i < symptomCount; i++) {
        if (symptom[i] && symptom[i]->getNameSym() == symptomName) {
            return true;
        }
    }
    return false;
}

void Disease :: display()
{
    medicine->displayMed();
    return;
}

