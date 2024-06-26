#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "User.h"
#include "Book.h"
#include "Fiction.h"
#include "NonFiction.h"
#include "Publish.h"
#include "Ratings.h"
#include "BookRecommendationSystem.h"
using namespace std;


int main() {
    BookRecommendationSystem bookSystem;

    // Adding Fiction Books
    bookSystem.addBook(new Fiction("The Great Gatsby", "F. Scott Fitzgerald", "Action"));
    bookSystem.addBook(new Fiction("1984", "George Orwell", "Mystery"));
    bookSystem.addBook(new Fiction("To Kill a Mockingbird", "Harper Lee", "Romance"));
    bookSystem.addBook(new Fiction("Pride and Prejudice", "Jane Austen", "Romance"));
    bookSystem.addBook(new Fiction("The Catcher in the Rye", "J.D. Salinger", "Action"));
    bookSystem.addBook(new Fiction("The Hobbit", "J.R.R. Tolkien", "Fantasy"));
    bookSystem.addBook(new Fiction("Harry Potter and the Philosopher's Stone", "J.K. Rowling", "Fantasy"));
    bookSystem.addBook(new Fiction("The Hunger Games", "Suzanne Collins", "Action"));
    bookSystem.addBook(new Fiction("Dune", "Frank Herbert", "Science Fiction"));
    bookSystem.addBook(new Fiction("Brave New World", "Aldous Huxley", "Science Fiction"));
    bookSystem.addBook(new Fiction("The Martian", "Andy Weir", "Science Fiction"));
    bookSystem.addBook(new Fiction("The Shining", "Stephen King", "Horror"));
    bookSystem.addBook(new Fiction("Gone Girl", "Gillian Flynn", "Thriller"));
    bookSystem.addBook(new Fiction("The Girl with the Dragon Tattoo", "Stieg Larsson", "Mystery"));
    bookSystem.addBook(new Fiction("The Road", "Cormac McCarthy", "Dystopian"));

    //Adding Non Fiction Books
    bookSystem.addBook(new NonFiction("The Philosophy Book", "DK", "Philosophy"));
    bookSystem.addBook(new NonFiction("Sapiens: A Brief History of Humankind", "Yuval Noah Harari", "Biography"));
    bookSystem.addBook(new NonFiction("The God Delusion", "Richard Dawkins", "Religion"));
    bookSystem.addBook(new NonFiction("The Power of Now", "Eckhart Tolle", "Spirituality"));
    bookSystem.addBook(new NonFiction("Educated", "Tara Westover", "Autobiography"));
    bookSystem.addBook(new NonFiction("Becoming", "Michelle Obama", "Memoir"));
    bookSystem.addBook(new NonFiction("Steve Jobs", "Walter Isaacson", "Biography"));
    bookSystem.addBook(new NonFiction("Quiet: The Power of Introverts in a World That Can't Stop Talking", "Susan Cain", "Psychology"));
    bookSystem.addBook(new NonFiction("Outliers: The Story of Success", "Malcolm Gladwell", "Success"));
    bookSystem.addBook(new NonFiction("Freakonomics: A Rogue Economist Explores the Hidden Side of Everything", "Steven D. Levitt and Stephen J. Dubner", "Economics"));

    //Adding Publishment Details for Fiction
    bookSystem.addPublication(Publish(Fiction("The Great Gatsby", "F. Scott Fitzgerald", "Action"), "Charles Scribner's Sons", 1925));
    bookSystem.addPublication(Publish(Fiction("1984", "George Orwell", "Mystery"), "Secker & Warburg", 1949));
    bookSystem.addPublication(Publish(Fiction("To Kill a Mockingbird", "Harper Lee", "Romance"), "J. B. Lippincott & Co.", 1960));
    bookSystem.addPublication(Publish(Fiction("Pride and Prejudice", "Jane Austen", "Romance"), "Dover Publicatiobns", 1813));
    bookSystem.addPublication(Publish(Fiction("The Catcher in the Rye", "J.D. Salinger", "Action"), "Little, Brown", 1951));
    bookSystem.addPublication(Publish(Fiction("The Hobbit", "J.R.R. Tolkien", "Fantasy"), "George Allen & Unwin (UK)", 1937));
    bookSystem.addPublication(Publish(Fiction("Harry Potter and the Philosopher's Stone", "J.K. Rowling", "Fantasy"), "Bloomsbury", 1997));
    bookSystem.addPublication(Publish(Fiction("The Hunger Games", "Suzanne Collins", "Action"), "Scholastic", 2008));
    bookSystem.addPublication(Publish(Fiction("Dune", "Frank Herbert", "Science Fiction"), "Chilton Books", 1965));
    bookSystem.addPublication(Publish(Fiction("Brave New World", "Aldous Huxley", "Science Fiction"), "Chatto & Windus", 1932));
    bookSystem.addPublication(Publish(Fiction("The Martian", "Andy Weir", "Science Fiction"), "Crown", 2014));
    bookSystem.addPublication(Publish(Fiction("The Shining", "Stephen King", "Horror"), "Doubleday", 1977));
    bookSystem.addPublication(Publish(Fiction("Gone Girl", "Gillian Flynn", "Thriller"), "Crown Publishing Group", 2012));
    bookSystem.addPublication(Publish(Fiction("The Girl with the Dragon Tattoo", "Stieg Larsson", "Mystery"), "Norstedts Förlag (Swedish)", 2005));
    bookSystem.addPublication(Publish(Fiction("The Road", "Cormac McCarthy", "Dystopian"), "Alfred A. Knopf", 2006));


    //Adding Publishment Details for Non Fiction
    bookSystem.addPublication(Publish(NonFiction("The Philosophy Book", "DK", "Philosophy"), "Dorling Kindersley", 2011));
    bookSystem.addPublication(Publish(NonFiction("Sapiens: A Brief History of Humankind", "Yuval Noah Harari", "Biography"), "Dvir Publishing House Ltd. (Israel) Random House Harper", 2011));
    bookSystem.addPublication(Publish(NonFiction("The God Delusion", "Richard Dawkins", "Religion"), "Bantam Press", 2006));
    bookSystem.addPublication(Publish(NonFiction("The Power of Now", "Eckhart Tolle", "Spirituality"), "Namaste Publishing", 1997));
    bookSystem.addPublication(Publish(NonFiction("Educated", "Tara Westover", "Autobiography"), "New York : Random House", 2018));
    bookSystem.addPublication(Publish(NonFiction("Becoming", "Michelle Obama", "Memoir"), "Crown (North America) Viking Press (Commonwealth)", 2018));
    bookSystem.addPublication(Publish(NonFiction("Steve Jobs", "Walter Isaacson", "Biography"), "Simon & Schuster (U.S.)", 2011));
    bookSystem.addPublication(Publish(NonFiction("Quiet: The Power of Introverts in a World That Can't Stop Talking", "Susan Cain", "Psychology"), "Crown Publishing Group", 2012));
    bookSystem.addPublication(Publish(NonFiction("Outliers: The Story of Success", "Malcolm Gladwell", "Success"), "Little, Brown", 2008));
    bookSystem.addPublication(Publish(NonFiction("Freakonomics: A Rogue Economist Explores the Hidden Side of Everything", "Steven D. Levitt and Stephen J. Dubner", "Economics"), "William Morrow", 2005));


    //Adding Ratings for Fiction
    bookSystem.addRating(Ratings(new Fiction("The Great Gatsby", "F. Scott Fitzgerald", "Action"), 4.8));
    bookSystem.addRating(Ratings(new Fiction("1984", "George Orwell", "Mystery"), 4.6));
    bookSystem.addRating(Ratings(new Fiction("To Kill a Mockingbird", "Harper Lee", "Romance"), 4.5));
    bookSystem.addRating(Ratings(new Fiction("Pride and Prejudice", "Jane Austen", "Romance"), 4.3));
    bookSystem.addRating(Ratings(new Fiction("The Catcher in the Rye", "J.D. Salinger", "Action"), 4.2));
    bookSystem.addRating(Ratings(new Fiction("The Hobbit", "J.R.R. Tolkien", "Fantasy"), 4.9));
    bookSystem.addRating(Ratings(new Fiction("Harry Potter and the Philosopher's Stone", "J.K. Rowling", "Fantasy"), 4.9));
    bookSystem.addRating(Ratings(new Fiction("The Hunger Games", "Suzanne Collins", "Action"), 4.8));
    bookSystem.addRating(Ratings(new Fiction("Dune", "Frank Herbert", "Science Fiction"), 5.0));
    bookSystem.addRating(Ratings(new Fiction("Brave New World", "Aldous Huxley", "Science Fiction"), 4.6));
    bookSystem.addRating(Ratings(new Fiction("The Martian", "Andy Weir", "Science Fiction"), 4.3));
    bookSystem.addRating(Ratings(new Fiction("The Shining", "Stephen King", "Horror"), 3.9));
    bookSystem.addRating(Ratings(new Fiction("Gone Girl", "Gillian Flynn", "Thriller"), 4.0));
    bookSystem.addRating(Ratings(new Fiction("The Girl with the Dragon Tattoo", "Stieg Larsson", "Mystery"), 4.5));
    bookSystem.addRating(Ratings(new Fiction("The Road", "Cormac McCarthy", "Dystopian"), 4.0));

    //Adding Ratings for Non Fiction
    bookSystem.addRating(Ratings(new NonFiction("The Philosophy Book", "DK", "Philosophy"), 4.5));
    bookSystem.addRating(Ratings(new NonFiction("Sapiens: A Brief History of Humankind", "Yuval Noah Harari", "Biography"), 4.9));
    bookSystem.addRating(Ratings(new NonFiction("The God Delusion", "Richard Dawkins", "Religion"), 4.6));
    bookSystem.addRating(Ratings(new NonFiction("The Power of Now", "Eckhart Tolle", "Spirituality"), 4.2));
    bookSystem.addRating(Ratings(new NonFiction("Educated", "Tara Westover", "Autobiography"), 4.1));
    bookSystem.addRating(Ratings(new NonFiction("Becoming", "Michelle Obama", "Memoir"), 4.2));
    bookSystem.addRating(Ratings(new NonFiction("Steve Jobs", "Walter Isaacson", "Biography"), 4.3));
    bookSystem.addRating(Ratings(new NonFiction("Quiet: The Power of Introverts in a World That Can't Stop Talking", "Susan Cain", "Psychology"), 4.0));
    bookSystem.addRating(Ratings(new NonFiction("Outliers: The Story of Success", "Malcolm Gladwell", "Success"), 4.7));
    bookSystem.addRating(Ratings(new NonFiction("Freakonomics: A Rogue Economist Explores the Hidden Side of Everything", "Steven D. Levitt and Stephen J. Dubner", "Economics"), 4.0));

    cout << "**********************************************************" << endl;
    cout << "             BOOK RECOMMENDATION SYSTEM" << endl;
    cout << "**********************************************************" << endl;

    User user;

    int choice;
    cout << "Choose an option: [1] Sign Up [2] Login: ";
    cin >> choice;
    cin.ignore(); // To ignore the newline character left in the input buffer

    if (choice == 1) {
        user.signUp();
    } else if (choice == 2) {
        user.read();

        if (user.login()) {
            user.print();
            char loop;
            do {
                bookSystem.getUserPreferencesAndRecommend();
                cout << "Press 0 to exit or any other key to continue: ";
                cin >> loop;
            } while (loop != '0');
        } else {
            cout << "Login failed. Exiting program." << endl;
        }
    } else {
        cout << "Invalid option. Exiting program." << endl;
    }
    system("pause");
    return 0;
}

