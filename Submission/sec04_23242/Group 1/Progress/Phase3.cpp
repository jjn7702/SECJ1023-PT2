#include <iostream>
using namespace std;

const int MAX_BOOKS = 100;
const int MAX_PUBLICATIONS = 50;
const int MAX_RATINGS = 50;

class User {
private:
    string name;
    string matrics;
public:
    User() : name(""), matrics("") {} //Default constructor

    void setName(string n) {
        name = n;
    }

    void setMatrics(string c) {
        matrics = c;
    }

    string getName() const {
        return name;
    }

    string getMatrics() const {
        return matrics;
    }

    void read() {
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter your matrics number: ";
        getline(cin, matrics);
    }

    void print() {
        cout << "Welcome " << name << "!" << endl;
    }
};

class Book { //Parent class
protected:
    string name, author, genre;
    int booktype; // 1 for Fiction, 2 for Non-Fiction
public:
    Book() : name(""), author(""), genre(""), booktype(0) {} //Default constructor
    Book(string n, string au, int bt, string gen) : name(n), author(au), booktype(bt), genre(gen) {}

    //Accessor
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
};

class Fiction : public Book {
public:
    Fiction() {}
    Fiction(string n, string au, string gen) : Book(n, au, 1, gen) {}
};

class NonFiction : public Book {
public:
    NonFiction() {}
    NonFiction(string n, string au, string gen) : Book(n, au, 2, gen) {}
};

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

class Ratings {
private:
    Book* book; // aggregation
    double rate;
public:
    Ratings() : book(nullptr), rate(0.0) {}
    Ratings(Book* b, double r) : book(b), rate(r) {}

    Book* getBook() const {
        return book;
    }

    void printRatings() const {
        cout << "Ratings: " << rate << endl;
    }
};

class BookRecommendationSystem {
private:
    Book books[MAX_BOOKS];
    Publish publications[MAX_PUBLICATIONS];
    Ratings rates[MAX_RATINGS];
    int bookCount, publicationCount, ratingCount;

public:
    BookRecommendationSystem() : bookCount(0), publicationCount(0), ratingCount(0) {}

    void addBook(Book book) {
        if (bookCount < MAX_BOOKS) {
            books[bookCount++] = book;
        }
    }

    void addPublication(Publish publish) {
        if (publicationCount < MAX_PUBLICATIONS) {
            publications[publicationCount++] = publish;
        }
    }

    void addRating(Ratings rating) {
        if (ratingCount < MAX_RATINGS) {
            rates[ratingCount++] = rating;
        }
    }

    void recommendBooks(int bookType, const string& genre) const {
        cout << "Recommended Books:" << endl;
        for (int i = 0; i < bookCount; ++i) {
            if (books[i].getBookType() == bookType && books[i].getGenre() == genre) {
                cout << "Book Name: " << books[i].getName() << endl;
                cout << "Author: " << books[i].getAuthor() << endl;
                cout << "Genre: " << books[i].getGenre() << endl;

                // Find and print the publication details
                for (int j = 0; j < publicationCount; ++j) {
                    if (publications[j].getBook().getName() == books[i].getName()) {
                        publications[j].printPublish();
                        break;
                    }
                }

                for (int j = 0; j < ratingCount; ++j) {
                    if (rates[j].getBook()->getName() == books[i].getName()) {
                        rates[j].printRatings();
                        break;
                    }
                }
                cout << "--------------------------------------" << endl;
            }
        }
    }

    void getUserPreferencesAndRecommend() {
        int booktype;
        cout << "Please choose the type of your Preferred Book" << endl
             << "[1] Fiction\n" << "[2] Non-Fiction\n";
        cin >> booktype;

        cout << "Please choose the Genre of your Preferred Book" << endl;
        if (booktype == 1) {
            cout << "[1] Action\n" << "[2] Romance\n" << "[3] Mystery\n";
        } else {
            cout << "[1] Religion\n" << "[2] Philosophy\n" << "[3] Biography\n";
        }

        int genreChoice;
        cin >> genreChoice;
        string genre = getGenreFromChoice(booktype, genreChoice);

        recommendBooks(booktype, genre);
    }

    string getGenreFromChoice(int booktype, int choice) const {
        if (booktype == 1) {
            switch (choice) {
                case 1: return "Action";
                case 2: return "Romance";
                case 3: return "Mystery";
                default: return "Unknown";
            }
        } else {
            switch (choice) {
                case 1: return "Religion";
                case 2: return "Philosophy";
                case 3: return "Biography";
                default: return "Unknown";
            }
        }
    }
};

int main() {
    BookRecommendationSystem bookSystem;

    // Adding some sample data
    bookSystem.addBook(Fiction("The Great Gatsby", "F. Scott Fitzgerald", "Action"));
    bookSystem.addBook(Fiction("1984", "George Orwell", "Mystery"));
    bookSystem.addBook(Fiction("To Kill a Mockingbird", "Harper Lee", "Romance"));

    bookSystem.addBook(NonFiction("The Philosophy Book", "DK", "Philosophy"));
    bookSystem.addBook(NonFiction("Sapiens", "Yuval Noah Harari", "Biography"));
    bookSystem.addBook(NonFiction("The God Delusion", "Richard Dawkins", "Religion"));

    bookSystem.addPublication(Publish(Fiction("The Great Gatsby", "F. Scott Fitzgerald", "Action"), "XYZ Publishing House", 1925));
    bookSystem.addPublication(Publish(Fiction("1984", "George Orwell", "Mystery"), "ABC Publishing House", 1949));

    bookSystem.addRating(Ratings(new Fiction("The Great Gatsby", "F. Scott Fitzgerald", "Action"), 4.8));
    bookSystem.addRating(Ratings(new Fiction("1984", "George Orwell", "Mystery"), 4.6));

    cout << "**********************************************************" << endl;
    cout << "             BOOK RECOMMENDATION SYSTEM" << endl;
    cout << "**********************************************************" << endl;

    // Create object for user class
    User u;
    //object u call method inside class User
    u.read();
    u.print();

    
    int choice;
    do {
        bookSystem.getUserPreferencesAndRecommend();
        cout << "Press 0 to exit or any other key to continue: ";
        cin >> choice;
    } while (choice != 0);

    cout << "Thank you for using the system! " << u.getName() << " " << u.getMatrics() << endl;

    system("pause");
    return 0;
}
