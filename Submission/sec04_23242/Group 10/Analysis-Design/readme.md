# PROJECT PROPOSAL GROUP 10
## TOPIC: Event Scheduler

### Table of Contents
- [Section A: Flow Chart](##Flow-Chart)
- [Section B: Problem Analysis](##Problem-Analysis)
- [Section C: Class Diagram](##Class-Diagram)

## 📈 Flow Chart 📉
<image src = "Image/Flowchart.jpeg">
  
### Main process of the system
  
> __i) Login / Sign up:__
  - Identifying the user type, allowing individuals to choose **Organizer** or **Participant**
  - Exiting users can login directly
  - New user must sign up by provoding necessary credentials

> __ii) Organizer__
  - The main page of organizer contains 5 different sections:
  - **Create Event**: Create event and write the details of the event such as date, time venue and the descriptions of the event
  - **Manage Event**: Edit event details or cancel the event and send the notification to participants
  - **Update Event Status**: Update event status such as "Pending", "In Progress", "Completed"
  - **Feedback**:View and respond to participants feedback
  - **User Profile**: View personal infomation

> __iii) Participant__
   - The main page of organizer contains 5 different sections:
  - **View Event**: View event details that created by organizer after accept invitation
  - **View Reminder**: View reminder and turn on notification
  - **View Progress**: View event status such as "Pending", "In Progress", "Completed"
  - **Feedback**:Give feedback via the feedback form
  - **User Profile**: View personal infomation
    
## 📊 Problem Analysis 📑

> __i) Identify the objects and then the classes involved in the project. As for the class members (i.e., attributes and methods), include only the significant ones.__

|No.| Class                      | Attribute          | Method       |
|-----|----------------------------|--------------------|--------------|
|1|Profile            |name, age, address, background| inputInfo, updateInfo, viewInfo, getName, getAge, getAddress, getBackground|
|2|User|username, password, profile|getUserName, checkPassword, inputProfile, updateProfile, viewProfile|
|3|Organizer|organizationName, contactInfo|getOrganizationName, getContactInfo, setOrganizationName, setContactInfo, createEvent, cancelEvent, viewEvents, updateEvent, sendInvitations, menu|
|4|Participant|username, password|viewEvents, viewReminder, trackProgress, feedback, menu|
|5|Event|title,description,date (pointer to a Date object), time (pointer to a Time object), venue (pointer to a Venue object), status, organizer, participant|getTitle, getDescription, getDate, getTime, getVenue, set Status, getStatus, displayEvent, viewUpdateEvent, viewEventFeedback|
|6|Date|day, month, year|getDay, getMonth, getYear|
|7|Time|hour, minute|getHour, getMinute|
|8|Venue|name, location|getName, getLocation|

> __ii) Identify class relationships. Here, analyze two things:__

## 🧾 Class Diagram 🗂️
> __i) Classes – including attributes and methods__
> __ii) Class relationship – including association and inheritance__
<image src = "Image/PT2 Project UML.png">


