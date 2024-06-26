# FINAL GROUP 4 #
## SECTION A 
### Flowchart
This is our flowcharts that illustrates the whole process of our proposed system.

<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/flowchart1.png" />
<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/flowchart2.png" />
<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/flowchart3.png" />
<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/flowchart4.png" />
<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/flowchart5.png" />

### UML DIAGRAM
<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/UML.png" />

## Section B

### Encapsulation

Encapsulation is primarily achieved through the use of private member variables and public member functions.

#### Admin Class
Encapsulation in the Admin class means that its inner workings—like usernames, passcodes, and menu items—are kept private and can only be managed through specific methods provided by the class.

### *Admin.h*
<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/Screenshot%202024-06-26%20223448.png" />

#### Bill Class
Encapsulation in the Bill class ensures that the internal details of the bill (such as the items, their quantities, and total sum) are hidden from external access and manipulation. Instead, controlled methods (addToCart, total, getSize, getTotalItems) provide interfaces to interact with and modify the bill's state.

### *Bill.h*
<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/images/Screenshot%202024-06-26%20223734.png" />

#### Customer Class
Encapsulation in the Customer class ensures that the internal details (name, phone number, associated Bill, estimated budget) of each customer are hidden and can only be accessed or modified through controlled methods.

#### *Customer.h*
<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/images/Screenshot%202024-06-26%20224022.png" />

#### Menu Class
Encapsulation in the Menu class ensures that the internal data (name, price, count) is protected from direct external access. This is achieved by using the protected access specifier for member variables and providing controlled access through public accessor and mutator methods.

### *Menu.h*
<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/images/Screenshot%202024-06-26%20224626.png" />

#### Page Class
Encapsulation in the Page class ensures that its internal functionality and interactions with other classes (Menu, Bill, Customer) are encapsulated and controlled through well-defined public interfaces.

### *Page.h*
<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/images/Screenshot%202024-06-26%20224905.png" />

### Composition

Composition is a design principle where a class is composed of one or more objects of other classes, establishing a "has-a" relationship.

#### Bill Class
Composition is used in the Bill class to establish a relationship with the Menu class. This means that the Bill class is responsible for containing and managing Menu items. When the Bill object is destroyed, the Menu object is also gone. When a Bill object is created, the Menu object is also created. This ensures that the bill reflects the accurate items selected from the menu, thereby maintaining the consistency of the billing process.

### *Bill.h*
<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/images/Screenshot%202024-06-26%20225532.png" />

### *Bill.cpp*
<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/images/Screenshot%202024-06-26%20225622.png" />
<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/images/Screenshot%202024-06-26%20225646.png" />

### Aggregation

Aggregation is a design principle that represents a "whole-part" relationship where the part can exist independently of the whole.

#### Customer Class
Aggregation is used in the Customer class to maintain a relationship with the Bill class. The Customer object contains pointers to a Bill object, which represents the customer's purchase details. Unlike composition, the existence of the Bill object is not dependent on the Customer class. This means that a Bill can exist independently of a Customer, and a Customer can be associated with multiple Bill objects over time, allowing for greater flexibility and reusability of these objects within the system.

### *Customer.h*
<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/images/Screenshot%202024-06-26%20230018.png" />

### *Customer.cpp*
<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/images/Screenshot%202024-06-26%20230248.png" />
<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/images/Screenshot%202024-06-26%20230258.png" />

#### Admin Class
Aggregation is a form of association where one class (Admin) has a relationship with another class (Menu), but the objects of the Menu class are not owned exclusively by the Admin class. Instead, Menu objects can exist independently and can be shared among multiple Admin objects or other parts of the application.

### *Admin.h*
<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/images/Screenshot%202024-06-26%20230321.png" />

### *Admin.cpp*
<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/images/Screenshot%202024-06-26%20230409.png" />
<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/images/Screenshot%202024-06-26%20230437.png" />
<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/images/Screenshot%202024-06-26%20230450.png" />


