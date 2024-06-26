#include "Customer.h"
using namespace std;

//
Customer :: Customer(string name, string phone,double estimatedBudget){
    this->name = name; 
    this->phone = phone;
    this->estimatedBudget = estimatedBudget;
    this->bill = nullptr;
}

Customer::Customer(): name(""), phone(""), estimatedBudget(0.0),bill(nullptr) {}

// Copy Constructor
Customer::Customer(const Customer& other) : name(other.name), phone(other.phone), estimatedBudget(other.estimatedBudget) {
    if (other.bill) {
        bill = new Bill(*other.bill);
    } else {
        bill = nullptr;
    }
}

// Assignment Operator
Customer& Customer::operator=(const Customer& other) {
    if (this != &other) {
        name = other.name;
        phone = other.phone;
        estimatedBudget = other.estimatedBudget;
        delete bill;
        if (other.bill) {
        bill = new Bill(*other.bill);
    } else {
        bill = nullptr;
        }
    }
    return *this;
}

// Destructor
Customer::~Customer() {
    delete bill;
}

string Customer::getname() const { return name;}

string Customer::getphone()const { return phone; }

void Customer::setname(string n) { name = n;}

void Customer::setphone(string p){ phone = p;}   

void Customer::setBill(Bill *b){bill = b;} 
// Sets the Bill object associated with this Customer.The Customer now points to the Bill object provided as 'b'.


void Customer::setEstimatedBudget( double budget) {estimatedBudget = budget;}

double Customer::getEstimatedBudget() const { return estimatedBudget;}

ostream& operator<<(ostream &strm, Customer c){
   strm << "-----------------------------RECEIPT-----------------------------" << endl;
    strm << left << setw(15) << "Name" << ": " << c.name << endl;
    strm << left << setw(15) << "Phone Number" << ": " << c.phone << endl;
    strm << left << setw(15) << "Estimated Budget (RM)" << ": " << fixed << setprecision(2) << c.getEstimatedBudget() << endl;
    strm << "Number of Items: " << c.bill->getTotalItems() << endl;
    strm << "------------------------------------------------------------------" << endl << endl;
    strm << *(c.bill);
    double remainingBudget = c.getEstimatedBudget() - c.bill->total();
    strm << "------------------------------------------------------------------" << endl;
    strm << setw(40) << left << "Remaining Budget (RM)" << ": " << remainingBudget << endl;
    strm << "------------------------------------------------------------------" << endl;

if (c.bill->total() <= c.getEstimatedBudget())    {
        strm << "Congratulations! Your spending is within budget,\ngreat job managing your expenses!" << endl;
    }
else
    {
        strm << "Unfortunately, your spending has exceeded the budget.\nPlease review your expenses and adjust accordingly." << endl;
    }

    return strm;
} 