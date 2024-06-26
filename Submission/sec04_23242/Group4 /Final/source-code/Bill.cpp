#include "Bill.h"
const int arrSize  = 100;

using namespace std;
// Constructor for Bill class
Bill::Bill(){
    size = 0;
    sum = 0;
    totCount = 0;
}

// Method to add items to the bill
void Bill :: addToCart(Menu a)
{
    for (int i = 0; i < size + 1; i++)
    {
        if (menu[i].getName() == a.getName() && menu[i].getName() != "")
        {
            menu[i].setCount(menu[i].getCount() + a.getCount());
            break;
        }

        else if (i == size)
        {
            menu[i] = a;
            menu[i].setCount(a.getCount());
            size++;
            break;
        }
    }
    totCount += a.getCount();
}

// Method to calculate total sum of bill
double Bill::total(){
    double sum=0;//
    for(int i = 0; i < size; i++){
        double subTotal = menu[i].getPrice() * menu[i].getCount();
        sum += subTotal;
    }

    return sum;
}

int Bill::getTotalItems() {return totCount;}

int Bill::getSize() {return size;}
// Overloaded stream insertion operator to print bill details
ostream& operator<< (ostream& out, Bill b)
{
     const int COLUMN_WIDTH_INDEX = 6;   
    const int COLUMN_WIDTH_NAME = 25;   
    const int COLUMN_WIDTH_COUNT = 10; 
    const int COLUMN_WIDTH_PRICE = 15;  
    const int COLUMN_WIDTH_TOTAL_UNIT_PRICE = 20;  
    const int COLUMN_WIDTH_TOTAL = 15;  

    out << left << fixed << setprecision(2);  

    out << setw(COLUMN_WIDTH_INDEX) << "No.";                     
    out << setw(COLUMN_WIDTH_NAME) << "Menu Item";                
    out << setw(COLUMN_WIDTH_COUNT) << "Count";                   
    out << setw(COLUMN_WIDTH_PRICE) << "Price (RM)";              
    out << setw(COLUMN_WIDTH_TOTAL_UNIT_PRICE) << "Total Unit Price (RM)";  
    out << endl;

    out << "-----------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < b.size; i++) {
        out << setw(COLUMN_WIDTH_INDEX) << (i + 1);                                       
        out << setw(COLUMN_WIDTH_NAME) << b.menu[i].getName();                           
        out << setw(COLUMN_WIDTH_COUNT) << b.menu[i].getCount();                          
        out << setw(COLUMN_WIDTH_PRICE) << b.menu[i].getPrice();                           
        out << setw(COLUMN_WIDTH_TOTAL_UNIT_PRICE) << b.menu[i].getCount() * b.menu[i].getPrice(); 
        out << endl;
    }

    out << "-----------------------------------------------------------------------------------------------------------------" << endl;

    out << setw(COLUMN_WIDTH_INDEX + COLUMN_WIDTH_NAME + COLUMN_WIDTH_COUNT) << "Total (RM): "; 
    out << setw(COLUMN_WIDTH_PRICE + COLUMN_WIDTH_TOTAL_UNIT_PRICE + COLUMN_WIDTH_TOTAL) << b.total(); 
    out << endl;

    out << "-----------------------------------------------------------------------------------------------------------------" << endl;
    return out;
}
    
