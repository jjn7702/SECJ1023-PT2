# Programming Technique II Phase 4: Project Finale

**DATE:** 27 May 2024

**LECTURER'S NAME:** Ms. Lizawati Binti Mi Yusuf

| NAME                                    | MATRICS NUMBER |
|-----------------------------------------|----------------|
| Muhammad Nazmi Bin Mohd Saifulizam      | A23CS0135      |
| Muhammad Azfar bin Sharifuddin          | A23CS0123      |
| Dillan Revada                           | A23CS0290      |
| Muhammad Danial Bin Nasharudin          | A23CS0125      |

# SECTION A

## 1.0 Project Description

### 1.1 Project Synopsis


**Synopsis**  
The Fitness Progress Tracker system is designed to support individuals on their journey toward achieving their health and fitness objectives. This comprehensive tool enables users to set specific fitness goals, such as weight loss or muscle gain, and meticulously track their progress. It provides a robust platform for recording various fitness activities, including workouts and daily meals, ensuring that users can monitor every aspect of their health and physical wellness.

Moreover, the system is efficient at monitoring user physical changes, particularly weight loss, to ensure they always keep track of their fitness goals. Along the way, it offers personalized feedback that helps users toward realizing their fitness goals. This supportive tool not only improves individual health but also encourages a sustained commitment to a healthier lifestyle.

In addition to its functional capabilities, the Fitness Progress Tracker prioritizes user experience and data security. It features a user-friendly interface while incorporating security measures to protect user data. This focus on usability and privacy indicates that the system is a reliable and trustworthy helper for anyone looking to enhance their physical health and well-being.

### 1.2 Objective/Purpose

The Fitness Progress Tracker is designed to help users manage their fitness routines and track their progress effectively. It aims to:


1. **Tracking Fitness Activities:**
    - Provide a user-friendly platform where users can easily log various fitness activities, such as cardio, strength training, and body weight workouts.
    - The system will allow for the entry of details like duration, type of activity, and perceived intensity, enabling users to maintain a detailed record of their exercise routines over time.


2. **Monitoring Progress:**
    - Enable users to set personal fitness goals related to aspects such as weight loss and muscle gain.
    - The system will track these goals by comparing the current weight with its goal weight, offering users a clear view of whether their goal has been achieved or not. This feature helps in maintaining users’ motivation.


3. **Providing Basic Feedback:**
    - Based on the user’s logged activities and progress towards set goals, the system will generate basic feedback.
    - This might include simple messages of encouragement and/or basic statistical feedback on their performance improvements over time.
    - Such interactions are intended to help users stay engaged and motivated throughout their fitness journey.

### 1.3 What Users Can Do in the System


1. **Set Profile:**
    - Users can define their fitness goals, such as losing weight or gaining muscle. They will be asked for their current weight and goal weight to help personalize their fitness journey.


2. **Log Activities:**
    - Users can log various fitness activities, including workouts, exercises, and nutrition. They can record details such as duration, intensity, distance, and calories burned to maintain a comprehensive log of their efforts.


3. **Track Progress:**
    - The users can track the progress related to their fitness activities and nutrition over time. This feature provides a clear view of overall activities and improvements, helping users stay informed about their journey.


4. **Receive Feedback and Recommendations:**
    - Users will be provided with simple feedback and recommendations based on the user's profile and goals. This helps users stay motivated and on track towards achieving their fitness objectives.

### 1.4 Output of the System

The Fitness Progress Tracker offers several useful outputs to help users monitor and achieve their fitness goals:


1. **Activity Tracking:**
    - The system provides a detailed log of the user's workouts, exercises, and fitness activities, including information like duration, intensity, distance, and calories burned, ensuring users have a comprehensive record of their physical activities.


2. **Nutritional Tracking:**
    - The system provides a detailed log of the user's nutritional intake, including information like food name and its calories, helping them ensure they are getting the right nutrients and managing their calorie intake according to their goals.


3. **Progress Summary:**
    - The system generates an overall summary of the user's fitness progress, highlighting their activities and nutrition over time. This summary helps users see what they have been doing and how it contributes to their goals.


4. **Weight Monitoring:**
    - By tracking changes in weight, the system allows users to see if they are moving closer to their desired goals. This feature provides a clear indication of progress in weight objectives.


5. **Feedback and Tips:**
    - The system offers simple personalized feedback and tips based on the users’ profile. This helps users stay motivated and make informed decisions to improve their fitness progress.

## 2.0 Analysis and Design 

### 2.1 UML Diagram
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/61c850d3-434c-47fe-a3ae-97158fae8d6e)


### 2.1 Flowchart
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/b4766f82-a1aa-462b-9256-f7df2b1e17f0)

**Brief Description of the Main Process**: The Fitness Progress Tracker System initiates interaction with new users through a user-friendly registration process where they input username, password and update profiles such as current weight, goal weight, and fitness goals to create an account. After successfully creating an account, users are guided to log in by authenticating their credentials in order to ensure secure access to their account. This integration of registration, profile updates and authentication is crucial for better user experiences and ensuring that each user's fitness journey is aligned with their specific goals and preferences.
Once logged in, users interact with the system by choosing menu options including logging various physical activities, nutritions and progress feedback.  The system records specifics such as activity duration, intensity, type of food consumed, and caloric intake which is important especially for calculating calories burned. Besides, the users also can choose to update their profile especially in situations where they already achieved their previous goal and want to make a new goal. Furthermore, the system provides users with feedback on their progress towards their fitness goals. This comprehensive approach to activity and nutrition management, coupled with  profile update and simple constructive feedback, creates a supportive environment that encourages users to maintain and enhance their health and fitness levels effectively.


# SECTION B

## 1.0 Encapsulation
Encapsulation is the bundling of data attributes and methods that operate on that data within a single unit or class, and restricting access to some of the object's components. All of the classes like Goal, Profile, Activity Nutrition and User have private data members and public Accessor and Mutator methods for outside the class to interact with their members. 
Here is the Explanation:

### Goal Class
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/b77c6876-5b25-4369-9cae-f16c2a4b2522)

- Private Data Members: description and isAchieved
- Accessor and Mutator: `getDesc()`, `getAchieved()`, `setDesc()`, `setAchieved()`

### Profile Class
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/f4d7ab97-ec0d-492d-ae8d-b7ab27bd0963)
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/ebb4219b-ae18-4e7b-950e-ca4a7f616101)

- Private Data Members: currentWeight, goalWeight
- Accessor: `getCurrentWeight()`, `getGoalWeight()`

### Nutrition Class
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/f1051409-2d20-4408-a87f-2de7dd754df1)

- Private Data Members: food, calories
- Accessor and Mutator: `getFood()`, `getCalories()`, `setFood()`, `setCalories()`

### Activity Class
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/99952fd0-77a4-4585-b767-c6ae3f4e6641)

- Private Data Members: duration, intensity
- Accessor: `getDuration()`, `getIntensity()`

### SportsActivity Class
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/135f1546-ccba-49f2-9dec-009b42bfbb89)

- Private Data Members: sportType
- Mutator: `setSportType()`

### CardioActivity Class 
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/d909f20f-f72b-453b-98b7-c7e3fe74fa5c)

- Private Data Members: distance
- Accessor and Mutator: `getDistance()`, `setDistance()`

### StrengthActivity Class
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/2389a85d-7125-47bf-b17e-fed56ae94bd3)

- Private Data Members: repsPerSet, sets
- Accessor and Mutator: `getReps()`, `getSets()`, `setReps()`, `setSets()`

### BodyWeightExercise Class
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/a196b1d3-1730-4d8d-a601-de76d5b8c3a3)

- Private Data Members: exerciseType
- Accessor and Mutator: `getExerciseType()`, `setExerciseType()`

### WeightExercise Class
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/2578f3b0-6abd-493b-9683-135bbda51bc5)

- Private Data Members: weight
- Accessor and Mutator: `getWeight()`, `setWeight()`

### User Class
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/15627377-446c-41d7-ab59-15a599e00f3c)

- Private Data Members: username, password
- Accessor and Mutator: `getUsername()`, `getPassword()`, `setUsername()`, `setPassword()`

**Conclusion**: We use encapsulation to protect the internal state of objects and ensure that they can only be modified through well-defined interfaces. This helps in maintaining data integrity and hiding the complexity of the implementation from the user. By using encapsulation, it allows us to control how data is accessed and modified, ensuring that the object's state remains consistent and valid.

## 2.0 Association (Composition)
Composition is a whole-part relationship with strong ownership. It represents that the enclosing object (whole) “consists of” enclosed objects (parts). The existence of the enclosed objects is determined by the enclosing objects. In this case, the User class has a composition relationship with the Profile class and ProgressTracker Class.
Here is the Explanation:

### User and Profile

- The relationship between User and Profile is a composition, indicating that each User must have a Profile to manage personal fitness goals and related information.
- This ensures that the lifecycle of the Profile is tightly coupled with the User. For example, if the User (whole) is deleted, the associated Profile (part) is also deleted.
- This composition relationship models the real-world scenario where a user's profile, which includes their goals, current weight, and target weight, is inherently a part of the user’s overall data and cannot exist independently.

### User and ProgressTracker

- The relationship between User and ProgressTracker is a composition because it demonstrates that each User must have a ProgressTracker to monitor and manage their fitness activities and nutrition.
- The ProgressTracker is a part of the user's fitness management system and its existence is dependent on the User.
- If the User is deleted, the associated ProgressTracker is also deleted.
- This ensures that the tracking of fitness progress is inherently linked to the user and cannot function independently.


## 3.0 Association (Aggregation)

Aggregation is a special form of association which is a one-way relationship. It models a "has-a" relationship between classes where the enclosing class "has-a" enclosed class. The existence of both enclosing and enclosed objects are independent. In this case, there are three aggregation relationships which are ProgressTracker and Activity, ProgressTracker and Nutrition, as well as Profile and Goal. Here is the explanation:

### ProgressTracker and Activity
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/4c4c23a6-21c2-448b-b762-d3aeae6a470f)
- The relationship between ProgressTracker and Activity is aggregation where both enclosing objects and enclosed objects can exist independently.
- In this context, the ProgressTracker class "has-a" and manages multiple Activity objects, but these Activity objects can exist independently of the ProgressTracker.
- The ProgressTracker class is designed to keep track of a user's fitness progress by recording various activities they perform which hold arrays of Activity objects to store and manage these activities.

### ProgressTracker and Nutrition
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/4f24f8ef-0a94-4d50-8b32-423b09efc340)
- ProgressTracker aggregates Nutrition.
- In this context, the ProgressTracker class "has-a" and manages multiple Nutrition objects, but these Nutrition objects can exist independently of the ProgressTracker.
- This relationship suggests that while ProgressTracker tracks multiple nutritional records, the existence of Nutrition objects is not dependent on the ProgressTracker.
- The ProgressTracker class is designed to keep track of a user's fitness progress by recording various nutritional intakes along with activities which hold arrays of Nutrition objects to store and manage these nutritional entries.

### Profile and Goal
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/5662593e-c562-42ca-966d-fb9d6e5b777a)
- Profile has aggregation with Goal.
- This means Profile manages Goal objects but does not strictly control their lifecycle.
- Profile objects (enclosing objects) do not necessarily have Goal objects (enclosed objects).
- Both of them can exist independently regardless of if one party is destroyed.
- The Profile class is designed to manage user details related to their fitness journey, including current weight, goal weight, and fitness goals which holds a pointer to a Goal object to represent the user's fitness goal.

## 4.0 Inheritance

Inheritance is a concept where a new class (derived class) inherits the properties and behavior of another class (base class). In this case, there are derived classes from the Activity (base class) and StrengthActivity (intermediate base class). Here is the explanation:

### Base Class: Activity
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/890d1189-1f75-4f4e-9c9b-2a26386da9fb)

**Interpretation:**
- Activity will be the base class where the derived classes such as SportsActivity, CardioActivity, and StrengthActivity inherit its attributes and behavior.

### Derived Class: SportsActivity
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/afe7578f-3ab7-4f28-9ddc-5efa504202a3)

### Derived Class: CardioActivity
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/c0621bca-1159-41a4-8d32-f05eb28df45d)

### Derived Class: StrengthActivity
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/c37a8bfc-59f2-477c-a465-f0f5efff0838)

**Interpretation:**
- These classes are specialized forms of Activity, each with unique attributes and behaviors that extend the base class Activity.
- Inheritance is used here to promote code reuse and polymorphic behavior.
- Each subclass extends the functionality of the base class and introduces specialized behaviors without duplicating code. For example, specific calorie burning calculations and activity-specific attributes.

### Derived Class: BodyWeightExercise
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/896be9ad-c904-4df5-8155-4cb487c58635)

### Derived Class: WeightExercise
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/a45b4db8-dbef-4aaa-bf8c-82afd9297f53)

**Interpretation:**
- These classes are specialized forms of Activity and StrengthActivity, each with unique attributes and behaviors that extend the Activity (base class) and StrengthActivity (intermediate base class).
- The BodyWeightExercise and WeightExercise are inherited from the StrengthActivity and through it, indirectly from Activity.
- By inheriting from StrengthActivity, they not only gain the general attributes of Activity (duration, intensity) but also the specialized attributes of StrengthActivity (sets, repsPerSet).

## 5.0 Polymorphism

Polymorphism is one of the most important concepts in OOP that describes the ability of objects to take or to be displayed in different forms. In other words, it performs the same actions but different behaviors. It allows objects of different classes to be treated as objects of a common superclass. In this case, we implement the virtual member functions on base classes like Activity and StrengthActivity that will do the dynamic binding where the bindings are decided at runtime. Here is the explanation:

### Base Class: Activity
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/dcd3405e-594c-4d36-8229-1ad8fcb14b67)

**Interpretation:**
- The `calculateCaloriesBurned()` and `displayActivity()` methods in the Activity (base class) are declared as virtual.
- This allows derived classes from the Activity (base class) such as StrengthActivity, SportsActivity, and CardioActivity to provide their own implementation.

### Derived Class: SportsActivity
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/21e1d5a8-16ac-48f4-a076-7c2aacf94d68)

### Derived Class: CardioActivity
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/db2bba49-719b-497e-8001-105626d05d03)

**Interpretation:**
- SportsActivity and CardioActivity classes override the `calculateCaloriesBurned()` and `displayActivity()` methods from the base class, providing specific implementations.

### Derived Class and Intermediate Base Class: StrengthActivity
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/276ee7de-913c-4930-85bd-a7e05fb35730)

**Interpretation:**
- Other than overriding the `calculateCaloriesBurned()` and `displayActivity()` methods from the Activity (base class), the StrengthActivity class also will be an intermediate base class.
- The `calculateCaloriesBurned()` and `displayActivity()` methods in the StrengthActivity (intermediate base class) will be declared as virtual too.
- This allows derived classes from the Activity (base class) and StrengthActivity (intermediate base class) which are WeightExercise and BodyWeightExercise classes to provide their own implementation.

### Derived Class: WeightExercise
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/be92f7a8-4b53-40cf-b8d4-5c2863c868a3)

### Derived Class: BodyWeightExercise
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/ab0e6524-c02f-4d60-82c1-d247670f5819)

**Interpretation:**
- WeightExercise and BodyWeightExercise override the `calculateCaloriesBurned()` and `displayActivity()` methods from the Activity (base class) and the StrengthActivity (intermediate base class) to provide specific implementations.

## 6.0 Array of Objects


An array of objects is a collection of instances of the same class type. It allows for the management of multiple objects of the same type in a structured way. The arrays of objects can be used to store and manipulate collections of objects using indices, providing a convenient way to handle multiple data items of the same type. This concept is implemented in the project to store the users, activities, and nutrition information. Here is the explanation:

### Activity and Nutrition Array in ProgressTracker Class
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/c941d2a1-01f2-4c27-9d8a-d5ded9b77ee8)

**Interpretation:**
- Arrays of objects are used in the ProgressTracker class to manage collections of Activity and Nutrition objects.
- `Activity *activities[100]` is an array that can hold up to 100 pointers to Activity objects.
- `Nutrition *nutritions[100]` is an array that can hold up to 100 pointers to Nutrition objects.
- The `numA` and `numN` variables are used to count the array of activities and nutrition respectively.
- These arrays allow ProgressTracker to keep track of multiple activities and nutrition entries for a user.
  
### Add Activtiy and Nutrition Method
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/193eea69-f492-46bc-bad9-2912acc2f0ee)

**Interpretation:**
- The `addActivity()` method takes a pointer to an Activity object and adds it to the activities array, incrementing the `numA` counter.
- The `addNutrition()` method takes a pointer to a Nutrition object and adds it to the nutritions array, incrementing the `numN` counter.
  
### Display Activtiy and Nutrition Method
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/900f4232-2b1f-4a97-8a42-da99b463f8a8)

**Interpretation:**
- The `showProgress()` method iterates over the activities array using a for loop, displaying each activity and calculating calories burned.
- Similarly, it iterates over the nutritions array to display each nutrition entry.
- The use of loops to iterate over arrays allows for processing each object stored in the array efficiently.

### Users Array in Main Function
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/93ea1608-5ed7-4d97-ae80-969ceee2c0b5)

**Interpretation:**
- `User u[100]` is an array of User objects that can hold up to 100 users. Each element in the array is an instance of the User class.
- The `arraycounter` variable is used to count the array of users.
  
### Users Array For Registration
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/1ead5d9e-6391-4c0d-a45f-04930e89dd55)

**Interpretation:**
- When a new user creates an account, their information is stored in the next available slot in the User array.
- `arraycounter` is incremented to point to the next available slot in the array for the next new user.

### Users Array For Login
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/dcf6db95-1902-4798-8f21-0fb5bfdb762c)

**Interpretation:**
- When an existing user attempts to log in, the program iterates through the User array to verify the username and password.
- If a match is found, `accindex` is set to the index of the matching user.

### Users Array For Add Activity and Nutrition
![image](https://github.com/jjn7702/SECJ1023-PT2/assets/147962263/7ff738b5-5087-4c45-928d-bf0ce3fa4a35)

**Interpretation:**
- Once logged in, users can perform various actions such as adding nutrition, adding activities, updating their profile, and showing progress.
- These actions are managed using the User object at the `accindex`.
- For example, the users can log their cardio activity.
- Similarly, other choices of menu allow users to add activities, update their profile, and display their progress.
