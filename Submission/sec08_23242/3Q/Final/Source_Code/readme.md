# Interim_Source_Code
---
## Header File
```c++

#ifndef PFM_H
#define PFM_H

#include <string>
using namespace std;

class Expense {
    double spend;
    string date;
    string type;
public:
    Expense(double s = 0, string d = "", string t = "");
    double getSpend() const;
    string getDate() const;
    string getType() const;
    void setSpend(double s);
    void setDate(string d);
    void setType(string t);
};

class Name {
    string fname;
    string lname;
public:
    Name(string fn = "", string ln = "");
    string getfname();
    string getlname();
};

class Income {
protected:
    double amount;
    string source;
public:
    Income(double a = 0, string s = "");
    double getAmount() const;
    string getSource() const;
    void setAmount(double a);
    void setSource(string s);
    virtual void display() const;
};

class ActiveIncome : public Income {
    double salary;
    int otHour;
    double rate;
public:
    ActiveIncome(double s = 0, int o = 0, double r = 0, double a = 0.0, string src = "Active Income");
    double getSalary() const;
    int getHour() const;
    double getRate() const;
    void setSalary(double s);
    void setHour(int h);
    void setRate(double r);
    void calcAmount();
    void display() const override;
};

class PassiveIncome : public Income {
    string type;
public:
    PassiveIncome(double a = 0.0, string tp = "", string src = "Passive Income");
    string getType() const;
    void setType(string t);
    void setAmount(double a);
    void display() const override;
};

class Budget {
    double savingsGoal;
    double mFood;
    double mTransport;
    double mShopping;
    double mBills;
    double mEntertainment;
    double mHealthcare;
    double mEducation;
    double mGroceries;
    double mGift;
    double mOthers;
    Income *myIncome; //Aggregation
public:
    Budget(Income *inc = nullptr);
    void setIncome(Income *inc);
    void calcBudget();
    double getSavingsGoal();
    double getMoneyOnFood();
    double getMoneyOnTransport();
    double getMoneyOnShopping();
    double getMoneyOnBills();
    double getMoneyOnEntertainment();
    double getMoneyOnHealthcare();
    double getMoneyOnEducation();
    double getMoneyOnGroceries();
    double getMoneyOnGift();
    double getMoneyOnOthers();
    void printBudget() const;
};

class User {
    Name name; 
    Income *income; //Aggregation
    Expense *expense[100]; 
    int expenseCount;
public:
    User(Name n = Name());
    void setIncome(Income *inc);
    double getIncomeAmount() const;
    void addExpense(Expense *exp);
    void removeExpense(int index);
    int getExpenseCount() const;
    void dispUserName();
    void display() const;
    double getTotalExpensesByCategory(const string& category) const;
};

#endif // PMF_H

```
## Implementation File
```c++
#include "PFM.h"
#include <iostream>
#include <iomanip>

// Expense class member functions
Expense::Expense(double s, string d, string t) : spend(s), date(d), type(t) {}

double Expense::getSpend() const {
    return spend;
}
string Expense::getDate() const {
    return date;
}
string Expense::getType() const {
    return type;
}
void Expense::setSpend(double s) {
    spend = s;
}
void Expense::setDate(string d) {
    date = d;
}
void Expense::setType(string t) {
    type = t;
}

// Name class member functions
Name::Name(string fn, string ln): fname(fn), lname(ln) {}
string Name::getfname() {
    return fname;
}
string Name::getlname() {
    return lname;
}

// Income class member functions
Income::Income(double a, string s) : amount(a), source(s) {}
double Income::getAmount() const {
    return amount;
}
string Income::getSource() const {
    return source;
}
void Income::setAmount(double a) {
    amount = a;
}
void Income::setSource(string s) {
    source = s;
}
void Income::display() const {
    cout << "Your " << source << " is = RM " << amount << endl;
}

// ActiveIncome class member functions
ActiveIncome::ActiveIncome(double s, int o, double r, double a, string src)
    : Income(a, src), salary(s), otHour(o), rate(r) {}

double ActiveIncome::getSalary() const {
    return salary;
}
int ActiveIncome::getHour() const {
    return otHour;
}
double ActiveIncome::getRate() const {
    return rate;
}
void ActiveIncome::setSalary(double s) {
    salary = s;
}
void ActiveIncome::setHour(int h) {
    otHour = h;
}
void ActiveIncome::setRate(double r) {
    rate = r;
}
void ActiveIncome::calcAmount() {
    amount = salary + (otHour * rate);
}
void ActiveIncome::display() const {
    Income::display();
    cout << "Your basic salary is = RM " << salary << endl;
    cout << "You have worked for OT of " << otHour << " hours at the rate of RM " << rate << " per hour\n";
}

// PassiveIncome class member functions
PassiveIncome::PassiveIncome(double a, string tp, string src)
    : Income(a, src), type(tp) {}

string PassiveIncome::getType() const {
    return type;
}
void PassiveIncome::setType(string t) {
    type = t;
}
void PassiveIncome::setAmount(double a) {
    amount = a;
}
void PassiveIncome::display() const {
    cout << "Passive Income Type : " << type << endl;
    cout << "The amount is : RM " << amount << endl;
}

// Budget class member functions
Budget::Budget(Income *inc) 
    : myIncome(inc), savingsGoal(0), mFood(0), mTransport(0), mShopping(0),
      mBills(0), mEntertainment(0), mHealthcare(0), mEducation(0),
      mGroceries(0), mGift(0), mOthers(0) {}

void Budget::setIncome(Income *inc) {
    myIncome = inc;
}
void Budget::calcBudget() {
    if (myIncome != nullptr) {
        savingsGoal = 0.2 * myIncome->getAmount();
        mFood = 0.1 * myIncome->getAmount();
        mTransport = 0.1 * myIncome->getAmount();
        mShopping = 0.05 * myIncome->getAmount();
        mBills = 0.1 * myIncome->getAmount();
        mEntertainment = 0.1 * myIncome->getAmount();
        mHealthcare = 0.1 * myIncome->getAmount();
        mEducation = 0.05 * myIncome->getAmount();
        mGroceries = 0.1 * myIncome->getAmount();
        mGift = 0.05 * myIncome->getAmount();
        mOthers = 0.05 * myIncome->getAmount();
    }
}
double Budget::getSavingsGoal() {
    return savingsGoal;
}
double Budget::getMoneyOnFood() {
    return mFood;
}
double Budget::getMoneyOnTransport() {
    return mTransport;
}
double Budget::getMoneyOnShopping() {
    return mShopping;
}
double Budget::getMoneyOnBills() {
    return mBills;
}
double Budget::getMoneyOnEntertainment() {
    return mEntertainment;
}
double Budget::getMoneyOnHealthcare() {
    return mHealthcare;
}
double Budget::getMoneyOnEducation() {
    return mEducation;
}
double Budget::getMoneyOnGroceries() {
    return mGroceries;
}
double Budget::getMoneyOnGift() {
    return mGift;
}
double Budget::getMoneyOnOthers() {
    return mOthers;
}
void Budget::printBudget() const {
    cout << "Budget Summary:" << endl;
    cout << "Savings Goal: RM " << savingsGoal << endl;
    cout << "Money on Food: RM " << mFood << endl;
    cout << "Money on Transport: RM " << mTransport << endl;
    cout << "Money on Shopping: RM " << mShopping << endl;
    cout << "Money on Bills: RM " << mBills << endl;
    cout << "Money on Entertainment: RM " << mEntertainment << endl;
    cout << "Money on Healthcare: RM " << mHealthcare << endl;
    cout << "Money on Education: RM " << mEducation << endl;
    cout << "Money on Groceries: RM " << mGroceries << endl;
    cout << "Money on Gift: RM " << mGift << endl;
    cout << "Money on Others: RM " << mOthers << endl << endl;
}

// User class member functions
User::User(Name n) : expenseCount(0), name(n) {}

void User::setIncome(Income *inc) {
    income = inc;
}
double User::getIncomeAmount() const {
    if (income != nullptr)
        return income->getAmount();
    else
        return 0.0;
}
void User::addExpense(Expense* exp) {
    if (expenseCount < 100) {
        expense[expenseCount++] = exp;
    } else {
        cout << "Expense limit reached!" << endl;
    }
}
void User::removeExpense(int index) {
    if (index < 0 || index >= expenseCount) {
        cout << "Invalid expense index!" << endl;
        return;
    }
    for (int i = index; i < expenseCount - 1; ++i) {
        expense[i] = expense[i + 1];
    }
    expense[--expenseCount] = nullptr;
}
int User::getExpenseCount() const {
    return expenseCount;
}
void User::dispUserName() {
    cout << name.getfname() << " " << name.getlname() << endl;
}
void User::display() const {
    cout << left << setw(5) << "No." << setw(20) << "Type" << setw(10) << "Amount" << setw(15) << "Date" << endl;
    for (int i = 0; i < getExpenseCount(); i++) {
        cout << left << setw(5) << i + 1
             << setw(20) << expense[i]->getType()
             << setw(10) << expense[i]->getSpend()
             << setw(15) << expense[i]->getDate() << endl;
    }
}
double User::getTotalExpensesByCategory(const string& category) const {
    double total = 0;
    for (int i = 0; i < expenseCount; ++i) {
        if (expense[i]->getType() == category) {
            total += expense[i]->getSpend();
        }
    }
    return total;
}

```
## Application File
```c++
#include "PFM.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <fstream>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void login( bool &);
void registration();
void forgot();
const int  BLUE=1;
const int  GREEN=2;
const int  RED=4;
const int  WHITE=15;
const int  YELLOW=14;

void clearScreen(int charlength){
    for(int i=0;i<charlength;i++)
        cout<<"\b";
}

void changeColour(int Colour){
    HANDLE hConsole;
    hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, Colour);
}

void showLoadingScreen(){
    int i;
    string closed="- - -", open="* * *";
    int colour[]={RED, GREEN, BLUE};
    cout<<closed;

    for(i=0;i<2;i++){
        Sleep(1000);
        clearScreen(5);
        changeColour(colour[i]);

        cout<<open;
        Sleep(1000);
        clearScreen(5);
        changeColour(WHITE);

        cout<<closed;
        
    }
    clearScreen(5);
    changeColour(WHITE);
}

void showBlinkingLight(){
    changeColour(GREEN);
    cout<<"Welcome ";
    Sleep(1000);

    cout<<"to ";
    Sleep(1000);

    cout<<"the ";
    Sleep(1000);

    cout<<"login page";
    Sleep(1000);

    changeColour(WHITE);
}

void clearScreen() {
    cout << string(100, '\n');
}

// Function to print the main menu
void printMainMenu() {
    cout << "Main Menu:" << endl;
    cout << "1. Edit Income" << endl;
    cout << "2. Enter Expenses" << endl;
    cout << "3. Calculate and Print Budget" << endl;
    cout << "4. Print Overall Report" << endl;
    cout << "5. Remove expenses" << endl;
    //cout << "6. Exit the Program" << endl;
    cout << "Enter your choice: ";
}

// Function to print the income menu
void printIncomeMenu() {
    cout << "Income Menu:" << endl;
    cout << "1. Enter Active Income" << endl;
    cout << "2. Enter Passive Income" << endl;
    cout << "Enter your choice: ";
}

// Function to print the expense menu
void printExpenseMenu() {
    cout << "Expense Menu:" << endl;
    cout << "1. Food" << endl;
    cout << "2. Transport" << endl;
    cout << "3. Shopping" << endl;
    cout << "4. Bills" << endl;
    cout << "5. Entertainment" << endl;
    cout << "6. Healthcare" << endl;
    cout << "7. Education" << endl;
    cout << "8. Groceries" << endl;
    cout << "9. Gift" << endl;
    cout << "10. Others" << endl;
    cout << "Enter your choice: ";
}

double totalIncome(ActiveIncome& actInc, double pasInc) {
    double total = actInc.getAmount() + pasInc;
    return total;
}

void readActive(ActiveIncome &actI, User &u){
    double salary, rate;
    int otHours;
    do{
    cout << "Enter salary         : ";
    cin >> salary;
    cout << "Enter overtime hours : ";
    cin >> otHours;
    cout << "Enter overtime rate  : ";
    cin >> rate;
    cout << endl;
    actI.setSalary(salary);
    actI.setHour(otHours);
    actI.setRate(rate);
    actI.calcAmount();

     if(actI.getAmount()<=0){
       cout << "***Please re-enter your active income and make sure it is more than 0***\n\n";
    }

    }while (actI.getAmount()<=0);

    u.setIncome(&actI);


}

void readPassive(PassiveIncome pasI[], User &u, int &count, double &total){
    string type="";
    double value;
    char input;

    do{
        cout << "What is the passive income type : ";
        cin >> type;
        cout << "Enter passive income amount     : ";
        cin >> value; 

        while(value<=0){
            cout << "***Please re-enter your passive income and make sure it is more than 0***\n\n";
            cout << "Enter passive income amount     : ";
            cin >> value; 
        }

        pasI[count].setType(type);
        pasI[count].setAmount(value);
        count++;
        total+=value;
        clearScreen();
        cout << "Do you wish to continue entering your passive income? (press Y/y for yes) : ";
        cin >> input;
        cout << endl;
    }while(input == 'y' || input == 'Y');
}

bool isValidDateFormat(string& date) {
    // Check if the length is exactly 10
    if (date.size() != 10) {
        return false;
    }
    
    // Check if the 5th and 8th characters are '-'
    if (date[4] != '-' || date[7] != '-') {
        return false;
    }
    // Extract year, month, and day as integers
    int year, month, day;
    try {
        year = stoi(date.substr(0, 4));
        month = stoi(date.substr(5, 2));
        day = stoi(date.substr(8, 2));
    } 
    catch (exception& e) {
        return false; // If conversion fails, the format is incorrect
    }
    // Check valid ranges for month and day
    if (month < 1 || month > 12) {
        return false;
    }
    if (day < 1 || day > 31) {
        return false;
    }
    // Check days in each month (ignoring leap year for simplicity)
    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (day > daysInMonth[month - 1]) {
        return false;
    }
    // For February, check leap year
    if (month == 2 && day == 29) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return true; // Leap year
        } else {
            return false; // Not a leap year
        }
    }

    return true;
}

int main() {
    Income income;
    ActiveIncome activeIncome;
    PassiveIncome passiveIncome;
    PassiveIncome pasIncome[100]; //Array of Object
    Budget budget;
    int choice, incomeChoice, expenseChoice, passiveIncomeCount = 0; 
    double amount, value;
    double totalPassive = 0; 
    string date, category;
    double totalFoodExpenses = 0;
    double totalTransportExpenses = 0;
    double totalShoppingExpenses = 0;
    double totalBillsExpenses = 0;
    double totalEntertainmentExpenses = 0;
    double totalHealthcareExpenses = 0;
    double totalEducationExpenses = 0;
    double totalGroceriesExpenses = 0;
    double totalGiftExpenses = 0;
    double totalOtherExpenses = 0;
    int wrong = 0;
    double in;
    char input;
    int c;
    bool password = false;
    showLoadingScreen();
    A:
        do {
                cout << " _________________________________________\n";
                cout << "|                                         |\n";
                cout << "|     ***";showBlinkingLight();cout<<"***     |\n";
                cout << "#########-------------------------#########"<< endl;
                cout << "|                                         |\n";
                Sleep(1000);
                cout << "|_________        MENU        ____________|\n";
                Sleep(1000);
                cout << "|  Press 1 to ";changeColour(YELLOW);cout<<"LOGIN";changeColour(WHITE);cout<<"                       |" << endl;
                cout << "|  Press 2 to ";changeColour(BLUE);cout<<"REGISTER";changeColour(WHITE);cout<<"                    |" << endl;
                cout << "|  Press 3 if you forgot your ";changeColour(GREEN);cout<<"PASSWORD";changeColour(WHITE);cout<<"    |" << endl;
                cout << "|  Press 4 to ";changeColour(RED);cout<<"EXIT";changeColour(WHITE);cout<<"                        |" << endl;
                cout << " ------------------------------------------\n";
                Sleep(1000);
                cout << "\n Please enter your choice : ";
                cin >> c;
                cout << endl;

                switch (c)
                {
                    case 1:
                        login(password);
                        if(password==true){
                            forgot();
                            Sleep(1000);
                            clearScreen();
                            goto A;
                        }
                        else
                            break;
                    case 2:
                        registration();
                        login(password);
                        if(password==true){
                            forgot();
                            Sleep(1000);
                            clearScreen();
                            goto A;
                        }
                        break;
                    case 3:
                        forgot();
                        break;
                    case 4:
                        cout << "\t\t\t Thank you! \n\n\n";
                        exit(1);
                    default:
                        cout << " Please select a valid option from the menu \n" << endl;
                }
            } while( c<1 && c>4 || c==3 );
    clearScreen();
    cin.ignore();
    cout << "Enter first name   : ";
    string firstName;
    getline(cin, firstName);

    cout << "Enter last name    : ";
    string lastName;
    getline(cin, lastName);
    cout << endl;
    clearScreen();
    
    Name name(firstName, lastName);
    User user(name);

    
        cout << "Please enter your income : " << endl;
        printIncomeMenu(); 
        cin >> incomeChoice;
        cout << endl;
        clearScreen();
        if (incomeChoice == 1) {
            readActive(activeIncome, user);
            clearScreen();
        } 
        else if (incomeChoice == 2) {
            readPassive(pasIncome, user, passiveIncomeCount, totalPassive);
            clearScreen();
        }
        income.setAmount(totalIncome(activeIncome, totalPassive));
        user.setIncome(&income);
       

    
    cout << endl;

    do {
        cout << endl;
        printMainMenu();
        cin >> choice;
        cout << endl;
        
        switch (choice) {

        case 1:
            clearScreen();
            printIncomeMenu(); 
            cin >> incomeChoice;
            cout << endl;

            if (incomeChoice == 1) {
                readActive(activeIncome, user);
                clearScreen();
            } 

            else if (incomeChoice == 2) {
                readPassive(pasIncome, user, passiveIncomeCount, totalPassive);
                clearScreen();
            }

            income.setAmount(totalIncome(activeIncome, totalPassive));
            user.setIncome(&income);

            Sleep(1000);   
            break;

        case 2:
            
            do {
                clearScreen();
                printExpenseMenu();
                cin >> expenseChoice;
                cout << "Enter amount spent: ";
                cin >> value;
                do {
                    cout << "Enter date (YYYY-MM-DD): ";
                    cin >> date;
                    try {
                        if (isValidDateFormat(date) == false) {
                            throw "Invalid date format!\n";
                        }    
                    }
                    catch (const char *msg) {
                        cout << msg;
                    }
                } while (isValidDateFormat(date) == false);

                switch (expenseChoice) {
                case 1:
                    category = "Food";
                    totalFoodExpenses += value;
                    break;
                    clearScreen();
                case 2:
                    category = "Transport";
                    totalTransportExpenses += value;
                    break;
                    clearScreen();
                case 3:
                    category = "Shopping";
                    totalShoppingExpenses += value;
                    break;
                    clearScreen();
                case 4:
                    category = "Bills";
                    totalBillsExpenses += value;
                    break;
                    clearScreen();
                case 5:
                    category = "Entertainment";
                    totalEntertainmentExpenses += value;
                    break;
                    clearScreen();
                case 6:
                    category = "Healthcare";
                    totalHealthcareExpenses += value;
                    break;
                    clearScreen();
                case 7:
                    category = "Education";
                    totalEducationExpenses += value;
                    break;
                    clearScreen();
                case 8:
                    category = "Groceries";
                    totalGroceriesExpenses += value;
                    break;
                    clearScreen();
                case 9:
                    category = "Gift";
                    totalGiftExpenses += value;
                    break;
                    clearScreen();
                case 10:
                    category = "Others";
                    totalOtherExpenses += value;
                    break;
                    clearScreen();
                default:
                    cout << "Invalid category!" << endl;
                    continue;
                }
                cout << endl;
                
                user.addExpense(new Expense(value, date, category));
                clearScreen();
                cout << "Do you wish to continue entering your expenses? (press Y/y for yes) : ";
                cin >> input;
            } while (input == 'y' || input == 'Y');
            clearScreen();
            break;
            

        case 3:
            clearScreen();
            budget.setIncome(&income); 
            budget.calcBudget();

            // Recalculate expenses by category if expenses is removed
            totalFoodExpenses = budget.getMoneyOnFood() - user.getTotalExpensesByCategory("Food");
            totalTransportExpenses = budget.getMoneyOnTransport() - user.getTotalExpensesByCategory("Transport");
            totalShoppingExpenses = budget.getMoneyOnShopping() - user.getTotalExpensesByCategory("Shopping");
            totalBillsExpenses = budget.getMoneyOnBills() - user.getTotalExpensesByCategory("Bills");
            totalEntertainmentExpenses = budget.getMoneyOnEntertainment() - user.getTotalExpensesByCategory("Entertainment");
            totalHealthcareExpenses = budget.getMoneyOnHealthcare() - user.getTotalExpensesByCategory("Healthcare");
            totalEducationExpenses = budget.getMoneyOnEducation() - user.getTotalExpensesByCategory("Education");
            totalGroceriesExpenses = budget.getMoneyOnGroceries() - user.getTotalExpensesByCategory("Groceries");
            totalGiftExpenses = budget.getMoneyOnGift() - user.getTotalExpensesByCategory("Gift");
            totalOtherExpenses = budget.getMoneyOnOthers() - user.getTotalExpensesByCategory("Others");

            budget.printBudget();
            

            cout << "Remaining budget after expenses:" << endl;
            cout << "Savings: RM " << budget.getSavingsGoal() << endl;
            cout << "Food: RM " << totalFoodExpenses << endl;
            cout << "Transport: RM " << totalTransportExpenses << endl;
            cout << "Shopping: RM " << totalShoppingExpenses << endl;
            cout << "Bills: RM " << totalBillsExpenses << endl;
            cout << "Entertainment: RM " << totalEntertainmentExpenses << endl;
            cout << "Healthcare: RM " << totalHealthcareExpenses << endl;
            cout << "Education: RM " << totalEducationExpenses << endl;
            cout << "Groceries: RM " << totalGroceriesExpenses << endl;
            cout << "Gift: RM " << totalGiftExpenses << endl;
            cout << "Others: RM " << totalOtherExpenses << endl;
            cout << endl;
            break;
            

        case 4:
            clearScreen();
            cout << "----------------------------------------Overall Report----------------------------------------\n";
            cout << "Name: " ;
            user.dispUserName();
            activeIncome.display();
            cout << endl;

            for(int i = 0; i<passiveIncomeCount; i++){
                pasIncome[i].display();
            }

            cout << "Your total passive income is : RM " << totalPassive << endl;
            cout << "Your total income including active and passive income is = RM " << totalIncome(activeIncome, totalPassive) << endl;  
            cout << endl;
            cout << "Your Expenses\n";
            user.display();
            cout << "----------------------------------------End of Report----------------------------------------\n";
            
            break;
            
        
        case 5:
                clearScreen();
                user.display();
                cout << "Enter the index of expense to remove: ";
                int index;

                cin >> index;
                cout << endl;
                try {
                    if (index > 0 && index <= user.getExpenseCount()) {
                        user.removeExpense(index - 1); 
                        throw "Expense removed successfully.\n";
                    }
                    else 
                        throw "Invalid index.\n";    
                }
        
                catch (const char *msg) {
                    cout << msg;
                }
                Sleep(1000);
                clearScreen();
                break;
        default:
                clearScreen();
                wrong++;
                try{
                    if (wrong < 2) {
                    throw "Invalid choice. Please try again.\n";
                    
                }
                }
                catch (const char *msg){
                cout << msg << endl;
                
                }
        }
    } while ((choice >= 1 && choice <= 5) || wrong < 2);

    try{
        if (wrong >= 2) {
        throw "Invalid choice entered twice. Exiting program.\n" ; 
        }
    }
    catch (const char *msg){
        cout << msg << endl;
    }
    cout << endl;
    changeColour(BLUE);
    cout << "Thanks ";
    Sleep(1000);
    cout << "for ";
    Sleep(1000);
    cout << "using ";
    Sleep(1000);
    cout << "our ";
    Sleep(1000);
    cout << "system.";
    Sleep(1000);
    cout << "^v^" << endl;
    exit(0);
    changeColour(WHITE);
    clearScreen();

    system("pause");

    return 0;
}

void login(bool &p)  // Pass by reference to modify the flag
{
    int count = 0;
    string userId, password, id, pass;
    cout << " Please enter the ";changeColour(YELLOW);cout<<"username";changeColour(WHITE);cout<<" and ";changeColour(GREEN);cout<<"password : " << endl;
    changeColour(WHITE);
    cout << " USERNAME: ";
    cin >> userId;
    cout << " PASSWORD: ";
    

    char passChar[32]; // To store the password
    int i = 0;
    char a; // Temp char
    for (i = 0;;) // Infinite loop
    {
        a = getch(); // Stores char typed in a
        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
        {
            passChar[i] = a; // Stores a in passChar
            ++i;
            cout << "*";
        }
        if (a == '\b' && i >= 1) // If user typed backspace
        {
            cout << "\b \b"; // Rub the character behind the cursor
            --i;
        }
        if (a == '\r') // If enter is pressed
        {
            passChar[i] = '\0'; // Null means end of string
            break; // Break the loop
        }
    }
    password = string(passChar);

    ifstream input("records.txt");

    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            break;
        }
    }
    input.close();

    if (count == 1)
    {
        cout << "\n" << userId << "\n Your LOGIN is successful \n Thanks for logging in! \n";
        p = false;  // Reset the flag on successful login
    }
    else
    {
        p = true;  // Set the flag if login fails
        cout << "\n LOGIN ERROR \n Please check your username and password\n";
    }
    clearScreen();
}

void registration()
{
    string ruserId; //rpassword;
    cout << " Enter the username: ";
    cin >> ruserId;
    START:
        cout << " Enter the password: ";
        char pass[32];//to store password.
        int i = 0;
        char a;//a Temp char
        for(i=0;;)//infinite loop
        {
            a=getch();//stores char typed in a
            if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
                //check if a is numeric or alphabet
            {
                pass[i]=a;//stores a in pass
                ++i;
                cout<<"*";
            }
            if(a=='\b'&&i>=1)//if user typed backspace
                //i should be greater than 1.
            {
                cout<<"\b \b";//rub the character behind the cursor.
                --i;
            }
            if(a=='\r')//if enter is pressed
            {
                pass[i]='\0';//null means end of string.
                break;//break the loop
            }
        }
        //here we can even check for minimum digits needed
        if(i<=0)
        {
            cout<<"\nMinimum 6 digits needed.\nEnter Again\n";
            getch();//It was not pausing :p
            goto START;
        }

    ofstream f1("records.txt", ios::app);
    f1 << ruserId << " " << pass << endl;
    f1.close();
    cout << "\n Registration is successful! \n\n";
}

void forgot()
{
    int option;
    cout << " You forgot the password? No worries \n";
    cout << "Press 1 to search your ID by username " << endl;
    cout << "Press 2 to go to the main menu " << endl;
    cout << " Enter your choice: ";
    cin >> option;
    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserId, sId, spass;
        cout << " Enter the username which you remember: ";
        cin >> suserId;

        ifstream f2("records.txt");
        while (f2 >> sId >> spass)
        {
            if (sId == suserId)
            {
                count = 1;
                cout << "\n Your account is found \n";
                cout << " Your password is: " << spass << endl;
                Sleep(2000);
                break;
                clearScreen();
            }
        }
        f2.close();
        if (count == 0)
        {
            cout << " Sorry! Your account is not found! \n";
        }
        break;
        clearScreen();
    }
    case 2:
        break;
    default:
        cout << " Wrong choice! Please try again " << endl;
        forgot();
        clearScreen();
    }
}
```