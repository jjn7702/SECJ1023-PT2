# Final Report

### **Table of Contents**

- [Report](files/2E1I_REPORT.pdf)
- [Presentation Slides](files/ProjectProposalNutritionTrackerSystem.pdf)
- [Source Code](source-code)
- [Synopsis and General Idea](#synopsis-and-general-idea)
- [Objectives and Purpose](#objectives-and-purpose)
- [Flowchart & UML Diagram](#flowchart--uml-diagram)
- [Implementation of OO Concept](#implementation-of-oo-concept)
- [References](#references)

## <ins>Synopsis and General Idea
These days, the prevalence of unhealthy eating habits, fueled by a reliance on junk food and snacks, has contributed to many health issues, including obesity and related diseases. Recognizing the importance of maintaining a balanced diet and an active lifestyle, we aim to introduce a nutrition tracker system to address this growing concern.The nutrition tracking system aims to provide users with a comprehensive platform to monitor their dietary intake, set nutrition goals, and receive personalized recommendations. By integrating user-friendly interfaces and advanced data analysis, the system empowers individuals to make informed decisions about their health and wellness.

## <ins>Objectives and Purpose
1. Enable users to set personalized health goals based on factors such as age, weight, gender, and activity level
2. Track daily food intake, including calories, macronutrients (carbohydrates, fats, proteins) and fiber
3. Provide a tracking report based on the user’s progress towards their calories intake and health condition.
4. Offer personalized feedback from nutritionists to optimize dietary habits and improve overall well-being.


## <ins>Flowchart & UML Diagram
<image src = "image/flowchart.jpg" width="650" height="700">
<image src = "image/PT2_CD.jpg" width="700" height="700">

## <ins>Implementation of OO Concept
### Array of Objects
Nutritionist has a array of object (regular user) to manage regular user<br>
<image src = "image/Array.png" width="700" height="260">
### **Encapsulation**
Encapsulation refers to combining attributes and methods in one package, known as a class and hiding the implementation of the data from the user of the object. This ensures data security and prevents unauthorized access. 
<image src = "image/encapsulation.png" width="500" height="500">
  
### **Association - Aggregation**
1. NutritionTracker and Food:
NutritionTracker class has an attribute food of type Food by using vector<br>
Justification: The nutrition tracker needs to manage different food items, hence associating it with the Food class
<image src = "image/aggregation.png" width="500" height="260">

2. Nutritionist and RegularUser:
Nutritionist class has an attribute regularUser of type RegularUser *.<br>
Justification: A nutritionist manages multiple regular users, providing recommendations and viewing their calorie catalogs, thereby creating an association relationship.
<image src = "image/aggregation2.png" width="800" height="160">
  
### Association - Composition
1. User and Feedback:
User class has an attribute feedback of type Feedback.<br>
Justification: A nutritionist can provide a feedback and it can be viewed by regular user, and thus, there is a direct relationship where each user can be associated with feedback.<br>
<image src = "image/composition.png" width="500" height="260">
<image src = "image/composition2.png" width="700" height="260">

2. RegularUser and NutritionTracker:
RegularUser class has an attribute calories of type NutritionTracker.<br>
Justification: Regular users need to track their calories, and this tracking is managed through the NutritionTracker class, thus associating these two classes.<br>
<image src = "image/composition3.png" width="800" height="160">
  
### **Inheritance and Polymorphism**
<image src = "image/parentClass.png" width="400" height="260">

<image src = "image/regularSignUp.png" width="500" height="240">

<image src = "image/nutritionistSignUp.png" width="500" height="250">

### **Exception Handling**
We apply on Regular User class that use to check age, height, weight, gender and activity level that entered by the user to avoid invalid data and accepted by the system in order to avoid abnormal conditions in the system.<br>
<image src = "image/exceptionhandling.png" width="500" height="350">

## **References**
- https://www.calculator.net/bmi-calculator.html
- https://www.calculator.net/bmr-calculator.html
- https://www.healthyweightforum.org/eng/calculators/activity-burned/
- https://www.kaggle.com/datasets/niharika41298/nutrition-details-for-most-common-foods
