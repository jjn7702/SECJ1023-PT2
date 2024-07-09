# 3.0 Classes Relationships
## 3.1 Encapsulation
Encapsulation is used in every class combining attributes of a class and methods of that particular class. For example, class User used encapsulation to combine all its attributes and methods. The same applies to every other class.
## 3.2 Composition
User object has a personalInfo object. The personalInfo object in user object stores user’s personal information such as username, email, address and phoneNum. If the user object is destroyed, its personal information should also be cleared from the system. Thus it is a composition relationship.


## 3.3 Aggregation
User object has a book array object that stores owned books. It is a one way aggregation relationship and objects involved here are independent. The books that are exchanged to other users still exist in the exchanged user’s account even if the original owner deleted its account and cleared his data.
User object has an exchanged book array that stores information about books that the user has exchanged with other users. 
User object also has a review object that stores user’s reviews. The relationship between review object and user object is aggregation because even if the user object is destroyed, the review that this user left for any book would still be useful for any other users wishing to exchange the books reviewed in the future.
User object has a wishlist array object that stores the title of all the books marked by the user for future reference. It is set as an aggregation relationship because more book titles will be needed to be added into it in the future, and the wishlist array object will undergo as many times of modification as the users like.

## 3.4 Inheritance
Dictionary class and Encyclopedia class are inherited from Book class as both are types of books and share certain similar attributes, thus will inherit attributes of title, publisher, publicationYear, ISBN, condition, and status.
Student class and NonStudent class are both inherited from User class as both share similar qualities and share similar functions, Thus both Student and NonStudent classes inherit all the attributes and methods of User class such as userID, password and others.




## 3.5 Polymorphism
In Book class, a method of dispBookDetails() is initialized and set as a virtual method meanwhile Dictionary class and Encyclopedia class also have methods of the same name and same parameter and same return type. The dispBookDetails() method in Dictionary class and Encyclopedia class will override the one in Book class when called to achieve similar but not entirely same actions.




## 3.6 Array of Objects
Array of objects is used in the main class when an allUser user array object is initialized to store all information of users in the system. The limit of users in allUser array object for now is 10.


