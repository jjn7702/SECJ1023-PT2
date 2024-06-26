#ifndef ADMIN_H
#define  ADMIN_H
#include<vector>
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include"Menu.h"
using namespace std;

class Admin {
private:
    string username;
    string passcode;
    vector<Menu*> menuItems; // Vector of pointers to Menu objects representing items in the Admin class (Composition)


public:
    // Constructor
    Admin(string n = "", string p = "");

    // Accessors
    string getUsername() const;
    string getPasscode() const;

    // Mutators
    void setUsername(const string &n);
    void setPasscode(const string &p);

    // Methods
    bool adminCheckUsername(string, string, int &);
    bool adminCheckPasscode(string, string, int &);
    bool adminPage1(); // true = next page, false = back to prev page
    void adminPage2();
    void addMenuItem(Menu* menuItem);  
    void displayAllMenuItems() const;
    void addMenuItemThroughInput();

};

#endif // ADMIN_H
