# Final Report

## Semester II 2023/2024

**Section:** 08  
**Task:** Final report  
**Due:** 26 June 2024  
**Lecturer:** Dr. Lizawati Binti Mi Yusuf  
**Group:** 08  

### Team Members

| Name                          | Matric Number    |
|-------------------------------|------------------|
| Rami Yassein Eltayeb Mohamed  | A23CS0022        |
| Ammar Abdulrahman Anaam Mudhsh| A23CS0287        |
| Mohamed Ali Mohamed Ali       | A21EC0287        |

## Table of Contents

1. Section A (Proposal)
    - [Synopsis and General Idea](#11-synopsis-and-general-idea)
    - [Objective and Purpose](#12-objective-and-purpose)
    - [System Features and User Guide](#13-system-features-and-user-guide)
    - [Reporting](#14-reporting)
    - [Flowchart](#15-flowchart)
    - [UML](#16-uml)
    - [Objects](#17-objects)
    - [Classes Relationship](#19-classes-relationship)

2. Section B (Updated)
    - [OOP Implementation](#21-oop-implementation)

---

## Section A

###  Synopsis and General Idea

**Foodi** is a cutting-edge food allergy management system specifically designed for individuals with food sensitivities and allergies. It aims to empower users by providing them with essential tools to identify and avoid foods that may trigger allergic reactions, ensuring their safety and well-being. By leveraging a comprehensive pre-set database of food information, Foodi enables users to make informed dietary choices and prevent potentially life-threatening allergic reactions.

###  Objective and Purpose

- To help users avoid any food that may trigger their allergies.
- To help keep people safe because some allergies can lead to death.
- To provide a fast and easy-to-use tool that gives specific and concise information about allergies based on each unique case.

###  System Features and User Guide

#### Login Page

Upon initial access, users will be prompted to enter essential personal information such as their name, email, and age range. They will also select their allergens from a dropdown list to personalize their profile.

#### Home Screen

Once logged in, users will navigate to the home screen, which features three primary options:

1. **Search Bar**: Users can type in the name of a specific food item to search for it. The system will then highlight any allergens present in the food's ingredients list, if applicable.
2. **List of Food Items**: Users can manually browse through a comprehensive list of food items categorized by type (e.g., dairy products). This is especially useful if the food item cannot be found using the search function.
3. **Allergy Information**: This section displays the user’s personalized allergy profile for quick and easy reference, ensuring that critical information is readily accessible.

#### Settings

- **Profile**:
    - Users can update their personal information by entering new values in the respective input fields.
    - Users can also manage their allergens by adding or removing items from their list.

###  Reporting

#### Output Based on Selected Allergen

- Displays lists of food items that contain, are free of, or are highly likely to contain the specified allergens.

#### Output Based on Searched Food

- Provides immediate feedback on whether the searched food is safe for the user.
- Lists which allergens, if any, are present in the searched food item.

#### Settings Output

- Displays user information and the list of registered allergies for verification and updates.




###  Proposed Flowchart

![realpg1](https://github.com/jjn7702/SECJ1023-PT2/assets/149052853/10cf9b15-98a5-4132-93e5-bc1eb1448ecc)

![Pt2_A2_flowchart-Page-2 (1)](https://github.com/jjn7702/SECJ1023-PT2/assets/149052853/c777e7b9-4d85-43a6-ba7e-73ed8729b411)


### 1.6 UML
[UML link:](https://app.creately.com/d/yvJ5es1K2eW/view).

![image](https://github.com/jjn7702/SECJ1023-PT2/assets/122166710/25d469f4-8874-4a65-aa4f-32da849bab66)



###  objects

1. **User**: Represents a user of the system with attributes like name and allergies.
2. **Allergen**: Represents a specific allergen (e.g., peanuts, dairy) with an attribute like name.
3. **Cuisine**: Represents a culinary tradition (e.g., Italian, Thai) with an attribute like cuisine name (protected for access by subclass).
4. **FoodCategory**: Represents a food category (breakfast, lunch, dinner, or snack) with an attribute like category.
5. **Diet**: Represents a dietary restriction (e.g., vegan, vegetarian) with an attribute like name.
6. **FoodItem**: Represents a specific food item with attributes like name, ingredients, category (FoodCategory object), and diet (Diet object). It inherits cuisine_name from the Cuisine class.
7. **Dessert**: Type of food category that has a polymorphism relationship with the FoodCategory class.
8. **Breakfast**: Type of food category that has a polymorphism relationship with the FoodCategory class.
9. **Lunch**: Type of food category that has a polymorphism relationship with the FoodCategory class.
10. **Dinner**: Type of food category that has a polymorphism relationship with the FoodCategory class.


###  Class Relationships:

##Inheritance:
- **FoodItem inherits from Cuisine:** This establishes a parent-child relationship where each FoodItem is a type of Cuisine. This means that FoodItem will inherit the `cuisine_name` attribute from Cuisine, making it easier to split FoodItem into categories where the user will find it simpler to locate FoodItem normally.

##Aggregation:
- **User and Allergy:** This is an aggregation relationship, where User has a pointer to Allergen objects. The Allergen pointer receives a list of Allergen objects created in `int main`. This means that the relationship between User and Allergen is a "has-a" relationship. The Allergen objects still exist even if a User object is destroyed. This is used to associate a list of allergens a user is allergic to.

- **FoodItem and FoodCategory:** This is an aggregation relationship, where FoodItem has a pointer to a FoodCategory object. The FoodCategory pointer receives an object of FoodCategory created in `int main`. This means that the relationship between FoodItem and FoodCategory is a "has-a" relationship. This is used to categorize food items into breakfast, lunch, dinner, and snack.

##Composition:
- **FoodItem and Diet:** This is a composition relationship. This means that a Diet cannot exist without a FoodItem. If a FoodItem is destroyed, the Diet will be destroyed too. This is done to enhance the experience of the user while searching for the FoodItem.

## Polymorphism:
- **FoodCategory and (Lunch, Breakfast, Dinner, Dessert):** The FoodCategory interface is designed to be polymorphic. Classes inheriting from FoodCategory implement the `getCategory` method, allowing FoodItem to treat different FoodCategory objects uniformly.

## Section B


###  OOP Implementation
Foodi leverages key Object-Oriented Programming (OOP) concepts to manage and operate on
user profiles and food items effectively. Following is an explanation of how each OOP concept
( Encapsulation,Composition , Aggegration , Inheritance , Polymorphism , Array of objects ) is
applied within Our source code:

## Encapsulation
Encapsulation is the bundling of data with methods that operate on that data. It restricts direct
access to some of the object's components, which is a means of preventing accidental
interference and misuse of the methods and data.
● Example: The Allergen and User classes demonstrate encapsulation. Data members such
as name and email in the User class are private and can only be accessed through public
getter and setter methods.


## Composition
Composition represents a "has-a" relationship where one class contains objects of another class.
● Example: The User class has a vector of Allergen objects, indicating that a user can have
multiple allergies. Here, User is composed of Allergen objects.


## Aggregation
Aggregation is a special form of association representing a "whole-part" relationship where the
part can exist independently of the whole.
● Example: The FoodItem class aggregates FoodCategory objects through a pointer. This
indicates that while FoodItem includes a FoodCategory, FoodCategory can exist
independently.


## Inheritance
Inheritance allows a class to inherit properties and behavior from another class, facilitating code
reusability and a hierarchical classification.
● Example: The Cuisine class is a base class, and FoodItem inherits from it, extending its
functionalities.
● FoodCategory is another example, where Dessert, Breakfast, Lunch, and Dinner classes
inherit from the FoodCategory interface.


## Polymorphism
Polymorphism allows objects of different classes to be treated as objects of a common base class,
particularly useful for dynamic method binding.
● Example: The FoodCategory interface is designed to be polymorphic. Classes inheriting
from FoodCategory implement the getCategory method, allowing FoodItem to treat
different FoodCategory objects uniformly


## Array of Objects
An array of objects is a data structure where each element is an object. This allows storing and
managing a collection of objects in a structured way.
● Example: The system uses vector containers to store multiple Allergen objects within a
User and multiple FoodItem objects to manage food data.


