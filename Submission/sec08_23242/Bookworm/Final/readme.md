<h1 align="center"> Final </h1>
<h1>Project description</h1>
Nowadays, there are more books available than ever before, which can make it hard for people to find books they will enjoy. Traditional ways of recommending books, like suggestions from friends or bestseller lists, often don't meet the varied tastes of readers. To solve this problem, creating a smart book recommendation system is essential.

The book recommendation system suggests books to the users that they might like based on their preferred genre. The main goal of this project is to design a book recommendation system that can accurately match books to a user's preferences, helping them find new and interesting reads. 

This report explains our book recommendation system, including its goals and purposes. It covers the analysis and design process, including flow charts and UML class diagrams, as well as the steps taken to create the system. Additionally, it includes the implementation of the concepts.

   By developing a reliable and user-friendly book recommendation system, we aim to make reading more enjoyable and help people discover books they might otherwise miss. This project benefits readers by saving them time and effort, and also supports authors and publishers by increasing the visibility of their books.

<h2>Objectives of the system </h2>
The main objective of this book recommendation system is to create a user-friendly platform that could provide personalized book recommendations to users based on the users' favorite genres. The system leverages user preferences to suggest books that align with their interests, ensuring a tailored reading experience. This approach helps users to discover the books that match their taste. Enhancing their experience on finding the book they are interested in.

    Additionally, the system enables users to explore trending books and various genres. By providing popular books in different genres, users can stay updated with the reading trends. These features ensure that users have access to a diverse range of books, encouraging exploration of new genres.
  
   Moreover, the system also provides functionality for users to create and customize their own book list. This allows them to save their personalized collections of books they are interested in, providing a convenient way to organize and manage their reading choice.
   
   Lastly, this book recommendation system aims to cultivate and spark interest of people to indulge in reading habits by making it easy and enjoyable for users to find and access new books. In a nutshell, the goal is to contribute to a culture of reading by making it easier to access different books.

<h2>Purpose of the system </h2>
The purpose of this book recommendation system is to let users view the books sorted by genres. Then, users can choose the book that they like and add to their personalized book list. If they don’t want the book anymore, they can also choose to remove the book from their book list. The users can also check the age of the book in their booklist. Users also can save their book list as a txt file, so they can have a copy of their booklist for future use.

<h2>Analysis and Design</h2>
<h2>Flow Chart</h2>

<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/8f66a4d5-4e7b-4259-aa5c-620a25c24514"></img>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/03d43c6f-3eb7-4c49-8a49-099edbbeff94"></img>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/849c5b12-bc94-44d0-b44c-89b88e0fede9"></img>

<h2>UML Class Diagram</h2>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/555a91d7-8e0f-45e3-b146-a42cd422161f"></img>

<h1>Implementation of the Concepts</h1>
<h2>Encapsulation</h2>

In this project, all classes have applied the concept of encapsulation, in which the classes bind the attributes and data into one entity and define itself and the scope of its operations. Encapsulation is demonstrated through the use of classes with private and public access specifiers.

**Class `Publisher`**

**Attributes**:
- `string publisherName`
- `string country`

`publisherName` and `country` are private member variables of the class. They are accessible only within the class and its member functions.

**Methods**:
- `Publisher()` - default constructor
- `Publisher(string n, string c)` - parameterized constructor that initializes `publisherName` and `country` with the provided values
- `~Publisher()` - destructor
- `string getPublisherName()` - accessor that returns the value of `publisherName`
- `void setPublisherName(string n)` - mutator that sets the value for `publisherName`
- `string getCountry()` - accessor that returns the value of `country`
- `void setCountry(string c)` - mutator that sets the value for `country`

**Class `Book`**

**Attributes**:
- `string bookCode`
- `string bookTitle`
- `string genre`
- `int yearPublish`
- `Publisher* publisher`

All attributes are protected member variables of the class. They are accessible within the class and its derived classes. `bookCode`, `bookTitle`, `genre`, and `yearPublish` store information about the book, while `publisher` is a pointer to a `Publisher` object, indicating the publisher of the book.

**Methods**:
- `Book()` - default constructor
- `Book(string bc, string bt, string g, int yp, Publisher* p)` - parameterized constructor that initializes `bookCode`, `bookTitle`, `genre`, `yearPublish`, and `publisher` with the provided values
- `~Book()` - destructor
- `string getBookCode()` - accessor that returns the value of `bookCode`
- `string getBookTitle()` - accessor that returns the value of `bookTitle`
- `string getGenre()` - accessor that returns the value of `genre`
- `int getYearPublish()` - accessor that returns the value of `yearPublish`
- `Publisher* getPublisher()` - accessor that returns a pointer that points to the book’s publisher
- `void setBookCode(string bc)` - mutator that sets the value of `bookCode`
- `void setBookTitle(string bt)` - mutator that sets the value of `bookTitle`
- `void setGenre(string g)` - mutator that sets the value of `genre`
- `void setYearPublish(int yp)` - mutator that sets the value of `yearPublish`
- `void setPublisher(Publisher* p)` - mutator that sets the value of `publisher`
- `virtual void display()` - virtual function that displays the information of the book. It is marked as virtual, indicating that it can be overridden by derived classes.
- `int getBookAge()` -  a function to calculate the book age
- `bool isClassic()` - a function to check whether the book is a classic book

**Class `Romance`**

**Attributes**:
- `string mainCoupleName`

`mainCoupleName` is a private member variable of the `Romance` class. `mainCoupleName` is accessible only within the class and its member functions.

**Methods**:
- `Romance()` - default constructor
- `Romance(string bc, string bt, int yp, Publisher* p, string mc)` - parameterized constructor that initializes the `Romance` object with the provided values
- `~Romance()` - destructor
- `string getMainCoupleName()` - accessor that returns the value of `mainCoupleName`
- `void setMainCoupleName(string mc)` - mutator that sets the value of `mainCoupleName`
- `void display()` - function that overrides the `display()` function of the base class `Book`. It first calls the `display()` function of the `Book` class to display book information, and then prints the `mainCoupleName`.

**Class `Fantasy`**

**Attributes**:
- `string creatureType`

`creatureType` is a private member variable of the `Fantasy` class. `creatureType` is accessible only within the class and its member functions.

**Methods**:
- `Fantasy()` - default constructor
- `Fantasy(string bc, string bt, int yp, Publisher* p, string ct)` - parameterized constructor that initializes the `Fantasy` object with the provided values
- `~Fantasy()` - destructor
- `string getCreatureType()` - accessor that returns the value of `creatureType`
- `void setCreatureType(string ct)` - mutator that sets the value of `creatureType`
- `void display()` - function that overrides the `display()` function of the base class `Book`. It first calls the `display()` function of the `Book` class to display book information, and then prints the `creatureType`.

**Class `SciFi`**

**Attributes**:
- `string scientificConcept`

`scientificConcept` is a private member variable of the `SciFi` class. `scientificConcept` is accessible only within the class and its member functions.

**Methods**:
- `SciFi()` - default constructor
- `SciFi(string bc, string bt, int yp, Publisher* p, string sc)` - parameterized constructor that initializes the `SciFi` object with the provided values
- `string getScientificConcept()` - accessor that returns the value of `scientificConcept`
- `void setScientificConcept(string ct)` - mutator that sets the value of `scientificConcept`
- `void display()` - function that overrides the `display()` function of the base class `Book`. It first calls the `display()` function of the `Book` class to display book information, and then prints the `scientificConcept`.

**Class `Booklist`**

**Attributes**:
- `Book* books[100]`
- `int count`

Both attributes are private member variables of the `Booklist` class. Both attributes are accessible only within the class and its member functions. `books` is an array of pointers to `Book` objects. The array can hold up to 100 `Book` pointers. `count` is an integer that tracks the number of `Book` objects currently in the list.

**Methods**:
- `Booklist()` - constructor
- `~Booklist()` - destructor
- `int getCount()` - accessor that returns the count of books
- - `void setCount(int c)` - mutator that sets the value of `count`
- `Book* getBook(int index)` - accessor that returns a pointer that points to the book
- `void addBook(Book* b)` - mutator that adds book objects to the `booklist` object
- `bool isBookInList(Book* b)` - method that checks whether the book that the user wants to add is in the book list already
- `void display()` - method that displays the list of books
- `void removeBook(int index)` - method to remove the book from `booklist`
- `void saveBooklist()` - method to save book list to a txt file

**Class `User`**

**Attributes**:
- `string name`
- `string phoneNum`
- `string icNum`
- `Booklist booklist`

All attributes are private member variables of the `User` class. All attributes are accessible only within the class and its member functions.

**Methods**:
- `User()` - default constructor
- `User(string ic, string n, string pn)` - parameterized constructor that initializes a `User` object with the given IC number, name, and phone number.
- `~User()` - destructor
- `string getName()` - accessor that returns the name of the user
- `string getPhoneNum()` - accessor that returns the `phoneNum` of the user
- `string getIcNum()` - accessor that returns the `icNum` of the user
- `void setName(string n)` - mutator that sets the name of the user
- `void setPhoneNum(string p)` - mutator that sets the `phoneNum` of the user
- `void setIcNum(string ic)` - mutator that sets the `icNum` of the user
- `void displayLogin()` - method to prompt the user to enter their IC number, name, and phone number
- `void displayBooklist()` - method to display the user details and user's list of books
- `void addBookToBooklist(Book* book)` - method that adds the user’s interested book to their `booklist`
- `void removeBookFromBooklist(int index)` - method that removes a book from the user’s personal `booklist`
- `void saveUserBooklist()` - method that saves user personalized `booklist` to a txt file
- `int getBooklistCount()` is a method to get the total count of books in user booklist
- `Book* getBookFromBooklist(int index)` is a method to access a book in user booklist

<h2>Composition</h2>

Composition is a "has-a" relationship between objects, where one object contains or is composed of another. In this project, the `User` class consists of a `Booklist` object, which is created by the `Booklist` class. 

**User-Booklist Relationship**

In this case, composition is applied as follows:
- In the book recommendation system, the user can choose the books they are interested in.
- Hence, the user must have a personalized booklist to which they can add books.
- Employing composition means that the `User` class can also access the public methods of the `Booklist` class.
- A `User` consists of a `Booklist` object, indicating that the `Booklist` cannot exist independently if there is no `User`.
- The `Booklist` strongly depends on the `User`. If the `User` object is destroyed, then the `Booklist` object is also destroyed.

<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/133843320/cc39c495-9292-4cd2-a291-1fb870bbf943"></img>


<h2>Aggregation</h2>

Aggregation implies a relationship where the child can exist independently of the parent.

**1. Book and Publisher Relationship**

In this project, the `Book` and `Publisher` classes will have an aggregation relationship:
- The `Book` class holds a pointer to a `Publisher` object.
- A `Book` has a `Publisher`. The `Publisher` object is created outside the `Book` and is passed to it, showing a "has-a" relationship.
- The `Publisher` can exist independently. If the `Book` object is destroyed, the `Publisher` object will not be destroyed.

<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/133843320/c3f486a7-cc65-4bd6-9f04-91b3bc6bb7a9"></img>

**2. Booklist and Book Relationship**

In this project, the `Booklist` and `Book` classes will have an aggregation relationship:
- The `Booklist` class aggregates `Book` pointers, showing a "has-a" relationship, meaning a `Booklist` has a collection of `Books`.
- `Books` can exist independently. If the `Booklist` object is destroyed, the `Book` objects will not be destroyed.

<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/133843320/40e7b316-1edc-47e9-a1c3-7c39f0327138"></img>





<h2>Inheritance</h2>
<p>&emsp;Inheritance allows derived classes to inherit properties and behaviors from the base class.  In this project, inheritance is demonstrated through the Book class and its derived classes: Romance, Fantasy, and SciFi.</p>
<p>&emsp;When an object of the Romance, Fantasy, or SciFi class is created, each object will contain all the attributes and methods of the Book class, plus any additional attributes and methods specific to the derived class. Each derived class object, for example: Romance class object, Fantasy class object and SciFi class object can access the protected and public members of the Book class directly. 
</p>

<p><b>Base Class: Book</b></p>
<p>The Book class contains attributes and methods that are common to all types of books. </p>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/1058c697-7957-4e81-a34c-d7bae682ee19"></img>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/94f16d62-783b-426a-ac77-f67799b02445"></img>

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

<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/a02bec76-f61b-4476-865b-bce6a131ca08"></img>

<h2>Exception handling</h2>
<p>&emsp;In this project, exception handling is used to manage errors related to user input phone number. In the User class, exception handling is applied specifically to validate the phone number input. This is to ensure that the phone number entered consists only of digits. </p>
<p>&emsp;The try block attempts to read and validate the phone number. If the phone number contains any alphabetic characters (isalpha(c)), an invalid_argument exception is thrown with a descriptive message. The catch block catches the exception (invalid_argument) and displays an error message, prompting the user to retry entering the phone number. The loop continues until a valid phone number (containing only digits) is entered.
</p>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/f2c21782-7504-4513-9df0-3aa5f499b38c"></img>
