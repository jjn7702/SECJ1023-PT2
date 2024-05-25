# Section A : Flowchart 
![](images/flowchart.png)
![](images/flowchart_fx.png)

The flowchart of the Personal Organizer system illustrates the processes for both users and admins. The process begins with the User Login and Registration, where users login with their credentials(account) or register for a new account. Upon successful login, the Main Menu presents options such as viewing timeline, adding, editing, or removing events, and updating event status. The Event Management process allows users to manage their events by displaying their upcoming events, adding new ones, editing existing ones, removing events, and updating their status. For admin users, the Admin Access and Management process provides additional functionalities. Admins log in and access the admin menu, where they can manage users by resetting their passwords, removing users, and editing user details. In addition, every page is provided with ‘Return’ and ‘Logout’ options which allow users to directly perform the actions without returning to the main menu. Collectively, these processes ensure the Personal Organizer system is functional, user-friendly, and provides essential features for effective personal and administrative management.


# Section B : Problem Analysis

| **Class** | **Attributes**                                                                                                         | **Methods**                                                                                         |
| --------- | ---------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------- |
| User      | - Username<br>- Password<br>- Schedule <br>- ID                                                                        | - newUser <br>- checkPassword <br>*(check if username and password match)*<br> |
| Admin     | - adminUserName<br>    <br>- adminPassword                                                                             | - resetPassword<br>- removeUser<br>- editUser                                                       |
| Schedule  | - Status *(to tell if time is occupied)*                                                          | - setStatus<br>- printStatus                                                                        |
| Date      | - Year<br>- Month<br>- Day                                                                                             | - printDate                                                                                         |
| Time      | - Hour<br>    <br>- Minute                                                                                             | - printTime<br>- Print *(print everything, from schedule to time)*             |
| Organiser | - startTime<br>- eventName<br>- eventDescription<br>- eventType<br>- eventStatus  *(done or not)*| - setEventStatus<br>- getStatus <br>- removeEvent                                                   |
| Event     | - endTime                                                                                                              | - setEvent <br>- printEvent                                                                         |
| Reminder  |                                                                                                                        | - setReminder<br>- Notify<br>- printReminder                                                        |

The three main classes here are User, Schedule and Organiser. The admin class should be a subclass of User as it is a special type of user. Class Time should be a subclass of Date, which is a subclass of Schedule. It is done in this way to make operations when the time is on the same day easier. Meanwhile, events and reminders are both two different types of “events”. Hence, we gave the container “events” the name Organiser to avoid confusion. In other words, Event and Reminder are subclasses of Organiser.

The class User shall have an array of objects of the class Schedule to store different times of events. Then, the starting time and ending time of the Organiser shall point to each specific time in the schedule of each user. Hence, the two main classes are associated with the main class Schedule.


# Section C : Class Diagrams
[<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group2/analysis-design/images/class%20UML%20diagram.drawio%20non%20trasnpart.png">](https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group2/analysis-design/images/class%20UML%20diagram.drawio%20non%20trasnpart.png)
