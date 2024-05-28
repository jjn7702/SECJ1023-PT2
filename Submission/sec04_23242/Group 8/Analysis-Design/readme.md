# Section A : Flow Chart

![flowchart drawio](https://github.com/jjn7702/SECJ1023-PT2/assets/102563828/bba9a30c-5f96-4c12-be59-cd19195b1144) <br>

*Figure 1: Flowchart of Sleep Analyzer System* <br>

The flowchart represents a sleep analyzer system that assists users in tracking and analyzing their sleep patterns. <br>
The program begins by printing instructions and prompting the user to enter their name. It then asks the user to <br>
input various sleep data, including the date, total time in bed, sleep duration, light sleep duration, deep sleep <br>
duration, and REM sleep duration. It then enters a loop where the user can decide to add more data collected from <br>
different data or stop entering more data. After collecting each set of data, the program adds it to the user's sleep records. <br>

Once the data collection phase is complete, the program generates a sleep report summarizing the data entered. It then <br>
proceeds to analyze the sleep cycles and assess sleep quality based on the recorded information. Finally, the program <br>
generates an improvement plan, offering suggestions to enhance the user's sleep quality. The program concludes by <br>
displaying these suggestions and terminating the execution.  

# Section B : Problem Analysis
**(i) Classes Involved, Attributes, Methods**
    

**1.  User**
    

-   Attributes: userID (string), name (string), age (int), weight (double), height (double), sleepSessions (vector<SleepSession>), sleepReport (pointer to SleepReport), sleepQualityAssessment (pointer to SleepQualityAssessment),  suggestions (vector<pointer to Suggestion>) ,sleepCycleAnalyzer (SleepCycleAnalyzer)
    

-   Methods: updateProfile(name: string, age: int, weight: double, height: double), analyzeSleep(), qualityAssessment (), generatelmprovementPlan()
    

**2.  SleepData**
    

-   Attributes: timestamp (string), duration (double), deepSleepDuration (double), lightSleepDuration (double), REMduration (double), session (SleepSession)
    

-   Methods: getTimestamp(), getDuration(), getSession()
    

**3.  SleepSession**
    

-   Attributes:  sessionID (string), startTime (string), endTime (string), sleepData (vector<pointer to SleepData>)
    

-   Methods: getSessionDuration()
    

**4.  SleepQualityAssessment**
    

-   Attributes:  sessionID (string), qualityScore (double), description (string), sleepData (vector<SleepData>)
    

-   Methods: assessQuality(), getQualityScore(), getDescription()
    

**5.  SleepCycleAnalyzer**
    

-   Methods: analyzeSleep(user:User), qualityAssessment(user:User)
    

**6.  SleepReport**
    

-   Attributes: reportDate (string), summary (string), recommendations (string)
    

-   Methods: generateSummary(user:User), generateRecommendations (user:User)
    

**7.  Suggestion**
    

-   Attributes: suggestionText (string)
    

-   Methods:  provideSuggestion(user: User)
    

**8.  ImprovementPlan**
    

-   Attributes: planDetails(string)
    

-   Methods: createPlan (user: User)


  
**(ii) Relationships**
    
****Inheritance****

-   Classes that involve inheritance relationship are class Suggestion which is considered as a base class and class ImprovementPlan which is considered as a derived class.
    

-   The reason that these two classes are in inheritance relationship is because a class Suggestion represents a basic recommendation or piece of advice. Therefore, it could be a general suggestion to improve sleep quality. In the other hand, a class ImprovementPlan is a more comprehensive and detailed plan that might include multiple suggestions. It is inherited from class Suggestion because it can be seen as an extension of class Suggestion but with additional details of method such as 'createPlan' method.
    

-   Besides, the reason they should be modelled with inheritance relationship is because inheritance leads class ImprovementPlan, a derived class can also use the attributes of class Suggestion, a base class and on top of that, we can add more functionalities by modifying the base class Suggestion so that a detailed series of suggestions aimed at improving sleep quality can be generated.

****Aggregation**** 

-    Definition: a special type of association which is one-way relationship. An aggregation relationship is implemented by objects containing pointers to other objects. 

-    The reason for using aggregation is the child's objects can exist independently of the parents' objects. This means that the lifecycle of the child is not tied to the lifecycle of the parents' class. Second, since the child's object is not tightly coupled with the parents' class, it can be reused in different contexts or with different parents' objects. Third, aggregation allows for building modular systems where components can be easily swapped or replaced without affecting the rest of the coding. Finally, aggregation simplifies maintenance and updates because changes to the part do not necessarily impact the parents.  


-    Class *sleepQualityAssessment* has a collection of pointers to *class SleepData* objects *sleepData: vector<SleepData*>.* This indicates aggregation because *class SleepData* object can exist independently of the *class SleepQualityAssessment* object that references them. They are aggregated into *SleepQualityAssessment* to analyze and assess sleep quality, but their lifecycle is not tied to it. 

 
-    *User* class has a collection of pointers to *class SleepQualityAssessment* objects *SleepQualityAssessment: SleepQualityAssessment*.* This indicates aggregation because *class SleepQualityAssessment* object can exist independently of the *class User* object that references them. It can be associated with multiple users and its lifecycle is not managed by the *class User*. 


-    *User* class has a collection of pointers to *class Suggestion* objects *suggestions: vector<Suggestion*>*. This indicates aggregation because *class Suggestion* object can exist independently and be shared among different users. 


-    *User* class has a collection of pointers to *class SleepReport* objects *SleepReport: SleepReport**. This indicates aggregation because *class SleepReport* object can exist independently of the *class User*. 

****Composition**** 

-    Definition: a restricted version of aggregation in which the enclosed and enclosed objects are highly dependent on each other. 
 

-    The reason for using composition is that the parents's object is responsible for the lifecycle of the child's object. The child cannot exist without the parents' class. Second, composition enhances encapsulation by ensuring that the child is tightly bound to the parents' class, making the parents's object a single cohesive unit. Third, the child's objects are created, managed, and destroyed by the parents' object, ensuring consistency and integrity within the parents' class. 

 
-    The *SleepSession* class has a collection of *class SleepData* objects *SleepData: vector<SleepData>.* This relationship is a composition because *class SleepData* objects are part of a *SleepSession* class, and their lifecycle is tied to the *class SleepSession*. 


-    The *class User* has a collection of *class SleepSession* objects *sleepSession: vector<SleepSession>.* This suggests composition because the *SleepSession* objects are tightly coupled with the *User* class and their lifecycle is managed and controlled by the *User* class. 

 
-    The *User* class has a *class SleepCycleAnalyzer* object *SleepCycleAnalyzer: SleepCycleAnalyzer*. This is a composition relationship because the *class SleepCycleAnalyzer* is a part of the User class, and its lifecycle is managed by the *User* class. It is created and destroyed with the *class User*. 



# Section C : Class Diagram
The class diagram represents a sleep analysis system that collects sleep data, analyzes it, and provides personalized recommendations to improve sleep quality. 

![SleepAnalyzer drawio (1)](https://github.com/jjn7702/SECJ1023-PT2/assets/147962293/9bb82ecf-b8ca-44f7-aa98-d46eba2e147b)
