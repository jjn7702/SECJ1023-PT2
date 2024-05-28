# 2.0 Problem Analysis  
## 2.1 Classes
In our proposed book exchange system, we will be including 9 classes which are listed as the following:
- Book class
- Dictionary class
- Encyclopedia class
- Review class
- Wishlist class
- PersonalInfo class
- User class
- Student class
- NonStudent class <br>

All 9 classes would be required to ensure the smooth running of this system More details about each class will be explained in the following analysis.

### 2.1.1 Book
In this class, we included basic features of a book as its attributes, including bookID, title, publisher, publicationYear, ISBN, condition (book quality) and status (book availability). These private attributes are necessary for us to keep a complete and detailed record of the books uploaded onto the system by users and to ensure clear distinction between each book. 
On the other hand, methods such as dispBookDetails (used to display book details when called in the main function) and changeStatus (used to change the status of a book based on its availability) are created as well. dispBookDetails method is created to reduce the lines of code needed to display all book details from any book listing and keep the output clean and well-arranged. changeStatus method is called when a book is requested to be exchanged. If the book request is approved, the status attribute of that book will be changed as the book is now unavailable to other users. Constructor of Book will also be included, receiving parameters of bookID, title, publisher, publicationYear, ISBN, and condition. Status of a book object will automatically be set to ‘Available’ upon creation. 

### 2.1.2 Dictionary
In this class, we will include important attributes such as pair_language (for bilingual dictionaries), edition (edition number) and authorTeam (refers to the team of authors and editors). 
A dispBookDetails method is included in this class and executed whenever a dictionary object is called to display its details. A constructor of Dictionary will also be created to receive parameters such as pair_language, edition, and authorTeam. Accessors of getPairLang, getEd, and getAut are included.

### 2.1.3 Encyclopedia
Private attributes of author and language are included in this class. A dispBookDetails method is created in this class as well to display book details of the encyclopedia object that is called. Constructor Encyclopedia receiving parameters of author and language. Accessors of getAuthor and getLang are included as well.

### 2.1.4 Review
This class includes only the attribute of comment, which would be related to users when they decide to write a review regarding the book condition. The book condition reviewed will be updated into the comment attribute.
The main method we will be focusing on in this class is dispReview which will display the review of a book made by users. A default constructor of Review with set the comment attribute to NULL is included. An accessor of getReview and mutator of setReview are also included.


### 2.1.5 Wishlist
This class is created with the purpose of allowing users to store details of their desired books which are unavailable at the moment and would like to refer back to in the future. 
The only attribute involved in this class is wishBook, which will store titles of all the books marked by users as desired.
The method used in this class would include dispWishlist, which would display the book listing of desired books added by users. A default constructor of Wishlist that doesn’t receive any parameters, that will set wishBook to NULL upon creation. addWishBook is a method created to allow users to add books into his or her wishlist.

### 2.1.6 PersonalInfo
This class is created to store personal information of a user into its attributes. The attributes include username, email, address and phoneNum. 
In this class, PersonalInfo constructor will receive 4 string variables as its parameters, which will each be assigned to its attributes username, email, address and phoneNum. Other than that, dispProfile method is also created to display user personal information, and updateProfile method for future updates by users regarding their personal information. Accessors of getUsername, getEmail, getAdd, and getPhone are included as well to obtain private attributes easily when called.

### 2.1.7 User
This class is created to store important information of a user in the system. 
Attributes included are userID, password, pi (PersonalInfo object), owned (for owned books), re (Review object) and wish (Wishlist object). 
Methods involved in this class includes updateBookInfo (to update owned books’ details), removeBook (to remove books from user’s owned book list), addBook (to add books into owned book list), dispBookList (to display book listing), addReview (to add review to a book), updateWishlist (to update user’s wishlist book listing), dispProfile (to display user profile with all user information), registerAcc (to register an account for new users), login (to login into the system with user credentials), and verification (to verify the validity of username and userID entered by users). A constructor of User is created and it receives parameters of userID, password, and pi. Attributes such as re and wish are automatically set to NULL upon creation of User object.

### 2.1.8 Student
This class is only used by users who are students as students have special privilege compared with non-student users.
In this class, attributes of eduLvl (education level of student) and eduInstitution (current education institution attended by the student).
Methods created in this class include seteduLvl (which allows users to set or update his/her current education level), seteduInstitution (which allows users to enter his/her education institution), and disProfile (used to display student users information). A constructor of Student is created in Student class, receiving parameters of eduLvl and eduInstitution, though it will be set to default value of empty string for both attributes if no parameters were passed to the constructor. Accessors of getEduLvl and getEduIns are included as well.

### 2.1.9 NonStudent
This class is used by all users who are not currently studying or are not a student. 
In this class, attributes of job and field (interested field of study or field of profession) are included.
On the other hand, methods created in this class are setJob (mutator that allows users to enter job name), setField (mutator that allows users to set the field interested for book exchange), and disProfile (to display user profile including job and field). Accessors of getJob and getField are also included. A constructor of NonStudent is also created upon creation and it receives parameters such as job and field, though both will be set to default value of NULL if no parameters were passed to the constructor.


## 2.2 Objects
Objects that will be created in this system are book object, dictionary object, encyclopedia object, review object, wishlist object, personalInfo object, user object (that are associated with other book object, review object, and wishlist object), student object and non-student object.


