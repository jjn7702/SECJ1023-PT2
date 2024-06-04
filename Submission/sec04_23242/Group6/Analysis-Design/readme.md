# Fitness Progress Tracker System

## Section A: Flowchart
(Submission/sec04_23242/Group6/Analysis-Design/Flowchart.png "Optional title")
### Brief Description of the Main Process:

The Fitness Progress Tracker System initiates interaction with new users through a user-friendly registration process where they input essential information to create an account. After successfully creating an account, users are guided to log in by authenticating their credentials in order to ensure secure access to their account. Then, the users need to update their health metrics profile such as current weight, goal weight, and fitness goals which the system uses to tailor recommendations and monitor progress. This integration of registration, authentication, and profile updates is crucial for personalizing user experiences and ensuring that each user's fitness journey is aligned with their specific goals and preferences.

Once logged in, users interact with the system by choosing menu options including logging various physical activities, nutrition, and progress feedback. The system records specifics such as activity duration, intensity, type of food consumed, and caloric intake which is important especially for calculating calories burned. Besides, the users also can choose to update their profile especially in situations where they already achieved their previous goal and want to make a new goal. Furthermore, the system will analyze this compiled data to provide users with feedback on their progress towards their fitness goals, offering motivational insights and practical recommendations for improvement. This comprehensive approach to activity and nutrition management, coupled with profile updates and constructive feedback, creates a supportive environment that encourages users to maintain and enhance their health and fitness levels effectively.

## Section B: Problem Analysis

### Objects Involved in the Project


1. **User Object**
   - This object represents a system user and holds essential user data such as username and password.

2. **Profile Object**
   - This object contains detailed information about a specific user, such as their current weight, goal weight, and fitness goals.

3. **Goal Object**
   - This object stores individual goals for a user where each goal includes a description and a status indicating whether it has been achieved.

4. **ProgressTracker Object**
   - This object acts as the central management system for tracking user fitness activities and nutritional intake.

5. **Activity Objects (including subclasses: SportsActivity, CardioActivity, StrengthActivity)**
   - These objects represent different types of physical activities. Each type records specific details relevant to the activity, such as duration, intensity, and for specific subclasses, other attributes like distance, speed, sets, reps, etc. They are used to calculate calories burned and to log each session of physical activity.

6. **Nutrition Object**
   - This object holds data about dietary intake, such as the type of food and calories consumed.

7. **BodyweightExercises Object and WeightExercises Object**
   - These objects are specialized forms of StrengthActivity objects that focus on body weight exercise and weights training, respectively.

#### Classes Involved in the Project

1. **User**
    - **Attributes:**
        - `string username`
        - `string password`
        - `Profile profile`
        - `ProgressTracker tracker`
    - **Methods:**
        - `string getUsername()`
        - `string getPassword()`
        - `void setUsername(string username)`
        - `void setPassword(string password)`
        - `void registerUser(User users[], int userCount)`
        - `bool login(User users[], int userCount)`


2. **Profile**
    - **Attributes:**
        - `Goal* goals`
        - `double currentWeight`
        - `double goalWeight`
        - `string fitnessGoal`
    - **Methods:**
        - `double getCurrentWeight()`
        - `double getGoalWeight()`
        - `string getFitnessGoal()`
        - `void setCurrentWeight(double weight)`
        - `void setGoalWeight(double weight)`
        - `void setFitnessGoal(string goal)`
        - `void updateProfile(double currentWeight, double goalWeight, string fitnessGoal)`
        - `void displayProfile()`


3. **Goal**
    - **Attributes:**
        - `string description`
        - `bool isAchieved`
    - **Methods:**
        - `string getDesc()`
        - `bool getAchieved()`
        - `void setDesc(string desc)`
        - `void setAchieved(bool isAchieved)`
        - `void updateGoal(string desc, bool isAchieved)`
        - `void checkGoalStatus()`


4. **ProgressTracker**
    - **Attributes:**
        - `Activity* activities[]`
        - `Nutrition* nutritions[]`
    - **Methods:**
        - `void addActivity(Activity &activity)`
        - `void addNutrition(Nutrition &nutrition)`
        - `void showProgress()`
        - `void giveFeedback()`


5. **Activity**
    - **Attributes:**
        - `int duration`
        - `int intensity`
    - **Methods:**
        - `int getDuration()`
        - `string getIntensity()`
        - `void setDuration(int duration)`
        - `void setIntensity(int intensity)`
        - `virtual void displayActivity()`
        - `virtual double calculateCaloriesBurned(Profile &profile)`


6. **SportsActivity (inherited from Activity)**
    - **Attributes:**
        - `string sportType`
    - **Methods:**
        - `string getSportType()`
        - `void setSportType(string Stype)`
        - `double calculateCaloriesBurned(Profile &profile)`
        - `void displayActivity()`


7. **CardioActivity (inherited from Activity)**
    - **Attributes:**
        - `double distance`
        - `double speed`
    - **Methods:**
        - `double getDistance()`
        - `double getSpeed()`
        - `void setDistance(double dist)`
        - `void setSpeed(double spd)`
        - `double calculateCaloriesBurned(Profile &profile)`
        - `void displayActivity()`


8. **StrengthActivity (inherited from Activity)**
    - **Attributes:**
        - `int repsPerSet`
        - `int sets`
    - **Methods:**
        - `int getReps()`
        - `int getSets()`
        - `void setReps(int reps)`
        - `void setSets(int sets)`


9. **BodyweightExercises (inherited from StrengthActivity, indirectly from Activity)**
    - **Attributes:**
        - `string exerciseType`
    - **Methods:**
        - `string getExerciseType()`
        - `void setExerciseType(string Etype)`
        - `double calculateCaloriesBurned(Profile &profile)`
        - `void displayActivity()`

10. **WeightExercises (inherited from StrengthActivity, indirectly from Activity)**
    - **Attributes:**
        - `double weight`
    - **Methods:**
        - `double getWeight()`
        - `void setWeight(double weight)`
        - `double calculateCaloriesBurned(Profile &profile)`
        - `void displayActivity()`

11. **Nutrition**
    - **Attributes:**
        - `string food`
        - `int calories`
    - **Methods:**
        - `string getFood()`
        - `int getCalories()`
        - `void setFood(string food)`
        - `void setCalories(int cal)`
        - `void displayNutrition()`

### Class Relationships

#### Association Relationships

1. **User and ProgressTracker**
- **Relationship:** Composition
- **Justification:** The relationship between User and ProgressTracker is a composition because it demonstrates that each User must have a ProgressTracker to monitor and manage their fitness activities and nutrition. The ProgressTracker is a part of the user's fitness management system and its existence is dependent on the User. If the User is deleted, the associated ProgressTracker is also deleted. This ensures that the tracking of fitness progress is inherently linked to the user and cannot function independently. 

2. **ProgressTracker and Nutrition**
- **Relationship:** Aggregation
- **Justification:** ProgressTracker aggregates Nutrition. This relationship suggests that while ProgressTracker tracks multiple nutritional records, the existence of Nutrition objects is not dependent on the ProgressTracker. This means Nutrition entries can exist independently of the ProgressTracker even if one party is destroyed.

3. **User and Profile**
- **Relationship:**  Composition
- **Justification:** The relationship between User and Profile is a composition, indicating that each User must have a Profile to manage personal fitness goals and related information. This ensures that the lifecycle of the Profile is tightly coupled with the User. For example if the User (whole) is deleted, the associated Profile (part) is also deleted. This composition relationship models the real-world scenario where a user's profile, which includes their goals, current weight, and fitness targets, is inherently a part of the user’s overall data and cannot exist independently.
 

4. **Profile and Goal**
- **Relationship:** Aggregation
- **Justification:** Similar to Nutrition, Profile has aggregation with Goal. This means Profile manages Goal objects but does not strictly control their lifecycle. Profile objects (enclosing objects) do not necessarily have Goal objects (enclosed objects). Both of them can exist independently regardless of if one party is destroyed.

#### Inheritance Relationships

1. SportsActivity, CardioActivity, StrengthActivity BodyweightExercises and WeightExercises inherit from Activity
- **Relationship:** Inheritance
- **Justification:** These classes are specialized forms of Activity, each with unique attributes and behaviors that extend the base class Activity. Inheritance is used here to promote code reuse and polymorphic behavior. Each subclass extends the functionality of the base class and introduces specialized behaviors without duplicating code. For example are specific calorie burning calculations and  activity-specific attributes. 

3. BodyweightExercises and WeightExercises inherit from StrengthActivity, indirectly from Activity  
- **Relationship:** Inheritance
- **Justification:** Activity will be the base class and StrengthActivity will be the intermediate class. Then, the BodyWeightExercises and WeightExercises are inherited from the StrengthActivity and through it, indirectly from Activity. By inheriting from StrengthActivity, they not only gain the general attributes of Activity (duration, intensity) but also the specialized attributes of StrengthActivity (sets, repsPerSet).

## Section C: Class Diagram
