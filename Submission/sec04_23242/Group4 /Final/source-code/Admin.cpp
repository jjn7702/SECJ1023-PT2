#include "Admin.h"
using namespace std;

// Constructor implementation
Admin::Admin(string n, string p): username(n), passcode(p) {}

// Accessor implementations
string Admin::getUsername() const {
    return username;
}

string Admin::getPasscode() const {
    return passcode;
}

// Mutator implementations
void Admin::setUsername(const string &n) {
    username = n;
}

void Admin::setPasscode(const string &p) {
    passcode = p;
}

// Method to check the admin's credentials; takes username,
bool Admin::adminCheckUsername(string n, string cn, int &i) {
    i++;
    if (i == 6)
    {
        cout << "Input tries exceeded, exiting to previous page" << endl;
        return false;
    }

    if (n != cn)
    {
        cout << "Input wrong, try again" << endl;
        cout << "Username:" << endl;
        getline(cin, n);
        return adminCheckUsername(n, cn, i);
    }

    return true;
}
// Method to check the admin's credentials; takes passcode,
bool Admin::adminCheckPasscode(string n, string cn, int &i) {
    i++;
    if (i == 6)
    {
        cout << "Input tries exceeded, exiting to previous page" << endl;
        return false;
    }

    if (n != cn)
    {
        cout << "Input wrong, try again" << endl;
        cout << "Passcode:" << endl;
        getline(cin, n);
        return adminCheckPasscode(n, cn, i);
    }

    return true;
}



// Method representing the first admin page; returns true for next page and false for previous page
bool Admin::adminPage1()
{
    string n;
    string p;
    int test = 0;
    
    cout << "Username: ";
    cin.ignore();
    getline(cin, n);

    if (!adminCheckUsername(n, username, test))
    return false;
    

    test = 0;
    cout << "Passcode: ";
    getline(cin, p);
    if (!adminCheckPasscode(p, passcode, test))
    return false;

    return true;
}

// Method representing the second admin page
void Admin::adminPage2()
{
    string name;
    cout << "Customer name: ";
    getline(cin, name);

    for (int i = 0; i < name.length(); i++)
        name[i] = tolower(name[i]);

    name += ".txt";

    try {
        ifstream in(name);
        if (!in)
        {
            throw runtime_error("File not found");
        }
        else
        {
            cout << "Customer Receipt:" << endl;
            cout << "-----------------" << endl;

            string temp;
            while (getline(in, temp))
            {
                cout << temp << endl; // Print each line
            }

            in.close();
        }
    } catch (const exception& e) {
        cout << "Exception caught in adminPage2(): " << e.what() << endl;
    }
}
void Admin::addMenuItem(Menu* menuItem) {
    menuItems.push_back(menuItem);
}

// New function to display all menu items
void Admin::displayAllMenuItems() const {
    cout << "All Menu Items:" << endl;

    // Separate containers for each type
    vector<Menu*> vegetables;
    vector<Menu*> fruits;
    vector<Menu*> meats;

    // Categorize menu items
    for (vector<Menu*>::const_iterator it = menuItems.begin(); it != menuItems.end(); ++it) {
        Menu* item = *it;
        if (dynamic_cast<Vegetable*>(item)) {
            vegetables.push_back(item);
        } else if (dynamic_cast<Fruit*>(item)) {
            fruits.push_back(item);
        } else if (dynamic_cast<Meat*>(item)) {
            meats.push_back(item);
        }
    }

    // Display Vegetables
    cout << "\nVegetables:" << endl;
    for (vector<Menu*>::const_iterator it = vegetables.begin(); it != vegetables.end(); ++it) {
        Vegetable* veg = dynamic_cast<Vegetable*>(*it);
        if (veg) {
            cout << setw(15) << left << veg->getName() << setw(8) << right << "RM" << fixed << setprecision(2) << veg->getPrice() << endl;
        }
    }

    // Display Fruits
    cout << "\nFruits:" << endl;
    for (vector<Menu*>::const_iterator it = fruits.begin(); it != fruits.end(); ++it) {
        Fruit* fruit = dynamic_cast<Fruit*>(*it);
        if (fruit) {
            cout << setw(15) << left << fruit->getName() << setw(8) << right << "RM" << fixed << setprecision(2) << fruit->getPrice() << endl;
        }
    }

    // Display Meats
    cout << "\nMeats:" << endl;
    for (vector<Menu*>::const_iterator it = meats.begin(); it != meats.end(); ++it) {
        Meat* meat = dynamic_cast<Meat*>(*it);
        if (meat) {
            cout << setw(15) << left << meat->getName() << setw(8) << right << "RM" << fixed << setprecision(2) << meat->getPrice() << endl;
        }
    }
}


void Admin::addMenuItemThroughInput() {
    string name;
    double price;
    int type;

    cout << "Enter item type (1: Vegetable, 2: Fruit, 3: Meat): ";
    cin >> type;
    cin.ignore();

    cout << "Enter item name: ";
    getline(cin, name);

    cout << "Enter item price: ";
    cin >> price;

    Menu* menuItem = nullptr;
    switch (type) {
        case 1:
            menuItem = new Vegetable(name, price);
            break;
        case 2:
            menuItem = new Fruit(name, price);
            break;
        case 3:
            menuItem = new Meat(name, price);
            break;
        default:
            cout << "Invalid type selected." << endl;
            return;
    }

    addMenuItem(menuItem);
    cout << "Item added successfully." << endl;
}