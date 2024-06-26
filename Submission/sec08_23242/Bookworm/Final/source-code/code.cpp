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

        void removeBook(int index) {
	        if (index >= 0 && index < count && books[index] != nullptr) {
	            books[index] = nullptr;
	            for (int i = index; i < count - 1; i++) {
	                books[i] = books[i + 1];
	            }
	            books[count - 1] = nullptr;
	            count--;
	            cout << "Book removed successfully." << endl;
	        } else {
	            cout << "Invalid book index." << endl;
	        }
	    }
	    
	    void saveBooklist() {
		    string filename = "user_booklist.txt";
		    ofstream file(filename);
		    if (!file) {
		        cerr << "Failed to open file for saving." << endl;
		        return;
		    }
		    file << "------------------------------------------------------------------------------------------------------------------\n";
		    file << "\t\t\t\t\t       Personal Book List   \t\t\t\t\t" << endl;
			file << "------------------------------------------------------------------------------------------------------------------\n";
			file << left << setw(15) << "Book Code" << setw(25) << "Book Title" << setw(20) << "Genre" << setw(20) << "Year Publish" << setw(31) << "Publisher" << endl;
			file << "------------------------------------------------------------------------------------------------------------------\n";
		    for (int i = 0; i < count; i++) {
		        if (books[i] != nullptr) {
		        	Publisher* publisher = books[i]->getPublisher();
		            file << i + 1 << ") " << left << setw(12) << books[i]->getBookCode()  
						 << setw(25) << books[i]->getBookTitle() << setw(20) << books[i]->getGenre() << setw(20) 
						 << books[i]->getYearPublish() << setw(31) << publisher->getPublisherName() + ", " + publisher->getCountry() << endl;
		        }
		    }
		    file.close();
		    cout << "Booklist saved to " << filename << "." << endl;
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

	void removeBookFromBooklist(int index) {
	        booklist.removeBook(index);
	    }
	    
	    void saveUserBooklist() {
		    booklist.saveBooklist();
		}
		
		int getBooklistCount() const {
            return booklist.getCount();
        }

        Book* getBookFromBooklist(int index) {
            return booklist.getBook(index);
        }
};

int main() {
	User user1;
	int choice, choice2, choice3, choice4, choice5, choice6, choice7, choice8, choice9, choice10, choice11, choice12;
	int genreChoice;
	
	// array of objects
	Publisher p[5]{{"HarperCollins", "United Kingdom"}, 
					{"Penguin Random House", "America"}, 
					{"Hachette Publishing", "America"}, 
					{"Simon & Schuster", "Australia"}, 
					{"Macmillan", "America"}};
					
	Book trending[5] = {{"t001","Pride and Prejudice","Romance", 1813, &p[1]},
						{"t002","Secrets in the dark","Romance", 2023,&p[0]},
						{"t003","The Olympian Affair","Sci-Fi", 2023, &p[1]},
						{"t004", "Hunt On Dark Waters", "Fantasy", 2023, &p[1]},
						{"t005", "The Scarlett Throne", "Sci-fi", 2024, &p[2]}};
						
	Romance romance[5]={{"r001", "Love from Scratch", 2024, &p[3], "Ethan and Hazel"},
						{"r002", "The Song of Achilles", 2012, &p[0], "Patroclus and Achilles"},
						{"r003", "Leopard's Hunt", 2024, &p[1], "Gorya and Maya"},
						{"r004", "Mistakes we never made", 2024, &p[2], "Finn and Emma"},
						{"r005", "Your Lion Eyes", 2018, &p[4], "Grady and Molly"}};
						
	Fantasy fantasy[5]={{"f001", "Rewitched", 2024, &p[4], "Witch"},
						{"f002", "Howl's moving castle", 2008, &p[0], "Magician"},
						{"f003", "Night Angel Nemesis", 2024, &p[2], "Angel"},
						{"f004", "Blood on the tide", 2024, &p[1], "Vampire"},
						{"f005", "The Desert Talon", 2025, &p[3], "Dragons"}};
						
	SciFi scifi[5] = {{"s001", "Service Model", 2024, &p[4], "Robot"},
					  {"s002", "The Hair Carpet Weavers", 2020, &p[1], "Universe"},
					  {"s003", "Translation State", 2024, &p[2], "Translator"},
					  {"s004", "Trinity:A Novel", 2024, &p[3], "Nuclear"},
					  {"s005", "Termination Shock", 2021, &p[0], "Futuristic"}};

	// Log In Page
	cout << "******************************************************************************************************************\n";
	cout << "*                                                                                                                *\n";
	cout << "*                              Welcome to Bookworm Book Recommendation System                                    *\n";
	cout << "*                                                                                                                *\n";
	cout << "******************************************************************************************************************\n";
	cout << "------------------------------------------------------------------------------------------------------------------\n";
	cout << "\t\t\t\t\t     Log In Page   \t\t\t\t\t" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------\n\n";
	user1.displayLogin();

		do {
		// Menu Page
		system("cls");
		cout << "******************************************************************************************************************\n";
		cout << "*                                                                                                                *\n";
		cout << "*                                   Bookworm Book Recommendation System                                          *\n";
		cout << "*                                                                                                                *\n";
		cout << "******************************************************************************************************************\n";
		cout << "------------------------------------------------------------------------------------------------------------------\n";
		cout << "\t\t\t\t\t        Menu Page \t\t\t\t\t" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------\n";
		cout << "Please select an option: \n";
	    cout << "Option 1: See trending book list" << endl;
	    cout << "Option 2: See specific genre book list" << endl;
	    cout << "Option 3: View my book recommendation list" << endl;
	    cout << "Option 4: Remove a Book from My Booklist" << endl;
	    cout << "Option 5: Save My Booklist to txt file" << endl;
	    cout << "Option 6: Check whether a book in My Booklist is classic book" << endl;
		cout << "Option 7: Exit" << endl;
	    cout << "\nEnter your option: ";
	    cin >> choice;
	    
	    // if user choose option 1 in menu page
	    if (choice == 1) {
	    	do {
	    		// Trending Book List Page
		    	system("cls");
		    	cout << "------------------------------------------------------------------------------------------------------------------\n";
				cout << "\t\t\t\t\t Trending List Page \t\t\t\t\t" << endl;
				cout << "------------------------------------------------------------------------------------------------------------------\n";
				cout << "\nHere is our most popular list of books: \n\n";
				cout << "------------------------------------------------------------------------------------------------------------------\n";
		        cout << left << setw(8) << "Code\t" << setw(25) << "Book Name" << setw(10) << "Genre" << setw(14) << "Year Publish"  << setw(31) << "Publisher" << endl;
		        cout << "------------------------------------------------------------------------------------------------------------------\n";
		        
				// display the books
				for (int i = 0; i < 5; i++) {
                    cout << (i + 1) << ". ";
                    trending[i].display();
                    cout << endl;
                }
		    	
		    	// choice2 user can input the number of trending book they want, or input 6 to go back main menu
	            cout << "\nPlease kindly input the number (1-5) of the trending book you are interested in, press 6 to back to main menu: ";
	            cin >> choice2;
		   
                if (choice2 >= 1 && choice2 <= 5) {
                    user1.addBookToBooklist(&trending[choice2 - 1]);
    				
    				bool validChoice = false;
            		while (!validChoice) {
	                    // choice3 user can input 1 if want add more book, or input other number to go back main menu
	                    cout << "Enter 1 to add more books, enter other number to go back to main menu: ";
	                    cin >> choice3;
	                    
	                    if(cin.fail()){
	                    	cin.clear(); // Clear the error flag
	            			cin.ignore(INT_MAX, '\n'); // Discard invalid input
	            			cout << "Invalid input. Please enter an integer value.\n";
                		} else {
                    		validChoice = true;
                		}
					}
					
                } else if (choice2 == 6) {
                    break;
                } else {
                	cin.clear(); // Clear the error flag
            		cin.ignore(INT_MAX, '\n'); // Discard invalid input
                	cout << "Invalid input.\n";
                	system("pause");
				}
		    } while (choice2 < 1 || choice2 > 5 || choice3 == 1);
	    }

	

