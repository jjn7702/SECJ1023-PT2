
# Final Report
## Table of Content

## Introduction

Our project is about creating a pet inventory management system. This system will in total consist of 10 classes in order to manage with the operation of a pet supply store in more streamline and automate method.

This system will focus on assisting the shop owners to manage the stores efficiently. It will help the vendors to keep track of every product they sell, including toys pet food etc. along with information about their costs and amounts. Everything will be organized by category for quick access. The system will mange the supplier information as well to provide a streamline reordering process based on the inventory level of each items.

Additionally, our system is also able to assist the staff in doing the sales process, the price of items bought by the customer can be automatically calculated after entering the item id and quantity. This can reduce human error in calculating the price.
In general, our pet inventory management system is to make daily operations of pet supply stores easier and more efficient. This will save operating costs and increase customer satisfaction. Our system will help pet businesses prosper in a more competitive market by utilizing technology to automate critical procedures and deliver useful data.

## Objective and Purpose
Developing a pet supply inventory system serves several critical objectives and purposes within the context of managing a pet store or similar business. Firstly, such a system that aims to streamline and optimize inventory management processes. By providing a centralized platform to track items, quantities, and relevant information like expiration dates, the system empowers staff to efficiently monitor stock levels, make informed purchasing decisions, and avoid stockouts or overstock situations.

Secondly, our system makes customer service and sales management more efficient. The system gives employees the ability to process transactions, keep track of sales history, manage client profiles, and track purchase trends in addition to providing tailored recommendations and ensuring correct and fast order fulfillment. This promotes client happiness and loyalty by improving the total customer experience.

Finally, the system facilitates business expansion and strategic decision-making. The system provides management with significant insights to optimize pricing strategies, supplier alliances, inventory stocking, and sales success by creating extensive reports on these and other indicators. These insights enable the company to grow its services, increase profitability, and adjust to changing market trends to better serve its customers.

## Flowchart on How The System is Used
![](https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec08_23242/Group%2010/Final%20Report/Images/Picture1.png)

![](https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec08_23242/Group%2010/Final%20Report/Images/Picture2.png)

![](https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec08_23242/Group%2010/Final%20Report/Images/Picture3.png)

The program starts with displaying the menu. There will have 6 choice for the user to input(1: supplier, 2: item, 3: view inventory, 4: view supplier, 5: process sale, 6: exit).

When the user choose ‘1’ the system will require user to input supplier name and contact then it will display supplier successfully added. 

When the user choose ‘2’ the system will display the operation list for the “add item” then it will require user to input the type of the category (1:food,2:toy,3:medicine,4:others).

Then the system will require user to input the supplier name, if no supplier found then it will display error and jump to main menu, if supplier found the system will require user to input the info of that category user selected. 

When the user choose ‘3’ the system will display all the info of all items the shop have (ID, name, price, details, supplier name and supplier contact). 

When the user choose ‘4’ the system will display list of the supplier info(supplier name and supplier contact).

When the user choose ‘5’ the system will require user to input item id and quantity then the system will send the price to it in the meanwhile the system also will update inventory for that specific items and display the total price for the items purchased. 

And lastly, when the user choose ‘6’ the programs will exit.

## UML Diagram
![](https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec08_23242/Group%2010/Final%20Report/Images/UML.png)

## Class Relation
- Association:
1. Inventory and Food
Inventory and Food will have an aggregation relationship. The Inventory class holds a
pointer to a Food object. The Food object is created outside the Inventory and is passed
to it, showing a "has-a" relationship. Food can exist independently.If the Inventory
object is destroyed, the Food object will not be destroyed.

2. Inventory and Toy

Inventory and Toy will have an aggregation relationship. The Inventory class holds a
pointer to a Toy object. The Toy object is created outside the Inventory and is passed to
it, showing a "has-a" relationship. Toy can exist independently. If the Inventory object is
destroyed, the Toy object will not be destroyed.

3. Inventory and Medicine
Inventory and Medicine will have an aggregation relationship. The Inventory class holds
a pointer to a Medicine object. The Medicine object is created outside the Inventory and
is passed to it, showing a "has-a" relationship.Medicine can exist independently. f the
Inventory object is destroyed, the Medicine object will not be destroyed.

4. Inventory and Other
Inventory and Other will have an aggregation relationship.The Inventory class holds a
pointer to a Other object. The Other object is created outside the Inventory and is
passed to it, showing a "has-a" relationship. Other can exist independently.If the
Inventory object is destroyed, the Other object will not be destroyed.

5. Sales and Item
Sales and Item will have an aggregation relationship. The Sales class holds a pointer to a
Item object. The Item object is created outside the Sales and is passed to it, showing a
"has-a" relationship. Other can exist independently. If the Sales object is destroyed, the
Item object will not be destroyed.

6. SupplierManager and Supplier
SupplierManager and Supplier will have an aggregation relationship. The
SupplierManager class holds a pointer to a Supplier object. The Supplier object is
created outside the SupplierManager and is passed to it, showing a "has-a" relationship.
Other can exist independently. If the SupplierManager object is destroyed, the Supplier
object will not be destroyed.
- Composition:
1. Item and Supplier
Item and Supplier have an composition relationship. Both of them are highly dependent
on each other, if the Item is destroyed then the Supplier also destroyed and vice versa.
2. Expired and Food,Toy,Medicine,Other
Expired and Food,Toy,Medicine,Other have composition relationship. All of them are
highly dependent with expired,if the Expired is destroyed then the Food also destroyed
and vice versa.
- Inheritance:
1. Item,Food,Toy,Medicine,Other
Inheritance among Food, Toy, Medicine and Other is representing an is-a relationship,
where Item, Food, Toy, Medicine and Other is a type of Item. Inheritance is used because
it allows to reuse common attributes and methods defined in the Item class while also
specifying their unique characteristics during instantiation. 

## Object Oriented Concept

- Encapsulation:
![](https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec08_23242/Group%2010/Final%20Report/Images/Encapsulate)
Encapsulation is used in this code such as getQuantity() and setQuantity().Item, Supplier,
and other classes, where data (attributes) and methods are bundled together within each
class, maintaining data integrity and providing a clear interface to interact with.

- Inheritance:
![](https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec08_23242/Group%2010/Final%20Report/Images/Inherrit.png)

The picture above shows that Food, Toy, Medicine, and Other inheriting from the Item class.
This relationship allows them to inherit common attributes and methods from Item while
implementing their specific details.

- Polymorphism:
![](https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec08_23242/Group%2010/Final%20Report/Images/Polymorphy.png)

This picture shows that polymorphism is demonstrated through the use of pure virtual
functions (getDetails() and LoadFile()) in the Item class, which are overridden in derived
classes (Food, Toy, Medicine, Other) to provide diƯerent implementations based on the
specific type of item.

- Composition:
![](https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec08_23242/Group%2010/Final%20Report/Images/Composition.png)

This picture shows that there are composition relationship. Composition describe how
objects are connected and used together. For example, the Item class has a composition
relationship with the Supplier class, where each Item contains a Supplier object (sup) and
Food,Toy,Medicime and other class has a composition relationship with the Expired class.
This signifies a strong ownership relationship.

- Aggregation:
![](https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec08_23242/Group%2010/Final%20Report/Images/Aggregation.png)

This picture shows that there are aggregation relationships. Aggregation describes how
objects are connected and used together. For example, the Inventory class aggregates an
array of Item pointers (Item* item[400]), representing a collection of items that are stored
and managed together, such as Food, Toy, Medicine, and Other items. The
SupplierManager class uses an array of Supplier pointers (Supplier* suppliers[100]) to
eƯiciently manage multiple suppliers. Similarly, the Sales class has a pointer to an Item
object (Item* item), linking each sale to a specific item. These aggregation relationships
facilitate organized and eƯicient management of items, suppliers, and sales transactions
within the system.

- Array of object:
![](https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec08_23242/Group%2010/Final%20Report/Images/Array%20of%20object.png)

The SupplierManager and Inventory class uses an array of pointers.For example in
inventory class (Item* item[400]) to manage and manipulate multiple instances of Food,
Toy, Medicine, and Other items eƯiciently and SupplierManager class （Supplier*
supplier[100]）to eƯiciently manage and manipulate multiple instances of Supplier
objects.

## Conclusion
In conclusion, our project on developing a pet inventory management system aims to enhance the efficiency of pet supply stores by automating and streamlining key processes. This system, comprising ten interconnected classes, optimizes inventory management, sales operations, and supplier relations. 

By centralizing inventory data, the system allows for efficient tracking of stock levels and streamlined reordering processes, preventing both overstock and stockouts. Automating transaction calculations reduces human errors and speeds up the sales process, improving the customer experience and promoting atisfaction and loyalty. 

Comprehensive capabilities offer actionable insights for informed decision-making regarding pricing, supplier partnerships, and inventory policies, aiding business growth and competitiveness. The system’s architecture, featuring clear relationships such as aggregation, composition, and inheritance, ensures robustness and scalability, allowing for easy maintenance and future enhancements.

Overall, our pet inventory management system simplifies and improves the operation of pet supply stores, helping businesses reduce costs, enhance customer service, and achieve sustainable growth. This project highlights the transformative potential of technology in business operations and the importance of strategic system design.
