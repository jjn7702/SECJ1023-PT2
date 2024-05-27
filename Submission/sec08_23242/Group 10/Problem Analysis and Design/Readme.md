<p align="center">
  <img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec08_23242/Group%2010/Images/OIG3.jpg" width="90" height="90">
</p>


# Pet Inventory Management System - Problem Analysis and Design

### Flowchart

### Problem Analysis
There are 10 classes in this program. They work with each other to let this program functionable.
class Supplier
Private attributes:
- string name
- string contact
Public methods:
- Supplier(string, string)-constructor to initialize supplier attributes
- string getName()- accessor to get the name
- string getContact()-accessor to get the contact

class Item
protected attributes:
- string id
- string name
- int quantity
- double price
- Supplier sup
Public methods:
- Item(string, string, int, double, Supplier) – a constructor that initialize the attribute
- string getName() – accessor to get the name
- string getContact() – accessor to get contact 
- string getID()-accessor to get ID
- int getQuantity()-accessor to get quantity
- double getPrice()-accessor to get price
- Supplier getSupplier()-accessor to get supplier
- void setQuantity(int)-mutator to set quantity
- string getDetails()const- virtual method to get the detail of the item

class SupplierManager
Private attributes:
- Supplier* suppliers[100]
- int supplierCount
Public methods:
- SupplierManager()- constructor to initialize SupplierManager attributes
- void addSupplier(string,string)- method to add supplier
- Supplier* string findSupplierByName- method to find supplier
- void viewSuppliers()- method to view supplier list

class Inventory
Private attributes:
- Food* foods[100]
- Toy* toys[100]
- Medicine* medicines[100]
- Other* others[100]
- int foodCount
- int toyCount
- int medicineCount
- int otherCount
Public methods:
- void addFood(Food*)- method to add food item
- void addToy(Toy*)- method to add toy item
- void addMedicine(Medicine*)- method to add medicine item
- void addOther(Other*)- method to add other item
- void viewItems()- method to check item list
- Item *findItemByID(string)- method to find item id
class sales
Private attributes:
- Item*item
- double totalPrice
Public methods:
- Sales(Item* x)- constructor of sales that allocate item attribute with x and initialize totalPrice
- double T_Price(int)- accessor to getT_Price
class Food
Private attributes:
- Expired expired
- Public methods:
- Food(string,string,int, double string, Supplier)
- sting getExpired()
- string getDetails()

class Toy
Private attributes:
- Expired expired
- string material
- Public methods:
- Toy(string,string,int, double string,string, Supplier)- constructor to initialize teh attributes
- string getExpired() =- accseesor to get expiry dates
- string getMaterial()- accessor to get the material of toys
- string getDetails()- method to get the detail of toys
class Medicine:
Private attributes:
- Expired expired
- int dosePD
Public methods:
- Medcine(string,string,int, double string,int,Supplier)- constructor to initialize the attributes
- string getExpired()- accessor to get the expiry date
- int getDosePD()- accessor to get dosage of the medicine
- string getDetails()- method to get details for medicine item

class other
Private attributes:
- Expired expired
- string description
Public methods:
- Other(string,string,int, double string,string,Supplier) – constructor to initialize the attributes
- string getExpired()- accessor to get expiry date
- string getDescription()- accessor to get the description
- string getDetails()- method to get the details for other item


class Expired
Private attributes:
- string expired
Public methods:
- Expired(string)- constructor to initialize expired
- String getExpired()-accessor to get expiry date

### UML Class Diagram
