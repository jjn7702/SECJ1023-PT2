
#ifndef MEDTYPE_H
#define MEDTYPE_H
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

#endif
