<p align="center">
  <img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec08_23242/Group%2010/Images/OIG3.jpg" width="90" height="90">
</p>

# Pet Inventory Management System - Problem Analysis and Design
## Table of Contents 📖
- [Flowchart](#Flowchart)
- [Proble Anaysis](#Problem-Analysis)
- [UML Class Diagram](#UML-Class-Diagram)
### Flowchart 

![Flowchart](https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec08_23242/Group%2010/Problem%20Analysis%20and%20Design/Images/photo_2024-05-27_20-16-04.jpg)
![Flowchart](https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec08_23242/Group%2010/Problem%20Analysis%20and%20Design/Images/photo_2024-05-27_20-16-08.jpg)
![Flowchart](https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec08_23242/Group%2010/Problem%20Analysis%20and%20Design/Images/photo_2024-05-27_20-24-00.jpg)

### Problem Analysis 
This project is an Inventory Management System with the following classes:

- `Supplier`
- `Item`
- `SupplierManager`
- `Inventory`
- `Sales`
- `Food`
- `Toy`
- `Medicine`
- `Other`
- `Expired`

##### 1. Supplier
##### Private Attributes:
- `string name`
- `string contact`

##### Public Methods:
- `Supplier(string name, string contact)` - Constructor to initialize supplier attributes.
- `string getName()` - Accessor to get the name.
- `string getContact()` - Accessor to get the contact.

##### 2. Item
##### Protected Attributes:
- `string id`
- `string name`
- `int quantity`
- `double price`
- `Supplier sup`

##### Public Methods:
- `Item(string id, string name, int quantity, double price, Supplier sup)` - Constructor to initialize the attributes.
- `string getName()` - Accessor to get the name.
- `string getContact()` - Accessor to get contact.
- `string getID()` - Accessor to get ID.
- `int getQuantity()` - Accessor to get quantity.
- `double getPrice()` - Accessor to get price.
- `Supplier getSupplier()` - Accessor to get supplier.
- `void setQuantity(int quantity)` - Mutator to set quantity.
- `string getDetails() const` - Virtual method to get the details of the item.

##### 3. SupplierManager
##### Private Attributes:
- `Supplier* suppliers[100]`
- `int supplierCount`

##### Public Methods:
- `SupplierManager()` - Constructor to initialize `SupplierManager` attributes.
- `void addSupplier(string name, string contact)` - Method to add a supplier.
- `Supplier* findSupplierByName(string name)` - Method to find a supplier by name.
- `void viewSuppliers()` - Method to view the supplier list.

#### 4. Inventory
#### Private Attributes:
- `Food* foods[100]`
- `Toy* toys[100]`
- `Medicine* medicines[100]`
- `Other* others[100]`
- `int foodCount`
- `int toyCount`
- `int medicineCount`
- `int otherCount`

#### Public Methods:
- `void addFood(Food* food)` - Method to add a food item.
- `void addToy(Toy* toy)` - Method to add a toy item.
- `void addMedicine(Medicine* medicine)` - Method to add a medicine item.
- `void addOther(Other* other)` - Method to add another item.
- `void viewItems()` - Method to check the item list.
- `Item* findItemByID(string id)` - Method to find an item by ID.

#### 5. Sales
#### Private Attributes:
- `Item* item`
- `double totalPrice`

#### Public Methods:
- `Sales(Item* x)` - Constructor that initializes the `item` attribute with `x` and sets `totalPrice`.
- `double T_Price(int quantity)` - Method to calculate total price.

#### 6. Food
#### Private Attributes:
- `Expired expired`

#### Public Methods:
- `Food(string id, string name, int quantity, double price, string expired, Supplier sup)` - Constructor to initialize the attributes.
- `string getExpired()` - Accessor to get expiry date.
- `string getDetails()` - Method to get the details of the food item.

#### 7. Toy
#### Private Attributes:
- `Expired expired`
- `string material`

#### Public Methods:
- `Toy(string id, string name, int quantity, double price, string expired, string material, Supplier sup)` - Constructor to initialize the attributes.
- `string getExpired()` - Accessor to get expiry date.
- `string getMaterial()` - Accessor to get the material of toys.
- `string getDetails()` - Method to get the details of the toy item.

#### 8. Medicine
#### Private Attributes:
- `Expired expired`
- `int dosePD`

#### Public Methods:
- `Medicine(string id, string name, int quantity, double price, string expired, int dosePD, Supplier sup)` - Constructor to initialize the attributes.
- `string getExpired()` - Accessor to get the expiry date.
- `int getDosePD()` - Accessor to get dosage of the medicine.
- `string getDetails()` - Method to get the details of the medicine item.

#### 9. Other
#### Private Attributes:
- `Expired expired`
- `string description`

#### Public Methods:
- `Other(string id, string name, int quantity, double price, string expired, string description, Supplier sup)` - Constructor to initialize the attributes.
- `string getExpired()` - Accessor to get expiry date.
- `string getDescription()` - Accessor to get the description.
- `string getDetails()` - Method to get the details of the other item.

#### 10. Expired
#### Private Attributes:
- `string expired`
- 
#### Public Methods:
- `Expired(string expired)` - Constructor to initialize `expired`.
- `string getExpired()` - Accessor to get expiry date.
- 
#### Class Relation:

#### Association
- Aggregation
  
 1. Inventory and Food
 
Inventory and Food will have an aggregation relationship. The Inventory class holds a pointer to a Food object.  The Food object is created outside the Inventory and is passed to it, showing a "has-a" relationship. Food can exist independently.If the Inventory object is destroyed, the Food object will not be destroyed.

2. Inventory and Toy

Inventory and Toy will have an aggregation relationship. The Inventory class holds a pointer to a Toy object.  The Toy object is created outside the Inventory and is passed to it, showing a "has-a" relationship.Toy can exist independently. If the Inventory object is destroyed, the Toy object will not be destroyed.

3. Inventory and Medicine

Inventory and Medicine will have an aggregation relationship. The Inventory class holds a pointer to a Medicine object. The Medicine object is created outside the Inventory and is passed to it, showing a "has-a" relationship.Medicine can exist independently. f the Inventory object is destroyed, the Medicine object will not be destroyed.

4. Inventory and Other

Inventory and Other will have an aggregation relationship.The Inventory class holds a pointer to a Other object. The Other object is created outside the Inventory and is passed to it, showing a "has-a" relationship. Other can exist independently.If the Inventory object is destroyed, the Other object will not be destroyed.

5. Sales and Item

Sales and Item will have an aggregation relationship.The Sales class holds a pointer to a Item object. The Item object is created outside the Sales and is passed to it, showing a "has-a" relationship. Other can exist independently.If the Sales object is destroyed, the Item object will not be destroyed.

6. SupplierManager and Supplier

SupplierManager and Supplier will have an aggregation relationship.The SupplierManager class holds a pointer to a Supplier object. The Supplier object is created outside the SupplierManager and is passed to it, showing a "has-a" relationship. Other can exist independently.If the SupplierManager object is destroyed, the Supplier object will not be destroyed.

- Composition
  
 1. Item and Supplier
 
  Item and Supplier have an composition relationship.Both of them are highly dependent on 
  each other,if the Item is destroyed then the Supplier also destroyed and vice versa.
  
  2. Expired and Food
  
  Expired and Food have an composition relationship.Both of them are highly dependent 
  on each other,if the Expired is destroyed then the Food also destroyed and vice versa.
  
  3. Expired and Toy
  
  Expired and Toy have an composition relationship.Both of them are highly dependent 
  on each other,if the Expired is destroyed then the Toy also destroyed and vice versa.

  4. Expired and Medicine
  
  Expired and Medicine have an composition relationship.Both of them are highly 
  dependent on each other,if the Expired is destroyed then the Medicine also destroyed 
  and vice versa.

  5. Expired and Other
  
  Expired and Other have an composition relationship.Both of them are highly dependent 
  on each other,if the Expired is destroyed then the Other also destroyed and vice versa.
  
##### Inherritance

 1. Item,Food,Toy,Medicine,Other
 
Inheritance among Food,Toy,Medicine and Other is representing an is-a relationship, where Item,Food,Toy,Medicine and Other is a type of Item. Inheritance is used because it allows  to reuse common attributes and methods defined in the Item class while also specifying their unique characteristics during instantiation.

### UML Class Diagram 

![UML diagram](https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec08_23242/Group%2010/Problem%20Analysis%20and%20Design/Images/UML%20CLASS%20DIAGRAM.drawio.png)

The program starts with displaying the menu. There will have 6 choice for the user to input(1:supplier,2:item,3:view inventory,4:view supplier,5:process sale,6:exit).When the user choose ‘1’ the system will require user to input supplier name and contact then it will display supplier successfully added. When the user choose ‘2’ the system will display the operation list for the “add item”  then it will require user to input the type of the category (1:food,2:toy,3:medicine,4:others).Then the system will require user to input the supplier name, if no supplier found then it will display error and jump to main menu, if supplier found the system will require user to input the info of that  category user selected. When the user choose ‘3’ the system will display all the info of all items the shop have (ID, name, price, details, supplier name and supplier contact). When the user choose ‘4’ the system will display list of the supplier info(supplier name and supplier contact).When the user choose ‘5’  the system will require user to input item id and quantity then the system will send the price to it in the meanwhile the system also will update inventory for that specific items and display the total price for the items purchased. When the user choose ‘6’ the programs will exit.
