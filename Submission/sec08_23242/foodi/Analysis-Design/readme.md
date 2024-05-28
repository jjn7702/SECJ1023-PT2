<h1 align = "center">Problem Analysis and Design</h1>
<h2>Content</h2>
<ul>
  <li>Flow Chart</li>
  <li>Problem Analysis</li>
  <li>Class Diagram</li>
</ul>

<h2>Flow Chart ⚙️</h2>

![realpg1](https://github.com/jjn7702/SECJ1023-PT2/assets/149052853/10cf9b15-98a5-4132-93e5-bc1eb1448ecc)


![Pt2_A2_flowchart-Page-2 (1)](https://github.com/jjn7702/SECJ1023-PT2/assets/149052853/c777e7b9-4d85-43a6-ba7e-73ed8729b411)

<h3>About the flowchart:-</h3>

The main process of the system begins with the Main Menu, where users can choose to manage their profiles or search for food items. Users can create a new profile by providing personal details such as name, email, age range, and selecting allergens from a pre-populated list. If an existing profile is chosen, the system retrieves the stored information for the user to review or update.
Once a profile is set up, users can perform food searches. They can either use the Search Bar to type in specific food items or browse through categorized lists of foods. The system checks the ingredients of the selected food against the user's allergy profile to determine if it is safe to consume. If the food contains allergens, the system alerts the user, specifying the allergens found. If no allergens are detected, the system confirms the food is safe. 

The system also provides detailed reporting based on search results, informing users whether a food is "Safe to Consume" or "Contains Allergens" along with specifics. Additionally, users can search by allergen to find foods that contain or are free from the allergen and those that may pose a cross-contamination risk. Throughout the process, users can update their profiles to ensure accurate and personalized allergy checks, continually enhancing their experience and safety

<h2>Problem Analysis 📊</h2>
<h3>Objects:</h3>
1.	User: Represents a user of the system with attributes like name and allergies.<br>
2.	Allergen: Represents a specific allergen (e.g., peanuts, dairy) with an attribute like name.<br>
3.	Cuisine: Represents a culinary tradition (e.g., Italian, Thai) with an attribute like cuisine name (protected for access by subclass).<br>
4.	FoodCategory: Represents a food category (breakfast, lunch, dinner, or snack) with an attribute like category.<br>
5.	Diet: Represents a dietary restriction (e.g., vegan, vegetarian) with an attribute like name.<br>
6.	FoodItem: Represents a specific food item with attributes like name, ingredients, category (FoodCategory object), and diet (Diet object). It inherits cuisine_name from the Cuisine class.<br>
<h3>Classes Involved:</h3>
1. User:<br>
<ul><li>Attributes:</li> 
  <ul>
  <li>name (string)</li>
  <li>* allergies (Allergen)</li>
  </ul>
</ul>
All member attributes are private.<br>
<ul><li>Methods:</li>
  <ul>
  <li>User(string n = "", Allergen *a = nullptr): Default constructor and parameter constructor for the User class. It can be called with no arguments (default constructor) or with a string argument for the name and an optional Allergen pointer (parameter constructor).</li>
  <li>~User(): Destructor for the User class. Called automatically when a User object goes out of scope or is explicitly deleted.</li>
  <li>string getName(): Accessor method that returns the user's name as a string.</li>
  <li>vector getAllergies(): Accessor method that returns a copy of the user's allergy list as a vector.</li>
  <li>void setName(string n): Mutator method that sets the user's name to the provided string.</li>
  <li>void add_allergy(Allergen allergy): Adds a new Allergen object to the user's allergy list.</li>
  <li>void remove_allergy(string allergy_name): Removes an Allergy object from the user's list based on the provided allergy name (assumes string comparison for matching).</li>
  <li>void load_user_data(istream filename): Reads user data from a local file specified by the input stream argument (filename).</li>
  <li>void save_user_data(ostream filename): Writes user data to a local file specified by the output stream argument (filename).</li>
  <li>void edit_profile(string new_name, Allergen *a): Allows editing of user information. Takes a new name as a string and an optional Allergen pointer for potential allergy updates.</li>
  </ul>
</ul>
2. Cuisine:<br>
<ul><li>Attributes:</li>
  <ul>
  <li>cuisine_name (string)</li>
  </ul>
</ul>
Member function is protected, then it is derived class FoodItem can access the member attribute (cuisine_name).<br>
<ul><li>Methods:</li>
  <ul>
  <li>Cuisine(string n = ""): Default constructor and parameter constructor for the Cuisine class. It can be called with no arguments (default constructor) or with a string argument for the name (parameter constructor).</li>
  <li>string getCuisine(): Accessor method that returns the cuisine name as a string.</li>
  <li>void setName(string n): Mutator method that sets the cuisine name to the provided string.</li>
  </ul>
</ul>
3. FoodCategory:<br>
<ul><li>Attributes:</li>
  <ul>
  <li>category (string) This is food category (breakfast, lunch, dinner, or snack).</li>
  </ul>
</ul>
Attribute category is private.<br>
<ul><li>Methods:</li>
  <ul>
   <li>FoodCategory(string c = ""): Default constructor and parameter constructor for the FoodCategory class. It can be called with no arguments (default constructor) or with a string argument for the category (parameter constructor).</li>
  <li>string getCategory(): Accessor method that returns the food category name as a string.</li>
  <li>void setCategory(string c): Mutator method that sets the food category name to the provided string.</li>
  </ul>
</ul>
4. Allergen:<br>
<ul><li>Attributes:</li>
  <ul>
  <li>name (string)</li>
  </ul>
</ul>
Attribute name is private<br>
<ul><li>Methods:</li>
  <ul>
  <li>Allergen(string n = ""): Default constructor and parameter constructor for the Allergen class. It can be called with no arguments (default constructor) or with a string argument for the name (parameter constructor).</li>
  <li>string getName(): Accessor method that returns the allergen name as a string.</li>
  <li>void setName(string n): Mutator method that sets the allergen name to the provided string.</li>
  </ul>
</ul>
5. Diet:<br>
<ul><li>Attributes:</li>
  <ul>
  <li>name (string)</li>
  </ul>
</ul>
Attribute name is private<br>
<ul><li>Methods:</li>
  <ul>
  <li>Diet(string n = ""): Default constructor and parameter constructor for the Diet class. It can be called with no arguments (default constructor) or with a string argument for the name (parameter constructor).</li>
  <li>string getName(): Accessor method that returns the diet name as a string.</li>
  <li>void setName(string n): Mutator method that sets the diet name to the provided string.</li>
  </ul>
</ul>
6. FoodItem (Class inheriting from Cuisine): 
<ul><li>Attributes:</li>
  <ul>
  <li>name (string)</li>
  <li>* ingredients (string)</li>
  <li>* category (FoodCategory)</li>
  <li>diet (Diet)</li>
  </ul>
</ul>
All member attributes are private.<br>
<ul><li>Methods:</li>
  <ul>
  <li>FoodItem(string n = "", string *ing = nullptr, string diet_n = "", FoodCategory *c = nullptr): Default constructor and parameter constructor for the FoodItem class. It can be called with no arguments (default constructor) or with arguments for name (string), ingredients (string pointer), diet name (string), and food category (FoodCategory pointer).</li>
  <li>string getName(): Accessor method that returns the food item name as a string.</li>
  <li>string* getIngredients(): Accessor method that returns a pointer to the list of ingredients as a string array (may need additional handling depending on implementation).</li>
  <li>string getDiet(): Accessor method that returns the food item's diet name as a string.</li>
  <li>string getCategory(): Accessor method that returns the food item's category name as a string (assuming FoodCategory has a getCategory() method).</li>
  <li>void setCategory(string c): Mutator method that sets the food item's category name to the provided string.</li>
  <li>void setName(string n): Mutator method that sets the food item's name to the provided string.</li>
  <li>void setIngredients(string *i): Mutator method that sets the food item's ingredients list using a provided string pointer (may need additional handling depending on implementation).</li>
  <li>void setDiet_name(string n): Mutator method that sets the food item's diet name to the provided string.</li>
  <li>void load_foodItem(istream filename): Reads food item data from a local file specified by the input stream argument (filename).</li>
  <li>void add_foodItem(): Adds a new food item to a local file (implementation details may vary).</li>
  </ul>
</ul>
<h3> Class Relationships:</h3>
<ul>
    <li>Inheritance:</li>
      <ul>
        <li>FoodItem inherits from Cuisine. This establishes a parent-child relationship where each FoodItem is a type                 of Cuisine, this means that FoodItem will inherit cuisine_name attribute from Cuisine making it easier to                  split FoodItem into categories where the user will find it simpler to find FoodItem normally</li>
      </ul>
    <li>Aggregation:</li>
      <ul>
        <li>User and Allergy: This is an aggregation relationship, where User has a pointer to Allergen object. The                    Allergen pointer receives a list of Allergen objects created in int main, this means that the relationship                 between User and Allergen is a “has-a” relationship. The Allergen objects still exist even if a User object                is destroyed. This is used to associate a list of allergens a user is allergic to.</li>
        <li>FoodItem and FoodCategory: This is an aggregation relationship, where FoodItem has a pointer to FoodCategory               object. The FoodCategory pointer receives an object of FoodCategory created in int main, this means that the               relationship between FoodItem and FoodCategory is a “has-a” relationship. This is used to categorize food                  items to breakfast, lunch, dinner, and snack.</li>
      </ul>
    <li>Composition:</li>
      <ul>
        <li>FoodItem and Diet: This is a composition relationship. This means that a Diet cannot exist without a FoodItem,             if a FoodItem is destroyed diet will be destroyed too. This too is done to enhance the experience of the user              while searching for the FoodItem.</li>
      </ul>
</ul>

<h2>Class Diagram 📋</h2>
<image src=https://github.com/jjn7702/SECJ1023-PT2/assets/122166710/d72734a4-25d4-46da-95d7-2f5c0c6b8ed8>
