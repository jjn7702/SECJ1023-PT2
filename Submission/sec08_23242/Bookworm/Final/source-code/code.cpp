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

class Romance : public Book { // inheritance
	private:
	    string mainCoupleName;

	public:
	    Romance() { 
			mainCoupleName = ""; 
		}
		
	    Romance(string bc, string bt, int yp, Publisher *p, string mc) : Book(bc, bt, "Romance", yp, p) {
	        mainCoupleName = mc;
	    }
	    
	    ~Romance() {}
	    
	    string getMainCoupleName() { 
			return mainCoupleName; 
		}
		
	    void setMainCouple(string mc) { 
			mainCoupleName = mc; 
		}
		
	    // override display function in Book class to display main couple name
	    void display(){
	        Book::display();
	        cout << left << setw(25) << mainCoupleName << endl;
	    }
};

class Fantasy : public Book { // inheritance
	private:
	    string creatureType;

	public:
	    Fantasy() {
	        creatureType = "";
	    }
	
	    Fantasy(string bc, string bt, int yp, Publisher *p, string ct) : Book(bc, bt, "Fantasy", yp, p) {
	        creatureType = ct;
	    }
	
	    ~Fantasy() {}
	
	    string getCreatureType() {
	        return creatureType;
	    }
	
	    void setCreatureType(string ct) {
	        creatureType = ct;
	    }
	
		// override display function in Book class to display creature type
	    void display() {
	        Book::display();
	        cout << left << setw(25) << creatureType << endl;
	    }
};

class SciFi : public Book { // inheritance
	private:
	    string scientificConcept;
	
	public:
	    SciFi() {
	        scientificConcept = "";
	    }
	
	    ~SciFi() {}
	
	    SciFi(string bc, string bt, int yp, Publisher *p, string sc) : Book(bc, bt, "Sci-Fi", yp, p) {
	        scientificConcept = sc;
	    }
	
	    string getScientificConcept(){
	        return scientificConcept;
	    }
	
	    void setScientificConcept(string sc) {
	        scientificConcept = sc;
	    }
	
		// override display function in Book class to display scientific concept
	    void display() {
	        Book::display();
	        cout << left << setw(25) << scientificConcept << endl;
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

class User{
    private:
        string name;
        string phoneNum;
        string icNum;
        Booklist booklist; // composition

    public:
        User(){}
        
        ~User(){}
        
        User(string ic, string n, string pn){
            icNum = ic;
            name = n;
            phoneNum = pn;
        }

        string getName() {
            return name;
        }

        string getPhoneNum() {
            return phoneNum;
        }

        string getIcNum() {
            return icNum;
        }

        void setName(string n) {
            name = n;
        }

        void setPhoneNum(string pn) {
            phoneNum = pn;
        }

        void setIcNum(string ic) {
            icNum = ic;
        }

        void displayLogin() {
        	do {
	            cout << "Please enter your ic number   : ";
	            getline(cin, icNum);
				if (icNum.empty()) {
					cout << "Ic cannot be empty. Please try again.\n";
				}
			} while (icNum.empty());
			
			do {
            	cout << "Please enter your name        : ";
            	getline(cin, name);
	            if (name.empty()) {
					cout << "Name cannot be empty. Please try again.\n";
				}
            } while (name.empty());
            
            bool valid = false;

            while (!valid) {
            	// exception handling
                try {
                    cout << "Please enter your phone number: ";
                    getline(cin, phoneNum);
					
					if (phoneNum.empty()) {
           				cout << "Phone cannot be empty. Please try again.\n";
            			continue; // Restart the loop if phone number is empty
       				}				
					
                    for (char c : phoneNum) {
                        if (isalpha(c)) {
                            throw invalid_argument("Phone number contains invalid characters");
                        }
                    }

                    valid = true; 
                }
                catch (const invalid_argument &e){
                    cout << e.what() << endl;
                    cout << "Please re-enter your phone number and only number digits allowed!" << endl << endl;
                }
            }
        }

        void displayBooklist(){
            cout << "------------------------------------------------------------------------------------------------------------------\n";
            cout << "\t\t\t\t\t       User details   \t\t\t\t\t" << endl;
            cout << "------------------------------------------------------------------------------------------------------------------\n";
            cout << left << setw(20) << "Name " << ": " << name << endl;
            cout << left << setw(20) << "Phone Number " << ": " << phoneNum << endl;
            cout << left << setw(20) << "IC Number " << ": " << icNum << endl << endl;
            cout << "------------------------------------------------------------------------------------------------------------------\n";
            cout << "\t\t\t\t\t       " << name << "'s  booklist \t\t\t\t\t" << endl;
            cout << "------------------------------------------------------------------------------------------------------------------\n";
            booklist.display();

        }

        void addBookToBooklist(Book* book){
            int y = booklist.isBookInList(book);
            if(y==0)
                booklist.addBook(book);
            else if(y==1)
                cout << "This book is already in your personalized book list! :)" << endl << endl;

        }
};
