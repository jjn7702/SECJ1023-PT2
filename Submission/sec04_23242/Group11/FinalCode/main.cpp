#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

class Frequency
{
    // so that child class have access
    protected:
        int freqVal;

    public:
        Frequency() : freqVal(1){}
        Frequency(int freqVal):freqVal(freqVal){}

        // MUTATOR
        void setFreq()
        {
            cout << "\nNumber of doses you need to take at one time : ";
            cin >> freqVal;
        }

        // ACCESSOR
        int getFreq() const { return freqVal; }

        //POLYMORPHISM
        // default print from parent class
        virtual void printFreq()
        {
            cout << "Frequency : " << freqVal << " each time\n";
        }

        // Destructor
        ~Frequency(){}

};

//------------------------------

class dailyFreq : public Frequency
{
    
    int dailyIntake;
    double time[10];

    public:
        dailyFreq(): Frequency(1), dailyIntake(1), time() {}
        dailyFreq(int f, int d, double t): Frequency(f), dailyIntake(d) 
        {
            if(d > 1)
            {
                for(int i = 0; i < d; i++)
                {
                    time[i] = t;   
                }
            }
        }


        //DAILY FREQUENCY DESTRUCTOR
        ~dailyFreq(){}


        //AQCUIRE DAILY INTAKE FROM USER
        void setdailyIntake()
        {

        // setting daily intake
            cout << "\nHow many times do you need to take the the medicine in a day?\n";
            cin >> dailyIntake;
        
        // setting time for user
            for(int i = 0; i < dailyIntake; i++)
            {
            cout << "\nWhat's the time no." << i+1 << " you need to take the medication in a day? \n";
            cout << "24hrs system (hh.mm) : ";
            cin >> time[i];
            }
        }

        //ACCESSORS
        int getdailyIntake() const { return dailyIntake; }
        double getTime(int i) const{ return time[i]; }
        

        //PRINT DAILY FREQUENCY (POLYMORPHISM)
        void printFreq() override
        {
            cout << fixed << setprecision(2);
            cout << "\nYou need to take " << dailyIntake << " per day.\n";
            cout << "Time: " ;
            for(int i = 0; i < dailyIntake; i++)
            {
                cout << time[i] << "\n" << setw(11) << endl;
            }
            Frequency :: printFreq();
        }

};

//----------------------------------------------------------

class weeklyFreq : public Frequency  //inheritance
{
    int dayPerWeek;

    public:
        weeklyFreq(): Frequency(1), dayPerWeek(1){}
        weeklyFreq(int f, int dpw): Frequency(f), dayPerWeek(dpw){}

        //WEEKLY FRQUENCY DESTRUCTOR
        ~weeklyFreq(){}

        //AQCUIRE DAYPERWEEK FROM USER
        void setdayPerWeek()
        {
            cout << "\nHow many times do you need to take the medication per week?\n";
            cin >> dayPerWeek;
        }

        //ACCESSOR
        int getdayPerWeek() const{ return dayPerWeek; }
        

        //PRINT WEEKLY FREQUENCY (POLYMORPHISM)
        void printFreq() override
        {
            cout << "\nThis medicine needs to be taken " << dayPerWeek << " day(s) per week, and\n";
            //Frequency :: printFreq(); // print also the general frequency
        }
};

//----------------------------------------------------

class MedType {
    string form, shape, color;

    public:
        //constructor
        MedType(){}
        MedType(string f, string s, string c): form(f), shape(s), color(c){}


        //accessor
        string getMedForm() const {return form;}
        string getMedShape() const {return shape;}
        string getMedColor() const {return color;}

        //mutators
        void setMedForm(const string &f) {form = f;}
        void setMedShape(const string &s) {shape = s;}
        void setMedColor(const string &c) {color = c;}

        //functions
        void read()
        {
        cout << "Enter form (tablet, capsule, powder, liquid): ";
        
        getline(cin, form);
        setMedForm(form);

        if (form=="tablet" || form=="capsule")
        {
            cout << "Enter shape (round, oval): ";
            getline(cin, shape);
            setMedShape(shape);
        }
        
        else if(form == "powder" || form == "liquid")
        {
            shape = "None";
        }

        else shape = "-";

        cout << "Enter color: ";
        
        getline(cin, color);
        setMedColor(color);
        }

        void printMedType()
        {
            cout << "Form" << setw(10) << ":  " << form << "\n";
            cout << "Shape" << setw(9) << ":  " << shape << "\n";
            cout << "Color" << setw(9) << ":  " << color << "\n";        
        }

        //destructor
        ~MedType(){}
};

//-----------------------------------------------

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

    //destructor
    ~Medication(){}
};

//----------------------------------------------------

class Patient {
    protected:
    string patientID,  fullname, password, dob, sex;
    Medication *med = nullptr; //aggregation with Medication class

    public:
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
            try {
                if(dob.length() > 7) {
                    size_t pos1 = dob.find('/');
                    size_t pos2 = dob.find('/', pos1 + 1);
                    year = stoi(dob.substr(pos2 + 1, 4)); 
                    age = 2024 - year;
                } else {
                    throw(age);
                }

            } catch (...) {
                cout << "Sorry, cannot extract your age from DOB." << endl;
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

//------------------------------------------------------

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

//-------------------------------------------------------

class SpecialPatient: public Patient {
    private:
    string guardianName, relationship, guardianContact;

    public:
    SpecialPatient(string g = " ", string r = " ", string gc =" "): 
    guardianName(g), relationship(r), guardianContact(gc) {}
 
    //mutators
    void setguardianName(const string &g) {guardianName = g;}
    void setrelationship(const string &r) {relationship = r;}
    void setguardianContact(const string &gc) {guardianContact = gc;}

    //accessors
    string getguardianName() const{return guardianName;}
    string getrelationship() const{return relationship;}
    string getguardianContact() const{return guardianContact;}

    void getData() {
        cout << "\t\tGuardian Name: ";
        getline(cin, guardianName);
        cout << "\t\tRelationship with Patient: ";
        getline(cin, relationship);
        cout << "\t\tGuardian Contact Info (+60): ";
        getline(cin, guardianContact);
    }

    ~SpecialPatient() {} //destructor
};

//----------------------------------------------

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
        cout << "(DD/MM) : ";
        cin.ignore();
        getline (cin, sD);
        startDate = sD;
        string a = startDate.substr(3,2);
        m = stoi(a);

        string b = startDate.substr(0,2);
        d = stoi(b);
        
        if(m > 13 || d > 31 ) // notification pop up if month/day entered is invalid
        cout << "Oops! It seems like there's a typo on your date.\n Enter again.";
        } while(m > 13 || d > 31);
        return m;

    }

    // Extract year from user
    /*string setYear()
    { 
        return startDate.substr(6,4);
    }*/

    void setEdate()
    {
        int n, e;
        string eD;
        
        do{
        cout << "(DD/MM) : ";
        getline (cin, eD);
        endDate = eD;
        size_t pos1 = endDate.find('-');
        size_t pos2 = endDate.find('-', pos1 + 1);
        string c = endDate.substr(pos1-1);
        n = stoi(c);

        string f = endDate.substr(pos2+1);
        e = stoi(f);
        
        if((n>12 && n<=0) || (e>31 && e<=0) ) // notification pop up if month entered is invalid
        cout << "Oops! It seems like there's a typo on your date.\n Enter again.";
        } while(n > 13 || e > 31);
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

//-------------------------------------------------------

void displayLine() {
    cout << "\t\t";
    for(int i = 0; i < 30; i++) {
        cout << "-";
    }
    cout << endl;
}

int userOption() {
    int useropt;
     cout << "\n\t\tWelcome to MEDICATION SCHEDULER!" << endl
         << "\t\tChoose your task for today." << endl;
    cout << "\t\t[OPTION 1] => Add medication" << endl
         << "\t\t[OPTION 2] => Remove medication" << endl
         << "\t\t[OPTION 3] => View history" << endl
         << "\t\t[OPTION 4] => View report and exit system." << endl << endl;
    cout << "\t\tOPTION => [ ]\b\b";
    cin >> useropt;
    system("cls");
    return useropt;
}

int returnorexit() {
    int choose;
    cout << "\n\t\tPress [1] to return to menu, [2] to exit system [ ]\b\b";
    cin >> choose;
    return choose;
    system("cls");
}

void case4(int numMed, Medication med[], Report report[], Patient patient, MedType mt[]) {
    cout << "\t\tYou have chosen to VIEW REPORT and EXIT SYSTEM.\n\n";
    displayLine();

    if (numMed == 0) {
        report[0].displayReport(&patient);
        cout << "\n\n *You have no medication scheduled.\n\n";
    } else {
        for (int i = 0; i < numMed; i++) {
            cout << "DATES FOR MEDICATION " << i + 1 << " : " << med[i].getMedName() << "\n";
            cout << "When would you like to start your medication " << i + 1 << " ? ";
            report[i].setSdate();

            cout << "When does this medication " << i + 1 << " end? ";
            report[i].setEdate();

            system("cls");
        }

        report[0].displayReport(&patient); // Display report, display patient's information
        for (int i = 0; i < numMed; ++i) {
            cout << "\nMEDICATION " << i + 1 << endl;
            report[0].displayMed(&med[i], &mt[i]);
        }
    }

    system("pause");
}

int main() {

    int addMedNum, removeMedNum, numMed=0;
    string addMed[20]; //store name of meds added 
    string removeMed[20];  //store name of meds removed

    Patient* patient;
    RegularPatient rPatient;
    SpecialPatient sPatient;
    Medication *med = new Medication[50];
    MedType *mt = new MedType[50];
    Report *report = new Report[50];
    Frequency *freq = new Frequency[50];

    //TIME-FOR MEDICATION INTAKE 
    time_t now = time(nullptr);

    displayLine();
    cout << "\t\t|       HI!! WELCOME TO        |" << endl;
    cout << "\t\t| 2024 MEDICATION SCHEDULER :) |" << endl;
    displayLine();
    // Print the current time
    cout << "\t\tCURRENT TIME: " << put_time(localtime(&now), "%Y-%m-%d %H:%M:%S") << endl << endl;

    rPatient.getData(); //get patient data
    patient = &rPatient;

    system("cls");

    patient->login(); //authenticate login process

    int age = patient->getAge();

    if(age < 13 || age > 70) {
        cout << "\n\t\tYOU NEED A GUARDIAN." << endl;
        sPatient.getData(); //for special patient
        patient = &sPatient;
        system("cls");
    }
    
        patient->printDetails();

    bool exit = 0;

    while(!exit)
    {

    //int optionUser = userOption(); //for user option

    switch(userOption()) 
    {
         case 1: 
        {
            cout << "\nYou have chosen to ADD MEDICATION" << endl;
            displayLine();
            cout << "How many medications do you want to add? [   ]\b\b\b";
            cin >> numMed;
            system("cls");

                for (int i = 0; i < numMed; ++i) 
                {
                    cout << "\n\nMEDICATION " << i+1 << " : \n\n";
                    med[i].input();
                    patient->setMed(med); //point to med
                    string medname = med[i].getMedName();
                    addMed[addMedNum++] = medname;
                    system("cls");
                }


            int c = returnorexit();
            if(c==2)
            case4(numMed, med, report, *patient, mt);
            break;

        }

        case 2: 
        {
            if(numMed == 0){
                cout << "\n\t\t! ERROR !" << endl
                << "\t\tYou have no record of medication to remove" << endl 
                << "\t\tPress 1 to add medication" << endl << endl;
            }
            else
            {
                string mdname;
        
                cout << "\t\tYou have chosen REMOVE MEDICATION" << endl;
                displayLine();
                cout << "\t\tEnter the medication name that you would like to delete from the list : ";
                cin.ignore();
                getline(cin, mdname);

                bool found = false;
                for(int i=0; i<numMed; i++)
                {
                    if(mdname == med[i].getMedName())
                    {
                        removeMed[removeMedNum++] = med[i].getMedName();
                        patient->setMed(med);
                        numMed--;
                        found = true;
                        break;
                    }
                }

                if(!found) cout << "\n\t\tError! Medicine cannot be found.\n\n";

            }
                int c = returnorexit();
                if(c==2)
                case4(numMed, med, report, *patient, mt);
                break;
        }

        case 3: 
       {system("cls");
        cout << "\t\tYou have chosen VIEW HISTORY" << endl;
        displayLine();

        cout << "\t\tLIST OF MEDICINE(S) ADDED: " << endl;
        for(int k = 0; k < addMedNum; k++) {
            cout << k+1 << ". " << addMed[k] << endl << endl;
        }
        
        cout << "\t\tLIST OF MEDICINE(S) REMOVED: " << endl;
        for(int j = 0; j < removeMedNum; j++) {
            cout << j+1 << ". " << removeMed[j] << endl << endl;
        }

        int c = returnorexit();
            if(c==2)
            case4(numMed, med, report, *patient, mt);
            break;}

        case 4:{case4(numMed, med, report, *patient, mt);}

        default: 
        {
            cout << "\t\tInvalid option!" << endl
                 << "\t\tChoose between [1] to [4]" << endl << endl;
            int c = returnorexit();
            if(c==2)
            exit = 1;
        }
        break; 
    }
    }

    delete[] freq;
    delete[] report;
    delete[] mt;
    delete[] med;
    system("pause");
    return 0; 
}
