# Section A : 
**OBJECTIVES & PURPOSES**
- To provide users with a platform to track and monitor their sleep patterns.

- To analyze sleep data and provide insights into sleep quality, duration, and stages (deep sleep, light sleep, and REM sleep).

- To offer personalized recommendations for improving sleep quality based on the user's sleep data.

- To educate users on the importance of sleep and provide resources for better sleep habits.


**FLOW CHART**

![flowchart drawio](https://github.com/jjn7702/SECJ1023-PT2/assets/102563828/bba9a30c-5f96-4c12-be59-cd19195b1144) <br>

*Figure 1: Flowchart of Sleep Analyzer System* <br>

**CLASS DIAGRAM**
- The class diagram represents a sleep analysis system that collects sleep data, analyzes it, and provides personalized recommendations to improve sleep quality. 

![SleepAnalyzer (4)](https://github.com/jjn7702/SECJ1023-PT2/assets/148436857/4d621d39-2445-47f0-a3d2-ca380e654b84)



# Section B : Implementation of the concepts
**(i) Module 1 : Sleep Data**

1. **Encapsulation**  
- 'SleepData' class encapsulates sleep-related data with private member variables such as such as 'timestamp', 'duration', 'deepSleepDuration','lightSleepDuration' and 'REMduration' 
- It provides public methods including a constructor like 'SleepData' and methods like 'getTimestamp' and 'getDuration', 'getREMduration' to access these variables.
- The internal state of the object can only be modified through its methods.  

2. **Composition** 
- 'SleepSession' class contains a vector of 'SleepData' objects that spans multiple segments within a single sleep period.
- This indicates that a sleep session is composed of multiple sleep data entries, but 'SleepData' objects can exist independently of 'SleepSession'.
- For example, methods in this class such as 'getSessionDuration' will operate on the contained 'SleepData' objects to calculate the total duration of the sleep session.

**(ii) Module 2 : Sleep Analysis**
1. **Encapsulation**
   - The `SleepQualityAssessment` class:
      - Encapsulates the qualityScore and description attributes and provides getter methods to access these values.
   - The `SleepCycleAnalyzer` class:
      - Encapsulates the logic for analyzing sleep data and assessing sleep quality within its methods.
    
2. **Composition**
   - The `SleepCycleAnalyzer` class:
      - The SleepCycleAnalyzer class uses the SleepQualityAssessment class to return the results of its analysis, demonstrating the "has-a" relationship.

**(iii) Module 3 : Sleep Summary**
1. **Encapsulation**
   - The `SleepReport` class:
     - Encapsulates `report date`, `summary`, and `recommendations` as private member variables.
     - Provides public member functions `getReportDate()`, `getSummary()`, and `getRecommendations()` to access these private members.
     - Organizes code into logical units, enhancing readability and maintainability.
   - Use of `auto`:
     - Encapsulates the type of the loop variable `session` within the compiler's type deduction mechanism.
     - Hides the implementation details of the type from the rest of the code.
     - Decouples the loop variable `session` from the specific type of the container `sleepSessions`.
     - Facilitates changing the container type without affecting the loop logic.

2. **Inheritance**
   - The `ImprovementPlan` class:
     - Inherits from the `Suggestion` class.
     - Inherits the `provideSuggestion()` method.
     - Overrides `provideSuggestion()` to provide its own implementation.
     - Establishes a class hierarchy from `Suggestion` to `ImprovementPlan`, clarifying their relationships.

3. **Polymorphism**
   - The `Suggestion` class:
     - Provides a virtual method `provideSuggestion()`.
   - The `ImprovementPlan` class:
     - Overrides the `provideSuggestion()` method.
   - The `User` class:
     - Has a method `displaySuggestions()` that takes a vector of `Suggestion` objects.
     - Can handle objects of type `ImprovementPlan` or any other subclass of `Suggestion`.
     - Reduces coupling between classes, making it easier to change one class without affecting others.
     
**(iv) Module 4 : User**



