<h1 align="center"> Problem Analysis and Design </h1>
<h1> Content :star2: </h1>
<ul>
  <li><a href="#flowchart"> Flow Chart </a></li>
  <li><a href="#problemanalysis"> Problem Analysis </a></li>
  <li><a href="#classdiagram"> Class Diagram </a></li>
</ul>

<h2 id="flowchart"> Flow Chart :clipboard:</h2>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/d35e8e5b-6289-433c-8904-86a63c8aa034"></img>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/763d8d14-60e1-4736-b2ec-ae6c31a4753f"></img>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/035c2553-e37e-4f29-b223-8d06f73bc248"></img>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/84137d16-11d9-4d9c-b806-4f27f7d29e9c"></img>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/19862d15-c3ae-4b0e-afc7-ea5190f5e6f0"></img>
First of all, the user must enter their IC number, name and phone number to use the system. Then, the system presents the main menu with three options (1. See trending book list, 2.See specific genre book list, and 3. View book recommendation list). Selecting ‘1’ displays the trending book list which consists of 5 trending books, and the user can choose which book they are interested in by input number from 1 to 5.
Besides, Selecting ‘2’ in the main menu will display the genre list (1. Romance, 2. Fantasy and 3. SciFi), and after picking a genre, the system will display a list of 5 books from the chosen genre. Users can also choose which book they are interested in by input number from 1 to 5. To return to the main menu, the user can enter ‘6’. When they choose a book, the system will check whether the book chosen has already been added into the recommendation book list before, if not the details of chosen book will be automatically added to the recommendation list. Users can then choose to add more books from the same list by entering ‘1’ or choose to return to the main menu by entering a different number.
Selecting ‘3’ in the main menu will display the recommendation list that was created by the user, which includes user details and the details of all the books chosen by the user. After that, the user can choose to exit the system by entering number ‘1’, or choose to return to the main menu by entering any other number. 

<h2 id="problemanalysis"> Problem Analysis :round_pushpin: </h2>
<b>The objects involved in the project</b>    

  
1. class Publisher  
- 5 publisher objects

2. class Books  
- Fantasy Class : 5 fantasy objects
- Romance Class : 5 romance objects
- SciFi Class : 5 sciFi objects

3. class User  
- 1 user object
  
4. class Booklist  
- 1 booklist object
  

<b>The classes involved in the project</b>    
  
1. class Publisher

Attributes :   
- string publisherName
- string country


publisherName and country are private member variables of the class. They are accessible only within the class and its member functions.


Methods:    
- Publisher()  is a default constructor
- Publisher(string n, string c) is a parameterized constructor that initializes publisherName and country with the provided values
- ~Publisher() is a destructor
- string getPublisherName() is an accessor that returns the value of publisherName
- void setPublisherName(string n) is a mutator that set value for the publisherName
- string getCountry() is an accessor that returns the value of country
- void setCountry(string c) is a mutator that set value for the country


2. class Book

Attributes :
- string bookCode
- string bookTitle
- string genre
- int yearPublish
- Publisher* publisher


All attributes are protected member variables of the class. They are accessible within the class and its derived classes. bookCode, bookTitle, genre, and yearPublish store information about the book, while publisher is a pointer to a Publisher object, indicating the publisher of the book.


Methods :  
- Book() is a default constructor
- Book(string bc, string bt, string g, int yp, Publisher* p) is a parameterized constructor that initializes bookCode, bookTitle, genre, yearPublish and publisher with the provided values 
- ~Book() is a destructor
- string getBookCode() is an accessor that returns the value of bookCode
- string getBookTitle() is an accessor that returns the value of bookTitle
- string getGenre() is an accessor that returns the value of genre
- int getYearPublish() is an accessor that returns the value of yearPublish
- Publisher* getPublisher() is an accessor that returns a pointer that points to the book’s publisher
- void setBookCode(string bc) is a mutator that sets the value of bookCode
- void setBookTitle(string bt) is a mutator that sets the value of bookTitle
- void setGenre(string g) is a mutator that sets the value of genre
- void setYearPublish(int yp) is a mutator that sets the value of yearPublish
- void setPublisher(Publisher *p) is a mutator that sets the value of publisher
- virtual void display() is a virtual function that displays the information of the book. It is marked as virtual, indicating that it can be overridden by derived classes.

  

3. class Romance
   
Attributes :
- string mainCoupleName


mainCoupleName is a private member variable of the Romance class. mainCoupleName is accessible only within the class and its member functions.


Methods : 
- Romance() is a default constructor
- Romance(string bc, string bt, int yp, Publisher* p, string mc) is a parameterized constructor that initializes the Romance object with the provided values
- ~Romance() is a destructor
- string getMainCoupleName() is an accessor that returns the value of mainCoupleName
- void setMainCoupleName(string mc) is a mutator that sets the value of mainCoupleName
- void display() is a function that overrides the display() function of the base class Book. It first calls the display() function of the Book class to display book information, and then prints the mainCoupleName.


4. class Fantasy

Attributes : 
- string creatureType


creatureType is a private member variable of the Fantasy class. creatureType is accessible only within the class and its member functions.


Methods :   
- Fantasy() is a default constructor
- Fantasy(string bc, string bt, int yp, Publisher* p, string ct) is a parameterized constructor that initializes the Fantasy object with the provided values. 
- ~Fantasy() is a destructor
- string getCreatureType() is a accessor that returns the value of creatureType
- void setCreatureType(string ct) is a mutator that sets the value of creatureType
- void display() is a function that overrides the display() function of the base class Book. It first calls the display() function of the Book class to display book information, and then prints the creatureType


5. class SciFi

Attributes :
- string scientificConcept


scientificConcept is a private member variable of the SciFi class. scientificConcept is accessible only within the class and its member functions.

Methods :   
- SciFi() is a default constructor
- SciFi(string bc, string bt, int yp, Publisher* p, string sc) is a parameterized constructor that initializes the SciFi object with the provided values. 
- string getScientificConcept() is an accessor that returns the value of scientificConcept
- void setScientificConcept(string ct) is a mutator that sets the value of scientificConcept
- void display() is a function that overrides the display() function of the base class Book. It first calls the display() function of the Book class to display book information, and then prints the scientificConcept

6. class Booklist
   
Attributes :
- Book* books[100]
- int count


Both attributes are private member variables of the Booklist class. Both attributes are accessible only within the class and its member functions. books is an array of pointers to Book objects. The array can hold up to 100 Book pointers. count is an integer that tracks the number of Book objects currently in the list.

Methods: 
- Booklist() is a constructor
- ~Booklist() is a destructor
- int getCount() is an accessor that returns the count of books
- Book* getBook(int index) is an accessor that returns a pointer that points to the book
- void addBook(Book* b) is a mutator that adds book objects to the booklist object
- void setCount(int c) is a mutator that set the value of count
- bool isBookInList(Book* b) is a method that checks whether the book that the user wants to add is in the book list already
- void display() is a method that displays the the list of books


7. class User

Attributes :
- string name
- string phoneNum
- string icNum
- Booklist booklist


All attributes are private member variables of the User class. All attributes are accessible only within the class and its member functions. 

Methods : 
- User() is a default constructor
- User(string ic, string n, string pn) is a parameterized constructor that initializes a User object with the given IC number, name, and phone number.
- ~User() is a destructor
- string getName() is an accessor that return the name of the user
- string getPhoneNum() is an accessor that returns the phoneNum of the user
- string getIcNum() is an accessor that return the icNum of the user
- void setName(string n) is a mutator that sets the name of the user
- void setPhoneNum(string p) is a mutator that sets the phoneNum of the user
- void setIcNum(string ic) is a mutator that sets the icNum of the user
- void displayLogin() is a method to prompt the user to enter their IC number, name, and phone number
- void displayBooklist() is a method to display the user details and user's list of books.
- void addBookToBooklist(Book* book) is a method that adds the user’s interested book to their booklist






ii) class relationships



 <b>Association Relationships</b>


1. Book and Publisher


Book and Publisher will have an aggregation relationship. The Book class holds a pointer to a Publisher object. A Book has a Publisher. The Publisher object is created outside the Book and is passed to it, showing a "has-a" relationship. Publisher can exist independently. If the Book object is destroyed, the Publisher object will not be destroyed. 


2. Booklist and Book


Booklist and Book will have an aggregation relationship. The Booklist class aggregates Book pointers, showing a "has-a" relationship, meaning booklist has a collection of books. Books can exist independently. If the Booklist object is destroyed, the Book object will not be destroyed. 


3. User and Booklist

   
User and Booklist will have a composition relationship. A User consists of a Booklist object, indicating that the Booklist cannot exist independently if no User. Booklist strongly depends on User. If the User object is destroyed, then the Booklist object is also destroyed. 



<b>Inheritance Relationships</b>

  
1. Book, Romance, Fantasy, SciFi


Inheritance among Book, Romance, Fantasy, and SciFi is suitable for representing an is-a relationship, where each specific genre is a type of book. Inheritance is used because it allows these specific genres to reuse common book attributes and methods defined in the Book class while also specifying their genre during instantiation.

<h2 id="classdiagram"> Class Diagram :clipboard: </h2>
<img src="https://github.com/jjn7702/SECJ1023-PT2/assets/147809633/7a95d31c-26da-4ba0-bd4b-e0747b8e523d"></img>
