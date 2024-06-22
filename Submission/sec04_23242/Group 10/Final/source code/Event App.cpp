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

int main() {
    vector<string> allFeedbacks;
    vector<Event> events;
    Organizer org;
    Participant p;
    int choice;

    while (true) {
    	system("cls");
        cout << "**********Main Menu**********\n";
        cout << "1. Organizer Login\n";
        cout << "2. Participant Login\n";
        cout << "3. Register\n";
        cout << "4. View Feedback\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
            	cin.ignore();
                string username, password;
                cout << "Enter username: ";
                getline(cin, username);
                cout << "Enter password: ";
                char ch = getch();
                while (ch != 13) { // character 13 is enter
                    password.push_back(ch);
                    std::cout << '*';
                    ch = getch();
                }
                 if (org.checkPassword(username, password, "ORGANIZER")) {
                    org.menu();
                } else {
                    cout << "\nInvalid username or password.\n";
                    getchar();
                }
                break;
            }
            case 2: {
                cin.ignore();
                string username, password;
                cout << "Enter username: ";
                getline(cin, username);
                cout << "Enter password: ";
               char ch = getch();
                while (ch != 13) { // character 13 is enter
                    password.push_back(ch);
                    std::cout << '*';
                    ch = getch();
                }
                if (p.checkPassword(username, password, "PARTICIPANT")) {
                    p.menu();
                } else {
                    cout << "\nInvalid username or password.\n";
                    getchar();
                }
                break;
            }
            case 3:
                {string r;
                cin.ignore();
				cout << "Enter role (Participant/Organizer): ";
                getline(cin,r);
                for(int i=0;i<r.length();i++)
                  r[i]= toupper(r[i]);
                  
                if (r=="PARTICIPANT")
				p.registerUser(r); 
				else
				org.registerUser(r);
                getchar();}
                break;
            case 4:
            	{cout<<"Feedback list:\n";
            	for(const auto& feedback :allFeedbacks)
            	cout<<"- "<<feedback<<endl;
            	getchar();}
            	break;
            case 5:
                {cout << "Exiting program...\n";
                getchar();}
                return 0;
            default:
                {cout << "Invalid choice. Try again.\n";
                getchar();}
        }
    }

    system("pause");
    return 0;
}