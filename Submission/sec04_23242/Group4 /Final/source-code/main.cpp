#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <limits>
#include "Customer.h"
#include "Page.h"
#include "Menu.h"
#include "Admin.h"
using namespace std;
#define size 10
#define MAX_CUSTOMERS 100

void getCustNames(Customer cust[])
{
    ifstream in("CustomerNames.txt");

    string name, phone;
    double budget;
    int i = 0;
    while (!in.eof())
    {
        getline(in, name);
        getline(in, phone);
        in >> budget;
        in.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore the rest of the line after reading budget
        cust[i++] = Customer(name, phone, budget);    
    }
    in.close();
}

Customer custChoice(Customer CustomerList[], Page p)
{
    cout << "List of Previous Customers: " << endl;
    if (CustomerList[0].getname() != "")
    {
        for (int i = 0; i < MAX_CUSTOMERS; i++)
        {
            if (CustomerList[i].getname() != "")
                cout << i + 1 << ". " << CustomerList[i].getname() << endl;
        }
    }

    int choice;
    cout << "Existing Customer [ENTER THE NUMBER ACCORDING TO THE LIST]" << endl
         << "New Customer [ENTER 0]" << endl
         <<"Enter your choice :";
    cin >> choice;
    p.errorCheck(choice, 0, MAX_CUSTOMERS);
    system("cls");

    if (choice == 0)
    {
        Customer temp = p.page2();
        string tempname = temp.getname() + ".txt";
        ofstream out(tempname);
        out << temp.getname() << endl
            << temp.getphone() << endl
            << temp.getEstimatedBudget() << endl << endl;
        out.close();

        for (int i = 0; i < MAX_CUSTOMERS; i++)
        {
            if (CustomerList[i].getname() == "")
            {
                CustomerList[i] = temp;
                return temp;
            }
        }
    }
    else if (choice > 0 && choice <= MAX_CUSTOMERS)
    {
        Customer existingCustomer = CustomerList[choice - 1];
        double newBudget;
        bool validInput = false;
         while (!validInput)
        {
            cout << "Enter new budget: ";
            cin >> newBudget;

            // Validate input
            if (cin.fail() || newBudget <= 0)
            {
                cout << "Invalid input. Budget must be a positive number." << endl;
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            }
            else
            {
                validInput = true; 
            }
        }
        existingCustomer.setEstimatedBudget(newBudget);
        CustomerList[choice - 1] = existingCustomer; 

        string tempname = existingCustomer.getname() + ".txt";
        ofstream out(tempname, ios::app);
        out << existingCustomer.getname() << endl
            << existingCustomer.getphone() << endl
            << existingCustomer.getEstimatedBudget() << endl << endl;
        out.close();

        return existingCustomer;
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return Customer(); 
}
void writeFile(Customer a) 
{
    string tempName = a.getname() + ".txt";
    ofstream out(tempName, ios::app);
    out << endl << endl << "Number of Items: " << a.bill->getTotalItems() << endl;
    out << "------------------------------------------------------------------" << endl;
    out << *(a.bill) << endl << endl;
    double remainingBudget = a.getEstimatedBudget() - a.bill->total();
    out << "------------------------------------------------------------------" << endl;
    out << setw(40) << right << "Remaining Budget (RM)" << ": " << fixed << setprecision(2) << remainingBudget << endl;
    out << "------------------------------------------------------------------" << endl;
    out.close();
}

void writeFile(Customer c[]) //for rewriting the CustomerNames.txt file with new names if any
{
    ofstream out("CustomerNames.txt");
    for (int i = 0; i < MAX_CUSTOMERS; i++)
    {
        if (c[i].getname() != "")
        {
            out << c[i].getname() << endl;
            out << c[i].getphone() << endl;
            out << c[i].getEstimatedBudget() << endl;
        }
    }

    out.close();
}

int main() 
{
    Customer CustomerList[MAX_CUSTOMERS];
    getCustNames(CustomerList);

    Customer me;
    Admin admin("Jay","2024");
    //Array of objects
    vector<Vegetable> v = {
        Vegetable("potato", 3), Vegetable("tomato", 4), Vegetable("carrot", 5), Vegetable("Artichoke", 6),
        Vegetable("Corn", 3.5), Vegetable("Mushroom", 10), Vegetable("Potato", 3), Vegetable("Spinach", 4),
        Vegetable("Kale", 4), Vegetable("Yam", 4)
    };

    vector<Fruit> f = {
        Fruit("Apple", 4), Fruit("Orange", 5), Fruit("Lemon", 3), Fruit("Banana", 2), Fruit("Dragonfruit", 15),
        Fruit("Kiwi", 3.5), Fruit("Mango", 6), Fruit("Orange", 2.5), Fruit("Watermelon", 10), Fruit("Rambutan", 7)
    };

    vector<Meat> m = {
        Meat("Chicken", 7), Meat("Beef", 8), Meat("Lamb", 9), Meat("Turkey", 30), Meat("Lobster", 60),
        Meat("Oyster", 25), Meat("Sausages", 18), Meat("Salami", 40), Meat("Fish", 20), Meat("Crab", 40)
    };
    Bill b;
    Page p;
    int typecount;

    int choice1;
    
     choice1 = p.page1();
   
    
    if (choice1 == 1) {
        me = custChoice(CustomerList, p);

        head:
            int choice2 = p.page3();
            char choice5;

    if (choice2 == 1) {
        haha:
        do {  
            int choice3 = p.page4();
            p.errorCheck(choice3, 1, 4);
            switch (choice3) {
                case 1:
                    for (int i = 0; i < size; i++) {
                        cout << i + 1 << ".) ";
                        v[i].displayMenu();
                        typecount = 1;                        
                    }
                    break;

                case 2:
                    for (int i = 0; i < size; i++) {
                        cout << i + 1 << ".) ";
                        f[i].displayMenu();
                        typecount = 2;                      
                    }
                    break;

                case 3:
                    for (int i = 0; i < size; i++) {
                        cout << i + 1 << ".) ";
                        m[i].displayMenu();
                        typecount = 3;                        
                    }
                    break;
                
                case 4:
                    goto head;
                    
            }

        

            int choicex = p.pagex()-1;

            for (int i = 0; i < 10; i++) {
                if (choicex == i) {
                    Menu temp1 = v[choicex];
                    Menu temp2 = f[choicex];
                    Menu temp3 = m[choicex];
                    switch (typecount) {
                        case 1:
                            p.page5(temp1,b,me);
                            b.addToCart(temp1);
                            break;

                        case 2:
                            p.page5(temp2,b,me);
                            b.addToCart(temp2);
                            break;
                        
                        case 3:
                            p.page5(temp3,b,me);
                            b.addToCart(temp3);
                            break;
                    
                    }
                }
            }
            if (choicex == 10) {
                system("cls");
                goto haha;    
            }

            do {
                cout << "ORDER MORE (Y|N)? ";
                cin >> choice5;
                choice5 = tolower(choice5); 

                if (choice5 != 'y' && choice5 != 'n') {
                    cout << "Invalid input. Please enter 'Y' or 'N'." << endl;
                }
               } while (choice5 != 'y' && choice5 != 'n');

        system("cls");

            } while (tolower(choice5) == 'y');
            
            me.setBill(&b);
            cout << "-------------------------Payment Pending------------------------" << endl;
        
            writeFile(me);
            writeFile(CustomerList);
            p.page6(b, me);
            

        } else {
        p.errorCheck(choice2, 1, 2);
    }


    }
    else if(choice1 ==2)
    {
         cout << "\n=== Admin Login ===" << endl;
    if (admin.adminPage1()) {
        cout << "Access granted to admin page 2." << endl;

        // Adding pre-created menu items
        for (vector<Vegetable>::iterator it = v.begin(); it != v.end(); ++it) {
            admin.addMenuItem(new Vegetable(*it));  // Using the copy constructor
        }

        for (vector<Fruit>::iterator it = f.begin(); it != f.end(); ++it) {
            admin.addMenuItem(new Fruit(*it));  // Using the copy constructor
        }

        for (vector<Meat>::iterator it = m.begin(); it != m.end(); ++it) {
            admin.addMenuItem(new Meat(*it));  // Using the copy constructor
        }

        int choice;
        do {
            cout << "\nAdmin Menu:\n";
            cout << "1. Add Menu Item\n";
            cout << "2. Display All Menu Items\n";
            cout << "3. Check customer file\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            system("cls");

            cin.ignore();

            switch (choice) {
                case 1:
                    admin.addMenuItemThroughInput();
                    break;
                case 2:
                    admin.displayAllMenuItems();
                    break;
                case 3:
                    admin.adminPage2();
                    break;
                case 4:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
                    break;
            }
        } while (choice != 4);
    }
    else {
        cout << "Access denied." << endl;
    }
}

    else if(choice1 == 3){
    p.page7();
    }else{
    p.errorCheck(choice1, 1, 4);
    }

    
    system("pause");
}