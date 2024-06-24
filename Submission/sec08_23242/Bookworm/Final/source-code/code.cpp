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