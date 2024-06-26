#ifndef BOOKRECOMMENDATIONSYSTEM_H
#define BOOKRECOMMENDATIONSYSTEM_H
#include <iostream>
using namespace std;

const int MAX_BOOKS = 100;
const int MAX_PUBLICATIONS = 50;
const int MAX_RATINGS = 50;

class BookRecommendationSystem {
private:
    Book* books[MAX_BOOKS];
    Publish publications[MAX_PUBLICATIONS];
    Ratings rates[MAX_RATINGS];
    int bookCount, publicationCount, ratingCount;

public:
    BookRecommendationSystem() : bookCount(0), publicationCount(0), ratingCount(0) {}

    void addBook(Book* book) {
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
            if (books[i]->getBookType() == bookType && books[i]->getGenre() == genre) {
                books[i]->printBookDetails();

                // Find and print the publication details
                for (int j = 0; j < publicationCount; ++j) {
                    if (publications[j].getBook().getName() == books[i]->getName()) {
                        publications[j].printPublish();
                        break;
                    }
                }

                for (int j = 0; j < ratingCount; ++j) {
                    if (rates[j].getBook()->getName() == books[i]->getName()) {
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
        int genreChoice;
        cout << "Please choose the type of your Preferred Book" << endl
             << "[1] Fiction\n" << "[2] Non-Fiction\n";
        cin >> booktype;

        cout << "Please choose the Genre of your Preferred Book" << endl;
        while ((booktype != 1) && (booktype != 2)) {
            cout << "Invalid option. Please enter again:" << endl;
            cin >> booktype;
        }
        if (booktype == 1) {
            cout << "[1] Action\t" << "[2] Romance\t" << "[3] Mystery\t" << "[4] Fantasy\n"
                << "[5] Science Fiction\t" << "[6] Horror\t" << "[7] Thriller\t" << "[8] Dystopian\n";
            cin >> genreChoice;
            while ((genreChoice != 1) && (genreChoice != 2) && (genreChoice != 3) && (genreChoice != 4)
                    && (genreChoice != 5) && (genreChoice != 6) && (genreChoice != 7) && (genreChoice != 8)) {
                cout << "Invalid option. Please enter again:" << endl;
                cin >> genreChoice;
            }
        } else {
            cout << "[1] Religion\t" << "[2] Philosophy\t" << "[3] Biography\t" << "[4] Spirituality\n"
                << "[5] Autobiography\t" << "[6] Memoir\t" << "[7] Psychology\t" << "[8] Success\t" << "[9] Economics\n";
            cin >> genreChoice;
            while ((genreChoice != 1) && (genreChoice != 2) && (genreChoice != 3) && (genreChoice != 4)
                    && (genreChoice != 5) && (genreChoice != 6) && (genreChoice != 7) && (genreChoice != 8) && (genreChoice != 9)) {
                cout << "Invalid option. Please enter again:" << endl;
                cin >> genreChoice;
            }
        }

        
        
        string genre = getGenreFromChoice(booktype, genreChoice);

        recommendBooks(booktype, genre);
    }

    string getGenreFromChoice(int booktype, int choice) const {
        if (booktype == 1) {
            switch (choice) {
                case 1: return "Action";
                case 2: return "Romance";
                case 3: return "Mystery";
                case 4: return "Fantasy";
                case 5: return "Science Fiction";
                case 6: return "Horror";
                case 7: return "Thriller";
                case 8: return "Dystopian";
                default: return "Unknown";
            }
        } else {
            switch (choice) {
                case 1: return "Religion";
                case 2: return "Philosophy";
                case 3: return "Biography";
                case 4: return "Spirituality";
                case 5: return "Autobiography";
                case 6: return "Memoir";
                case 7: return "Psychology";
                case 8: return "Success";
                case 9: return "Economics";
                default: return "Unknown";
            }
        }
    }
};

#endif