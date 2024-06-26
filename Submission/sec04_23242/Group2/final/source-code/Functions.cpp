#include "Time.h"
#include "User.h"
#include "Reminder.h"
#include "Event.h"
#include <fstream>
#include <string>
using namespace std;

void errorCheck(int &c, int start, int end)
{
    if (c < start || c > end)
    {
        cout << "value out of range, please try again\n";
        cin >> c;
        errorCheck(c, start, end);
    }
}

void errorCheck(char &c)
{
    c = tolower(c);
    if (c != 'y' && c != 'n')
    {
        cout << "Error, please reenter (Y/N) : ";
        cin >> c;
        c = tolower(c);
        errorCheck(c);
    }

    else
        return;
}

void errorCheck(string &s, int start, int end){
    if(s == "0" || s == "00")
        return;

    int choice = stoi(s);

    if (choice < start || choice > end)
    {
        cout << "value out of range, please try again\n";
        cin >> s;
        errorCheck(s, start, end);
    }
}

void readFile(User user[])
{
    ifstream in("Usernames.txt");
    int i = 0;
    string temp;
    if (in.fail())
        throw "unable to find Usernames.txt file, exiting program\n\n";

    while (!in.eof())
    {
        getline(in, temp, '\n');
        user[i].setUsername(temp);
        getline(in, temp, '\n');
        user[i++].setPassword(temp);


    }
    in.close();
}

void writeFile(User user[])
{
    ofstream out("Usernames.txt");
    for (int i = 0; i < 10; i++)
    {
        if (user[i].getUsername() != "")
            out << user[i].getUsername() << endl << user[i].getPassword() << endl;

    }
    
    out.close();
}

void writeSingleFile(User user)
{
    ofstream out;
        if (user.getUsername() != "")
        {
            string temp = user.getUsername() + ".txt";
            out.open(temp);
            for (int j = 0; j < user.getNumEvent(); j++)
            {
                Time tempTime = user.getTime(j);
                out << user.getOrganiser(j) << tempTime << user.getEventType(j) << endl;
                if (user.getEventType(j) == 2)
                {
                    Time tempEndTime = user.getEndTime(j);
                    out << tempEndTime;
                }
            }
            out.close();
        }
}

void readSingleFile(User &user)
{
    ifstream in(user.getUsername() + ".txt");
    string temp;
    Organiser tempOrg, tempOrg2;
    Time tempTime;
    while (!in.eof())
    {
        getline(in, temp);
        if (temp == "")
            break;
        tempOrg.setEventName(temp.substr(21));
        getline(in, temp);
        tempOrg.setEventStatus(temp.substr(21, '\n') == "Done"? true: false);
        getline(in, temp);
        tempOrg.setEventDesc(temp.substr(21));
        getline(in, temp);
        tempTime.setDay(stoi(temp.substr(6, 2)));
        tempTime.setMonth(stoi(temp.substr(9, 2)));
        tempTime.setYear(stoi(temp.substr(12, 4)));
        getline(in, temp);
        tempTime.setHour(stoi(temp.substr(6, 2)));
        tempTime.setMinute(stoi(temp.substr(9, 2)));
        getline(in, temp);
        tempTime.setStatus(temp.substr(8, '\n') == "Free"? false: true);
        tempOrg.setStartTime(tempTime);
        getline(in, temp);
        int tempint = stoi(temp);
        if (tempint == 2)
        {
            getline(in, temp);
            tempTime.setDay(stoi(temp.substr(6, 2)));
            tempTime.setMonth(stoi(temp.substr(9, 2)));
            tempTime.setYear(stoi(temp.substr(12, 4)));
            getline(in, temp);
            tempTime.setHour(stoi(temp.substr(6, 2)));
            tempTime.setMinute(stoi(temp.substr(9, 2)));
            getline(in, temp);
            tempTime.setStatus(temp.substr(8, '\n') == "Free"? false: true);
        }

        if (tempint == 0)
        {
            user.setOrganiser(new Organiser(tempOrg));
        }

        else if (tempint == 1)
        {
            user.setOrganiser(new Reminder(tempOrg));
        }

        else if (tempint == 2)
        {
            Event tempEvent(tempOrg);
            tempEvent.setEndTime(tempTime);
            user.setOrganiser(new Event(tempEvent));
        }
    }
    in.close();
}

int getShortestTimeIndex(Time t[], int numEvent)
{
    Time temp = t[0];
    int index = 0;
    for (int i = 1; i < numEvent; i++)
    {
        if(t[i] < temp){
            temp = t[i];
            index = i;
        }

    }

    return index;
}