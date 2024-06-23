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

        void printMedType()
        {
            cout << "\t\tForm" << setw(10) << ":  " << form << "\n";
            cout << "\t\tShape" << setw(9) << ":  " << shape << "\n";
            cout << "\t\tColor" << setw(9) << ":  " << color << "\n";        
        }

        //destructor
        ~MedType(){}
};
