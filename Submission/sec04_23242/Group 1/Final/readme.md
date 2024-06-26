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

