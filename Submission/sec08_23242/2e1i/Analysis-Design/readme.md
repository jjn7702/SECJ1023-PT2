# 2- Problem Analysis and Design

### Table of Contents

- [Section A Flow Chart](image/PT2_flowchart.jpg)
- [Section B Problem Analysis]()
- [Section C Class Diagram](image/CLASSDIAGRAM.jpg)

## Section A Flow Chart 📊
<image src = "image/PT2_flowchart.jpg" width="700" height="550">

### Main Process of the System
> __i) Login / Sign up:__
  - Identifying the user type, allowing individuals to choose **Regular User** or **Nutritionist**
  - Exiting users can login directly
  - New user must sign up by provoding necessary credentials

> __ii) Regular User__
  - The main page of regular user contains 3 different sections:
  - **User Profile**: view nutrition history and generated weekly report
  - **Nutrition Tracker**: log nutritional intake for different meal categories
  - **Feedback and Recommendation**: respond user feedback and view recommendations from nutritionist

> __iii) Nutritionist__
  - Able to view user nutriotion history and **calorie catalog**
  - View user **feedback**
  - Provide **recommendation**

## Section B Problem Analysis 🔍
> ### (i) The objects and the classes involved in the project


### 1. User (class)
```
Attributes:
- username :string
- password :string

Methods:
- bool LogIn(string username, string password)
```


### 2. RegularUser(derived class of User class)
```
Attributes:
- dailyHistory[] :double

Methods:
- void viewDailySummary()
```

### 3. Nutritionist (derived class of User class)
```
Attributes:
- regularUser:RegularUser * 

Methods:
- void viewUsersCatalog()
```

### 4. CalorieTracker(class)
```
Attributes:
- food: Food*

Methods:
- void enterCaloriesBurnt()
```

### 5. Feedback(class)
```
Attributes:
- feedbackText:string
- recommendationText:string

Methods:
- void setFeedback()
- void setRecommendation()
```

### 6. Food(class)
```
Attributes:
- foodName:string

Method:
- void printFoodList()
```

> ### (ii) Identify Class Relationships
### Association Relationships:
- ### Composition:
**1. User and Feedback:**
User class has an attribute feedback of type Feedback.
Justification: A user can provide feedback or recommendation, and thus, there is a direct relationship where each user can be associated with feedback.

**2. RegularUser and CalorieTracker:**
RegularUser class has an attribute calories of type CalorieTracker.
Justification: Regular users need to track their calories, and this tracking is managed through the CalorieTracker class, thus associating these two classes.

- ### Aggregation:
**1. CalorieTracker and Food:**
CalorieTracker class has an attribute food of type Food.
Justification: The calorie tracker needs to manage different food items, hence associating it with the Food class.

**2. Nutritionist and RegularUser:**
Nutritionist class has an attribute regularUser of type RegularUser *.
Justification: A nutritionist manages multiple regular users, providing recommendations and viewing their calorie catalogs, thereby creating an association relationship.

### Inheritance Relationships:
**1. RegularUser and User:**
RegularUser inherits from User.
Justification: A regular user is a specific type of user with additional attributes and methods related to health and calorie tracking, thus inheriting basic user properties.

**2. Nutritionist and User:**
Nutritionist inherits from User.
Justification: A nutritionist is also a type of user with specialized methods for managing regular users, making inheritance from the User class appropriate.

### Class Diagram Justification:

User as a Base Class: Since both RegularUser and Nutritionist share common attributes like username and password, it's logical to have a base User class.

RegularUser and Nutritionist Inheritance: Inheriting from User allows code reuse for common functionalities like SignUp and LogIn.

Association Relationships: These relationships model real-world interactions between users, calorie tracking, and feedback mechanisms, ensuring that the design is intuitive and maintainable.


## Section C Class Diagram 🗂️
<image src = "image/CLASSDIAGRAM.jpg" width="800" height="550">
