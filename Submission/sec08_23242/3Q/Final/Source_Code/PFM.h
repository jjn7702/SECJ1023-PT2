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
