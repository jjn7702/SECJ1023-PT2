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

*Admin.h*
<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/Screenshot%202024-06-26%20223448.png" />

#### Bill Class
Encapsulation in the Bill class ensures that the internal details of the bill (such as the items, their quantities, and total sum) are hidden from external access and manipulation. Instead, controlled methods (addToCart, total, getSize, getTotalItems) provide interfaces to interact with and modify the bill's state.

*Bill.h*
<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/images/Screenshot%202024-06-26%20223734.png" />

#### Customer Class
Encapsulation in the Customer class ensures that the internal details (name, phone number, associated Bill, estimated budget) of each customer are hidden and can only be accessed or modified through controlled methods.

*Customer.h*
<img src="https://github.com/jjn7702/SECJ1023-PT2/blob/main/Submission/sec04_23242/Group4%20/Final/images/Screenshot%202024-06-26%20224022.png" />

#### Menu Class
Encapsulation in the Menu class ensures that the internal data (name, price, count) is protected from direct external access. This is achieved by using the protected access specifier for member variables and providing controlled access through public accessor and mutator methods.

*Menu.h*




