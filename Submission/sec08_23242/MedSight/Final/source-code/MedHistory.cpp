#include <iostream>
#include <string>
#include "MedHistory.h"

using namespace std;

MedHistory :: MedHistory(string ed, string med, string all) {
        existDisease = ed;
        medicine = med;
        allergic = all;
    }

void MedHistory ::setExistDisease (string ed){ existDisease = ed;}

void MedHistory ::setMedicine (string med){ medicine = med;}

void MedHistory ::setAllergic (string all){allergic = all;}

string MedHistory ::getExistDisease (){return existDisease;}
    
string MedHistory ::getMedicine (){return medicine;}

string MedHistory ::getAllergic (){return allergic;}

void MedHistory ::addMedHis() {
     char nAllergic;


        cout << "Enter disease name: ";
        cin >> existDisease;
        cin.ignore();
        setExistDisease(existDisease);
        cout << "Enter medicine consume: ";
        cin >> medicine;
        setMedicine(medicine);
        
        cout << "Do you have any allergic?(y/n) :";
        cin >> nAllergic;

        if (nAllergic == 'y') {
            cout << "Enter allergic to what: ";
            cin >> allergic;
            setAllergic(allergic);
        }
      
}