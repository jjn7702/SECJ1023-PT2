/*
Project     : Scholarship Application
Group No    : Group 7

Member 1    : Mior Danial Hakim
Matric No   : A23CS0111

Member 2    : Wan Muhammad Afif Zikry
Matric No   : A23CS0282

Member 3    : Balqis Nabilah
Matric  No  : A23CS0054
*/

#include <iostream>
#include <string>
using namespace std;

// FUNCTION
bool isValidEmail(const string& email) 
{
    int atPosition = -1;
    int dotPosition = -1;

    // Iterate through the string to find positions of '@' and '.'
    for (int i = 0; i < email.length(); i++) 
    {
        if (email[i] == '@') 
        {
            atPosition = i;
        } 
        else if (email[i] == '.') 
        {
            dotPosition = i;
        }
    }

    // Basic checks: '@' should be present, followed by '.', and '.' should not be at the end
    return atPosition > 0 && dotPosition > (atPosition + 1) && dotPosition < (email.length() - 1);
}

bool isValidDate(const string& date) {

    // Check if the date is exactly 10 characters long
    if (date.length() != 10) 
        return false;

    // Check if the format is DD/MM/YYYY
    for (int i = 0; i < date.length(); i++) 
    {
        if (i == 2 || i == 5) 
        {
            if (date[i] != '/') 
                return false;
        } 
        else 
        {
            if (!isdigit(date[i])) 
                return false;
        }
    }
    
    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));

    // Basic validation for day and month
    if (month < 1 || month > 12) 
        return false;
    if (day < 1 || day > 31) 
        return false;

    //  validation for days in each month
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) 
        return false;

    return true;
}

void upperCase(string& str)
{
    for(int i=0; i< str.length(); i++)
    {
        str[i] = toupper(str[i]);
    }
}

// CLASSES
// Base Class for class applicant and class admin
class account
{
    protected:
        string password, email, phoneNo, fullname;
    public:
        account()
        {
            password = "";
            email = "";
            phoneNo = "";
            fullname = "";
        }

        account(string pwd, string e, string ph, string fname)
        {
            password = pwd;
            email = e;
            phoneNo = ph;
            fullname = fname;
        }

        void setPwd()
        {
            cout << "Create Password: ";
            getline(cin, password);
        }

        void setEmail()
        {
            string temp;
            cout << "Enter Email: ";
            getline(cin, temp);

            if(!isValidEmail(temp))
            {
                throw "Invalid Email Format! Please Re-enter." ;
            }
            email = temp;
            throw true;
        }

        void setPhoNo()
        {
            cout << "Enter Phone No :(+60) ";
            getline(cin, phoneNo);
        }

        void setName()
        {
            cout << "Enter Full Name: ";
            getline(cin,fullname);
            upperCase(fullname);
        }

        string getPwd(){return password;}
        string getEmail(){return email;}
        string getPhoNo(){return phoneNo;}
        string getName(){return fullname;}
        ~account(){};
};

class Status
{
    private:
        string status;
    public:
        Status()
        {
            status = "Applied";
        }

        void setStatus(string s)
        {
            status = s;
        }

        string getStatus(){return status;}
        ~Status(){};
};

// Derived class from class account 
// Aggregation with class academicBG
class applicant : public account
{
    private:
        string race, religion;
        string ICnum;
        char gender;
        string appliedScholarship;
        Status s;

    public:
        applicant() : account("","","","")
        {
            race = ""; 
            religion = "";
            ICnum = "";
            gender = ' ';
            appliedScholarship = " ";
        }

        applicant(string fname, string e, string ph, string pwd, string r, string rel, string IC, char g, string AS) : account(pwd, e, ph, fname)
        {
            race = r;
            religion = rel;
            ICnum = IC;
            gender = g;
            appliedScholarship = AS;
        }

        void setRace()
        {
            cout << "Enter Your Race (Malay, Chinese, Indian, Others): ";
            getline(cin, race);
            upperCase(race);
        }

        void setReligion()
        {
            cout << "Enter Your Religion (Islam, Buddha, Hindu, Others): ";
            getline(cin,religion);
            upperCase(religion);
        }

        void setIC()
        {
            cout << "Enter Your IC Number: ";
            getline(cin, ICnum);
        }

        void setGender()
        {
            // cout << "Enter Gender Male(m) || Female(f): ";
            string last = ICnum.substr(11,1);
            int num = stoi(last);
            if(num%2 == 0)
                gender = 'f';
            else	
                gender = 'm';
        }

        void setAppScholarship(string AS)
        {
            appliedScholarship = AS;
            upperCase(appliedScholarship);
        }

        void showStatus()
        {
            cout << "Application Status \t: " << s.getStatus() << endl;
        }

        void changeStatus()
        {
            string NewStatus;
            cout << "\nEnter New Status: ";
            getline(cin, NewStatus);
            s.setStatus(NewStatus);
        }

        string getRace(){return race;}
        string getReligion(){return religion;}
        string getIC(){return ICnum;}
        char getGender(){return gender;}
        string getAS(){return appliedScholarship;}
        Status getStatusObj(){return s;}

        ~applicant(){};
};

bool isValidInstName(const string& instN)
{
    return instN.length() < 11;
}

// Aggregation with class applicant
// Base class for class UGacadBG
class academicBG
{
    protected:
        string instName, startDate, endDate, fieldOS;
        char levelOS;
        int SPM;
        applicant *app;
    public:
        academicBG()
        {
            instName = "";
            startDate = "";
            endDate = "";
            fieldOS = "";
            levelOS = ' ';
            SPM = 0;
            app = NULL;
        }

        academicBG(string instN, string SDate, string EDate, string FOS, char LOS, int SPM, applicant *a)
        {
            instName = instN;
            startDate = SDate;
            endDate = EDate;
            fieldOS = FOS;
            levelOS = LOS;
            this->SPM = SPM;
            app = a;
        }
        
        void setInst()
        {
            string temp;
            do
            {
                cout << "Enter Your Institution Name [ex: UTM]: ";
                getline(cin,temp);
                
                if(!isValidInstName(temp))
                {
                    cout << endl;
                    cout << "Invalid Institution Format! Please Re-enter." << endl;
                }

            }while(!isValidInstName(temp));

            instName = temp;
        }

        void setLOS(char LOS)
        {
            this->levelOS = LOS;
        }

        void setStartDate()
        {
            string sdate;
            do 
            {
                cout << "Enter Start Date (DD/MM/YYYY): ";
                getline(cin, sdate);

                if(!isValidDate(sdate))
                {
                    cout << endl;
                    cout << "Invalid Date Format. Please Use DD/MM/YYYY." << endl;
                }
            } while(!isValidDate(sdate));

            startDate = sdate;
        }

        void setEndDate()
        {
            string edate;
            do 
            {
                cout << "Enter Finish Date (DD/MM/YYYY): ";
                getline(cin, edate);

                if(!isValidDate(edate))
                {
                    cout << endl;
                    cout << "Invalid Date Format. Please Use DD/MM/YYYY." << endl;
                }
                else if(edate.substr(6,4) <= startDate.substr(6,4))
                {
                    cout << endl;
                    cout << "Invalid Finish Date! Please Re-enter." << endl;
                }
            } while(!isValidDate(edate) || edate.substr(6,4) <= startDate.substr(6,4));

            endDate = edate;
        }

        void setFOS()
        {
            cout << "Enter Your Field of Study: ";
            getline(cin,fieldOS);
        }

        void setSPM()
        {
            cout << "Enter SPM Result (number only): ";
            cin >> SPM;
        }

        void setaggregation(applicant *a)
        {
            app = a;
        }

        // Shows Polymorphism
        virtual void displayDetails() 
        {
            cout << "Scholarship Applied \t: " << app->getAS() << endl;
            cout << "Name \t\t\t: " << app->getName() << endl;
            cout << "Race \t\t\t: "  << app->getRace() << endl;
            cout << "Religion \t\t: "  << app->getReligion() << endl;
            cout << "IC Number \t\t: "  << app->getIC() << endl;

            switch(app->getGender())
            {
                case 'm':
                    cout << "Gender \t\t\t: MALE" << endl;
                    break;
                case 'p':
                    cout << "Gender \t\t\t: FEMALE" << endl;
                    break;
            }

            cout << "Instituition \t\t: " << instName << endl;
            cout << "Field of Study \t\t: " << fieldOS << endl;
            cout << "Start Date \t\t: " << startDate << endl;
            cout << "End Date \t\t: " << endDate << endl;
            cout << "SPM Result \t\t: " << SPM << "A" << endl;
        }

        string getInstName(){return instName;}
        string getStartDate(){return startDate;}
        string getEndDate(){return endDate;}
        string getFOS(){return fieldOS;}
        char getLOS(){return levelOS;}
        int getSPM(){return SPM;}
        applicant* getApp(){return app;}
        ~academicBG(){delete app;}
};

// Derived class from class academicBG
class UGacadBG : public academicBG
{
    private:
        char highQuali;
        double CGPA;
    public:
        UGacadBG(){};
        UGacadBG(string instN, string SDate, string EDate, string FOS, char LOS, int SPM, applicant *a, char HQ, double cgpa) : academicBG(instN, SDate, EDate, FOS, LOS, SPM, a)
        {
            highQuali = HQ;
            CGPA = cgpa;
        }
        void sethighqual()
        {
            cout << "Enter Your Highest Qualification Pre-Uni(p) or Diploma(d) : ";
            cin >> highQuali;
            highQuali = tolower(highQuali);
        }

        void setCGPA()
        {
            cout << "Enter Your Highest Qualification CGPA: ";
            cin >> CGPA;
        }

        //overridden polymorphism
        void displayDetails()
        {
            academicBG :: displayDetails();

            if(tolower(highQuali) == 'p' )
                cout << "Highest Qualification \t: Pre-Uni" << endl;
            else
                cout << "Highest Qualification \t: Diploma" << endl;
            
            cout << "Highest Qualification \t: " << CGPA << "\nCGPA" << endl;
        }
        ~UGacadBG(){};
};

// Derived class from class account
class admin : public account
{
    private:
        string adminID, adminLevelOfStudy;

    public:
        admin() : account()
        {
            adminID = " ";
            adminLevelOfStudy = " ";
        }

        admin(string fname, string ID, string LOS, string pwd, string email, string ph) : account(pwd, email, ph, fname)
        {
            adminID = ID;
            adminLevelOfStudy = LOS;
        }

        void setAdminID(string ID)
        {
            adminID = ID;
        }

        void setAdminLOS(string LOS)
        {
            adminLevelOfStudy = LOS;
        }

        string getadminID(){return adminID;}
        string getadminLOS(){return adminLevelOfStudy;}
        ~admin(){};
};

// Base Class for class UGscholarship
class scholarship
{
    protected:
        string name, deadline;
        int minAge, minSPM;
    public:
        scholarship()
        {
            name = "";
            deadline = "";
            minAge = 0;
            minSPM = 0;
        }

        void setName()
        {
            cout << "Enter Scholarship Name: ";
            getline(cin,name);
        }

        void setDeadline()
        {
            string date;
            cout << "Enter Deadline (DD/MM/YYYY): ";
            cin >> date;

            if(!isValidDate(date))
            {
                throw "Invalid Date Format. Please use DD/MM/YYYY.";
                cout << endl;
            }
            deadline = date;
            throw true;
        }

        void setMinAge()
        {
            cout << "Enter Minimum Age to Apply: ";
            cin >> minAge;
        }

        void setMinSpm()
        {
            cout << "Enter Minimum SPM Result: ";
            cin >> minSPM;
        }

        // Shows Polymorphism
        virtual void displayScholarship()
        {
            cout << "Scholarship Name: " << name << endl;
            cout << "Close Date: " << deadline << endl;
            cout << "Min Age: " << minAge << " Years Old" <<endl;
            cout << "Min SPM: "<< minSPM << "A" << endl;
        }

        string getName(){return name;}
        string getdeadline(){return deadline;}
        int getMinAge(){return minAge;}
        int getMinSPM(){return minSPM;}
        ~scholarship(){};
};

// Derived class of class scholarship
class UGscholarship : public scholarship 
{
    private:
        double minPreUniCGPA;
    public:
        UGscholarship()
        {
            minPreUniCGPA = 0.0;
        }

        void setMin()
        {
            cout << "Enter Minimum Pre-Uni CGPA: ";
            cin >> minPreUniCGPA;
        }

        //overriden polymorphism
        void displayScholarship()
        {
            scholarship :: displayScholarship();
            cout << "Min Pre-Uni CGPA: " << minPreUniCGPA << endl;
        }

        double getMin(){return minPreUniCGPA;}
        ~UGscholarship(){};
};

// FUNCTION
int getIndex(applicant* app, academicBG *acad, int currentAcad, UGacadBG *UGacad, int currentUGacad, int position, char &LOS)
{
    for(int i=0; i<currentAcad; i++)
    {
        if(acad[i].getApp() == &app[position])
        {
            LOS = acad[i].getLOS();  //will return A = pre-uni
            return i;
        }
    }

    for(int i=0; i<currentUGacad; i++)
    {
        if(UGacad[i].getApp() == &app[position])
        {
            LOS = UGacad[i].getLOS();  //will return B = degree
            return i;
        }
    }

    return -1;
}

void adminHeader()
{
    cout << "=========" << endl;
    cout << "| ADMIN |" << endl;
    cout << "=========" << endl;
}

void studentHeader()
{
    cout << "===========" << endl;
    cout << "| Student |" << endl;
    cout << "===========" << endl;
}

int displayMenu()
{
    int option;
    cout << "=====================" << endl;
    cout << "| DREAM SCHOLARSHIP |" << endl;
    cout << "=====================" << endl << endl;
    cout << "1. ADMIN \n2. STUDENT" << endl << endl;;
    cout << "Enter Your Choice: ";
    cin >> option;
    cin.ignore();

    return option;
}

int AdminMenu(admin a[], int pos)
{
    int option;
    string AdminNameUpperCase;

    AdminNameUpperCase = a[pos].getName();
    for(int i=0; i < AdminNameUpperCase.length(); i++)
    {
        AdminNameUpperCase[i] = toupper(AdminNameUpperCase[i]);
    }

    adminHeader();
    cout << "Welcome Mr/Ms " << AdminNameUpperCase << endl << endl;
    cout << "1. Setup Scholarship \n2. Review and Evaluate \n3. Logout" << endl << endl;
    cout << "Enter Your Choice: ";
    cin >> option;
    cin.ignore();

    return option;
}

int StudentMenu()
{
    int option;
    studentHeader();
    cout << endl;
    cout << "1. View Scholarship \n2. Sign Up (New Applicant) \n3. Sign In (Existing Applicant)" << endl << endl;
    cout << "Enter Your Choice [PRESS 0 TO BACK]: ";
    cin >> option;
    cin.ignore();

    return option;
}

// will return the index of object in the array of admin or applicant through pass by reference 
int checkPassword(admin ad[], applicant app[], int option, int sizeAd, int sizeApp, int &objectPos)
{
    string input1,input2;

    switch(option)
    {
        case 1: // admin
            for(int i=3; i>0; --i)
            {
                adminHeader();
                cout << endl;
                cout << "Admin ID [PRESS 0 TO BACK]: ";
                getline(cin,input1);

                if(input1 == "0")
                    break;
                cout << "Password: ";
                getline(cin, input2);

                for(int i=0; i<sizeAd; i++)
                {
                    if(input1.compare(ad[i].getadminID())==0 && input2.compare(ad[i].getPwd())==0)
                    {
                        objectPos = i;
                        return 1;
                    }
                }

                system("cls");
                cout << "Incorrect Admin ID or Password. You Have " << i-1 << " More Attempts" << endl;
            }
            break;
        case 2: // applicant
            for(int i=3; i>0; --i)
            {
                studentHeader();
                cout << endl;
                cout << "IC Number [PRESS 0 TO BACK]: ";
                getline(cin,input1);

                if(input1 == "0")
                    break;
            		
                cout << "Password: ";
                getline(cin, input2);

                for(int i=0; i<sizeApp; i++)
                {
		
                    if(input1.compare(app[i].getIC())==0 && input2.compare(app[i].getPwd())==0)
                    {
                        objectPos = i;
                        return 1;
                    }
                }

                system("cls");
                cout << "Incorrect Student IC or Password. You Have " << i-1 << " More Attempts" << endl;
            }
            break;
    }
    
    return 0;
}

int displayAllScholarship(scholarship S[], UGscholarship UGS[], int current, int currentUG, char ch, int option)
{
    switch(ch)
    {
        case 'A': 
            if(current == 0)
            {
                cout << "No Available Scholarship for Pre-Uni Currently." << endl;

                if(option == 2)
                    system("pause");

                return 1;
            }
            else 
            {
                cout << "Available Scholarship" << endl << endl;
                for(int i=0; i<current; i++)
                {
                    cout << i+1 << ") " << S[i].getName() << endl;
                }
            }
            break;
        
        case 'B':
            if(currentUG == 0)
            {
                cout << "No Available Scholarship for Undergraduate Currently." << endl;
                if(option == 2)
                    system("pause");
                return 1;
            }
            else 
            {
                cout << "Available Scholarship" << endl << endl;
                for(int i=0; i<currentUG; i++)
                {
                    cout << i+1 << ") " << UGS[i].getName() << endl;
                }
            }
            break;
    }
    return 0;
}

void viewScholarship(scholarship S[], UGscholarship UGS[], char ch, int option)
{
    int view;
    cout << "Enter Number From The List To View: ";
    cin >> view;

    system("cls");

    switch(option)
    {
        case 1: 
            adminHeader();
            cout << endl;
            break;
        case 2:
            studentHeader(); 
            cout << endl;
            break;
    }

    switch(ch)
    {
        case 'A':
            S[view-1].displayScholarship();
            break;
        case 'B':
            UGS[view-1].displayScholarship();
            break;
        default :
            cout << "Invalid Input. Please Re-enter." << endl;
    }

    cout << endl;
    system("pause");
}

int main()
{
    // variable to get index of object in an array of object
    int position;

    // admin information 
    admin ad[3] = { admin("Mior Danial Hakim", "A23CS0111", "Pre-Uni" , "123456", "mdhmzb@gmail.com", "0193473581"), 
                    admin("Balqis Nabilah", "A23CS0054", "Degree", "123456", "balqis@gmail.com", "0123456789" ),
                    admin("Wan Muhammad Afif Zikry", "A23CS0282","Pre-Uni", "123456", "zikry@gmail.com", "01160941233") };
    int adminSize = 3;

    // array of object for class scholarship 
    scholarship *S = new scholarship[2];
    int capacity = 2;
    int current = 0;

    // array of object for class UGscholarship
    UGscholarship *UGS = new UGscholarship[2];
    int capacityUG = 2;
    int currentUG = 0;

    //array of object for class applicant
    applicant *app = new applicant[10];
    int capacityApp =  10;
    int currentApp = 0;

    //array of object for class academicBG
    academicBG *acad = new academicBG[2];
    int capacityAcad = 2;
    int currentAcad = 0;

    //array of object for class UGacadBG
    UGacadBG *UGacad = new UGacadBG[2];
    int capacityUGacad = 2;
    int currentUGacad = 0;


    //Hardcoded (use for presentation)
    //Applicant 1 (Pre-U)
//     applicant app1("ABU BIN BAKRI", "abu@gmail.com", "0123456789", "12345", "MALAY", "ISLAM", "040506100709", 'm', "FOUNDATION");
//     app[currentApp] = app1;
//
//     academicBG acad1("UM", "10/10/2023", "10/10/2024", "CS", 'A', 8, &app[currentApp]);
//     acad[currentAcad] = acad1;
//     currentApp++;
//     currentAcad++;

    // //Applicant 2 (Degree)
    // applicant app2("ALEEYA BINTI HAFIZ", "aleeya@gmail.com", "0123334444", "12345", "MALAY", "ISLAM", "040506100708", 'f', "DEGREE");
    // app[currentApp] = app2;

    // UGacadBG UGacad1("UiTM", "10/10/2023", "10/10/2027", "CS", 'B', 7, &app[currentApp], 'p', 3.5);
    // UGacad[currentUGacad] = UGacad1;
    // currentApp++;
    // currentUGacad++;

    MainMenu: 
    int option;

    // Show Exception Handling
    do
    {
        try
        {
            option = displayMenu(); 
            if(option > 2 || option < 1)
                throw "Invalid Input! Please Re-Enter.";
        }
        catch (const char *msg)
        {
            system("cls");
            cout << msg << endl;
        }
    } while (option>2 || option < 1);
    
    //Main Switch 
    switch(option)
    {
        // Admin  
        case 1: 
            int AdOption, result;

            // check admin ID and password 
            system("cls");
            result = checkPassword(ad,app,option,adminSize,currentApp, position); 
            system("cls");

            // go back to Main Menu when attempt exceed 3 times
            if(result == 0)
            {
                system("cls");
                goto MainMenu;
            }

            // Login Success. Display Admin Menu
            adminMenu:
            do
            {
                system("cls");
                AdOption = AdminMenu(ad, position);
            } while (AdOption > 3 || AdOption < 1);
            system("cls");
            

            // Nested Switch
            // Display Features in Admin Menu
            switch(AdOption)
            {
                int choice;
                char ch;

                // 1.add and update scholarships
                case 1: 
                        menuScholars:
                        adminHeader();
                        cout << endl;

                        cout << "A) Pre-Uni/Diploma \nB) Degree" << endl << endl;
                        cout << "Enter Your Choice [PRESS 0 TO BACK]: ";
                        cin >> ch;

                        ch = toupper(ch);
                        if(ch == '0')
                            goto adminMenu;
                        else if(ch != 'A' && ch != 'B')
                        {
                            system("cls");
                            cout << "Invalid Input!. Please Re-Enter." << endl;
                            goto menuScholars;
                        }
                        system("cls");

                        option1:
                        adminHeader();
                        displayAllScholarship(S, UGS, current, currentUG, ch, option);
                        cout << endl;

                        cout << "1. Add New Scholarship \n2. Update Scholarship \n3. View Scholarship" << endl << endl;
                        cout << "Enter Your Choice [PRESS 0 TO BACK]: ";
                        cin >> choice;
                        cin.ignore();
                        
                        bool valid;

                        // Go Back to Previous Page
                        if(choice == 0)
                        {
                            system("cls");
                            goto menuScholars;
                        }

                        // 1. Add New Scholarship
                        if(choice == 1)
                        {
                            system("cls");
                            adminHeader();
                            cout << endl;

                            valid = false;
                            switch(ch)
                            {
                                //Pre-U Scholarship
                                case 'A':   // to expand array of object if it reached maximum capacity
                                            if(current == capacity)
                                            {
                                                scholarship *newS = new scholarship[capacity+1];
                                                for(int i=0; i<current; i++)
                                                {
                                                    newS[i] = S[i];
                                                }

                                                delete [] S;
                                                S = newS;
                                                capacity++;
                                            }
                                            S[current].setName();
                                            
                                            // Shows Exception Handling
                                            while(!valid)
                                            {
                                                try
                                                {
                                                    S[current].setDeadline();
                                                }
                                                catch(const char* dateFormatError)
                                                {
                                                    cout << endl;
                                                    cout << dateFormatError << endl;
                                                }
                                                catch(bool val)
                                                {
                                                    valid = val;
                                                }
                                            }
                                            S[current].setMinAge();
                                            S[current].setMinSpm();
                                            current++;
                                            break;

                                //Degree Scholarship
                                case 'B':   // to expand array of object if it reached maximum capacity
                                            if(currentUG == capacityUG)
                                            {
                                                UGscholarship *newUGS = new UGscholarship[capacityUG+1];
                                                for(int i=0; i<currentUG; i++)
                                                {
                                                    newUGS[i] = UGS[i];
                                                }

                                                delete [] UGS;
                                                UGS = newUGS;
                                                capacityUG++;
                                            }
                                            UGS[currentUG].setName();

                                            // Shows Exception Handling
                                            while(!valid)
                                            {
                                                try
                                                {
                                                    UGS[currentUG].setDeadline();
                                                }
                                                catch(const char* dateFormatError)
                                                {
                                                    cout << endl;
                                                    cout << dateFormatError << endl;
                                                }
                                                catch(bool val)
                                                {
                                                    valid = val;
                                                }
                                            }
                                            UGS[currentUG].setMinAge();
                                            UGS[currentUG].setMinSpm();
                                            UGS[currentUG].setMin();
                                            currentUG++;
                                            break;
                            } // End of Switch

                            cout << endl;
                            cout << "Scholarship Added!" << endl;
                            system("pause");
                            system("cls");
                            goto option1;
                        } // End of if 

                        // 2. Update Scholarship
                        else if(choice == 2)
                        {
                            if((ch == 'A' && current == 0) || (ch == 'B' && currentUG == 0) )
                            {
                                system("cls");
                                cout << "Invalid Input! This Feature Currently Not Available." << endl;
                                goto option1;
                            }

                            int update;
                            cout << "Enter Number From The List To Update: ";
                            cin >> update;
                            cin.ignore();

                            system("cls");
                            adminHeader();
                            cout << endl ;
                            cout << "***Current Scholarship Information***" << endl;
                            
                            valid = false;
                            switch(ch)
                            {
                                // Display Information of Chosen Pre-Uni Scholarship
                                case 'A':   S[update-1].displayScholarship();
                                            cout << endl;
                                            cout << "***New Scholarship Information***" << endl;
                                            S[update-1].setName();

                                            // Shows Exception Handling
                                            while(!valid)
                                            {
                                                try
                                                {
                                                    S[update-1].setDeadline();
                                                }
                                                catch(const char* dateFormatError)
                                                {
                                                    cout << endl;
                                                    cout << dateFormatError << endl;
                                                }
                                                catch(bool val)
                                                {
                                                    valid = val;
                                                }
                                            }
                                            S[update-1].setMinAge();
                                            S[update-1].setMinSpm(); 
                                            break;
                                
                                // Display Information of Chosen Degree Scholarship
                                case 'B':   UGS[update-1].displayScholarship();
                                            cout << endl;

                                            cout << "New Scholarship Information" << endl;
                                            UGS[update-1].setName();
                                            while(!valid)
                                            {
                                                try
                                                {
                                                    UGS[update-1].setDeadline();
                                                }
                                                catch(const char* dateFormatError)
                                                {
                                                    cout << endl;
                                                    cout << dateFormatError << endl;
                                                }
                                                catch(bool val)
                                                {
                                                    valid = val;
                                                }
                                            }
                                            UGS[update-1].setMinAge();
                                            UGS[update-1].setMinSpm();
                                            UGS[update-1].setMin();
                                            break;
                            }
                            cout << endl;
                            cout << "Scholarship Updated!" << endl;
                            system("pause");
                            system("cls");
                            goto option1;
                        }

                        //3. View scholarship
                        else if(choice == 3)
                        {
                            if((ch == 'A' && current == 0) || (ch == 'B' && currentUG == 0) )
                            {
                                system("cls");
                                cout << "Invalid Input! This Feature Currently Not Available." << endl;
                                goto option1;
                            }
                            viewScholarship(S, UGS, ch, option);
                            system("cls");
                            goto option1;
                        }
                        else 
                        {
                            system("cls");
                            cout << "Invalid Input! Please Re-Enter." << endl;
                            goto option1;
                        }
                        break; //End of case 1

                // 2. Review and Evaluate Applicants    
                case 2: 
                    system("cls");
                    int count;

                    // List of PRE-U Applicants
                    if(ad[position].getadminLOS() == "Pre-Uni")
                    {   
                        PreUList: 
                        count = 0;
                        char decision;
                        adminHeader();
                        cout << endl;  
                    
                        // Shows Exception Handling
                        try
                        {
                            if(currentAcad-1 < 0)
                            {
                                throw "No Applicant Currently (Pre-Uni).";
                            }

                            cout << "*List of PRE-U / DIPLOMA Applicants*" << endl << endl;
                            for(int i=0; i<currentAcad; i++)
                            {
                                if(acad[i].getApp()->getStatusObj().getStatus() == "Applied")
                                {
                                    count++;
                                    cout << count << ") " << acad[i].getApp()->getName() << endl;
                                }
                                else if(acad[i].getApp()->getStatusObj().getStatus() != "Applied")
                                {
                                    count++;
                                    cout << count << ") " << acad[i].getApp()->getName() << " (Evaluated) "<< endl;
                                }
                            } 

                            if(count == 0) 
                            {
                                throw "No Applicant Currently (Pre-Uni).";
                            }
                        }
                        catch(const char *msg)
                        {
                            cout << msg << endl;
                            cout << endl;
                            system("pause");
                            system("cls");
                            goto adminMenu;
                        }

                        cout << endl;  
                        cout << "Enter Number From The List To Evaluate [PRESS 0 TO BACK]: ";
                        cin >> choice;

                        if(choice == 0)
                        {
                            system("cls");
                            goto adminMenu;
                        }

                        if(choice > count && choice < count)
                        {
                            system("cls");
                            cout << "Invalid Input! Please Re-enter." << endl;
                            goto PreUList;
                        }
                        
                        system("cls");
                        adminHeader();
                        cout << endl;

                        acad[choice-1].displayDetails();
                        acad[choice-1].getApp()->showStatus();
                        cout << "\nChange Applicant Status? [Y/N]: ";
                        cin >> decision;
                        decision = toupper(decision);
                        cin.ignore();

                        if(decision == 'Y')
                        {
                            acad[choice-1].getApp()->changeStatus();
                            cout << "Status Updated!" << endl;
                        }
                        
                        cout << endl;
                        system("pause");
                        system("cls");
                        goto PreUList;
                    }

                    // List of DEGREE Applicants
                    else if(ad[result].getadminLOS() == "Degree")
                    {
                        DegreeList:
                        count = 0;
                        char decision;
                        adminHeader();
                        cout << endl;

                        // Shows Exception Handling
                        try
                        {
                            if(currentUGacad-1 < 0)
                            {
                                throw "No Applicant Currently. (Degree)";
                            }

                            cout << "*List of DEGREE Applicants*" << endl << endl;
                            for(int i=0; i<currentUGacad; i++)
                            {
                                if(UGacad[i].getApp()->getStatusObj().getStatus() == "Applied")
                                {
                                    count++;
                                    cout << count << ") " << UGacad[i].getApp()->getName() << endl;
                                }
                                else if(UGacad[i].getApp()->getStatusObj().getStatus() != "Applied")
                                {
                                    count++;
                                    cout << count << ") " << UGacad[i].getApp()->getName() << " (Evaluated) "<< endl;
                                }
                            } 

                            if(count == 0) 
                            {
                                throw "No Applicant Currently (Pre-Uni).";
                            }
                        }
                        catch(const char *msg)
                        {
                            cout << msg << endl;
                            cout << endl;
                            system("pause");
                            system("cls");
                            goto adminMenu;
                        }
                        
                        cout << endl;   
                        cout << "Enter Number From The List To Evaluate [PRESS 0 TO BACK]: ";
                        cin >> choice;

                        if(choice == 0)
                        {
                            system("cls");
                            goto adminMenu;
                        }

                        if(choice > count || choice < count)
                        {
                            system("cls");
                            cout << "Invalid Input! Please Re-enter." << endl;
                            goto DegreeList;
                        }
                        
                        system("cls");
                        adminHeader();
                        cout << endl;

                        UGacad[choice-1].displayDetails();
                        UGacad[choice-1].getApp()->showStatus();
                        cout << "Change Applicant Status? [Y/N]: ";
                        cin >> decision;
                        decision = toupper(decision);
                        cin.ignore();

                        if(decision == 'Y')
                        {
                            cout << endl;
                            UGacad[choice-1].getApp()->changeStatus();
                        }
                        
                        cout << endl ;
                        system("pause");
                        system("cls");
                        goto DegreeList;
                    }
                    break; // End of case 2
                default:
                    system("cls"); 
                    goto MainMenu;
            }
            break; // End of Admin Menu

        // Applicant
        case 2:
            studMenu:
            int studOption, choice;
            bool valid2;

            system("cls");
            do
            {
                studOption = StudentMenu();

                if(studOption > 3 || studOption < 0)
                {
                    system("cls");
                    cout << "Invalid Input! Please Re-enter." << endl;
                }
            } while (studOption > 3 || studOption < 0);

            // Go Back to Previous Page
            if(studOption == 0)
            {
                system("cls");
                goto MainMenu;
            }
            
            system("cls");
            studentHeader(); 
            cout << endl;

            // Nested Switch
            // Display Features in Applicant Menu
            switch(studOption)
            {
                char ch;
                int result;

                // 1. View scholarship
                case 1:
                        viewSch:
                        cout << "A) Pre-Uni/Diploma \nB) Degree" << endl << endl;
                        cout << "Enter Your Choice [PRESS 0 TO BACK]: ";
                        cin >> ch;
                        ch = toupper(ch);

                        if(ch == '0')
                            goto studMenu;
                        else if(ch != 'A' && ch != 'B')
                        {
                            system("cls");
                            cout << "Invalid Input!. Please Re-Enter." << endl;
                            studentHeader();
                            cout << endl;
                            goto viewSch;
                        }

                        system("cls");
                        studentHeader();
                        result = displayAllScholarship(S, UGS, current, currentUG, ch, option);

                        if(result == 1)
                            goto studMenu;
                        else
                        {
                            cout << endl;
                            viewScholarship(S, UGS, ch, option);
                            goto studMenu;
                        }
                        break; // End of case 1

                // 2. Sign Up (New Applicant)
                case 2:
                    valid2 = false;

                    cout << "A) Pre-Uni/Diploma \nB) Degree" << endl << endl;
                    cout << "Enter Your Level of Study [PRESS 0 TO BACK]: ";
                    cin >> ch;
                    ch = toupper(ch);

                    if(ch == '0')
                        goto studMenu;
                    
                    system("cls");
                    studentHeader();

                    // to check and expand array size if it reached its max size
                    if(currentApp == capacityApp)
                    {
                        cout << "maximum app" << endl;
                        applicant *newS = new applicant[capacityApp+1];
                        for(int i=0; i<currentApp; i++)
                        {
                            newS[i] = app[i];
                        }

                        delete [] app;
                        app = newS;
                        capacityApp++;
                    }

                    result = displayAllScholarship(S, UGS, current, currentUG, ch, option);

                    if(result == 1)
                        goto studMenu;
                    
                    cout << "\nEnter Number From The List To Select Scholarship [PRESS 0 TO BACK]: ";
                    cin >> choice;

                    
                    if(ch == 'A') // Pre U
                    {
                        app[currentApp].setAppScholarship(S[choice-1].getName());
                    }
                    else if(ch == 'B') // Degree
                    {
                        app[currentApp].setAppScholarship(UGS[choice-1].getName());
                    }

                    system("cls");
                    studentHeader();
                    cout << "*Please Fill All Required Information*" << endl << endl;
                    cin.ignore();

                    // Shows Exception Handling
                    while(!valid2)
                    {
                        try
                        {
                            app[currentApp].setEmail();
                        }
                        catch(const char* emailFormaterror)
                        {
                            cout << endl;
                            cout << emailFormaterror << endl;
                        }
                        catch(bool val)
                        {
                            valid2 = val;
                        }
                    }
                    app[currentApp].setPwd();
                    app[currentApp].setPhoNo();
                    app[currentApp].setName();
                    app[currentApp].setRace();
                    app[currentApp].setReligion();
                    app[currentApp].setIC();
                    app[currentApp].setGender();
                        
                    if(ch == 'A') // Pre-U 
                    {
                        // to check and expand array size if it reached its max size
                        if(currentAcad == capacityAcad)
                        {
                            // store array of ic to compare to applicant array of object. this is used to get the correct corresponding index in academicBG array of object 
                            string *arrayIC = new string [currentAcad];
                            for(int i=0; i<currentAcad; i++)
                                arrayIC[i] = acad[i].getApp()->getIC();
                            
                            // create temporary array of object to store current data before expanding the array of object of acadBG
                            academicBG *newAcadBG = new academicBG[capacityAcad+1];
                            for(int i=0; i<currentAcad; i++)
                            {

                                newAcadBG[i] = acad[i];
                                for(int j=0; j<currentApp; j++)
                                {
                                    //if IC stored in array of object of academicBG same with IC stored in array of object of applicant, then the address of applicant object will be stored in academicBG object (aggregation)
                                    if(arrayIC[i] == app[j].getIC())
                                        newAcadBG[i].setaggregation( &app[j] );
                                }
                            }

                            delete [] acad;
                            acad = newAcadBG; 
                            capacityAcad++;
                            delete [] arrayIC;
                        }

                        acad[currentAcad].setaggregation( &app[currentApp] );
                        acad[currentAcad].setInst();
                        acad[currentAcad].setLOS(ch);
                        acad[currentAcad].setFOS();
                        acad[currentAcad].setStartDate();
                        acad[currentAcad].setEndDate();
                        acad[currentAcad].setSPM();
                        
                        currentAcad++;
                    }
                    else if(ch == 'B') // Degree
                    {
                        //to check and expand array size if it reached its max size
                        if(currentUGacad == capacityUGacad)
                        {
                            // store array of ic to compare to applicant array of object. this is used to get the correct corresponding index in UGacadBG array of object
                            string *arrayIC = new string [currentUGacad];
                            for(int i=0; i<currentUGacad; i++)
                                arrayIC[i] = UGacad[i].getApp()->getIC();

                            //create temporary array of object to store current data before expanding the array of object of UGacadBG
                            UGacadBG *newS = new UGacadBG [capacityUGacad+1];
                            for(int i=0; i<currentUGacad; i++)
                            {
                                newS[i] = UGacad[i];
                                for(int j=0; j<currentApp; j++)
                                {
                                    //if IC stored in array of object of UGacadBG same with IC stored in array of object of applicant, then the address of applicant object will be stored in UGacadBG object 
                                    if(arrayIC[i] == app[j].getIC())
                                        newS[i].setaggregation( &app[j] );
                                }
                            }

                            delete [] UGacad;
                            UGacad = newS;
                            capacityUGacad++;
                            delete [] arrayIC;
                        }

                        UGacad[currentUGacad].setaggregation( &app[currentApp] );
                        UGacad[currentUGacad].setInst();
                        UGacad[currentUGacad].setLOS(ch);
                        UGacad[currentUGacad].setFOS();
                        UGacad[currentUGacad].setStartDate();
                        UGacad[currentUGacad].setEndDate();
                        UGacad[currentUGacad].setSPM();
                        UGacad[currentUGacad].sethighqual();
                        UGacad[currentUGacad].setCGPA();
                        currentUGacad++;
                    }
                    currentApp++;
                    break; // End of case 2
                
                // 3. Sign In (existing applicant)
                case 3:
                    //check student IC and password
                    system("cls");
                    result = checkPassword(ad,app,option,adminSize,currentApp,position); 
                    system("cls");

                    // go back to main menu when attempt exceed 3 times
                    if(result == 0)
                        goto studMenu;

                    int index;
                    char LOS;
                    index = getIndex(app, acad, currentAcad, UGacad, currentUGacad, position, LOS); 
                    
                    applicantMenu:
                    studentHeader();
                    cout << endl;
                    cout << "1) Summary of Application Form" << endl;
                    cout << "2) Status" << endl << endl;  // show status : Ppplied, Interview, Rejected, Accepted;
                    cout << "Enter Your Choice [PRESS 0 TO SIGN OUT]: ";
                    cin >> choice;

                    system("cls");
                    studentHeader();
                    cout << endl;

                    // Go back to previous page
                    if(choice == 0)
                        goto studMenu;

                    if(choice == 1 && LOS == 'A')       // Shows Summary of The Chosen Pre-U Applicant
                    {
                        acad[index].displayDetails();
                    }
                    else if(choice == 1 && LOS == 'B')  // Shows Summary of The Chosen Degree Applicant
                    {
                        UGacad[index].displayDetails();
                    }
                    else if(choice == 2 && LOS == 'A')  // Shows Application Status of The Chosen Pre-U Applicant
                    {
                        acad[index].getApp()->showStatus();
                    }
                    else if(choice == 2 && LOS == 'B')  // Shows Application Status of The Chosen Degree Applicant
                    {
                        UGacad[index].getApp()->showStatus();
                    }

                    cout << endl;
                    system("pause");
                    system("cls");
                    goto applicantMenu;
                    break; // End of case 3
            } // End of Nested Switch

            system("pause");
            goto studMenu;
            break; // End of Applicant Menu
    } // End of Main Switch

    delete [] S;
    delete [] UGS;
    delete [] app;
    delete [] acad;
    delete [] UGacad;
    return 0;
}