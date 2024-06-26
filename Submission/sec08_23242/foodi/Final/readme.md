# Semester II 2023/2024

## Subject: Programming Technique 2 - SECJ1023

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
    - [1.1 Synopsis and General Idea](#11-synopsis-and-general-idea)
    - [1.2 Objective and Purpose](#12-objective-and-purpose)
    - [1.3 System Features and User Guide](#13-system-features-and-user-guide)
    - [1.4 Reporting](#14-reporting)
    - [1.5 Flowchart](#15-flowchart)
    - [1.6 UML](#16-uml)
    - [1.7 Objects](#17-objects)
    - [1.8 Proposed Classes Involved](#18-proposed-classes-involved)
    - [1.9 Classes Relationship](#19-classes-relationship)

2. Section B (Updated)
    - [2.1 OOP Implementation](#21-oop-implementation)

---

## 1.0 Section A

### 1.1 Synopsis and General Idea

**Foodi** is a cutting-edge food allergy management system specifically designed for individuals with food sensitivities and allergies. It aims to empower users by providing them with essential tools to identify and avoid foods that may trigger allergic reactions, ensuring their safety and well-being. By leveraging a comprehensive pre-set database of food information, Foodi enables users to make informed dietary choices and prevent potentially life-threatening allergic reactions.

### 1.2 Objective and Purpose

- To help users avoid any food that may trigger their allergies.
- To help keep people safe because some allergies can lead to death.
- To provide a fast and easy-to-use tool that gives specific and concise information about allergies based on each unique case.

### 1.3 System Features and User Guide

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

### 1.4 Reporting

#### Output Based on Selected Allergen

- Displays lists of food items that contain, are free of, or are highly likely to contain the specified allergens.

#### Output Based on Searched Food

- Provides immediate feedback on whether the searched food is safe for the user.
- Lists which allergens, if any, are present in the searched food item.

#### Settings Output

- Displays user information and the list of registered allergies for verification and updates.

### 1.5 Proposed Flowchart

![Flowchart](#)

### 1.6 UML
[UML link:](https://app.creately.com/d/yvJ5es1K2eW/view).

![image](https://github.com/jjn7702/SECJ1023-PT2/assets/122166710/25d469f4-8874-4a65-aa4f-32da849bab66)

### 1.7 Objects

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

### 1.8 Proposed Classes Involved

#### 1. User

- **Attributes**:
    - `name` (string)
    - `allergies` (vector <Allergen>)
    - `email` (string)
    - All member attributes are private.

- **Methods**:
    - `User(string _name = "", string _email, vector<Allergen> _allergies)` is both a default constructor and a parameterized constructor.
    - `string getEmail()` is an accessor of email.
    - `void setEmail(string _email)` is a mutator of email.
    - `string getName()` is an accessor of name.
    - `void setName(string _name)` is a mutator of name.
    - `vector<Allergen> getAllergies()` is an accessor of allergies.
    - `void add_allergy(vector<Allergen> _allergens)` adds a new Allergy object to the allergy list.
    - `void remove_allergy(string allergy_name)` removes an Allergy object with the specified name.
    - `void displayProfile()` shows what the class contains.
    - `void saveUserData()` writes user data to a local file.

#### 2. Cuisine

- **Attributes**:
    - `cuisine_name` (string)
    - Member function is protected, then its derived class FoodItem can access the member attribute (`cuisine_name`).

- **Methods**:
    - `Cuisine(string n = "")` is both a default constructor and a parameterized constructor.
    - `string getCuisine()` is an accessor of name.
    - `void setName(string n)` is a mutator.

#### 3. FoodCategory

- **Attributes**:
    - `category` (string)
    - Attribute category is private.

- **Methods**:
    - `FoodCategory(string c = "")` is both a default constructor.
    - `String getCategory()` is an accessor of category.
    - `void setCategory(string c)` is a mutator of category.

#### 4. Allergen

- **Attributes**:
    - `name` (string)
    - Attribute name is private.

- **Methods**:
    - `Allergen(string n = "")` is both a default constructor and a parameterized constructor.
    - `string getName()` is an accessor of name.
    - `void setName(string n)` is a mutator of name.

#### 5. Diet

- **Attributes**:
    - `name` (string)
    - Attribute name is private.

- **Methods**:
    - `Diet(string n = "")` is both a default constructor and a parameterized constructor.
    - `string getName()` is an accessor of name.
    - `void setName(string n)` is a mutator of name.
    - `~Diet()` is a destructor.

#### 6. FoodItem (Class inheriting from Cuisine)

- **Attributes**: (Inherits `cuisine_name` from `Cuisine`)
    - `name` (string)
    - `ingredients` (string)
    - `category` (FoodCategory)
    - `diet` (Diet)
    - All member attributes are private.

- **Methods**:
    - `FoodItem(string n= "", string *ing = nullptr, string diet_n = "", FoodCategory *c)` is both a default constructor and a parameterized constructor.
    - `string getName()` is an accessor of name.
    - `string *getIngredients()` is an accessor of ingredients.
    - `string getDiet()` is an accessor of diet.
    - `string getCategory()` is an accessor of category.
    - `void setCategory(string c)` is a mutator of category.
    - `void setName(string n)` is a mutator of name.
    - `void setIngredients(string *i)` is a mutator of ingredients.
    - `void setDiet_name(string n)` is a mutator of diet name.
    - `void load_foodItem(istream filename)` reads food item data from a local file (e.g., food_data.txt).
    - `void add_foodItem()` adds a new food item to the local file.

### 1.9 Classes Relationship

1. User → Allergy: User has a composition relationship with Allergy (each user can have multiple allergies).
2. FoodCategory (Abstract) → FoodItem: Each food category can have many food items.
3. Diet → FoodItem: Each diet can have many food items.
4. Allergen → FoodItem: Each allergen can affect multiple food items.

## 2.0 Section B

### 2.1 OOP Implementation

The object-oriented approach used to build the system included the following principles:

- **Encapsulation**: Encapsulation was achieved by making class attributes private and providing public methods for accessing and modifying these attributes.
- **Abstraction**: Abstract classes were used to represent generalized food categories that could be inherited by more specific food items.
- **Inheritance**: The FoodItem class inherited attributes and methods from the Cuisine class to represent different types of food.
- **Polymorphism**: Polymorphism was used in the FoodCategory class to allow different types of food items to be treated as instances of the FoodCategory class.

### Additional Notes

The project implementation followed the prescribed guidelines to ensure the correct application of object-oriented principles. The class designs were carefully reviewed and revised to meet the requirements of the system and to provide a robust solution for managing food allergies.

---

### Appendix

#### References

- Lecture Notes and Slides
- Online Tutorials
- API Documentation

#### Diagrams

- [Flowchart](#)
- [UML Diagram](#)

