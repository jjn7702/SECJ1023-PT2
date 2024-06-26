#ifndef PUBLISH_H
#define PUBLISH_H
#include <iostream>
using namespace std;

class Publish {
private:
    Book book; // composition
    string publishmentDetails;
    int year;
public:
    Publish() : publishmentDetails(""), year(0) {}
    Publish(Book b, string pDetails, int y) : book(b), publishmentDetails(pDetails), year(y) {}

    Book getBook() const {
        return book;
    }

    void printPublish() const {
        cout << "Publishment Details: " << publishmentDetails << endl
             << "Published Year: " << year << endl;
    }
};

#endif