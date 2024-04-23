# How To Use System
As the user runs the application, he should see the following pages: 
## Page 1 : User Login

| ------------------ | --- |
| User : |     |
| Password :                        |     |
|                                   |     |
| New User? |     |
Once the user inputs their username , they shall be redirected to the second page. If either the username or the password is incorrect, they shall be requested to re-input the username and password for at most 5 times where there will be a cooldown period. For new users, they have an option to create a new account.
## Page 1.1 New User
| User :             |     |
| ------------------ | --- |
| Password :         |     |
| Confirm Password : |     |
| Press Enter        |     |
The new user needs to input their intended username, as well as their password.
## Page 2 : Menu

| 2.1              | See Timeline         |
| ---------------- | -------------------- |
| 2.2              | Add or Remove Events |
| Upcoming Event : | EventName            |
|                  |                      |
| Option :         | 2.1  / 2.2           |
In the menu page the user should see two options, one to see their timeline and another to edit events. Below the two options, the application will show the nearest upcoming event. Followed by that is the input of the user where they choose their following action.

## Page 2.1 : Timeline
The user's timeline should be shown in the following order

| Date 1                      |        |         |             |
| --------------------------- | ------ | ------- | ----------- |
| 1.                          | Time 1 | Event 1 | eventType 1 |
| 2.                          | Time 2 | Event 2 | eventType 2 |
|                             |        |         |             |
| Date 2                      |        |         |             |
| 3.                          | Time 3 | Event 3 | eventType 3 |
| 4.                          | Time 4 | Event 4 | eventType 4 |
|                             |        |         |             |
| 0                           | Back   |         |             |
| 00                          | Logout |         |             |
| Input number to show more : |        |         |             |
The user is able to input the number of their desired event to see more detailed descriptions of it. When the user inputs 0, they will be redirected to the previous page, and when the user inputs 00, they will logout. Inputs 0 and 00 will be consistent in the whole application.

## Page 2.1.1 Event Details

| Month                             | eventMonth        |
| --------------------------------- | ----------------- |
| Date                              | eventDate         |
| Starting Time                     | eventStart        |
| End Time                          | eventEnd          |
| Event Name                        | eventName         |
| Event Type                        | eventType         |
| Status                            | eventStatus       |
| Descriptions                      | eventDescriptions |
|                                   |                   |
| Press 0 to return , 00 to logout: |                   |
## Page 2.2 Add or Remove Events
In this page there will be 3 main options

| 1.                  | Add event    |
| ------------------- | ------------ |
| 2.                  | Remove event |
| 3.                  | Edit event   |
| 4.                  | Event status |
|                     |              |
| 0                   | return       |
| 00                  | logout       |
| Choose your option: |              |
## Page 2.2.1 Add Event
The user will input the details of their event in this page. 

| Month                             | eventMonth        |
| --------------------------------- | ----------------- |
| Date                              | eventDate         |
| Starting Time                     | eventStart        |
| End Time                          | eventEnd          |
| Event Name                        | eventName         |
| Event Type                        | eventType         |
| Status                            | eventStatus       |
| Descriptions                      | eventDescriptions |
|                                   |                   |
| Press 0 to return , 00 to logout: |                   |
## Page 2.2.2 Remove Event
The application will show the list of events in a similar manner to the timeline for the user to choose from.

| Date 1                         |        |         |             |
| ------------------------------ | ------ | ------- | ----------- |
| 1.                             | Time 1 | Event 1 | eventType 1 |
| 2.                             | Time 2 | Event 2 | eventType 2 |
|                                |        |         |             |
| Date 2                         |        |         |             |
| 3.                             | Time 3 | Event 3 | eventType 3 |
| 4.                             | Time 4 | Event 4 | eventType 4 |
|                                |        |         |             |
| 0                              | Back   |         |             |
| 00                             | Logout |         |             |
| Input number to remove event : |        |         |             |
## Page 2.2.2.1 Remove Confirmation
The user will need to confirm by pressing y.

| Are you sure to remove event eventName on eventDate? **It will no longer be available** (y/n) |     |
| --------------------------------------------------------------------------------------------- | --- |
When y is pressed, event will be erased from timeline. When either y or n is inputted, the user will be directed to page 2.2.2

## Page 2.2.3 Edit Event
The interface is similar to page 2.2.2

| Date 1                       |        |         |             |
| ---------------------------- | ------ | ------- | ----------- |
| 1.                           | Time 1 | Event 1 | eventType 1 |
| 2.                           | Time 2 | Event 2 | eventType 2 |
|                              |        |         |             |
| Date 2                       |        |         |             |
| 3.                           | Time 3 | Event 3 | eventType 3 |
| 4.                           | Time 4 | Event 4 | eventType 4 |
|                              |        |         |             |
| 0                            | Back   |         |             |
| 00                           | Logout |         |             |
| Input number to edit event : |        |         |             |
## Page 2.2.3.1 Edit Details
The user will be shown the details page, similar to page 2.2.1


| 1.                     | Month         | eventMonth        |
| ---------------------- | ------------- | ----------------- |
| 2.                     | Date          | eventDate         |
| 3.                     | Starting Time | eventStart        |
| 4.                     | End Time      | eventEnd          |
| 5.                     | Event Name    | eventName         |
| 6.                     | Event Type    | eventType         |
| 7.                     | Status        | eventStatus       |
| 8.                     | Descriptions  | eventDescriptions |
|                        |               |                   |
| 0                      | return        |                   |
| 00                     | logout        |                   |
|                        |               |                   |
| Choose event to edit : |               |                   |
After input, the user will redirected to confirm the edit.

## Page 2.2.3.2 Edit Confirmation
The user will need to confirm by pressing y.

| Are you sure to edit event eventName on eventDate (y/n) |             |
| ------------------------------------------------------- | ----------- |
| Changes :                                               | eventEdited |

When y is pressed, event will be edited. When either y or n is inputted, the user will be directed to page 2.2.3

## Page 2.2.4 Event Status
This page is for the user to change the status of an event from in progress to done. The interface is similar to page 2.2.3.

| Date 1                               |        |         |             |
| ------------------------------------ | ------ | ------- | ----------- |
| 1.                                   | Time 1 | Event 1 | eventType 1 |
| 2.                                   | Time 2 | Event 2 | eventType 2 |
|                                      |        |         |             |
| Date 2                               |        |         |             |
| 3.                                   | Time 3 | Event 3 | eventType 3 |
| 4.                                   | Time 4 | Event 4 | eventType 4 |
|                                      |        |         |             |
| 0                                    | Back   |         |             |
| 00                                   | Logout |         |             |
| Input number to change event status: |        |         |             |
## Page 2.2.4.1 Status Change Confirmation
The user will need to confirm by pressing y.

| Are you sure to eventName on eventDate is done? **It will no longer be shown on the timeline** (y/n) |     |
| ---------------------------------------------------------------------------------------------------- | --- |


When y is pressed, event will be changed to done. When either y or n is inputted, the user will be directed to page 2.2.4
