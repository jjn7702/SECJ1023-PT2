# Section A : 
**OBJECTIVES & PURPOSES**

**FLOW CHART**

![flowchart drawio](https://github.com/jjn7702/SECJ1023-PT2/assets/102563828/bba9a30c-5f96-4c12-be59-cd19195b1144) <br>

*Figure 1: Flowchart of Sleep Analyzer System* <br>

**CLASS DIAGRAM**
The class diagram represents a sleep analysis system that collects sleep data, analyzes it, and provides personalized recommendations to improve sleep quality. 

![SleepAnalyzer (3)](https://github.com/jjn7702/SECJ1023-PT2/assets/148436857/e965494f-45d2-4b4a-88b6-86d70c42b4f2)



# Section B : Implementation of the concepts
**(i) Module 1 : Sleep Data**

1.Encapsulation  
- SleepData class encapsulates sleep-related data with private member variables such as such as timestamp, duration, deepSleepDuration,lightSleepDuration and REMduration 
- It provides public methods including a constructor like SleepData and methods like getTimestamp and getDuration getREMduration to access these variables.
- The internal state of the object can only be modified through its methods.  

2. Composition 
- SleepSession class contains a vector of SleepData objects that spans multiple segments within a single sleep period.
- This indicates that a sleep session is composed of multiple sleep data entries, but SleepData objects can exist independently of SleepSession.
- For example, methods in this class such as getSessionDuration will operate on the contained SleepData objects to calculate the total duration of the sleep session.

**(ii) Module 2 : Sleep Analysis**
**(iii) Module 3 : Sleep Summary**
**(iv) Module 4 : User**



