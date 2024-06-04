#include "UserInfo.h"
#include "MedHistory.h"
#include "Symptom.h"
#include <iostream>
#include <string>
using namespace  std;

UserInfo :: UserInfo() : name(""), gender(""), nophone(""), email(""), age(0), med(NULL), sym(NULL) {}


UserInfo :: UserInfo (string n ="", string g ="", string nop ="", string e ="", int a =0, MedHistory *mH = NULL, Symptom *s = NULL ){
        name = n;
        gender = g;
        nophone = nop;
        email = e;
        age = a;
        med = mH;
        sym = s;
}

string UserInfo :: getNoPhone () {
    return nophone;
}

void UserInfo :: addUserInfo () {

        char nMedH;
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter your gender: ";
        getline(cin, gender);
        cout << "Enter your phone number: ";
        getline(cin, nophone);
        cout << "Enter your email: ";
        getline(cin, email);
        cout << "Enter your age: ";
        cin >> age;
        cin.ignore();  
        /*cout << "Do you have any medical history?(y/n) ";
        cin >> nMedH;
        cin.ignore();

        if (nMedH == 'y' && med != NULL) {
               med->addMedHis();
        }*/
}

void UserInfo :: displayUserInfo () {

        cout << "name : "<< name << endl;
        cout << "age : "<< age << endl;
        cout << "gender : "<< gender << endl;
        cout << "phone number : "<< nophone << endl;
        cout << "email address : "<< email << endl;
}

