
#ifndef REGULARPATIENT_H
#define REGULARPATIENT_H

class RegularPatient : public Patient{
    private:
    string contactInfo, emergencyContact;

    public:
    RegularPatient(string contact=" ", string emergency=" "): 
    contactInfo(contact), emergencyContact(emergency) {}
 
    //mutators
    void setcontactInfo(const string &cont) {contactInfo = cont;}
    void setemergencyContact(const string &emercon) {emergencyContact = emercon;}

    //accessors
    string getcontactInfo() const{return contactInfo;}
    string getemergencyContact() const{return emergencyContact;}

    //using polymorphism
    void getData() {
        Patient::getData();
        cout << "\t\tContact Info (+60): ";
        getline(cin, contactInfo);
        cout << "\t\tEmergency Contact (+60): ";
        getline(cin, emergencyContact);
    }

    ~RegularPatient() {} //destructor
};

#ENDIF

//-------------------------------------------------------
