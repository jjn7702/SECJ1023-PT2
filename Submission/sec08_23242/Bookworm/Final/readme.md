<h1 align="center"> Final </h1>
<h1>Project description</h1>
<h2>Objectives of the system </h2>
<h2>Purpose of the system </h2>

<h2>Analysis and Design</h2>
<h2>Flow Chart</h2>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/deb9f064-640d-4980-a23f-e0d1efa6e6c8"></img>



<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/03d43c6f-3eb7-4c49-8a49-099edbbeff94"></img>





<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/95fdf40e-3c6a-4571-aa27-ee7a0326fd27"></img>

<h2>UML Class Diagram</h2>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/779cdf3b-c25a-4712-8729-9814cbaf1745"></img>

<h1>Implementation of the Concepts</h1>
<h2>Encapsulation</h2>
<h2>Composition</h2>
<h2>Aggregation</h2>

<h2>Inheritance</h2>
<p>&emsp;Inheritance allows derived classes to inherit properties and behaviors from the base class.  In this project, inheritance is demonstrated through the Book class and its derived classes: Romance, Fantasy, and SciFi.</p>
<p>&emsp;When an object of the Romance, Fantasy, or SciFi class is created, each object will contain all the attributes and methods of the Book class, plus any additional attributes and methods specific to the derived class. Each derived class object, for example: Romance class object, Fantasy class object and SciFi class object can access the protected and public members of the Book class directly. 
</p>

<p><b>Base Class: Book</b></p>
<p>The Book class contains attributes and methods that are common to all types of books. </p>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/75f27bdc-798d-419c-99e6-4113a9808edf"></img>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/5a4c56cf-d1fe-48d8-a62f-7771a18abaf4"></img>

<p><b>Derived Class: Romance</b></p>
<p>The Romance class inherits from Book and adds an attribute specific to romance books. The attribute specific to the Romance class is mainCoupleName. </p>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/c70ff9c2-3435-470f-8da4-fe7706ab9955"></img>

<p><b>Derived Class: Fantasy</b></p>
<p>The Fantasy class inherits from Book and adds an attribute specific to fantasy books. The attribute specific to the Fantasy class is creatureType. </p>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/b36ef00a-eed9-4859-9b9e-64e62ab53c11"></img>

<p><b>Derived Class: SciFi </b></p>
<p>The SciFi class inherits from Book and adds an attribute specific to sci-fi books. The attribute specific to the SciFi class is scientificConcept. </p>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/111c067c-b6bb-4f5e-baea-57b4fc95debe"></img>





<h2>Polymorphism</h2>
<p>&emsp;In this project, polymorphism is applied using a virtual function. In the Book class, the display() function is declared as virtual void display() const. This means that derived classes which are Romance, Fantasy, SciFi can override this function with their specific implementations. 
</p>

<p>&emsp;Each derived class overrides the display function in the Book class to display all the common book attributes and every derived class specific attribute. This allows each genre of book to display additional details, for example mainCoupleName for Romance books,  creatureType for Fantasy books and scientificConcept for Sci-Fi books while still leveraging common behavior defined in the Book class.
</p>

<p><b>Base Class: Book</b></p>
<p>Virtual display method is declared in Book class to display the common attribute of a book which includes the bookCode, bookTitle, genre, yearPublish and publisher. This virtual display method can be overridden by derived classes. </p>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/c65b449b-a0d6-4adf-b4be-781abfd51284"></img>

<p><b>Derived Class: Romance</b></p>
<p>Romance class overrides the display() function to display genre-specific information which is mainCoupleName in addition to the general book details.</p>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/0a84250f-d586-4336-9a28-7e0868da42c1"></img>

<p><b>Derived Class: Fantasy</b></p>
<p>Fantasy class overrides the display() function to display genre-specific information which is creatureType in addition to the general book details.</p>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/a1d3f330-f3ed-4019-b789-69a13213e61a"></img>

<p><b>Derived Class: SciFi</b></p>
<p>SciFi class overrides the display() function to display genre-specific information which is scientificConcept in addition to the general book details.</p>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/cdd8e005-8761-4e29-aa30-ecd104b6aa8d"></img>





<h2>Array of objects</h2>
<p>&emsp;In this project, arrays of objects are initialized directly in the main function. Arrays of objects in this code are used to manage collections of books and publishers. For example, p is an array of Publisher objects, trending is an array of Book objects, romance is an array of Romance objects, fantasy is an array of Fantasy objects and scifi is an array of SciFi objects. Each element in these arrays represents an instance of the respective class. </p>

<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/8af0c9da-6959-4fa8-94a3-b9e58f3f752d"></img>





<h2>Exception handling</h2>
<p>&emsp;In this project, exception handling is used to manage errors related to user input phone number. In the User class, exception handling is applied specifically to validate the phone number input. This is to ensure that the phone number entered consists only of digits. </p>
<p>&emsp;The try block attempts to read and validate the phone number. If the phone number contains any alphabetic characters (isalpha(c)), an invalid_argument exception is thrown with a descriptive message. The catch block catches the exception (invalid_argument) and displays an error message, prompting the user to retry entering the phone number. The loop continues until a valid phone number (containing only digits) is entered.
</p>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/f2c21782-7504-4513-9df0-3aa5f499b38c"></img>
