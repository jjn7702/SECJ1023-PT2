# 🩺 **DISEASE DIAGNOSIS SYSTEM** 💉
### By MedSight

# Phase 4 Final

## 📌**Source Code**
<ul>
  <li><a href="https://github.com/jjn7702/SECJ1023-PT2/tree/main/Submission/sec08_23242/MedSight/Final/source-code"> Source Code </a></li>
</ul>

## 📌**Report**
# 1.0 Introduction

  Our project Disease Diagnose system is a software application designed to diagnose disease based on  the symptoms entered by the user.  The main aim of this application is to ensure the users can take early precautions to treat their disease. The application will prompt the user to enter as many symptoms as they have and how long they have been sick to ensure accurate and early disease diagnosis. In addition, this system will also recommend to users which medicine they should take to treat the disease and also clinics and physicians according to their locations.

  In an era where healthcare is so crucial, the Disease Diagnosis System analyzes user entered symptoms and provides a preliminary diagnosis. Our system not only helps in identifying diseases at an early stage but also provides the user detailed description of their diseases, suggested medicines and nearby clinics information. It is designed to be user-friendly, ensuring that users can easily solve their health issues and also use it to improve their health conditions.

# 2.0 Project Description

The Disease Diagnose System is designed to enhance the healthcare experience by diagnosing diseases based on symptoms and illness duration entered by the users. Once symptoms are entered, the system will analyze the data to diagnose the possible disease the user is suffering from. In addition to diagnosing the disease, the system provides several key features:

+ Suggested Medicines:  The system suggests the user appropriate medications based on the diagnosed disease.

+ Clinic Referrals: There are some serious diseases which  require professional medical attention. And so our system will ask the user to enter their current location, it will recommend visiting a clinic nearby with the clinic’s name, location, availability and contact details.

+ Early Precautions: Users can take early precautions for their disease with the help of our system before confirming the diagnosis with doctors or healthcare professionals.

# 3.0 Objectives
Our disease diagnosis system is an exploration and implementation of innovations in healthcare to provide better diagnostic solutions.

- Early Detection and Diagnosis: Ensuring early detection and diagnosis of diseases to alert the user before confirming the diagnosis with professional physicians.

- User Convenience: Users only need to enter their symptoms, illness duration, existing diseases and some basic information, and the system will diagnose the disease they might be suffering from.

- Preventive Measures: Enabling users to easily diagnose their disease at home and take early precautions and preventive measures to manage and treat potential health issues effectively.

- User Health Improvement: Improving users' health conditions by providing timely and accurate disease diagnosis and detailed information about their disease, medicine suggestions and clinic referrals.

- Support for Healthcare Professionals: Supporting healthcare professionals, this system suggests doctors and healthcare professionals for further treatment based on the diagnosed disease, ensuring users receive professional medical advice when necessary.

# 4.0 UML Class Diagram
<image src = "https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec08_23242/MedSight/Analysis-Design/images/UML%20Class%20Diagram%20.png" width="1000" height="1000">

# 5.0 Class Explanation

+ Class Entity
Private member of class entity is name, this class has 5 public member which has 2 constructors, 1 mutator, 1 accessor and 1 function 

+ Class Clinic 
Clinic class has 4 private members which are stateName, clinicName, availability and ClinicNo. It has 11 public members which has 2 constructor, 4 mutator, 4 accessor and 1 function

+ Class UserInfo
UserInfo class has 6 private members which are gender, nophone, email, age. This class has 12 public members which has 2 constructors, 4 mutators, 4 accessors and 2 functions. 

+ Class MedHistory
MedHistory class has 3 private members which are existDisease, medicine and allergic. This class has 9 public members which has 1 constructor, 3 mutators, 3 accessors and 2 functions. 

+ Class Symptom 
Symptom class has 1 private member which is nameSym . This class has 3 public members which has 1 constructor, 1 mutator and 1 accessor.

+ Class Disease
Disease class has 3 private members which are nameDisease, decs, symptomCount. This class has 12 public members which has 3 constructors, 2 mutators, 2 accessors and 5 functions.

+ Class Suggested_Medicines
Suggested_Medicine has 2 private member2 which are medicines and duration. This class has 7 public members which has 2 constructors, 2 mutators, 2 accessors, and 1 function.

Three classes have been inherited from Class Entity which are Class Clinic, Class UserInfo and Class Medhistory. Class UserInfo has a composition relationship with Class MedHistory. Class Disease has an aggregation relationship with Class Symptom, indicating that a disease can have multiple symptoms. Class disease also has an aggregation relationship with Class Suggesred_Medicines. 


# 6.0 Benefits of The Proposed System

+ Convenient and Accessible Health Information
-- Users do not need to go to the healthcare facilities as often since this system provides the features for diagnosing the possible disease based on the symptom entered by the users.Thus, users can easily access the system even from their home without needing to go to the clinic first. 
-- Users can view the report of their health information after diagnosing the disease.

+ Early Disease Detection and Intervention
-- Users can detect earlier the possible disease they are suffering from before going to the healthcare facilities and they can avoid things that will worsen their condition before referring to the doctor. 
-- Users will also be provided with suggested medications for the non - critical diseases.

+ Time and Cost Efficiency
-- Users  can conveniently access the system from anywhere, eliminating the need to visit the healthcare facilities for minor or common health issues like flu or common cold. Thus, transportation costs will decrease.

+ Keeping Track of Users Record
-- The system will store the user's data in the file so that we can easily manage the user's data and the users can log in with a phone number without needing to enter their information again the next time they use the system.

+ Keeping Track of Current Disease
-- The system allows for the addition of new symptoms to existing diseases and the updating of diseases it can diagnose, enabling it to keep track of the current diseases globally.

# 7.0 Summary

  To conclude, our current disease diagnosis system mainly has three main features which are adding new symptoms to built in disease or existing disease sets in the system, adding new diseases and also diagnosing the disease itself. For the first feature, users are able to add new symptoms to the current or existing disease that have been set in the system so that the system can diagnose the disease more specifically based on the symptoms entered. Then, for the second feature, since there are still many diseases that haven’t been added in the system, this feature can ensure the system can keep track of the new discoverable diseases to increase the efficiency of the system. Next, for the third feature, the system can diagnose the possible diseases based on the symptoms entered by the user and they can also print the report consisting of the user’s information and the suggested medicines and clinic for the user to refer to.

  Additionally, this system can also be improved in terms of the user interface and the data storage capabilities. Since our current system only includes three features, implementing more features in the future would significantly improve the system efficiency and functionality. 

  In terms of teamworking, everyone puts in their maximum effort to complete their assigned task without delay. Furthermore, in case there are any problems with the assigned task, we will discuss it immediately either face to face or in the telegram group to ensure everyone is able to complete their assigned task efficiently. As a result, we were able to finish the whole project within the allocated time with the support of every member in our group. Throughout the entire process, it provided us with a great deal of valuable insights into team working, time management and also problem-solving. In short, this project has given us a whole new experience and knowledge in making our own C++ object - oriented programming project that can be used in the future.


