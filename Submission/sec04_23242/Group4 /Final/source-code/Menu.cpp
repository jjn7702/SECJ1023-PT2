#include "Menu.h"
using namespace std;

Menu :: Menu(): name(""), price(0), count(0){}
Menu :: Menu(string n, double p): name(n), price(p) {count = 0;}

//Accessors
string Menu:: getName(){return name;}
double Menu:: getPrice(){return price;}
int Menu:: getCount(){return count;}

//Mutators
void Menu:: setCount(int c){count = c;}
void Menu::setName(string n) { name = n; }
void Menu::setPrice(double p) { price = p; }
//Member Functions
void Menu:: displayMenu(){   //output format
    cout << name << "\tRM" << fixed << setprecision(2) << price << endl;
}

// Inheritance:
// Derived class Vegetable constructor, invoking base class Menu constructor
Vegetable::Vegetable(string n, double p) : Menu(n, p) {}

// Override displayMenu() method in Vegetable class
void Vegetable::displayMenu() {
    Menu::displayMenu(); // Invoke base class displayMenu() to output Vegetable details
}

// Derived class Fruit constructor, invoking base class Menu constructor
Fruit::Fruit(string n, double p) : Menu(n, p) {}

// Override displayMenu() method in Fruit class
void Fruit::displayMenu() {
    Menu::displayMenu(); // Invoke base class displayMenu() to output Fruit details
}

// Derived class Meat constructor, invoking base class Menu constructor
Meat::Meat(string n, double p) : Menu(n, p) {}

// Override displayMenu() method in Meat class
void Meat::displayMenu() {
    Menu::displayMenu(); // Invoke base class displayMenu() to output Meat details
}
