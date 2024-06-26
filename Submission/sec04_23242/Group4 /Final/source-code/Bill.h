#ifndef BILL_H
#define BILL_H
#include "Menu.h"
#include <iomanip>
#include <iostream>

class Bill{
    protected:
        Menu menu[100];     // Array of Menu objects representing items in the bill[Composition]
        int size;           // Current size of the bill (number of items)
        int totCount;       // Total count of items in the bill
        double sum = 0;     // Total sum of prices of items in the bill
    
    public:
    Bill();                         // Default constructor
    void addToCart(Menu a);         // Method to add a Menu item to the bill
    double total();                 // Method to calculate the total sum of the bill
    // Accessors
    int getSize();                  // Method to get the current size of the bill
    int getTotalItems();            // Method to get the total count of items in the bill

    friend ostream& operator<<(ostream &out, Bill b);  // Overloaded insertion operator to print bill details
};


#endif