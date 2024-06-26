# PROJECT REPORT GROUP 10
# TOPIC: Book Recommendation System

## 1.0 Introduction
The Book Recommendation System is a command-line tool (CLI) developed in C++ designed to help users discover new books based on their interests. The system allows users to input preferences such as genre or author and receive recommendations accordingly. With a simple CLI interface, the Book Recommendation System provides a seamless experience for users to explore a wide range of books tailored to their tastes.

## 2.0 Objectives and Purposes
The primary objectives and purposes of the Book Recommendation System are:
- **Assist Users**: Help users discover new books that match their preferences.
- **Personalization**: Provide personalised book recommendations tailored to each user's specific criteria.
- **Engagement**: Enhance user engagement with books by suggesting titles they may enjoy.
- **Encouragement**: Foster a love for reading by introducing users to new genres and authors they may not have explored before.

## 3.0 System Design and Architecture
The system design follows an object-oriented approach with the following key components:
- **User Management**: Handles user registration and authentication.
- **Book Management**: Manages book details, including their types (Fiction, NonFiction), authors, genres, and ratings.
- **Recommendation Engine**: Analyses user preferences to recommend books.

**Key Classes**
- **User Class**: Manages user data, including username, password, and preferences.
- **Book Class**: Represents books, with derived classes for different types of books (e.g., Fiction, NonFiction).
- **Publish Class**: Manages publication details associated with each book.
- **Ratings Class**: Handles ratings associated with books.
- **BookRecommendationSystem Class**: Integrates all functionalities, managing books, publications, ratings, and providing book recommendations.

## 4.0 Flowchart and UML Class Diagram

**UML Class Diagram**
<image src = "Image/PT2UML.drawio.jpg">

**Flowchart**
<image src = "Image/FlowchartPT2 page 1.png">
<image src = "Image/FlowchartPT2 page 2.png">
<image src = "Image/FlowchartPT2 page 3.png">
<image src = "Image/FlowchartPT2 page 4.png">

## 5.0 Class Details
**User Class**

The **User** class is responsible for managing user information and authentication. It includes methods for setting and getting user details, reading user data from input, printing user details, and handling login and sign-up processes. User data is stored in files to maintain persistence.

**Book Class**

The **Book** class serves as the base class for all book objects. It includes attributes for book name, author, genre, and book type, along with methods to retrieve these details. Derived classes Fiction and NonFiction extend the Book class to handle specific types of books. Methods in these classes allow for printing detailed information about each book.

**Fiction Class**

Derived from Book, represents fiction books specifically. It inherits attributes from Book and adds a specialisation for fiction books. It overrides printBookDetails() to display details specific to fiction books.

**NonFiction Class**

Also derived from Book, represents non-fiction books. It inherits attributes from Book and specialises for non-fiction books. Similar to Fiction, it overrides printBookDetails() to display details specific to non-fiction books.

**Publish Class**

The **Publish** class manages publication details, including the publisher's name and the year of publication. It associates these details with a book and provides methods to retrieve and print publication details.

**Ratings Class**

The **Ratings** class handles book ratings. It associates a rating value with a book and includes methods to retrieve the book associated with a rating and to print rating details.

**BookRecommendationSystem Class**

The **BookRecommendationSystem** class is the core class that integrates all functionalities. It maintains arrays of books, publications, and ratings, along with counters to track the number of entries. The class provides methods to add books, publications, and ratings to the system, recommend books based on user preferences, and retrieve genres based on user choices.

## 6.0 Implementation of Concept
1. **Encapsulation**

Explanation: Encapsulation in object-oriented programming bundles data (attributes) and methods (functions) that operate on the data into a single unit (class). It hides the internal state of objects from direct access by clients and allows controlled access via public methods.

Justification: The Book class encapsulates attributes such as name, author, genre, and booktype, providing public methods like getName(), getAuthor(), getGenre() to access these attributes. This prevents direct modification of internal data and ensures data integrity

2. **Aggregation**

Explanation: Aggregation represents a "has-a" relationship where one class (the container or aggregator) contains references to objects of another class (the aggregate). The aggregated objects can exist independently of the container.

Justification: The Ratings class aggregates a Book object using a pointer (Book* book). It maintains a relationship where Ratings can refer to a Book object without owning it, allowing flexibility in object relationships and data management

3. **Composition**

Explanation: Composition is a stronger form of aggregation where the lifetime of the contained object is managed by the container. If the container object is destroyed, all contained objects are also destroyed.

Justification: In your design, the Publish class demonstrates composition with Book as a member object (Book book). The Publish object owns its associated Book object, ensuring that a Publish instance cannot exist without a corresponding Book instance

4. **Inheritance**

Explanation: Inheritance allows one class (derived class) to inherit properties and behaviors from another class (base or parent class). It promotes code reuse and supports the "is-a" relationship.

Justification: Both Fiction and NonFiction classes inherit from the Book class. They inherit attributes and methods such as printBookDetails() from Book, enabling specialization (e.g., specific genre handling) while leveraging common functionality defined in Book

5. **Polymorphism**

Explanation: Polymorphism allows objects of different classes to be treated as objects of a common superclass. It enables methods to be defined in multiple derived classes with the same name but different implementations.

Justification: The printBookDetails() method in the Book class is declared as virtual, allowing Fiction and NonFiction classes to override this method with their specific implementations (void printBookDetails() const). This supports dynamic method binding at runtime based on the actual object type.

6. **Array of Object**

Explanation: An array of objects refers to storing multiple instances of a class in a contiguous block of memory, allowing efficient access and manipulation of objects as a group.

Justification: In BookRecommendationSystem, arrays (adbooks[], addpublications[], addrating[]) store multiple instances of Book, Publish, and Ratings objects respectively. This facilitates managing and accessing collections of related objects (e.g., books, publication details, ratings) within the system.

In main(), we use BookRecommendationSystem to populate these arrays

7. **File handling**

Explanation: File handling in C++ provides mechanisms to read from and write to files. It allows data to be stored persistently and retrieved as needed by the program.

Justification: The User class utilizes file handling (fstream) in methods like login()to read and write user credentials (username and password) to a file (users.txt). This enables user authentication and registration functionalities while persisting user data across program executions.

## 7.0 Conclusion

The Book Recommendation System developed using C++ provides a user-friendly way to discover new books based on personal preferences. By leveraging object-oriented programming principles, we have created a robust and flexible system that can be easily extended with new features and functionalities. This project not only enhances user engagement with books but also encourages exploration of new genres and authors, fostering a deeper love for reading.

