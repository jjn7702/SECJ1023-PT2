#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;

class User {
private:
    string username;
    string password;
public:
    User() : username(""), password("") {} // Default constructor

    void setUsername(string u) {
        username = u;
    }

    void setPassword(string p) {
        password = p;
    }

    string getUsername() const {
        return username;
    }

    string getPassword() const {
        return password;
    }

    void read() {
        cout << "Enter your username: ";
        getline(cin, username);
        cout << "Enter your password: ";
        getline(cin, password);
    }

    void print() {
        cout << "Welcome " << username << "!" << endl;
    }

    bool login() {
        ifstream userFile("users.txt");
        if (!userFile) {
            cerr << "Unable to open user file 'users.txt'." << endl;
            return false;
        }

        string storedUsername;
        string storedPassword;
        bool loginSuccessful = false;

        while (userFile >> storedUsername >> storedPassword) {
            if (username == storedUsername && password == storedPassword) {
                loginSuccessful = true;
                break;
            }
        }

        userFile.close();

        if (loginSuccessful) {
            return true;
        } else {
            cout << "Incorrect username or password." << endl;
            return false;
        }
    }

    void signUp() {
        ofstream userFile("users.txt", ios::app); // Open file in append mode
        if (!userFile) {
            cerr << "Unable to open user file 'users.txt'." << endl;
            return;
        }

        string newUser, newPassword;
        cout << "Create a new username: ";
        getline(cin, newUser);
        cout << "Create a new password: ";
        getline(cin, newPassword);

        userFile << newUser << " " << newPassword << endl; // Write new username and password to the file
        userFile.close();
        cout << "Sign up successful. You can now login with your username and password." << endl;
    }
};

#endif