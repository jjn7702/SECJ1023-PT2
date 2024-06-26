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
![PT2UML drawio](https://github.com/jjn7702/SECJ1023-PT2/assets/148675768/651c6e84-20ac-4689-a5f3-e790f225709e)


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
