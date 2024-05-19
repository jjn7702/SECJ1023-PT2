# Section A : Flowchart 

# Section B : Problem Analysis

| **Class** | **Attributes**                                                                                                         | **Methods**                                                                                         |
| --------- | ---------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------- |
| User      | - Username<br>- Password<br>- Schedule <br>- ID                                                                        | - newUser <br>- checkPassword <br>{:: comment}*check if username and password match*{;/comment}<br> |
| Admin     | - adminUserName<br>    <br>- adminPassword                                                                             | - resetPassword<br>- removeUser<br>- editUser                                                       |
| Schedule  | - Status {:: comment}*to tell if time is occupied*{;/comment}                                                          | - setStatus<br>- printStatus                                                                        |
| Date      | - Year<br>- Month<br>- Day                                                                                             | - printDate                                                                                         |
| Time      | - Hour<br>    <br>- Minute                                                                                             | - printTime<br>- Print {:: comment}*print everything, from schedule to time* {;/comment}            |
| Organiser | - startTime<br>- eventName<br>- eventDescription<br>- eventType<br>- eventStatus  {:: comment}*done or not*{;/comment} | - setEventStatus<br>- getStatus <br>- removeEvent                                                   |
| Event     | - endTime                                                                                                              | - setEvent <br>- printEvent                                                                         |
| Reminder  |                                                                                                                        | - setReminder<br>- Notify<br>- printReminder                                                        |


# Section C : Class Diagrams
