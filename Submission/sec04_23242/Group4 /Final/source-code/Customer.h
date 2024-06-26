#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Bill.h"
#include <iostream>
#include <iomanip>

class Customer{
private:
    string name;              // Name of the customer
    string phone;             // Phone number of the customer
    Bill *bill;               // Pointer to a Bill object associated with the customer[Aggregation]
    double estimatedBudget;   // Estimated budget of the customer

public:
    // Constructors and Destructor
    Customer(string, string, double);     // Parameterized constructor
    Customer();                          // Default constructor
    Customer(const Customer& other);     // Copy constructor
    Customer& operator=(const Customer& other);  // Assignment operator
    ~Customer();                         // Destructor

    // Accessor methods
    string getname() const;               // Get the name of the customer
    string getphone() const;              // Get the phone number of the customer
    double getEstimatedBudget() const;    // Get the estimated budget of the customer

    // Mutators methods
    void setBill(Bill *b);                // Set the Bill object associated with the customer
    void setname(string n);               // Set the name of the customer
    void setphone(string p);              // Set the phone number of the customer
    void setEstimatedBudget(double budget);  // Set the estimated budget of the customer

    // Friend functions
    friend ostream& operator<<(ostream&, Customer);  // Overloaded insertion operator to print customer details
    friend void writeFile(Customer);                 // Function to write customer details to file
};

#endif // CUSTOMER_H