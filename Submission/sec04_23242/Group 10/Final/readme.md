# PROJECT REPORT GROUP 10
## TOPIC: Event Scheduler

### Table of Contents
- [1.0 Introduction]
- [2.0 Objectives and Purposes of The System]
- [2.1 Objectives of The System]
- [2.2 Purpose of The System (What Users can do?)]
- [3.0 Flow Chart and UML Class Diagram]
- [4.0 Implementation of The Concept]
- [5.0 Conclusion]

## 📈 Introduction 📉
  In today's fast-paced world, effective time management is crucial for both personal and professional success. Hence, in this project we will create a "Event Scheduler" program using C++. Written in C++, this program enables users to create and view events while ensuring that no two events overlap. By leveraging the power and efficiency of C++, the Event Scheduler offers a robust and reliable solution for individuals and organizations to manage their schedules effectively. By leveraging the capabilities of object-oriented programming principles in C++, the program provides a high-performance, reliable and user-friendly interface for handling various scheduling tasks to ensure scalability, maintainability and ease of use. In reality, the event scheduler is a sophisticated application designed to streamline the process of event management and scheduling. The ability to schedule events efficiently can significantly enhance productivity and ensure that important tasks and commitments are not overlooked.

## 🎯 Objective and Purpose of The System 📌
### 💡Objectives of The System 💡
•	Better time management: Automate the process of event management including scheduling the event and maintaining a calendar of activities. 
•	Enhance productivity: Allow organizers to promote events on our platform and the participants can choose their interested events. This system also gives the convenience to company or organization for arranging and managing their upcoming and past events.
•	Improve organization: Provide a structured way to manage and view events, enhancing the user's ability to stay organized and on top of their schedule.
•	User Convenience: The user-friendly interface and flexible features are designed to make the system easy to use for individuals and organizations alike, catering to various scheduling needs.

### 🚩Purpose of The System 🚩
•	To create, schedule and manage events such as book fairs, circus shows and so on which will be arranged in ascending order based on the date and time.
•	To see an overview of the events such as the date, time, venue and description of an event.
•	To view their scheduled events for managing their time and events better.
•	To search and add the interested event into wish list.

## 📑Flow Chart and UML Class Diagram	🗒️
<image src = "Images/Title.jpg">

## 📚 Implementation of The Concept 📚
1. Encapsulation

   Encapsulation combines attributes and methods in one package and hides the implementation of data from the user of the object. It restricts direct access to some of the object's components, which can prevent the accidental modification of data.
Justification: Address class encapsulates the data members and provides public methods to access and modify these members.

2. Aggregation

   Aggregation is a special type of association which is one way relationship. Aggregation represents a "has-a" relationship where the child can exist independently of the parent. Aggregation is implemented by objects contain pointer to other object.
Justification: In both Participant class and Organizer class, the Feedback object is an example of aggregation. The Feedback class is a part of the Participant and Organizer class, but it can exist independently.

3. Composition

   Composition is restricted version of aggregation in which the enclosing and enclosed objects are highly dependent on each other. If the parent object is destroyed, the child object is also destroyed. Composition is implemented by the nested objects. 
Justification: In code, Address should not exist outside Profile. The Profile class contains an Address object directly, meaning the Address object is created and destroyed with the Profile object.



## 📈 Conclusion 📉
  To put in nutshell, event scheduler is a valuable tool for enhancing personal productivity and time management. It simplifies the process of managing commitments and helps users stay on top of their schedules, ensuring that no important event is overlooked. This tool can be especially beneficial in both personal and professional setttings, where efficient time management is crucial for success.
  
  Our project, Event Scheduler program in C++ effectively demonstrates the use of object-oriented programming to create a practical and useful application. By providing functionalities to manage events, it aids users in organizing their schedules efficiently. The modular design ensures that the program can be easily extended and customized to meet additional requirements. Besides that, our system has offered a comprehensive solution managing and scheduling events. With its intuitive interface and robust features, users can easily stay organized and on top of their commitments. For both personal and professional use, this system streamlines event management to ensure the important events and tasks will never be missed.
  
  This project is very useful for our future as it has developed our application development skills effectively. Also, special thanks to our lecturer, Dr. Lizawati for her help and guidance throughout this project.
