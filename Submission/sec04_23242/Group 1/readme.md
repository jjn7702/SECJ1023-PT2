# Book Recommendation System

![Picture](https://github.com/jjn7702/SECJ1023-PT2/assets/147811435/ed2211cf-c968-49a7-89ed-a169bb228fe7)



## Group Members

| No | Name                               | Matrix    | GitHub       |
|----|------------------------------------|-----------|--------------|
| 1  | AVIDIAN DIPESH SIVA                | A23CS0052 | `Avidian22`  |
| 2  | MUHAMMAD AZIIDAN BIN MUHD AZLAN NG | A23CS0124 | `AziidanNg`  |
| 3  | MERVYN BEE ZHENG CHENG             | A23CS0245 | `MERVYN3567` |

## Synopsis

The Book Recommendation System is a command-line tool (CLI) developed in C++ designed to help users discover new books based on their interests. The system allows users to input preferences such as genre or author and receive recommendations accordingly. With a simple CLI interface, the Book Recommendation System provides a seamless experience for users to explore a wide range of books tailored to their tastes.

## System Objectives & Purposes

- Assist users in discovering new books that match their preferences.
- Provide personalized book recommendations tailored to each user's specific criteria.
- Enhance user engagement with books by suggesting titles they may enjoy
- Foster a love for reading by introducing users to new genres and authors they may not have explored before

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
4. Author name
5. Year publishment

## Exception Handling

Exception is something unexpected has occurred or been detected. Exception handling allows the program to deal with the problem in a controlled manner. In this case, when the user enters an input out of options, the system will display “Error! Invalid input. Please enter again.”
Another situation is that the book/author that user wants is not in the database, the system will display “Sorry, this book/author is not in the database.”
