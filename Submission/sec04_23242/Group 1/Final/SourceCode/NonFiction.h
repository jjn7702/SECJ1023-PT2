#ifndef NONFICTION_H
#define NONFICTION_H
#include <iostream>
using namespace std;

class NonFiction : public Book {
public:
    NonFiction() {}
    NonFiction(string n, string au, string gen) : Book(n, au, 2, gen) {}

    void printBookDetails() const {
        cout << "Non-Fiction Book Details:" << endl;
        Book::printBookDetails();
    }
};

#endif