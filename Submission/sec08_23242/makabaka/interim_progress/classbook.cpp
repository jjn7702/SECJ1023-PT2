#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Book {
    protected:
        int bookID;
        string title;
        string publisher;
        int publicationYear;
        string ISBN;
        string condition;
        string status;

    public:
        Book(int b=0, string t="", string ps="", int py=0, string cond="", string isbn="", string st="") {
            bookID = b;
            title = t;
            publisher = ps;
            publicationYear = py;
            ISBN = isbn;
            condition = cond;
            status = st;
        }

        virtual ~Book() {}


        int getBookID() {return bookID;}
        string getTitle() {return title;}
        string getPS() {return publisher;}
        int getPY() {return publicationYear;}
        string getISBN() {return ISBN;}
        string getCondition() {return condition;}
        string getStatus() {return status;}
        virtual string getAuthor() {return "";}
        virtual string getLanguage() {return "";}

        void setTitle(string t) {title = t;}
        void setPS(string ps) {publisher = ps;}
        void setPY(int py) {publicationYear = py;}
        void setISBN(string isbn) {ISBN = isbn;}
        void setCondition(string c) {condition = c;}
        void setStatus(string s) 
        {
            if(s == "Available" || s == "Unavailable")
                status = s;
            else
                cout << "Invalid status" << endl;
        }
        virtual void setAuthor(string a) {}
        virtual void setLanguage(string l) {}
        
        virtual void dispBookDetails(){
            cout << setw(8) << bookID
                << setw(13) << title
                << setw(11) << publisher
                << setw(10) << publicationYear
                << setw(10) << ISBN
                << setw(10) << condition
                << setw(15) << status << endl;
        }

        void changeStatus(){
            if (status == "Available") {
                status = "Unavailable";
            }else {
                status = "Available";
            }
        }
};

class Dictionary:public Book {
    private:
        string pair_language;
        string authorTeam;

    public:
        Dictionary(string p1="", string auT="", int b=0, string t="", string ps="", int py=0, string cond="", string isbn="", string st="")
        :Book(b, t, ps, py, cond, isbn, st) {
            setPairLanguage(p1);
            setAuT(auT);
        }

        ~Dictionary(){}



        void setPairLanguage(string p1){
            pair_language = p1;
        }

        void setAuT(string auT){
            authorTeam = auT;
        }

        virtual string getPairLanguage() {return pair_language;}

        virtual string getAuT(){
            return authorTeam;
        }

        void dispBookDetails(){
            cout << setw(8) << bookID
                << setw(15) << title
                << setw(13) << authorTeam
                << setw(14) << pair_language
                << setw(10) << condition
                << setw(15) << status << endl;
        }
};

class Encyclopedia: public Book{
    private:
        string author;
        string language;

    public: 
        Encyclopedia(string a="", string l="",int b=0, string t="", string ps="", int py=0, string cond="", string isbn="", string st="")
        :Book(b, t, ps, py, cond, isbn, st){
            setAuthor(a);
            setLanguage(l);
        }

        ~Encyclopedia(){}

        virtual void setAuthor(string a){
            author = a;
        }

        virtual void setLanguage(string l){
            language = l;
        }

        string getAuthor(){
            return author;
        }

        string getLanguage(){
            return language;
        }

        virtual void dispBookDetails()override{
            cout << setw(8) << bookID
                << setw(17) << title
                << setw(10) << author
                << setw(15) << language
                << setw(10) << condition
                << setw(15) << status << endl;
        }
};

int main()
{
    cout << "------------------------------Book Listing Details--------------------------------" << endl;
    cout<< setw(11)<< "Book ID" << setw(10) << "Title" << setw(14) << "Author" << setw(15) << "Language" << setw(13) << "Condition" << setw(10) << "Status" << endl;
    Dictionary d1("English", "Sabrina", 1, "Dictionary", "Oxford", 2021, "Good", "123456", "Available");
    Encyclopedia e1("Amanda", "English", 2, "Encyclopedia", "Oxford", 2021, "Good", "123456", "Available");
    d1.dispBookDetails();
    e1.dispBookDetails();

    cout << endl;

    cout << "--------------------------------Book Details--------------------------------" << endl;
    cout << setw(11) << "Book ID" << setw(10) << "Title" << setw(13) << "Publisher" << setw(8) << "Year" << setw(8) << "ISBN" << setw(15) << "Condition" << setw(10) << "Status" << endl;
    Book b1(1, "C++ OOP", "Oxford", 2021, "Good", "135467", "Available");

    b1.dispBookDetails();

    cout << endl;    
    
    Book b2(2, "Java OOP", "Oxford", 2021, "Good", "184874", "Available");

    //Access and display details using getter methods
    cout << "-------------------Book Details----------------------- " << endl;
    cout << "Book ID: " << b2.getBookID() << endl;
    cout << "Title: " << b2.getTitle() << endl;
    cout << "Publisher: " << b2.getPS() << endl;
    cout << "Publication Year: " << b2.getPY() << endl;
    cout << "ISBN: " << b2.getISBN() << endl;
    cout << "Condition: " << b2.getCondition() << endl;
    cout << "Status: " << b2.getStatus() << endl;

    //display updated details
    cout << "\nUpdated Book Details: " << endl;
    cout << "--------------------------------Book Details--------------------------------" << endl;
    cout << setw(11) << "Book ID" << setw(10) << "Title" << setw(13) << "Publisher" << setw(8) << "Year" << setw(8) << "ISBN" << setw(15) << "Condition" << setw(10) << "Status" << endl;
    b2.dispBookDetails();

    //Change status of the book
    b2.changeStatus();
    cout << "\n>>>>> After changing status <<<<<" << endl;
    cout << "Updated Status: " << b2.getStatus() << endl;


    return 0;
}