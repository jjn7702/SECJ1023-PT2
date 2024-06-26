#include "User.h"
#include "Time.h"
#include "Organiser.h"
#include "Reminder.h"
#include "Event.h"
#include <fstream>
#include <iomanip>
#include "Functions.cpp"
using namespace std;

//1
int startMenu(){
    cout << "1. Login(Existing User)" << endl;
    cout << "2. Sign Up(New User)" << endl;
    cout << "0. End Program" << endl;

    int inputChoice;
    cout << "Input(0/1/2): ";
    cin >> inputChoice;
    errorCheck(inputChoice, 0, 2);
    cin.ignore();
    system("cls");
    return inputChoice;
}

bool loginPage(User users[], User &user){

    string username, password, usernameTemp;
    bool correct = false;
    cout << "Enter username, or press 0 to exit back to start menu\n";
    cout << "Username: ";
    getline(cin, username, '\n');

    if (username == "0")
    return false;

    cout << "Password: ";
    getline(cin, password, '\n');

    for (int i = 0; i < 100 + 1; i++)
    {   
        if (i == 100)
        {
            cout << "Username not found, try reentering your username or press 0 to return to start menu\n";
            return loginPage(users, user);
        }

        if (users[i].getUsername() == username && users[i].getUsername() != "")
        {
            if (password != users[i].getPassword())
            {
                bool ab = users[i].passCheck(password, 1);
                if (ab)
                    user = users[i];

                return ab;
            }

            else
            {
                user = users[i];
                return true;
            }
                
        }
    }

    system("cls");
    return true;

}
//1.1

bool newUser(User users[], User &user)
{
    bool temp;
    cout << "Enter your new username & password, or press 0 to return back to start menu\n";
    for (int i = 0; i < 100; i++)
    {
        if (users[i].getUsername() == "")
        {
            temp = users[i].newUser(users);
                if (temp)
                    user = users[i];
            
            system("cls");
            return temp;
        }
    }

    return true;

}

//2
int menu(User &user){
    int inputChoice;
    
    cout << "1. See Timeline\n"
         << "2. Add or Remove Events\n"
         << "0. Back to login page ( logout )\n";

    cout << "=======Upcoming Event(s):=======\n\n";
    bool j;
    Time currentTime, timeDiff, tempTime[user.getNumEvent()];
    Organiser *tempOrg[user.getNumEvent()];
    currentTime.getCurrentTime();
    if (!user.getNumEvent())
        cout << "No upcoming events to display\n\n";
    else{
        for (int i = 0; i < user.getNumEvent(); i++)
            tempOrg[i] = user.getOrganiserPointer(i);

        for (int i = 0; i < user.getNumEvent(); i++)
            tempTime[i] = tempOrg[i]->getTime();

        int index = getShortestTimeIndex(tempTime, user.getNumEvent());


        if (!(timeCompareForEvent(currentTime, tempTime[index])))
            cout << "\n\n===HAPPENING NOW===\n\n";

        cout << "Event: \n";
        cout << *tempOrg[index] << "\n";
        timeDiff = tempTime[index] - currentTime;
        if (timeCompareForEvent(currentTime, tempTime[index]))
        {
            cout << "Time until event starts: ";
            timeDiff.diffPrint();
            cout << endl;
            if (tempOrg[index]->getEventType() == 2)
            {
                Time tempEndTime = tempOrg[index]->getEndTime();
                Time eventTimeDiff = tempEndTime - tempTime[index];
                cout << "Duration: ";
                eventTimeDiff.diffPrint();            
            }
        }
        else
        {
            Time tempTimeDiff = currentTime - tempTime[index];
            cout << "Event started ";
            tempTimeDiff.diffPrint();
            cout << " ago\n\n";
            tempOrg[index]->setEventStatus(true);
            if (timeCompareOneHour(currentTime, tempTime[index]))
                user.removeEvent(index);
        }
    }

    cout << "Input(0/1/2): ";
    cin >> inputChoice;
    errorCheck(inputChoice, 0, 2);

    system("cls");
    return inputChoice;
}

//2.1.1
string eventDetails(const Organiser *organiser){
    string inputChoice;
    Date tempDate = organiser->getDate();
    Time tempTime = organiser->getTime();
    tempTime.printDate();
    cout << "\nStart Time: \t";
    cout << tempTime.getHour() << ":" << (tempTime.getMinute() < 0)? "0": "";
    cout << tempTime.getMinute();

    if (organiser->getEventType() == 2)
    {
        Time tempEndTime = organiser->getEndTime();
        cout << "\nEnd Time: \t";
        cout << tempEndTime.getHour() << ":";
        if(tempEndTime.getMinute() < 10)
            cout << "0";
        cout << tempEndTime.getMinute();
    }
    //tempDate.printDate();

    cout << endl << left << setw(30) << *organiser << endl;

    cout << "Input(Press 0 to return, 00 to logout): ";
    cin >> inputChoice;

    system("cls");
    return inputChoice;
}

//2.1
string menuTimeline(const User &user){
    string x = "0";
    while (x == "0")
    {
        string inputChoice;
        int numEvent = user.getNumEvent();
        Organiser *o[maxOrganiser];
        cout << left << setw(10) << "No." << setw(30) << "Name" << setw(30) << "Description\t" << "Date           \tTime\t\tStatus\n";
        for(int i = 0; i < numEvent; i++){
            o[i] = user.getOrganiserPointer(i);
            Time temp = o[i]->getTime();
            cout << left << setw(10) << i + 1 << setw(30) << o[i]->getEventName() << setw(30) << o[i]->getEventDesc() << "\t  ";
            temp.print(); 
        }
        cout << endl;
        cout << "0. Return To Previous Page\n"
            << "00. Logout\n\n"
            << "Input Event for Details(1~" << numEvent << "):";
        cin >> inputChoice;
        errorCheck(inputChoice, 1, numEvent);

        system("cls");
        
        if(inputChoice == "0" || inputChoice == "00")
            return inputChoice;

        x = eventDetails(o[stoi(inputChoice) - 1]);
    }
    return x;
}

//2.2
string editMenu(){
    string inputChoice;
    
    cout << "1. Add Event\n"
         << "2. Remove Event\n"
         << "3. Edit Event\n\n"
         
         << "0. Return To Previous Page\n"
         << "00. Logout\n"
         << "Input: ";

    cin >> inputChoice;
    errorCheck(inputChoice, 0, 3);
    system("cls");
    return inputChoice;
}

//2.2.1
Organiser *addEvent(){

    Time tempStart, tempEnd, currentTime;
    currentTime.getCurrentTime();
    tempStart.readInput();

    if (tempStart.getDay() == 0)
    {
        system("cls");
        return new Organiser();
    }
    while (timeCompareForEvent(tempStart, currentTime))
    {
        cout << "Error: date invalid. try again.\n\n";
        tempStart.readInput();
    }
    
    cin.ignore();

    string eventName, eventDesc;
    int eventType;

    cout << left << setw(40) << "Event Name" << ":";
    getline(cin, eventName);

    cout << left << setw(40) << "Event Type(1 for reminder, 2 for event)" << ":";
    cin >> eventType;
    errorCheck(eventType, 1, 2);
    cin.ignore();

    cout << left << setw(40) << "Event Description" << ":";
    getline(cin, eventDesc);

    system("cls");
    if(eventType == 1)
        return new Reminder(tempStart, eventName, eventDesc, false);
    if(eventType == 2){
        cout << "End Time:\n";
        tempEnd.readInput();
        while (timeCompareForEvent(tempEnd, tempStart))
        {
            cout << "Error: date invalid. try again.\n\n";
            tempEnd.readInput();
        }
        system("cls");
        return new Event(tempStart, tempEnd, eventName, eventDesc, false);
    }

    return new Organiser(tempStart, eventName, eventDesc, false);
        
}

//2.2.2.1
bool confirmRemove(const Organiser &o){
    char confirm;
    cout << "Are you sure to remove event \"" << o.getEventName() <<"\" ? This step is not recoverable\n"
         << "(Y/N)";
    
    cin >> confirm;
    confirm = tolower(confirm);
    errorCheck(confirm);
    system("cls");
    return (confirm == 'y');
}

//2.2.2
string removeEvent(User &user){
    string inputChoice;
    int numEvent = user.getNumEvent();
    Organiser o[maxOrganiser];
    for(int i = 0; i < numEvent; i++){
        o[i] = user.getOrganiser(i);
        Time temp = o[i].getTime();
        cout << i + 1 << ".\t" << o[i].getEventName() << "\t" << o[i].getEventDesc() << "\t";
        temp.print();
        cout << endl;
    }

    cout << "Input number to remove event or press 0 to return to previous page or 00 to logout: ";
    cin >> inputChoice;

    errorCheck(inputChoice, 1, numEvent);
    system("cls");
    if (inputChoice == "0" || inputChoice == "00")
        return inputChoice;
    int iChoiceint = stoi(inputChoice);
    if(confirmRemove(o[iChoiceint - 1]))
        user.removeEvent(iChoiceint - 1);    

    return "0";
}



//2.2.3
string menuEditEvent(const User &user){
    string inputChoice;
    int numEvent = user.getNumEvent();
    Organiser o[maxOrganiser];
    for(int i = 0; i < numEvent; i++){
        o[i] = user.getOrganiser(i);
        cout << i + 1 << "." << o[i] << endl;
    }

    cout << "Input number to edit event or press 0 to return to previous page or 00 to logout: ";
    cin >> inputChoice;
    errorCheck(inputChoice, 1, numEvent);

    system("cls");
    return inputChoice;
}

//2.2.3.2
template<class A>
bool confirmEdit(int choice, A a){
    char confirm;
    cout << endl;
    

    switch(choice){
        case 1:
            cout << "Are you sure to edit Event Name to \"" << a << "\"?\n"
                 << "(Y/N)";
            break;

        case 2:
            cout << "Are you sure to edit Event Description to \"" << a << "\"?\n"
                 << "(Y/N)";
            break;
        
        case 3:
            cout << "Are you sure to edit Event Date to: \n"
                 << a << "(Y/N)";
                
            break;

        case 4:
            cout << "Are you sure to edit Event Starting Time to :\n"
                << a <<  "(Y/N)";
            break;

        case 5:
            cout << "Are you sure to edit Event End Time to :\n"
                 << a << "\n (Y/N)\n";
            break;
    }    
    cin >> confirm;
    confirm = tolower(confirm);
    errorCheck(confirm);
    system("cls");
    return (confirm == 'y');
}

//2.2.3.1
string editEvent(User &user){
    Time currentTime;
    currentTime.getCurrentTime();
    string strIndex = menuEditEvent(user);
    if (strIndex == "00" || strIndex == "0")
        return strIndex;

    int index = stoi(strIndex);
    
    string inputChoice;
    int numEvent = user.getNumEvent();
    Organiser *o[maxOrganiser];

    for(int i = 0; i < numEvent; i++){
        o[i] = user.getOrganiserPointer(i);
    }

    index--;
    Date tempDate = o[index]->getDate();
    Time tempTime = o[index]->getTime();
    Time tempEndTime;

    cout << left << setw(20) << "1. Event Name" << ":";
    cout << o[index]->getEventName();

    cout << right << setw(20) << "\n2. Event Description" << ":";
    cout << o[index]->getEventDesc();

    cout << right << setw(20) <<  "\n3. Event Date" << ":\t";
    tempDate.printDate();

    cout << right << setw(20) << "\n4. Event Time" << ":\t";
    tempTime.printTime();

    if (o[index]->getEventType() == 2){
            cout << right << setw(20) << "\n5. Event End Time" << ":\t";
            tempEndTime = o[index]->getEndTime();
            tempEndTime.printTime();
    }

    cout << "\n0. Return to previous page" << endl    
         << "00. Logout" << endl << endl;

    cout << "Input number to edit event: ";
    cin >> inputChoice;

    int choiceEnd = o[index]->getEventType() == 2? 5: 4;
    errorCheck(inputChoice, 1, choiceEnd);

    system("cls");

    if(inputChoice == "0" || inputChoice == "00")
        return inputChoice;
        

    int temp = stoi(inputChoice);
    cin.ignore();
    if(temp == 1){
        string tempName;
        cout << "New Event Name: " ;
        getline(cin, tempName);

        if(confirmEdit(temp, tempName));
            o[index]->setEventName(tempName);

    }else if(temp == 2){
        string tempDesc;
        cout << "New Event Description: ";
        getline(cin, tempDesc);

        if(confirmEdit(temp, tempDesc))
            o[index]->setEventDesc(tempDesc);

    }else if(temp == 3){
        cout << "New Event Date: \n";
        tempDate.readInput();

        if(confirmEdit(temp, tempDate))
            o[index]->setEventDate(tempDate);

    }else if(temp == 4){
        cout << "New Starting Time: \n";
        tempTime.readInputTime();
        while (timeCompareForEvent(tempTime, currentTime))
        {
            cout << "Error: date invalid. try again\n";
            tempTime.readInputTime();
        }

        if(confirmEdit(temp, tempTime))
            o[index]->setStartTime(tempTime);

    }else if(temp == 5){
        cout << "New Ending Time: \n";
        tempEndTime.readInputTime();
        while (timeCompareForEvent(tempEndTime, tempTime))
        {
            cout << "Error: date invalid. try again\n"
                 << "Starting time: " << tempTime << endl;
            tempEndTime.readInputTime();
        }

        if(confirmEdit(temp, tempEndTime))
            o[index]->setEndTime(tempEndTime);
    }

    user.setOrganiser(o[index], index);
    system("cls");
    return "0";
}
