#include<vector>
#include<fstream>
#include "NT.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include <chrono>
#include <thread>
#include<sstream>


using namespace chrono;
using namespace this_thread;
using namespace std;

// Constants for console text colors
const string RESET = "\033[0m";
const string RED = "\033[1;31m";
const string GREEN = "\033[1;32m";
const string YELLOW = "\033[1;33m";
const string BLUE = "\033[1;34m";
const string CYAN = "\033[1;36m";
const string BRIGHT_BLUE = "\033[1;94m";
const string ORANGE = "\033[38;5;208m";
const string PURPLE = "\033[38;5;165m";

int compareUsername() {
    cout << "\n\t\t============***LOG IN ("<<BLUE<<"REGULAR USER"<<RESET<<")***============\n";
    cout << "\n\t\tPlease enter your username: ";
    string a;
    getline(cin, a);
                    
    ifstream infile("regular_user.txt");
    if (!infile.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    string username;
    int index = 0;

    while (getline(infile, username)) {
        string storedUsername = username.substr(0, username.find(' '));
                            
        if (a == storedUsername) {
            break;
        }
        index++;
    }

    infile.close();

    return index;
}

int loadUsersFromFile(const string& filename, RegularUser users[], int maxUsers) {
    ifstream file(filename);
    string line;
    int index = 0;

    
    if (file.is_open()) {
        
        while (getline(file, line) && index < maxUsers) {
            stringstream ss(line);
            string username, password;
            
            if (ss >> username >> password) {
                users[index] = RegularUser(username, password);
                index++;
            }
        }
        file.close(); 
    } else {
        cerr << "Unable to open file" << endl;
    }

    return index; 
}

int main() {

    vector<User*> users;
    int choice;
    RegularUser tempUser[MAX];
    Nutritionist tempNutritionist;
    int count = loadUsersFromFile("regular_user.txt", tempUser, MAX);
    for(int i = 0; i < count; i++)
    {
        tempNutritionist.addRegularUser(&tempUser[i]);
    }

    cout << "\t\t _  _      _       _ _   _            _____            _           " << endl;
    cout << "\t\t| \\| |_  _| |_ _ _(_) |_(_)___ _ _   |_   _| _ __ _ __| |_____ _ _ " << endl;
    cout << "\t\t| .` | || |  _| '_| |  _| / _ \\ '  \\   | | | '_/ _` / _| / / -_) '_|" << endl;
    cout << "\t\t|_|\\_|\\___|\\__|_| |_|\\__|_\\___/_||_|   |_| |_| \\___\\__|_\\_\\___|_|  " << endl;
 
    do {
        
        cout << "\t\t===========================================================================\n";
        cout << PURPLE << "\n\t\t\t\t*** Welcome to the MAIN PAGE ***\n\n"<<RESET;
        cout << "\t\t===========================================================================\n\n";
        cout << "\t\t1. Sign Up (Regular User)\n"
             << "\t\t2. Sign Up (Nutritionist)\n"
             << "\t\t3. Log In (Regular User)\n"
             << "\t\t4. Log In (Nutritionist)\n"
             << RED << "\t\t5. Exit\n\n" << RESET;
        cout << "\t\tPlease enter the code (1 - 5): ";
        cin >> choice;

        while (choice < 1 || choice > 5) {
            cout << RED << "\t\tINVALID INPUT!!! "
                 << "\t\tPlease enter the code (1 - 5): " << RESET;
            cin >> choice;
        }
        
        system("cls");
        switch (choice) {
            case 1: {
                cin.ignore();
                if(count < MAX){
                tempUser[count].signUp(users);
                tempNutritionist.addRegularUser(&tempUser[count++]);
                }
                else{
                    cout<<"\t\tMaximum number of users reached. Cannot add more users."<<endl;
                }
                
                break;
            }
            case 2: {
                cin.ignore();
                tempNutritionist.signUp(users);
                break;
            }
            case 3: {
                cin.ignore();
                if (count > 0) {
                    int index = compareUsername();
                    if (tempUser[index].logIn(users)) {
                        int choice2;
                        do {
                            system("cls");
                            cout << "\t\t+================================================================+" << endl;
                            cout << "\t\t|                                                                |" << endl;
                            cout << "\t\t|                     *** Select your choice ***                 |" << endl;
                            cout << "\t\t|                                                                |" << endl;
                            cout << "\t\t+================================================================+" << endl;
                            cout << "\t\t|  1. Nutrition Tracker Page                                     |" << endl;
                            cout << "\t\t|  2. Workout Tracker Page                                       |" << endl;
                            cout << "\t\t|  3. View Daily Summary                                         |" << endl;
                            cout << "\t\t|  4. View Profile                                               |" << endl;
                            cout << "\t\t|  5. Set Up Profile                                             |" << endl;
                            cout << "\t\t|  6. View Feedback                                              |" << endl;
                            cout << "\t\t|  " << RED << "7. Exit                                                       " << RESET << "|" << endl;
                            cout << "\t\t+================================================================+" << endl;
                            cout << "\t\tPlease enter the code (1 - 7): ";
                            cin >> choice2;
                            while (choice2 < 1 || choice2 > 7) {
                            cout << RED << "\t\tINVALID INPUT!!! "
                             << "\t\tPlease enter the code (1 - 7): " << RESET;
                            cin >> choice2;
                    }

                            switch (choice2) {
                                case 1: tempUser[index].viewNutritionTracker(); break;
                                case 2: tempUser[index].viewWorkoutTracker(); break;
                                case 3: tempUser[index].viewDailySummary(); break;
                                case 4: system("cls"); tempUser[index].viewProfile(); break;
                                case 5: tempUser[index].setInfo(); break;
                                case 6: tempUser[index].viewFeedback(); break;
                                default:
                                    cout << ORANGE << "\n\t\tReturning to main page...\n" << RESET;
                                    sleep_for(seconds(1));
                                    system("cls");
                                    break;
                            }
                        } while (choice2 != 7);
                    } else {
                        cout << RED << "\t\tLogin failed. Please try again." << RESET << endl;
                        sleep_for(seconds(1));
                        system("cls");
                    }
                } else {
                    cout << RED << "\t\tNo users available. Please sign up first." << RESET << endl;
                    sleep_for(seconds(1));
                    system("cls");
                }
                break;
            }
                
            case 4: {
                cin.ignore();
                int choice3;
                if (tempNutritionist.logIn(users)) {
                    system("cls");
                     do {
                        system("cls");
                    cout << "\t\t+================================================================+" << endl;
                    cout << "\t\t|                                                                |" << endl;
                    cout << "\t\t|                     *** Select you choice***                   |" << endl;
                    cout << "\t\t|                                                                |" << endl;
                    cout << "\t\t|================================================================|" << endl;
                    cout << "\t\t|                                                                |" << endl;
                    cout << "\t\t|  1. View User Report                                           |" << endl;
                    cout << "\t\t|  2. Write Feedback                                             |" << endl;
                    cout << "\t\t|  "<<RED<<"3. Exit                                                       "<<RESET<<"|" << endl;
                    cout << "\t\t|                                                                |" << endl;
                    cout << "\t\t|                                                                |" << endl;
                    cout << "\t\t|                                                                |" << endl;
                    cout << "\t\t|                                                                |" << endl;
                    cout << "\t\t+================================================================+" << endl;

                    cout << "\t\tPlease enter the code (1 - 3): ";
                    cin >> choice3;

                    while (choice3 < 1 || choice3 > 3) {
                        cout << RED << "\t\tINVALID INPUT!!! "
                             << "\t\tPlease enter the code (1 - 3): " << RESET;
                        cin >> choice3;
                    }
                    
                    switch(choice3){
                        case 1: tempNutritionist.viewUsersReport();
                                break;
                        case 2: tempNutritionist.writeFeedback();
                                break;
                        default: cout << ORANGE<<"\n\t\tGoing back to main page.....\n"<<RESET;
                                 sleep_for(seconds());
                                 system("cls");
                    }
                    } while (choice3 != 3);        
                    
                    } 
                    break;
                    
                }
                break;
            
            case 5: {
                cout << RED << "\t\tExiting the program...\n" << RESET;
                sleep_for(seconds(2));
                break;
            default:
                break;    
            }
        } 
    }while (choice != 5);

    for (auto user : users) {
        delete user;
    }

    return 0;
}