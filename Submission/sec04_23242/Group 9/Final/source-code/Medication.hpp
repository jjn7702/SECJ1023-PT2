
#ifndef MEDICATION_H
#define MEDICATION_H

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
    Medication(string n, string d, string f, string s, string c): medName(n), dosage(d), medType(f, c, s){}

    //accessors
    string getMedName() {return medName;}
    string getMedDosage() {return dosage;}

    //functions
    void input()
    {
        cout << "\t\tEnter medication name: ";
        cin.ignore();
    }

    void freqInput() {
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

    void display() {
        cout << "\t\tMedicine Name: " << medName << endl;
        cout << "\t\tMedicine Dosage: " << dosage << endl;
        medType.printMedType();
    }

    void outputMed(){
        cout << "\t\t" << setw(20) << medName << setw(10) << dosage << setw(10) << medType.getMedForm() << setw(10)<< medType.getMedShape() << setw(10) << medType.getMedColor() << "\n";
    }

    //destructor 
    ~Medication(){}
};

#ENDIF
