#ifndef BOOK_H
#define BOOK_H
#include <iostream>
using namespace std;

class Book { // Parent class
protected:
    string name, author, genre;
    int booktype; // 1 for Fiction, 2 for Non-Fiction
public:
    Book() : name(""), author(""), genre(""), booktype(0) {} // Default constructor
    Book(string n, string au, int bt, string gen) : name(n), author(au), booktype(bt), genre(gen) {}

    // Accessor
    int getBookType() const {
        return booktype;
    }

    string getName() const {
        return name;
    }

    string getAuthor() const {
        return author;
    }

    string getGenre() const {
        return genre;
    }

    virtual void printBookDetails() const {
        cout << "Book Name: " << name << endl;
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
    }

    virtual ~Book() {}
};

#endif