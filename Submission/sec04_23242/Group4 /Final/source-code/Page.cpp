#include "Page.h"
#include "Customer.h"
#include "Bill.h"
#include <limits>


void Page::errorCheck(int &choice, int start, int end)
{
    bool repeat = true;
    while (repeat) {
        if (cin.fail() || choice < start || choice > end) {
            cin.clear(); // clear the error flag

            // Read and discard all characters from the input buffer until a newline is encountered
            while (cin.get() != '\n')
                continue;

            cout << "\nInvalid input, please enter a valid choice number ";
            cin >> choice;
        } else {
            repeat = false;
        }
    }
}

int Page::page1() {
    int choice1;
    cout << "\n";
    cout << " \t|| SHOP GROCERY ASSISTANT || \n";
    cout << " --------------------------------------- \n\n";
    cout << "\n 1.) Customer \n 2.) Admin \n 3.) Read me \n 4.) EXIT \nPlease Enter this(1/2/3/4): ";
    cin >> choice1;

    errorCheck(choice1, 1, 4);
    system("cls");
    return choice1;
}

Customer Page::page2() {
    string custName, phoneNum;
    double estimatedBudget;

    cin.ignore();
    cout << " Name : ";
    getline(cin, custName);

    cout << " Phone Number : ";
    cin >> phoneNum;

    cout << " Enter your estimated budget (in RM): ";
    cin >> estimatedBudget;

    system("cls");
    return Customer(custName, phoneNum, estimatedBudget);
}

int Page::page3() {
    int choice2;
    cout << " 1.) Buy \n"
    << " 2.) Exit \n"
    << "Enter your choice : ";
    cin >> choice2;
    errorCheck(choice2, 1, 2);
    system("cls");
    return choice2;
}

int Page::page4() {
    int choice3;

    cout << "WELCOME TO GROCERY \n"
     << " 1.) VEGETABLE \n"
     << " 2.) FRUIT \n"
     << " 3.) MEAT \n"
     << " 4.) BACK \n"
     << "Enter your choice : ";
    cin >> choice3;

    errorCheck(choice3, 1, 4);
    system("cls");
    return choice3;
}

int Page::pagex(){
    int choice4;
    cout << "11.) BACK \n";
    cout << "Enter your choice : ";
    cin >> choice4;

    errorCheck(choice4, 1, 11);
    return choice4;
}


void Page::page5(Menu &a,Bill &bill,Customer &customer) {
    int choice5;
    cout << "Quantity [1 kg per pack]: ";
    cin >> choice5;
    a.setCount(a.getCount() + choice5);

    string itemName = a.getName();
    double itemPrice = a.getPrice() * choice5;

    system("cls");
    cout<<"Your Cart :\n";
    bill.addToCart(a);
    double totalBill = bill.total();
    double remainingBudget = customer.getEstimatedBudget() - totalBill;
    cout << bill; 
    cout << "Remaining Budget: RM " << fixed << setprecision(2) << remainingBudget << endl;

}

void Page::page6(Bill b, Customer c) {
    double pay, total = b.total();

    cout << "Total: RM " << fixed << setprecision(2) << total << endl;
    cout << "Pay: RM ";
    cin >> pay;
    system("cls");
    if (pay == total)
    {  
        cout << "Thanks for your purchase" << endl;
        cout << c;
    }
    else if (pay < total)
    {       
        cout << "Payment insufficient, please pay sufficient amount" << endl << endl;
        page6(b, c);  
    }     
    else 
    {
        double change = pay - total;
        cout << "Here's your change RM " << change << " , thank you for your purchase" << endl;
        cout << c;
    }
}

void Page::page7(){
    ifstream manualFile("UserManual.txt"); 
    
    if (manualFile.is_open()) {
        string line;
        while (getline(manualFile, line)) { 
            cout << line << endl;
        }
        manualFile.close(); 
    } else {
        cout << "Unable to open UserManual.txt" << endl; 
    }

}


