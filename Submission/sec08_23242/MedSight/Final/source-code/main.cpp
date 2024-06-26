#include "UserInfo.h"
#include "MedHistory.h"
#include "Symptom.h"
#include "Disease.h"
#include "Suggested_Medicines.h"
#include "Clinic.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*void displayMenu () {
    cout << "\n***************** MENU ********************\n\n";
    cout << " 1) ADDING NEW DISEASE                       " << endl;
    cout << " 2) ADDING NEW SYMPTOMS                      " << endl;
    cout << " 3) DIAGNOSIS DISEASE                        " << endl;
    cout << " 4) DISPLAY REPORT                           " << endl;
    cout << "\n*******************************************\n\n";
   
    cout << "Please enter the number (1 to 4): ";
    cin >> choice;

    system ("cls");
}*/

int main() 
{

    UserInfo person[100];
    char nuser, ndisease, conti = 'n', contid = 'n', contis = 'n', contiid = 'n', cont1='n', continue1 = 'n';
    string phonenum, nsym, edisease; 
    int userCount = 0, numsym, numnewdisease = 11, ndis=0, diseaseCount = 100, choice;
    Disease diseases[100];
    string name, desc, med, dur;
    ifstream fin("DiseaseList.txt");


    while(getline(fin, name, ',')) 
    {
        getline(fin, desc, '/');
        getline(fin,med,'/');
        getline(fin,dur);
        diseases[ndis++] = Disease(name, desc, med, dur);
    }

   /* for (int i = 0; i < 11; i++) {
        cout << "Disease: " << diseases[i].getDiseaseName() << ", Description: " << diseases[i].getDiseaseDesc() << endl;
    }*/



    Symptom fever("fever");
    Symptom nausea("nausea");
    Symptom vomitting ("vomitting");
    Symptom wateryStool("watery stool");
    Symptom headache ("headache");
    Symptom musclePain ("muscle pain");
    Symptom coughUpBlood ("cough up blood");
    Symptom chestPain ("chest pain");
    Symptom cough ("cough");
    Symptom soreThroat ("sore throat");
    Symptom redness("redness");
    Symptom redSpot ("red spot");
    Symptom swelling ("swelling");
    Symptom blister ("blister");
    Symptom neckPain ("neck pain");
    Symptom stuffNose ("stuff nose");
    Symptom shortnessOfBreath ("shortness of breath");
    Symptom rapidBreathing ("rapid breathing");



    // symptom for diarrhea
    diseases[0].addSymptom(&fever); 
    diseases[0].addSymptom(&nausea);
    diseases[0].addSymptom(&wateryStool);

    // symptom for malaria
    diseases[1].addSymptom(&fever); 
    diseases[1].addSymptom(&headache);
    diseases[1].addSymptom(&musclePain);  

    // symptom for common cold 
    diseases[2].addSymptom(&fever); 
    diseases[2].addSymptom(&headache);
    diseases[2].addSymptom(&cough);
    diseases[2].addSymptom(&soreThroat);
    diseases[2].addSymptom(&stuffNose);

    // symptom for TB
    diseases[3].addSymptom(&fever); 
    diseases[3].addSymptom(&coughUpBlood);
    diseases[3].addSymptom(&chestPain);     

    // symptom for Pneumonia
    diseases[4].addSymptom(&fever); 
    diseases[4].addSymptom(&coughUpBlood);
    diseases[4].addSymptom(&shortnessOfBreath);
    diseases[4].addSymptom(&rapidBreathing);

    // symptom for influenza
    diseases[5].addSymptom(&fever); 
    diseases[5].addSymptom(&cough);
    diseases[5].addSymptom(&soreThroat);  

    // symptom for cellulitis
    diseases[6].addSymptom(&fever); 
    diseases[6].addSymptom(&redness);
    diseases[6].addSymptom(&redSpot);     
    diseases[6].addSymptom(&swelling);   

    // symptom for chickenpox
    diseases[7].addSymptom(&fever); 
    diseases[7].addSymptom(&redness);
    diseases[7].addSymptom(&redSpot); 
    diseases[7].addSymptom(&blister); 

    // symptom for migraine
    diseases[8].addSymptom(&nausea); 
    diseases[8].addSymptom(&vomitting);
    diseases[8].addSymptom(&headache); 
    diseases[8].addSymptom(&neckPain); 

    // symptom for food poisoning
    diseases[9].addSymptom(&nausea); 
    diseases[9].addSymptom(&vomitting);
    diseases[9].addSymptom(&headache); 

    // symptom for asthma
    diseases[10].addSymptom(&cough);
    diseases[10].addSymptom(&shortnessOfBreath);

    
    cout << "---------- to test : add new user and display user info ---------- "<< endl;

    while (conti == 'n') {
        cout << "Are you a new user? (y/n): ";
        cin >> nuser;
        cin.ignore();  

        if (nuser == 'y') {
            if (userCount < 100) {
                person[userCount].addUserInfo();
                userCount++;
            } else {
                cout << "User limit reached." << endl;
                break;
            }
        }
        else {
            cout << "Enter your phone number: ";
            getline (cin, phonenum);
            cin.ignore();  

            bool found = false;
            for (int j = 0; j < userCount; j++) {
                if (phonenum == person[j].getNoPhone()) {
                    person[j].displayUserInfo();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "User not found." << endl;
            }
        }

        cout << "Do you want to continue to our system? (y/n) : ";
        cin >> conti ;
    }

    system ("pause");
    system ("cls");

   // cout << "---------- to test : add new user medical history and display medical history ----------" << endl;

  /*while (contim == 'n') {
        cout << " do you have any medical history? (y/n) : ";
        cin >> nMedHis;

        if (nMedHis ==  'y') {
            
        }
    }*/

    while (continue1 == 'n')
    {
    
    
    cout << "\n***************** MENU ********************\n\n";
    cout << " 1) ADDING NEW DISEASE                       " << endl;
    cout << " 2) ADDING NEW SYMPTOMS                      " << endl;
    cout << " 3) DIAGNOSIS DISEASE                        " << endl;
    cout << " 4) DISPLAY REPORT                           " << endl;
    cout << "\n*******************************************\n\n";
   
    cout << "Please enter the number (1 to 4): ";
    cin >> choice;

    system("pause");

    system ("cls");

    if (choice == 1) {
        cout << "---------- to test : add new disease ----------"<<endl;
        //while (contid == 'n'){
            cout << " Do you want to add new disease? (y/n) : ";
            cin >> ndisease;

            if ( ndisease == 'y'){
                diseases[numnewdisease].addDisease();

                cout << "how many symptom do you want to add? : ";
                cin >> numsym; 
                cin.ignore();
                
                for (int j = 0; j < numsym; j++) {
                    cout << "Symptom " << j + 1 << ": ";
                    getline(cin, nsym);
                    Symptom *newSymptom = new Symptom(nsym);
                    diseases[numnewdisease].addSymptom(newSymptom);
                }

                diseases[numnewdisease].printSymptoms();
            }
            numnewdisease++;
            cout << "Do you want to continue to our system? (y/n) : ";
            cin >> continue1;
            if (continue1 == 'n') {
                break;
            }
            else {
                continue;
            }
       // }

        system ("pause");
        system ("cls");
    } 
    
    else if (choice == 2) {

        cout << "---------- to test : add symptom to exist disease ----------"<<endl;
        //while (contis =='n'){
            
            cout << "enter exist disease : ";
            cin.ignore ();
            getline(cin, edisease);
        
            bool found = false;
            for (int i =0; i<100; i++){
                if (edisease == diseases[i].getDiseaseName()){
                    
                    found = true;
                    cout << "how many symptom do you want to add? : ";
                    cin >> numsym; 
                    cin.ignore();

                    for (int j = 0; j < numsym; j++) {
                        cout << "Symptom " << j + 1 << ": ";
                        getline(cin, nsym);
                        Symptom *newSymptom = new Symptom(nsym);
                        diseases[i].addSymptom(newSymptom);
                    }

                    diseases[i].printSymptoms();
                    break;
                }
            }

            if (!found) {
                cout << "Disease not found." << endl;
            }

            cout << "Do you want to continue to our system? (y/n) : ";
            cin >> continue1;
            if (continue1 == 'n') {
                break;
            }
            else {
                continue;
            }
        
        //}

        system ("pause");
        system ("cls");
    
    }

    else if (choice == 3) {
        
        cout << "---------- to test : identify disease ----------"<<endl;
        //while (contiid == 'n') {
            
            cout << "How many symptoms do you have: ";
            cin >> numsym;
            cin.ignore();

            Symptom *userSymptoms[100];
            for (int i = 0; i < numsym; i++) {
                cout << "Symptom " << i + 1 << ": ";
                getline(cin, nsym);
                userSymptoms[i] = new Symptom(nsym);
            }

            for (int i = 0; i < diseaseCount; i++) {
                
                bool hasAllSymptoms = true;
                for (int j = 0; j < numsym; j++) {
                    if (!diseases[i].hasSymptom(userSymptoms[j]->getNameSym())) {
                        hasAllSymptoms = false;
                        break;
                    }
                }

                if (hasAllSymptoms) {
                    cout << "Possible disease: " << diseases[i].getDiseaseName() << " (" << diseases[i].getDiseaseDesc() << ")" << endl;
                }
            }
        
            cout << "Do you want to continue to our system? (y/n) : ";
            cin >> continue1;

            if (continue1 == 'n') {
                break;
            }
            else {
                continue;
            }

        //}
        system ("pause");
        system ("cls"); 
   
    }

    else if (choice == 4) {
        
        cout << "---------- to test : display suggested medicines ----------"<<endl;
        //while (cont1 == 'n') {
            cout << "How many symptoms do you have: ";
            cin >> numsym;
            cin.ignore();

            Symptom *userSymptoms[100];

            for (int i = 0; i < numsym; i++) {
                cout << "Symptom " << i + 1 << ": ";
                getline(cin, nsym);
                userSymptoms[i] = new Symptom(nsym);
            }

            for (int i = 0; i < diseaseCount; i++) {
                bool hasAllSymptoms = true;
                
                for (int j = 0; j < numsym; j++) {
                    if (!diseases[i].hasSymptom(userSymptoms[j]->getNameSym())) {
                        hasAllSymptoms = false;
                        break;
                    }
                }
            
                if (hasAllSymptoms) {
                    
                    cout << "Possible disease: " << diseases[i].getDiseaseName() << " (" << diseases[i].getDiseaseDesc() << ")" << endl;
                    cout << "Suggested Medicines: " << endl;
                    diseases[i].display();
                }
            }

            //cout << "Do you want to continue to our system? (y/n) : ";
            //cin >> cont1;
        //}
        system ("pause");
        system ("cls");


        cout << "---------- to test : display suggested clinics ----------" << endl;
        char cont = 'n';
        //while (cont == 'n') {
            
            Clinic clinic;
            string state;
            cout << "Enter your state: ";
            cin >> state;
            clinic.setState(state);
            clinic.displayclinic();

            cout << "Do you want to continue to our system? (y/n) : ";
            cin >> continue1;
            cin.ignore();
            
            if (continue1 == 'n') {
                break;
            }
            else {
                continue;
            }
        //}

        system ("pause");
        system ("cls");
    }

    
        cout << "\nThank You for Using Our System!" << endl;

        system("pause");
    
    }

    system("pause");
    return 0;
}
     