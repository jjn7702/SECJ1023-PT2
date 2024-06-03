#include "Admin.h"
#include "User.h"
#include <iostream>
#include <string>

using namespace std;

Admin :: Admin() : adminUsername(""), adminPassword("") {}

Admin :: Admin(string n, string p) : adminUsername(n), adminPassword(p) {}

void Admin :: resetPassword(User user[]) {
    string newP;
    int _id;
    cout << "Enter user ID: ";
    cin >> _id;
    for (int i = 0; i < 100; i++) {
        if (user[i].getID() == _id) {
            cout << "New password for user (" << user[i].getUsername() << "): ";
            cin >> newP;
            user[i].setPassword(newP);
            cout << "Password reset successfully." << endl;
            break;
        }
    }
}

void Admin :: removeUser(User user[], int &userCount) {
    int _id;
    cout << "Enter user ID: ";
    cin >> _id;
    for (int i = 0; i < userCount; i++) {
        if (user[i].getID() == _id) {
            user[i] = User();
            if (user[i].getUsername()!="")
                cout << "Unsuccessful"  << endl;
            cout << "User removed successfully." << endl;
            break;
        }
    }
    userCount--;
}

void Admin :: editUser(User user[]) {
    string newN;
    int _id;
    cout << "Enter user ID: ";
    cin >> _id;
    for (int i = 0; i < 100; i++) {
        if (user[i].getID() == _id) {
            cout << "New username for user (" << user[i].getUsername() << "): ";
            cin >> newN;
            user[i].setUsername(newN);
            cout << "User" << _id << " username are updated: " << endl
                 << "Username: " << user[i].getUsername() << endl;
            break;
        }
    }
}