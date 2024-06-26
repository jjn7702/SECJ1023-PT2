**SECTION A**

Our project focuses on the development of a Personal Organiser system, which serves as a centralised platform for users to manage their reminders and events efficiently. Similar to popular tools like Google Keep, our Personal Organiser provides users the ability to create a timeline which lets the user keep track of any upcoming events.

The main objective of the system is to help the user to organise their activities and events in a more structured and easier to access way. The user can input their future events or activities into the system and the system will save and display any upcoming activities to act as a reminder for the user on the timeline, almost like a calendar. The system will also ask for the date and time of the events and calculate which event is going to come out first and display it on the front page for the user to see, and the user can further check their other events if they choose to do so. An optional description could also be added to the events, giving more options for the user to set up their events. Furthermore, the system allows for the users to remove or edit the events that they’ve entered into the system previously. When the current time has already passed the date of an event, it would display that the event is happening now and remind the user to attend the event. After approximately an hour after the reminder or the event has gone by, the system will automatically remove the event from the user’s timeline, which means as long as before the one hour mark reaches, the user is still able to edit details about the event that was currently happening. The events that a user enters would also be saved in an external file, so the user can still see back all the previous events that they have entered.

The main output for the system would be the display of events on an ordered basis based on the order that the events were keyed into the system. The most recent upcoming event would be displayed on the front page, and if the user chooses to do so, they can view all the other events they have added by choosing the option to “view timeline”. Once the date for the events have passed, the status of the event will be changed to ‘done’ and the event will be cleared from the system and no longer be shown on the user’s timeline. 

**SECTION B**

|**Class**|**Attributes**|**Methods**|
| - | - | - |
|User|<p>- username</p><p>- password</p><p>- ` `vector \*organiser</p><p>- numEvent </p><p>- ID</p>|<p>- newUser </p><p>- passCheck</p><p>- getUsername</p><p>- getPassword</p><p>- getID</p><p>- getOrganiser</p><p>- getOrganiserPointer</p><p>- getOrganiserName</p><p>- getEventType</p><p>- getNumEvent</p><p>- getTime</p><p>- getEndTime</p><p>- setUsername</p><p>- setPassword</p><p>- setOrganiser</p><p>- setOrganiser(overloaded)</p><p>- setID</p><p>- removeEvent</p><p>- arrange</p>|
|Schedule|- status |<p>- setStatus</p><p>- printStatus</p>|
|Date|<p>- year</p><p>- month</p><p>- day</p>|<p>- setYear</p><p>- setMonth</p><p>- setDay</p><p>- getYear</p><p>- getMonth</p><p>- getDay</p><p>- readInput</p><p>- printDate</p>|
|Time|<p>- hour</p><p>- minute</p>|<p>- setHour</p><p>- setMinute</p><p>- getHour</p><p>- getMinute</p><p>- dateExtract</p><p>- readInputTime</p><p>- readInput</p><p>- printTime</p><p>- Print</p><p>- diffPrint</p><p>- getCurrentTime</p>|
|Organiser|<p>- start</p><p>- eventName</p><p>- eventDescr</p><p>- eventType</p><p>- eventStatus</p>|<p>- setEventStatus</p><p>- setEventName</p><p>- setEventDesc</p><p>- setEventDate</p><p>- setStartTime</p><p>- setEndTime</p><p>- eventDone</p><p>- getStatus</p><p>- getEventType</p><p>- getDay</p><p>- getEventName</p><p>- getEventDesc</p><p>- getEndTime</p><p>- getDate</p><p>- getTime</p><p>- readInput</p>|
|Event|- end|<p>- setEndTime</p><p>- getEndTime</p><p>- readInput</p>|
|Reminder||<p>- notify</p><p>- readInput</p>|




**ENCAPSULATION**

The code implements the encapsulation concept for almost all of the member variables for each of the classes, such as making their member variables either private or protected against code outside of the class. 

**COMPOSITION**

The concept of composition can be found in the **Organiser** class, where a **Time** class. It takes in a **Time** object named ‘start’ and sets the starting time of the event. The same could also be said for the class **Event**, which is a child class of **Organiser**. It adds another **Time** class object as their attribute and acts as the ending time of the event. 

**AGGREGATION**

The class that implemented the concept of aggregation is the **User** class, where a vector of **Organiser** pointers were used. The **Organiser** objects need to be saved as pointers to further let us implement the concept of polymorphism, where we can just directly call a virtual member function of an **Organiser** object’s child class’s member functions, more specifically for the functionalities of the **Event** class, where it has an ending time which the **Reminder** class does not.

**INHERITANCE**

The inheritance concept is used whenever a class is defined as a child class of another class. For example, the class **Schedule** is the parent class of the **Date** class, and the **Time** class is a child class for the **Date** class. That means that the class **Time** will have access to public and protected member functions of both the **Schedule** and **Date** class, and acts as the main class to call whenever a starting or ending time is needed. Another class that implements the concept of inheritance is the **Organiser** class, where it has 2 child classes, namely the **Event** class and the **Reminder** class. Both of these classes have access to any protected or public member function available in the Organiser** class.

**POLYMORPHISM**

The concept of polymorphism is used for one of the member functions in the **Organiser** class. A virtual method called setEndTime() and getEndTime() are both virtual methods that do nothing for the main class, and are only used for when calling the ending time of an **Event** class object. This coupled with the aggregation concept with the vector **Organiser** pointers inside the **User** class lets us display the ending time of an **Event** class without having to create an **Event** member variable inside the **User** class.

**ARRAY OF OBJECTS**

An array of objects is used in main.cpp when a number of usernames and passwords are read from a file named “Usernames.txt”. The usernames and passwords are promptly inputted into an array of **User** objects, and is used to verify usernames for the login process.


** 

**Appendix**

**“Schedule.h”**

|**Function Header**|**Parameters**|**Function**|
| :- | :- | :- |
|Schedule(bool)|Status(true : occupied, false : free)|Creates **Schedule** object|
|void setStatus(bool)|Status(true : occupied, false : free)|Sets status to be true or occupied|
|void printStatus()|None|Prints the status |

**“Date.h”**

|**Function Header**|**Parameters**|**Function**|
| :- | :- | :- |
|Date()|None|Creates null **Date** object|
|Date(bool, int, int, int)|Status, year, month, day|Creates initialised **Date** object|
|void setYear(int)|year|Sets year of object to input value|
|void setMonth(int)|month |Sets month of object to input value|
|void setDay(int)|Day of month|Sets day of object to input value|
|int getYear() const|none|Gets the value of year|
|int getMonth() const |none|Gets the value of month|
|int getDay() const|none|Gets the value of day|
|virtual void readInput()|none|Reads the user input for day, month, and year|
|void printDate()|none|Prints the values day, month, and year in a date format|
|friend ostream& operator<< (ostream&, Date )|out, date|<p>Outputs the values day, month, and year in a date format</p><p>using the << operator</p>|

**“Time.h”**

|**Function Header**|**Parameters**|**Function**|
| :- | :- | :- |
|Time()|None|Creates null **Time** object|
|Time(bool, int, int, int, int, int)|Status, year, month, day, hour, minute|Creates initialised **Time** object|
|void setHour(int)|hour|Sets hour of object to input value|
|void setMinute(int)|minute|Sets minute of object to input value|
|Int getHour() const|none|Gets the value of hour|
|int getMinute() const|none|Gets the value of minute|
|void dateExtract(string)|String that shows the current date|Extracts the values of the current date from the string given by time.h library|
|void readInputTime()|none|Read the input of the user to set the values of hour and minute|
|void readInput()|none|Read the input of the user to set the values of day, month, year, hour and minute|
|void printTime()|none|Prints the values of hour and minute in a clock format|
|void print()|none|Prints the values day, month, and year in a date format, the values of hour and minute in a clock format, and the status of the event|
|void diffPrint()|none|Prints the values of day, month, year, hour and minute one by one (used for printing out the difference between 2 **Time** objects)|
|**Time** operator- (const Time &)|**Time** object to be subtracted|Subtracts the values of year, month, day, hour and minute of the first **Time** object with another **Time** object|
|void getCurrentTime()|none|Sets the **Time** object to the current time|
|bool operator< (const Time &)|**Time** object to be compared|Returns true if the 1st **Time** object’s attributes are smaller than the 2nd **Time** object|
|friend bool timeCompareForEvent(Time &, Time &)|1st **Time** object to be compared, 2nd **Time** object to be compared|Returns true if the 1st **Time** object’s attributes are smaller than the 2nd **Time** object, but directly returns false when attributes for the 2nd **Time** object are larger than the 1st|
|friend bool timeCompareOneHour(Time &, TIme &)|1st **Time** object to be compared, 2nd **Time** object to be compared|Returns true if there is more than a one hour difference between the 1st **Time** object and the 2nd **Time** object |
|friend ostream& operator<< (ostream&, Time)|Ostream object, **Time** object to be outputted|Prints the values day, month, and year in a date format, the values of hour and minute in a clock format, and the status of the event using the << operator|


**“Organiser.h”**

|**Function Header**|**Parameters**|**Function**|
| :- | :- | :- |
|Organiser()|None|Creates null **Organiser** object|
|Organiser(**Time**, string, string, bool)|Starting time, event name, event description, event status|Creates initialised **Organiser** object, and sets the event type to 0|
|void setEventStatus(int)|Event status|Sets the event status to the input value|
|void setEventName(string)|Event name|Sets the event name to the input value|
|void setEventDesc(string)|Event description|Sets the event description to the input value|
|void setEventDate(**Date**)|Event date|Sets the year, month and day of the **Time** object ‘start’|
|void setStartTime(**Time**) |Event time|Sets the value of **Time** object ‘start’ to the input value|
|virtual void setEndTime(**Time**)|Event end time|Placeholder virtual method for **Event.h** end time **Time** objects|
|void eventDone()|none|Sets the eventStatus attribute to true|
|int getStatus() const|none|Returns the status of the event|
|int getEventType() const|none|Returns the event type(0 = organiser, 1 = reminder, 2 = event)|
|int getDay() const|none|Returns the day of the event|
|string getEventName() const|none|Returns the name of the event|
|string getEventDesc() const|none|Returns the description of the event|
|virtual **Time** getEndTime() const|none|Placeholder virtual method for **Event.h** end time **Time** objects|
|**Date** getDate() const|none|Returns the date of the starting time of the event’|
|**Time** getTime() const|none|Returns the starting time of the event|
|void readInput()|none|Reads the user input for the event name, starting time, and event description|
|friend ostream& operator<<(ostream&, const **Organiser** &)|ostream object, **Organiser** object|Prints the event name, event status, and the event description using the << operator|
|bool operator<(const **Organiser** &)|**Organiser** object to be compared|Returns true if the time of the first **Organiser** object is smaller than the 2nd one|

**“Reminder.h”**

|**Function Header**|**Parameters**|**Function**|
| :- | :- | :- |
|Reminder()|None|Creates null **Reminder** object, and sets event type to 1|
|Reminder(const **Organiser** &)|**Organiser** object|Copies the values of an **Organiser** object into a **Reminder** object, and sets event type to 1|
|Reminder(**Time**, string, string, bool)|Starting time, reminder name, reminder description, reminder status|Creates initialised **Reminder** object, and sets event type to 1|
|void notify()|none |Prints the time left until the event starts|
|void readInput()|none|Reads the input of the user for event name, starting time, and event description|
|friend ostream& operator<< (ostream&, const **Reminder** &)|ostream object, **Reminder** object|Prints the event name, event status, event description, event type, and starting time using the << operator|

**“Event.h”**

|**Function Header**|**Parameters**|**Function**|
| :- | :- | :- |
|Event()|None|Creates null **Event** object, and sets event type to 2|
|Event(**Organiser** )|**Organiser** object|Copies the values of an **Organiser** object into a **Event** object, and sets event type to 2|
|Event(**Time**, **Time**, string, string, bool)|Starting time, ending time, event name, event description, status|Creates initialised **Event** object, and sets the event type to 2|
|void setEndTime(**Time** )|Ending time|Sets ending time to input value|
|Time getEndTime() const|none|Gets the ending time of the event|
|void readInput()|none|Reads the input values for event name, starting time, ending time, and event description|
|friend ostream& operator<< (ostream&, const **Event** & )|ostream object, **Event** object|Prints the event name, event status, event description, event type, starting time, and ending time using the << operator|

**“User.h”**

|**Function Header**|**Parameters**|**Function**|
| :- | :- | :- |
|User()|None|Create a null **User** object|
|User(string, string, int)|Username, user password, user ID|Create an initialized**User** object|
|bool newUser(User[])|Array of **User** objects|<p>Adds new **User** object to array after detecting no existing similar usernames</p><p></p><p>Returns true if new user is created</p>|
|bool passCheck(string, int)|Input password, maximum attempts|<p>Checks for correct password for input amount of attempts</p><p></p><p>Returns true if password is correct within attempt count</p>|
|string getUsername() const|None|Returns username|
|string getPassword() const|None|Returns user password|
|int getID() const|None|Returns user ID|
|Organiser getOrganiser(int) const|Index of organiser|Returns single organiser from vector of organiser|
|Organiser \*getOrganiserPointer(int)|Index of organiser|Returns pointer of single organiser from vector of organiser|
|string getOrganiserName(int)|Index of organiser|Returns attribute eventName of the organiser |
|int getEventType(int)|Index of organiser|Returns attribute eventType of the organiser|
|int getNumEvent()|none|Returns attribute numEvent of the organiser|
|Time getTime(int)|Index of organiser|Returns the starting time of the organiser of the index passed into the member function|
|Time getEndTime(int)|Index of organiser|Returns the end time of the organiser of the index passed into the member function|
|void setUsername(string)|username |Sets the username of the user to the input value|
|void setPassword(string)|password |Sets the password of the user to the input value|
|void setOrganiser(Organiser\*)|pointer to **Organiser** object|Adds a new **Organiser** pointer to the end of the **Organiser** pointer vector array|
|void setOrganiser(Organiser\*, int)|pointer to **Organiser** object, index of **Organiser** pointer|Sets the **Organiser** pointer of the selected index as the pointer of the passed value|
|void setID(int)|ID|Sets the ID attribute with the input value|
|void removeEvent(int)|Index of **Organiser** pointer to be removed|Removes the **Organiser** pointer of the selected index|
|void arrange()|none|Arranges the vector of **Organiser** pointers in ascending order|




**“Pages.cpp”**

|**Function Header**|**Parameters**|**Function**|
| :- | :- | :- |
|int startMenu()|None|Returns a value for the choice of input at the start menu|
|bool loginPage(**User** [], **User** &)|Array of **User** objects, **User** object|Returns a true value when a successful login has been done|
|bool newUser(**User** [], **User** &)|Array of **User** objects, **User** object|Returns true when a successful opening of a new user has been detected|
|int menu(**User** &)|**User** object|Prints the menu and returns the choice of the menu|
|string eventDetails(const **Organiser** \*)|**Organiser** object pointer|Prints the details from the **Organiser** pointer passed into the function and returns a string value to indicate the next menu choice|
|string menuTimeline(const **User** &)|**User** object|Prints all the upcoming events saved in the user’s timeline and returns a value to indicate the next menu choice|
|string editMenu()|none|Prints the menu to edit an event and returns a value to indicate the next menu choice|
|**Organiser \***addEvent()|none|Creates a new event, either a **Reminder** class or **Event** class, and returns it as a **Organiser** object pointer|
|bool confirmRemove(const **Organiser** &)|**Organiser** object|Returns true if the user confirms to remove the event from their timeline|
|string removeEvent(**User** &)|**User** object|Let the user choose which event to remove from their timeline and returns a value to indicate the next menu choice|
|string menuEditEvent(const **User** &)|**User** object|Let the user choose which event to edit from their timeline and returns a value to indicate the next menu choice|
|<p>template<class A></p><p>bool confirmEdit(int, A)</p>|Integer of choice, class A|Returns true when user confirms to edit the value of an event|
|string editEvent(**User** &)|**User** object|Lets the user choose which attribute of an **Organiser** object they want to edit and returns a value to indicate the next menu choice|

**“Functions.cpp”**

|**Function Header**|**Parameters**|**Function**|
| :- | :- | :- |
|void errorCheck(int &, int, int)|Integer choice, starting integer, ending integer|Checks if the integer choice is in between the starting integer and the ending integer, and asks the user to reinput another value if not|
|void errorCheck(char &)|character choice|Checks if the character choice is is either the character ‘y’ or ‘n’, and asks the user to reinput another value if not|
|void errorCheck(string &, int, int)|string choice|Checks if the string choice after converting to integer is in between the starting integer and the ending integer or if the string choice is either “0” or “00”, and asks the user to reinput another value if not|
|void readFile(**User** [])|Array of **User** objects|Reads a file named “Usernames.txt” and inputs the values into an array of **User** objects|
|void writeFile(**User** [])|Array of **User** objects|Writes a file named “Usernames.txt” and writes the values of an array of **User** objects into the file|
|void writeSingleFile(**User** )|**User** object|Writes a file filled with the information of the events inputted by the user |
|void readSingleFile(**User** &)|**User** object|Writes a file filled with the information of the events inputted by the user and copies them into a **User** object|
|int getShortestTimeIndex(**Time** [], int)|Array of **Time** objects, number of events|Returns the index of an array of  **Time** objects that shows the shortest time|

