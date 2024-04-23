# Book Recommendation System

## Synopsis

The Book Recommendation System is a command-line tool (CLI) developed in C++ designed to help users discover new books based on their interests. The system allows users to input preferences such as genre or author and receive recommendations accordingly. With a simple CLI interface, the Book Recommendation System provides a seamless experience for users to explore a wide range of books tailored to their tastes.

## System Objectives & Purposes

- Assist users in discovering new books that match their preferences.
- Provide personalized recommendations based on user input, such as genre or author.
- Help users explore a diverse range of books across various genres and authors.
- Enhance user engagement with books by suggesting titles they may enjoy.

## User Manual

The Book Recommendation System is simple to use. Follow these steps:

1. Launch the application.
2. Enter your preferences, such as genre or author.
3. Receive personalized book recommendations.
4. Explore the recommended books and choose the ones you're interested in.

## Output / Result

After filtering is done by the user, the system will display book(s) based on user's preference. Moreover, the system lists out every detail of the recommended book(s).

## Array of Objects

Array is used in this system, acting as database. Every data will stored based on their data types. For example:
1. Name of book
2. Type of book
3. Genre
4. Language
5. Author name
6. Year publishment
7. Synopsis

## Exception Handling

Exception is something unexpected has occurred or been detected. Exception handling allows the program to deal with the problem in a controlled manner. In this case, when the user enters an input out of options, the system will display “Error! Invalid input. Please enter again.”
Another situation is that the book/author that user wants is not in the database, the system will display “Sorry, this book/author is not in the database.”
