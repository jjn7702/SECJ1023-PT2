#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#define SIZE 3
using namespace std;
class Menu {
protected:
    string name;     
    double price;    
    int count;       

public:
    // Constructors
    Menu();                      // Default constructor
    Menu(string n, double p);    // Parameterized constructor

    // Accessors
    string getName();   // Get the name of the menu item
    double getPrice();  // Get the price of the menu item
    int getCount();     // Get the count of the menu item

    // Mutators
    void setCount(int);   // Set the count of the menu item
    void setName(string n);
    void setPrice(double p);
    // Virtual method to display the menu item (to be overridden by derived classes)
    // This method demonstrates polymorphism, allowing derived classes (Vegetable, Fruit, Meat)
    // to provide specialized implementations while being accessed through a common interface (Menu).
    virtual void displayMenu();
};

// Derived class Vegetable, inherits from Menu
class Vegetable : public Menu {
private:
    string type;    // Type of vegetable (e.g., spinach, carrot)

public:
    // Constructors
    Vegetable(string n = " ", double p = 0.0);   // Default and parameterized constructors

    // Overridden method to display vegetable-specific menu item
    void displayMenu();
};

// Derived class Fruit, inherits from Menu
class Fruit : public Menu {
private:
    string type;    // Type of fruit (e.g., apple, banana)

public:
    // Constructors
    Fruit(string n = "", double p = 0.00);   // Default and parameterized constructors

    // Overridden method to display fruit-specific menu item
    void displayMenu();
};
// Derived class Meat, inherits from Menu
class Meat : public Menu {
private:
    string type;    // Type of meat (e.g., chicken, beef)

public:
    // Constructors
    Meat(string n = "", double p = 0.00);   // Default and parameterized constructors

    // Overridden method to display meat-specific menu item
    void displayMenu();
};


#endif