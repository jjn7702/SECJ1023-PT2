# Section A : 
**INTRODUCTION**
The Sleep Analyzer System is an advanced platform designed to track, monitor, 
analyze, and enhance users’ sleep patterns with the awareness of the importance of 
sleep for overall health and well-being, the system offers a comprehensive solution. It 
aims to provide individuals with deep insights into their sleep habits, facilitating 
informed decision to improve sleep quality. By leveraging data-driven insights, the 
Sleep Analyzer System aims to provide personalized recommendations and actionable 
plans tailored to each user’s unique sleep profile. This report outlines the functionalities 
and benefits of the system, emphasizing its role in empowering users to achieve optimal 
sleep health.

**PURPOSE**
The primary purpose of the Sleep Analyzer System is to assist users in 
understanding, managing, and enhancing their sleep quality. By offering detailed 
analysis and personalized recommendations based on individual sleep data, the system 
aims to:
• Track and monitor sleep patterns.
• Provide insights into sleep stages and overall sleep quality.
• Enable users to make informed decisions regarding sleep habits and routines.
• Offer actionable plans for improving sleep health based on data-driven insights.
The Sleep Analyzer System aims to empower users to take proactive steps towards 
achieving better sleep quality through these functionalities. By having excellent sleep 
quality, it will contribute to their overall health and quality of life

**FLOW CHART**

![new flowchart drawio](https://github.com/jjn7702/SECJ1023-PT2/assets/102563828/b25fce48-0b89-4ae3-9fde-0a0d4e1d3bc8) <br>

*Figure 1: Flowchart of Sleep Analyzer System* <br>

**CLASS DIAGRAM**
- The class diagram represents a sleep analysis system that collects sleep data, analyzes it, and provides personalized recommendations to improve sleep quality. 

![SleepAnalyzer (4)](https://github.com/jjn7702/SECJ1023-PT2/assets/148436857/4d621d39-2445-47f0-a3d2-ca380e654b84)



# Section B : Implementation of the concepts
**(i) Module 1 : Sleep Data**

1. **Encapsulation**  
- `SleepData` class encapsulates sleep-related data with private member variables such as such as `timestamp`, `duration`, `deepSleepDuration`,`lightSleepDuration` and `REMduration` 
- It provides public methods including a constructor like `SleepData` and methods like `getTimestamp` and `getDuration`, `getREMduration` to access these variables.
- The internal state of the object can only be modified through its methods.  

2. **Composition** 
- `SleepSession` class contains a vector of `SleepData` objects that spans multiple segments within a single sleep period.
- This indicates that a sleep session is composed of multiple sleep data entries, but `SleepData` objects can exist independently of `SleepSession`.
- For example, methods in this class such as `getSessionDuration` will operate on the contained `SleepData` objects to calculate the total duration of the sleep session.

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
       
4. **Composition**
   - The `SleepReport` class:
     - Utilizes `SleepSession` objects to generate sleep reports.
     - `generateSummary` method:
       - Iterates through the vector of `SleepSession` objects.
       - Calculates total and average sleep durations, including deep sleep, light sleep, and REM sleep.
     - `generateRecommendations` method:
       - Analyzes average sleep duration from `SleepSession` objects.
       - Provides tailored sleep recommendations.
     - `printReport` method:
       - Calls `generateSummary` and `generateRecommendations`.
       - Compiles a complete sleep report based on data from `SleepSession` objects.
   - This composition relationship indicates that `SleepReport` "has" `SleepSession` objects, meaning `SleepReport` relies on the `SleepSession` objects to fulfill its responsibilities.
     
**(iv) Module 4 : User**
1. **Encapsulation**
   - The `User` class encapsulates user attributes which is `userID`, `name`, `age`, `weight`, 
and `height` and methods like `updateProfile`, `addSleepSession`, `analyzeSleep`, and 
`generateReport` to manipulate these attributes.
-The private attributes are accessed and 
modified through public methods, ensuring control over the data.
   
2. **Composition**
    - The `SleepSession` is directly contains instances of `SleepData` object 
`vector<SleepData>`.
- The `SleepData` instances are tightly bound to their respective `SleepSession` 
instances means that when a `SleepSession` is created, its associated `SleepData` instances 
are also initialized. Conversely, when the `SleepSession` is destroyed, all its contains 
`SleepData` instances are automatically destroyed as well.
-The `SleepCycleAnalyzer` is an instance of `SleepCycleAnalyzer` directly embedded 
within the User class. It performs analysis on the sleep sessions owned by the User.

3. **Aggregation**
   - The User class aggregated a `SleepReport` object pointer. This represents that a 
`User` has an associated `SleepReport` that contains summary information and 
recommendations.
- The `User` class aggregates a pointer to a `SleepQualityAssessment` object,
indicating that the user’s sleep quality can be assessed and updated independently.
- The `vector<Suggestion*>suggestion` in the `User` class can be considered as 
aggregation. The User class contains `Suggestion` objects, but they can exist 
independently of the `User` class
   
4. **Array of Objects**
   - The User class contains a vector<SleepSession> which is an array of 
SleepSession objects. This allows the User to manage multiple sleep sessions.

# References
1.	Yilmaz, D., Tanrikulu, F., & Dikmen, Y. (2017). Research on sleep quality and the factors affecting the sleep quality of the nursing students. PubMed, 43(1), 20–24. https://doi.org/10.12865/chsj.43.01.03
  -	Taken for sleep quality score calculation in the SleepQualityAssessment class.

2.	Ms, J. L. (2024, January 18). How much deep, light, and REM sleep do you need? Healthline. https://www.healthline.com/health/how-much-deep-sleep-do-you-need#stages-of-sleep
  -	The article provides information on the recommended ranges for sleep duration, deep sleep, light sleep, and REM sleep. The information is used in the ImprovementPlan class in the createPlan method to provide suggestions for improving sleep quality.

3.	Patel, A. K., Reddy, V., Shumway, K. R., & Araujo, J. F. (2024b, January 26). Physiology, sleep stages. StatPearls - NCBI Bookshelf. https://www.ncbi.nlm.nih.gov/books/NBK526132/
  -	The article provides information on the different sleep stages and their typical duration. This information is used for sleep stages percentage calculation in the main function.




