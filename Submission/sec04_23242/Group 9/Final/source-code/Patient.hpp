
#ifndef PATIENT_H
#define PATIENT_H

class Patient {
    protected:
    string patientID,  fullname, password, dob, sex;
    Medication *med = nullptr; //aggregation with Medication class

    public:
    class Wrong{};
    Patient(string id=" ", string _name=" ", string pw=" ", string _dob=" ", string _sex=" "): 
    patientID(id), fullname(_name), password(pw), dob(_dob), sex(_sex) {} //argument constructor

    //mutators
    void setID(const string &id) {patientID = id;}
    void setname(const string &n) {fullname = n;}
    void setpassword(const string &pw) {password = pw;}
    void setdob(const string &d) {dob = d;}
    void setsex(const string &s) {sex = s;}

    //accessors
    string getID() const{return patientID;}
    string getname() const{return fullname;}
    string getpassword() const{return password;}
    string getdob() const{return dob;}
    string getsex() const{
        if(sex=="f") return "Female";
        else if(sex=="m") return "Male";
        return "";} //M=Male, F=Female

    virtual void getData() { //for first time
        cout << "\t\t<< ENTER DETAILS >>" << endl
             << "\t\t<< TO REGISTER >>" << endl << endl;
        cout << "\t\tPatient ID: ";
        getline(cin, patientID);
        setID(patientID);
        cout << "\t\tFull Name: ";
        getline(cin, fullname);
        cout << "\t\tPassword: ";
        getline(cin, password);
        setpassword(password);
        cout << "\t\tDate of Birth (DD/MM/YYYY): ";
        getline(cin, dob);
        cout << "\t\tGender (M/F): ";
        getline(cin, sex);
        for(int i = 0; i < sex.length(); i++){
            sex = tolower(sex[i]);
        } 
    }

    //method to calculate age (assume DD/MM/YYYY format)
    int getAge() const {
            int year;
            int age = 0;
            try{
                if(dob.length() > 7) {
                    size_t pos1 = dob.find('/');
                    size_t pos2 = dob.find('/', pos1 + 1);
                    year = stoi(dob.substr(pos2 + 1, 4)); 
                    age = 2024 - year;
                } else {
                    throw (age);
                }

            } catch(...) {
                cout << "\n\t\tSorry, cannot extract your age from DOB." << endl;
            }

            return age;
        }


  void login() {
    string pt, pw;

    cout << "\n\t\t<< LOGIN >>" << endl << endl;

    cout << "\t\tPatient ID: ";
    getline(cin, pt);
    cout << "\t\tPassword: ";
    getline(cin, pw);

    //login credentials
    if (pt == getID() && pw == getpassword()) {
        cout << "\t\tLOGIN SUCCESSFUL." << endl;
    } else {
        cout << "\t\t!Invalid ID or Password!" << endl;
        cout << "\t\tEnter again." << endl;
        login(); 
    }
}

     virtual void printDetails() const{
        cout << "---PATIENT DETAILS---" << endl;
        cout << "NAME          : " << getname() << endl
             << "DATE OF BIRTH : " << getdob() << endl
             << "GENDER        : " << getsex() << endl 
             << "AGE           : " << getAge() << endl << endl;
    }

    //method to prescribe med (mutator)
    void setMed(Medication *m) {
        med = m;
    }

    ~Patient() {} //destructor
};

#ENDIF

//------------------------------------------------------
