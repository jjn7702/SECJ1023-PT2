#include "Event.h"
#include "Reminder.h"
#include "Date.h"
#include "Pages.cpp"
#include "Schedule.h"
using namespace std;


int main ()
{
    User users[10];
    User user;
    int choice;
    try
    {
        readFile(users);
    }
    catch (const char* msg)
    {
        cout << msg;
        system("pause");
        return 0;
    }

    bool nextPage = false;
    startMenu:
    do
    {
        int choice = startMenu();
        switch (choice)
        {
            case 1:
            nextPage = loginPage(users, user);
            system("cls");
            break;

            case 2:
            nextPage = newUser(users, user);
            break;

            case 0:
            cout << "Program ended\n\n";
            writeFile(users);
            writeSingleFile(user);
            system("pause");
            return 0;
        }
    } while (!nextPage);

    cout << "Welcome, " << user.getUsername() << "!\n";
    readSingleFile(user);

    Menu:
    choice = menu(user);
    string temp;
    switch (choice)
    {
        case 1:
        temp = menuTimeline(user);
        if (temp == "0")
            goto Menu;

        if (temp == "00")
            goto startMenu;

        case 2:
        goto editMenu;

        case 0:
        goto startMenu;
    }

    editMenu:
    bool repeat = true;
    do
    {
        string temp1 = editMenu();
        string temp3;
        if (temp1 == "0")
            goto Menu;

        if (temp1 == "00")
            goto startMenu;

        int temp1int = stoi(temp1);
        switch (temp1int)
        {
            case 1:
            user.setOrganiser(addEvent());
            break;

            case 2:
            temp3 = removeEvent(user);
            break;

            case 3:
            string temp2 = editEvent(user);
            if (temp2 == "0")
                goto editMenu;

            if (temp2 == "00")
                goto startMenu;
            break;
        }     
    } while (repeat);
}