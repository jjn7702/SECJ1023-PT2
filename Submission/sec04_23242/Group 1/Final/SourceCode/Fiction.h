#ifndef FICTION_H
#define FICTION_H
#include <iostream>
using namespace std;

class Fiction : public Book {
public:
    Fiction() {}
    Fiction(string n, string au, string gen) : Book(n, au, 1, gen) {}

    void printBookDetails() const {
        cout << "Fiction Book Details:" << endl;
        Book::printBookDetails();
    }
};

#endif