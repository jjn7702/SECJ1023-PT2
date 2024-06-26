#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "NewUser.h" 
#include "Time.h"
using namespace std;

#ifndef DATA_H
#define DATA_H

class Data {
    protected:
        char category;
        NewUser newUser;
        Time time;
    public:
        Data(char _category = ' ', NewUser _userData = NewUser(), Time _time = Time()) : category(_category), newUser(_userData), time(_time) { } // Default constructor (with default values

        void setCategory(char _category) { category = _category; }
        char getCategory() const { return category; }


        void analyzeSleep(int, int);
        void displayMessage();
        void calculateSleepDiff(int, int);
};

void Data::analyzeSleep(int minutes, int age) {
        if (age < 1) {
            if (minutes < 12*60) {
                category = 'B';
            } else if (minutes > 16*60) {
                category = 'C';
            } else {
                category = 'A';
            }
        } else if (age < 3) {
            if (minutes < 11*60) {
                category = 'B';
            } else if (minutes > 14*60) {
                category = 'C';
            } else {
                category = 'A';
            }
        } else if (age < 6) {
            if (minutes < 10*60) {
                category = 'B';
            } else if (minutes > 13*60) {
                category = 'C';
            } else {
                category = 'A';
            }
        } else if (age < 13) {
            if (minutes < 9*60) {
                category = 'B';
            } else if (minutes > 12*60) {
                category = 'C';
            } else {
                category = 'A';
            }
        } else if (age < 18) {
            if (minutes < 8*60) {
                category = 'B';
            } else if (minutes > 10*60) {
                category = 'C';
            } else {
                category = 'A';
            }
        } else if (age >= 65) {
            if (minutes < 7*60) {
                category = 'B';
            } else if (minutes > 8*60) {
                category = 'C';
            } else {
                category = 'A';
            }
        }
}

void Data::displayMessage() {
    switch(category) {
        case 'A':
            cout << "Good sleep quality." << endl;
            break;
        case 'B':
            cout << "Poor sleep quality (less than average)." << endl;
            break;
        case 'C':
            cout << "Overslept." << endl;
            break;
        default:
            cout << "Invalid category." << endl;
            break;
    }
}

void Data::calculateSleepDiff(int averageTime, int age) {
    int averageSleepForAgeGroup;
    if (age < 1) {
        averageSleepForAgeGroup = 14*60; 
    } else if (age < 3) {
        averageSleepForAgeGroup = 12.5*60; 
    } else if (age < 6) {
        averageSleepForAgeGroup = 11.5*60;
    } else if (age < 13) {
        averageSleepForAgeGroup = 10.5*60; 
    } else if (age < 18) {
        averageSleepForAgeGroup = 9*60; 
    } else {
        averageSleepForAgeGroup = 7.5*60; 
    }

    int averageSleepMinutes = averageTime;
    int differenceInMinutes = abs(averageSleepMinutes - averageSleepForAgeGroup);
    
    int dhours = differenceInMinutes / 60; 
    int dminutes = differenceInMinutes % 60; 

    switch (category) {
        case 'A':
            cout << "Keep it up!" << endl;
            break;
        case 'B':
            cout << "Sleep time less than average by: " << dhours << " hours and " << dminutes << " minutes" << endl;
            break;
        case 'C':
            cout << "Sleep time more than average by: " << dhours << " hours and " << dminutes << " minutes" << endl;
            break;
        default:
            cout << "Invalid category." << endl;
            break;
    }
}

#endif
