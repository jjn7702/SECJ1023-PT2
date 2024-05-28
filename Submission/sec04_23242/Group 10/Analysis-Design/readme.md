# PROJECT PROPOSAL GROUP 10
## TOPIC: Event Scheduler

### Table of Contents
- [Section A: Flow Chart](##Flow-Chart)
- [Section B: Problem Analysis](##Problem-Analysis)
- [Section C: Class Diagram](##Class-Diagram)

## 📈 Flow Chart 📉
<image src = "Image/FlowChart.jpeg">
  
### Main process of the system
  
> __i) Login / Sign up:__
  - Identifying the user type, allowing individuals to choose **Organizer** or **Participant**
  - Exiting users can login directly
  - New user must sign up by providing the necessary credentials

> __ii) Organizer__
  - The main page of the organizer contains 5 different sections:
  - **Create Event**: Create an event and write the details of the event such as date, time venue and the descriptions of the event
  - **Manage Event**: Edit event details or cancel the event and send the notification to participants
  - **Update Event Status**: Update event status such as "Pending", "In Progress", "Completed"
  - **Feedback**:View and respond to participants' feedback
  - **User Profile**: View personal information

> __iii) Participant__
   - The main page of organizer contains 5 different sections:
  - **View Event**: View event details created by the organizer after accepting invitation
  - **View Reminder**: View the reminder and turn on the notification
  - **View Progress**: View event status such as "Pending", "In Progress", "Completed"
  - **Feedback**:Give feedback via the feedback form
  - **User Profile**: View personal information
    
## 📊 Problem Analysis 📑

> __i) Identify the objects and then the classes involved in the project. As for the class members (i.e., attributes and methods), include only the significant ones.__

|No.| Class                      | Attribute          | Method       |
|-----|----------------------------|--------------------|--------------|
|1|Profile            |name, age, address, background| inputInfo, updateInfo, viewInfo, getName, getAge, getAddress, getBackground|
|2|User|username, password, profile|getUserName, checkPassword, inputProfile, updateProfile, viewProfile|
|3|Organizer|organizationName, contactInfo|getOrganizationName, getContactInfo, setOrganizationName, setContactInfo, createEvent, cancelEvent, viewEvents, updateEvent, sendInvitations, menu|
|4|Participant|username, password|viewEvents, viewReminder, trackProgress, feedback, menu|
|5|Event|title, description, date (pointer to a Date object), time (pointer to a Time object), venue (pointer to a Venue object), status, organizer, participant|getTitle, getDescription, getDate, getTime, getVenue, set Status, getStatus, displayEvent, viewUpdateEvent, viewEventFeedback|
|6|Date|day, month, year|getDay, getMonth, getYear|
|7|Time|hour, minute|getHour, getMinute|
|8|Venue|name, location|getName, getLocation|

> __ii) Identify class relationships.__

**1) Association Relationships**
- **Composition**

**1. Event and Organizer:**

Event class has an attribute of organizer of type Organizer. 
Justification: An event needs organizer to enter the detail of the event and later send the invitation and notification to the participants. Thus, it shown that event is associated with organizer. 

**2. Event and Participant:**

Event class has an attribute of participant list of type Participant. 
Justification: An event needs a participant list to allow organizer to send the invitation thus there is a direct relationship where each event can associate with participant.  

**3. User and Profile:**

User class has an attribute profile of type Profile. 
Justification: Users need to enter their personal information such as name, age and address and this information is managed through the Profile class thus associating these two classes.  

- **Aggregation**

**1. Event and Venue:**

Event class has an attribute venue of type Venue. 
Justification: An Event needs a venue to carry out programs, thereby there is an association relationship.  

**2. Event and Time:**

Event class has an attribute venue of type Time. 
Justification: An Event occurs at a specific Time, hence associating it with Time class. 

**3. Event and Date:**

Event class has an attribute venue of type Date. 
Justification: An Event happens on a specific Date, thereby creating an association relationship. 

**2) Inheritance Relationships**

**1. User and Organizer:**

Organizer inherits from User. 
Justification: An organizer is a specific type of user with additional attributes and methods related to username and password, thus inheriting basic user properties. 

**2. User and Participant:**

Participant inherits from User. 
Justification: A participant is a specific type of user with additional functionalities that extend the basic user class that related to username and password, thus inheriting basic user properties.

3)	Class Diagram Justification

**User as a Base Class**: Since both Participant and Organizer share common attributes like username and password, it is logical to have a base User class.
  
**Participant and Organizer Inheritance**: Inheriting from User allows code reuse for common functionalities
  
**Association Relationship**: These relationships model real-world interactions between users, event progress tracking, and feedback mechanisms, ensuring that the design is intuitive and maintainable.


## 🧾 Class Diagram 🗂️

<image src = "Image/UMLdiagram.png">


