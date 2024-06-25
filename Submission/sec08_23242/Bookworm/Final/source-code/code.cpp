#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Publisher {
	private:
    	string publisherName;
		string country;
	
	public:
	    Publisher() {}
	    
	    Publisher(string n, string c) : publisherName(n), country(c) {}
	    
		~Publisher() {}
		
	    string getPublisherName() const { 
			return publisherName; 
		}
		
	    void setPublisherName (string n) { 
			publisherName = n; 
		}
		
	    string getCountry() const { 
			return country; 
		}
		
	    void setCountry(string c) { 
			country = c; 
		}
};

class Book {
	protected:
	    string bookCode;
	    string bookTitle;
	    string genre;
	    int yearPublish;
	    Publisher* publisher; // aggregation

	public:
	    Book() : publisher(NULL) {}
	    
	    Book(string bc, string bt, string g, int yp, Publisher* p) 
	        : bookCode(bc), bookTitle(bt), genre(g), yearPublish(yp), publisher(p) {}
	    
		~Book() {}
		
	    string getBookCode() const { 
			return bookCode; 
		}
		
	    string getBookTitle() const { 
			return bookTitle; 
		}
		
	    string getGenre() const { 
			return genre; 
		}
		
	    int getYearPublish() const { 
			return yearPublish; 
		}
		
	    Publisher* getPublisher() const { 
			return publisher; 
		}
	    
		void setBookCode(string bc) { 
			bookCode = bc; 
		}
		
	    void setBookTitle(string bt) { 
			bookTitle = bt; 
		}
		
	    void setGenre(string g) { 
			genre = g; 
		}
		
	    void setYearPublish(int yp) { 
			yearPublish = yp; 
		}
		
	    void setPublisher(Publisher* p) { 
			publisher = p; 
		}
	    
	    virtual void display() const {  // use virtual to apply polymorphism
	        cout << left << setw(8) << bookCode 
	             << setw(25) << bookTitle 
	             << setw(10) << genre 
	             << setw(14) << yearPublish 
	             << setw(31) << publisher->getPublisherName() + ", " + publisher->getCountry();
	    }
	    
	    int getBookAge() const {
	        time_t t = time(0);
	        tm* now = localtime(&t);
	        int currentYear = now->tm_year + 1900;
	        return currentYear - yearPublish;
	    }

	    bool isClassic() const {
	        return getBookAge() > 50;
	    }
};

class Booklist {
    private:
        Book* books[100]; // aggregation
        int count;

    public:
        Booklist(){
            count = 0;
            for(int i=0; i<100; i++){
                books[i] = NULL;
            }
        }

        ~Booklist(){}

        int getCount(){ return count; }
		
		void setCount(int c){ count = c; }
        
        Book* getBook(int index){
            return books[index];
        }

        void addBook(Book *b){
            for (int i=0; i<100; i++){
                if (books[i] == nullptr){
                    books[i] = b;
                    count++;
                    cout << "This book is successfully added into your personalized booklist!" << endl << endl;
                    break;
                }
            }
        }

        bool isBookInList(Book *b){
            for(int i=0; i<count; i++){
                if (books[i] == b)
                    return true;
            }
            return false;
        }

        void display(){
            cout << left << setw(11) << "Book Code" << setw(25) << "Book Title" << setw(10) << "Genre" << setw(14) << "Year Publish" << setw(31) <<"Publisher" << endl;
            for (int i=0; i<count; i++){
                if (books[i] != nullptr)
                {
                	cout << i + 1 << ") ";
                    books[i]->display();
                    cout << endl;
                }
        	}
		}
};
