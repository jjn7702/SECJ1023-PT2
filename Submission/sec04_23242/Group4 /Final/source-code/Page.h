#ifndef PAGE_H
#define PAGE_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Customer.h"
#include "Bill.h"
using namespace std;

class Page{

    public:
     void errorCheck(int &, int, int); // Function to perform input validation
    int page1(); // Function for page 1
    Customer page2(); // Function for page 2
    int page3(); // Function for page 3
    int page4(); // Function for page 4
    int pagex(); // Function for page x
    void page5(Menu &,Bill &,Customer&); // Function for page 5
    void page6(Bill, Customer); // Function for page 6
    void page7(); // Function for page 7
    

};


#endif
