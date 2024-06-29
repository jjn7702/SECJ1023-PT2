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
