#ifndef RATINGS_H
#define RATINGS_H
#include <iostream>
using namespace std;

class Ratings {
private:
    Book* book; // aggregation
    double rate;
public:
    Ratings() : book(NULL), rate(0.0) {}
    Ratings(Book* b, double r) : book(b), rate(r) {}

    Book* getBook() const {
        return book;
    }

    void printRatings() const {
        cout << "Ratings: " << rate << endl;
    }
};

#endif