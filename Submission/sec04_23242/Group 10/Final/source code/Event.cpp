#include "Header.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <conio.h>
#include <cctype>
using namespace std;

vector<Event> events;
vector<string> allFeedbacks;

void Address::inputAddress() {
        cin.ignore();
        cout << "*Enter street: ";
        getline(cin, street);
        cout << "*Enter city: ";
        getline(cin, city);
        cout << "*Enter state: ";
        getline(cin, state);
        cout << "*Enter postcode: ";
        cin >> postcode;
    }

void Address::displayAddress() const {
    	cout << "Address "<<endl;
        cout << "*Street: " << street << endl;
        cout << "*City: " << city << endl;
        cout << "*State: " << state << endl;
        cout << "*Postcode: " << postcode << endl;
    }
    
void Profile::inputInfo() {
        cin.ignore();
        cout << "Enter full name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
    	cout << "Enter address "<<endl;
        address.inputAddress();
        cin.ignore();
        cout << "Enter background information: ";
        getline(cin, background);
    }
    
void Profile::viewInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        address.displayAddress();
        cout << "Background: " << background << endl;
    }

void Profile::updateProfile() 
    {
        cout << "\nYour Profile\n"
             << "------------\n";
        viewInfo();
        getchar();

       int choice;
       do
       {
       	system("cls");
         cout << "What would you like to update?\n";
         cout << "1. Name\n2. Age\n3. Address\n4. Background\n5. Exit\n";
         cout << "Enter your choice: ";
         cin >> choice;
         cin.ignore();

         switch (choice)
         {
            case 1:
                cout << "Enter new name: ";
                getline(cin, name);
                break;
            case 2:
                cout << "Enter new age: ";
                cin >> age;
                cin.ignore();
                break;
            case 3:
                cout << "Enter new address: ";
                address.inputAddress();
                break;
            case 4:
                cout << "Enter new background information: ";
                getline(cin, background);
                break;   
            case 5:
                break; 
            default:
                cout << "Invalid choice.\n";
                break;
        }
       } while (choice != 5);
       
        cout << "Profile updated sucessfully...\n\n";
        viewInfo();
    }
    
void Feedback::addFeedback(const string& feedback) {
        feedbackList.push_back(feedback);
        cout << "Feedback added successfully." << endl;
    }
    
void User::updateProfile() {
        profile.updateProfile();
    }


void Organizer::createEvent() {
  double dateTime;
    string title, venue, description;

    cin.ignore();
    cout << "Enter event title: ";
    getline(cin, title);
    cout << "Enter date and time (YYMMDD.HHMM): ";
    cin >> dateTime;
    cin.ignore();
    cout << "Enter venue: ";
    getline(cin, venue);
    cout << "Enter description: ";
    getline(cin, description);
    cout<<"Event have successfully created"<<endl;

    events.emplace_back(dateTime, title, venue, description);

    // Sort events by dateTime
    sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        return a.dateTime < b.dateTime;
    });

}

void Organizer::menu() {
    int choice;
    while (true) {
    	system("cls");
        cout << "**********Organizer Menu**********\n";
        cout << "1. Create Event\n";
        cout << "2. Provide Feedback\n";
        cout << "3. View and Update Profile\n";
        cout << "4. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                {createEvent();
                getchar();}
                break;
            case 2:
                { string fb;
                    cout << "Enter feedback: ";
                    getline(cin, fb);
                    feedback->addFeedback(fb);
                allFeedbacks.push_back(fb); 
                getchar();}
                break;
            case 3:
            	 {updateProfile();
                getchar();}
                break;
            case 4:
                return;
            default:
                {cout << "Invalid choice. Try again.\n";
                getchar();}
        }
    }
}

void Participant::viewEvents(double currentDateTime) {
    cout << fixed << setprecision(4) << "\n# Current date and time: " << currentDateTime <<" #"<< endl;
    cout << "\nAll events\n";
    cout << "-----------"<<endl;
    cout << "History events:\n";
    for (const auto& e : events) {
    	if (e.dateTime < currentDateTime) {
        cout << "~ Date and Time: " << e.dateTime << ", Title: " << e.title 
             << ", Venue: " << e.venue << ", Description: " << e.description << endl;}
    }
    cout << "\nUpcoming events:\n";
    for (const auto& e : events) {
        if (e.dateTime >= currentDateTime) {
            cout << "~ Date and Time: " << e.dateTime << ", Title: " << e.title 
                 << ", Venue: " << e.venue << ", Description: " << e.description << endl;
        }
    }
    cout << "\nEnter the title of the upcoming event you want to join: ";
    string selectedTitle;
    getline(cin, selectedTitle);

    auto it = find_if(events.begin(), events.end(), [&selectedTitle](const Event& e) {
        return e.title == selectedTitle;
    });

    if (it != events.end() && it->dateTime >= currentDateTime) {
        selectedEvents.push_back(*it);
        cout << "You have successfully joined the event: " << it->title << endl;
    } else {
        cout << "Event not found or it is not an upcoming event." << endl;
    }
}

void Participant::displaySelectedEvent(double currentDateTime) const {
	cout << fixed << setprecision(4) << "Current date and time: " << currentDateTime << endl;
    cout << "\nSelected Events:\n";
     cout << "Past selected events:\n";
    for (const auto& e : selectedEvents) {
    	if (e.dateTime < currentDateTime) {
        cout << "Date and Time: " << e.dateTime << ", Title: " << e.title 
             << ", Venue: " << e.venue << ", Description: " << e.description << endl;}
    }
    cout << "\nUpcoming selected events:\n";
    for (const auto& e : selectedEvents) {
        if (e.dateTime >= currentDateTime) {
            cout << "Date and Time: " << e.dateTime << ", Title: " << e.title 
                 << ", Venue: " << e.venue << ", Description: " << e.description << endl;
        }
    }
}

void Participant::menu() {
    int choice;
    while (true) {
    	system("cls");
        cout << "**********Participant Menu**********\n";
        cout << "1. Event List\n";
        cout << "2. View Selected Events\n";
        cout << "3. Provide Feedback\n";
        cout << "4. View and Update Profile\n";
        cout << "5. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

    time_t t = time(0);
    struct tm* now = localtime(&t);
    double currentDateTime = (now->tm_year-100) * 10000 + (now->tm_mon + 1) * 100 + now->tm_mday + (now->tm_hour / 100.0) + (now->tm_min / 10000.0);
                 
        switch (choice) {
            case 1:
            	{viewEvents(currentDateTime);
				getchar();}
                break;
            case 2:
               	{displaySelectedEvent(currentDateTime);
				getchar();}
                break;
            case 3:
                { string fb;
                    cout << "Enter feedback: ";
                    getline(cin, fb);
                    feedback->addFeedback(fb);
                allFeedbacks.push_back(fb); 
                getchar();}
                break;
            case 4:
                {updateProfile();
                getchar();}
                break;
            case 5:
                return;
            default:
               {cout << "Invalid choice. Try again.\n";
                getchar();}
        }
    }
}

void User::registerUser(const string &role) {
    string username, password;
    while (true) {
        cout << "Enter new username (5-15 characters): ";
        cin >> username;
        if (username.length() >= 5 && username.length() <= 15) {
            break;
        }
        else {
            cout << "Username must be between 5 and 15 characters." << endl;
        }
    }
    while (true) {
        cout << "Enter new password (8-20 characters): ";
        cin >> password;
        if (password.length() >= 8 && password.length() <= 20) {
            break;
        }
        else {
            cout << "Password must be between 8 and 20 characters." << endl;
        }
    }
    
    ofstream outfile("users.txt", ios::app);
    if (!outfile) {
        cout << "Error opening users.txt file." << endl;
        return;
    }
    outfile << setw(15) << username << setw(15) << password << setw(15) << role << endl;
    outfile.close();
    cout << "\n<<<Enter your personal data>>>\n";
    profile.inputInfo();
    cout << "Registration successful..." << endl;
}

bool User::checkPassword(const string& username, const string& password, const string& role) {
    ifstream infile("users.txt");
    if (!infile) {
        cout << "Error opening users.txt file." << endl;
        return false;
    }

    string storedUsername, storedPassword, storedRole;
    while (infile >> storedUsername >> storedPassword >> storedRole) {
        if (storedUsername == username && storedPassword == password && storedRole == role) {
            return true;
        }
    }

    return false;
}