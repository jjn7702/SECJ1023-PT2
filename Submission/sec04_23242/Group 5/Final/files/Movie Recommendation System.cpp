// *** Movie Recommendation System ***

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
using namespace std;

// MoviePreferences class
class MoviePreferences {
private:
    static const int MAX_G = 4, MAX_A = 5, MAX_D = 5, MAX_Y = 3;
    string genres[MAX_G] = {"Horror", "Action", "Comedy", "Drama"};
	string actors[MAX_A] = {"Russell Crowe", "Daniel Craig", "Keanu Reeves", "Robert Downey Jr", "Leonardo DiCaprio"};
	string directors[MAX_D] = {"Christopher Nolan", "Jon Favreau", "James Gunn","James Wan", "David Leitch"};
	string years_of_release[MAX_Y] = {"2000s", "2010s", "2020s"};
    string _genre, _actor, _director, _years_of_release;
    int g, a, d, y;

public:
    MoviePreferences(string genre = "", string actor = "", string director = "", string year = "") 
        : _genre(genre), _actor(actor), _director(director), _years_of_release(year) {}
    ~MoviePreferences() {}
	
	// Display genre
    void displayGenresList() {
        do {
            cout << " Genres's List :" << endl;
            for (int i = 0; i < MAX_G; ++i)
                cout << "  " << i+1 << " - " << genres[i] << endl;
            cout << " Choose one of the Genres => ";
            cin >> g;

            if (g <= 0 || g > MAX_G) {
                cout << endl;
                cout << " *** INVALID. Please choose between 1 - " << MAX_G << " ***" << endl << endl << endl;
            }
        } while (g <= 0 || g > MAX_G);
        cout << endl;
    }
	
	// Display actor
    void displayActorsList() {
        do {
            cout << " Actor's List :" << endl;
        	for (int i = 0; i < MAX_A; ++i) 
            	cout << "  " << i+1 << " - " << actors[i] << endl;
        	cout << " Choose one of the Actors => ";
        	cin >> a;
        	
        	if (a <= 0 || a > MAX_A) {
        		cout << endl;
            	cout << " *** INVALID. Please choose between 1 - " << MAX_A << " ***" << endl << endl << endl;
        	}
    	} while (a <= 0 || a > MAX_A);
    	cout << endl;
    }
	
	// Display director
    void displayDirectorsList() {
        do {
        	cout << " Director's List :" << endl;
        	for (int i = 0; i < MAX_D; ++i) 
            	cout << "  " << i+1 << " - " << directors[i] << endl;
        	cout << " Choose one of the Directors => ";
        	cin >> d;
        	
        	if (d <= 0 || d > MAX_D) {
        		cout << endl;
            	cout << " *** INVALID. Please choose between 1 - " << MAX_D << " ***" << endl << endl << endl;
        	}
    	} while (d <= 0 || d > MAX_D);
    	cout << endl;
    }

	// Display year
    void displayYearList() {
        do {
        	cout << " YEAR of RELEASE LIST :" << endl;
        	for (int i = 0; i < MAX_Y; ++i) 
            	cout << "  " << i+1 << " - " << years_of_release[i] << endl;
        	cout << " Choose one of the Years => ";
        	cin >> y;

        	if (y <= 0 || y > MAX_Y) {
        		cout << endl;
            	cout << " *** INVALID. Please choose between 1 - " << MAX_Y << " ***" << endl << endl << endl;
        	}
    	} while (y <= 0 || y > MAX_Y);
    	cout << endl << endl << endl;
    }
    
    // Getter function
    int getG () const { return g; }
    int getA () const { return a; }
    int getD () const { return d; } 
	int getY () const { return y; }
	
    // Mapping
	int genreName (string n) {
		map <string, int> GName ={{"Horror", 1}, {"Action", 2}, {"Comedy", 3}, {"Drama", 4}};
		return GName[n];
	}
	int actorName (string n) {
		map <string, int> AName ={{"Russell Crowe", 1}, {"Daniel Craig", 2}, {"Keanu Reeves", 3}, {"Robert Downey Jr", 4}, {"Leonardo DiCaprio", 5}};
		return AName[n];
	}
	int direcName (string n) {
		map <string, int> DName ={{"Christopher Nolan", 1}, {"Jon Favreau", 2}, {"James Gunn", 3}, {"James Wan", 4}, {"David Leitch", 5}};
		return DName[n];
	}
	int yearName (string n) {
		map <string, int> YName ={{"2000s", 1}, {"2010s", 2}, {"2020s", 3}};
		return YName[n];
	}
    
	// Set user's preferences
    void set_preferences() {
        if (g > 0 && g <= MAX_G) { _genre = genres[g - 1]; }
        if (a > 0 && a <= MAX_A) { _actor = actors[a - 1]; }
        if (d > 0 && d <= MAX_D) { _director = directors[d - 1]; }
        if (y > 0 && y <= MAX_Y) { _years_of_release = years_of_release[y - 1]; }
    }
    
    // Set user's preference
    void set_preferences(string _g, string _a, string _d, string _y) {
        _genre = _g; 
        _actor = _a; 
        _director = _d; 
        _years_of_release = _y; 
    }
    
    // Getter function
    string get_G () const { return _genre; }
    string get_A () const { return _actor; }
    string get_D () const { return _director; } 
	string get_Y () const { return _years_of_release; }
	
	// Display preferences
    void get_preferences() const {
        cout << " YOUR PREFERENCES:" << endl;
        cout << "-------------------" << endl;
        cout << "  Genre           => " << _genre << endl;
        cout << "  Actor           => " << _actor << endl;
        cout << "  Director        => " << _director << endl;
        cout << "  Year of Release => " << _years_of_release << endl << endl << endl;
    }

    // Function to save preferences to a user.txt file
    void savePreferences(const string& username) const {
        ofstream userFile("user.txt", ios::app);
        if (!userFile.is_open()) {
            cerr << " Error opening user file." << endl;
            return;
        }
        userFile << username << "," << _genre << ","
                 << _actor << ","
                 << _director << ","
                 << _years_of_release << endl;
        userFile.close();
        cout << " Preferences saved successfully!" << endl << endl;
    }

    // Function to load preferences from user.txt file
    bool loadPreferences(const string& username) {
        ifstream userFile("user.txt");
        if (!userFile.is_open()) {
            cerr << " Error opening user file." << endl;
            return false;
        }

        string line;
        while (getline(userFile, line)) {
            istringstream iss(line);
            string user, genre, actor, director, year;
            if (getline(iss, user, ',') &&
                getline(iss, genre, ',') &&
                getline(iss, actor, ',') &&
                getline(iss, director, ',') &&
                getline(iss, year)) {
                
                if (user == username) {
                    _genre = genre;
                    _actor = actor;
                    _director = director;
                    _years_of_release = year;
                    userFile.close();
                    return true;
                }
            }
        }
        userFile.close();
        return false;
    }
};

// Movie class
class Movie {
private:
    string title, genre, actor, director, year;
    float rating;

public:
    Movie(string t = "", string g = "", string a = "", string d = "", string y = "", float r = 0) 
		: title(t), genre(g), actor(a), director(d), year(y), rating(r) {}

    // Pure virtual function for setting preferences
	virtual void set_preferences(){}

    // Setter functions
    void setTitle(string t) { title = t; }
    void setGenre(string g) { genre = g; }
    void setActor(string a) { actor = a; }
    void setDirector(string d) { director = d; }
    void setYear(string y) { year = y; }
    void setRating(float r) { rating = r; }

    // Getter functions
    string getTitle() const { return title; }
    string getGenre() const { return genre; }
    string getActor() const { return actor; }
    string getDirector() const { return director; }
    string getYear() const { return year; }
    float getRating() const { return rating; }

	// Display movie's details
    void get_details() const {
        cout << "  Title           : " << title << endl;
        cout << "  Genre           : " << genre << endl;
        cout << "  Actor           : " << actor << endl;
        cout << "  Director        : " << director << endl;
        cout << "  Year of Release : " << year << endl;
        cout << "  Rating          : " << rating << endl << endl;
    }
};

// RecommendationSystem class
// Composition & Aggregation
class RecommendationSystem {
private:
    static const int MAX_MOVIES = 120;
    string movie_titles[MAX_MOVIES];
    string movie_genres[MAX_MOVIES];
    string movie_year[MAX_MOVIES];
    string movie_director[MAX_MOVIES];
	string movie_actor[MAX_MOVIES];
    double movie_ratings[MAX_MOVIES];
    int recommendation_list[MAX_MOVIES];
    int recommendation_count;
    int n;
    
    vector<Movie*> movies; 
    MoviePreferences mp;
    Movie* movie;

public:
    RecommendationSystem() : n(0), recommendation_count(0) {
    	// Read the INPUT2 file
        ifstream inputFile("INPUT2.txt");
        if (!inputFile.is_open()) {
            cerr << " Error opening input file 'INPUT2.txt'" << endl;
            return;
        }
		
		for (int i = 0; i < MAX_MOVIES; i++) {
			string title, genre, year, director, actor;
			double rating;
			
			getline(inputFile, title, ',');
        	getline(inputFile, genre, ',');
        	getline(inputFile, year, ',');
        	getline(inputFile, director, ',');
        	getline(inputFile, actor, ',');
        	inputFile >> rating;
        	inputFile.ignore();
	
        	movie_titles[i] = title;
        	movie_genres[i] = genre;
        	movie_year[i] = year;
        	movie_director[i] = director;
        	movie_actor[i] = actor;
        	movie_ratings[i]  = rating;	
        	
        	n++;
		}
        inputFile.close();
        
        // Initialize movies vector with pointers to Movie objects
        for (int i = 0; i < n; i++) {
            movies.push_back(new Movie(movie_titles[i], movie_genres[i], movie_actor[i], movie_director[i], movie_year[i], movie_ratings[i]));
        }
    }
	
	// Mapping
	string genreName (int n) {
		map <int, string> GName ={{1, "Horror"}, {2, "Action"}, {3, "Comedy"}, {4, "Drama"}};
		return GName[n];
	}
	string actorName (int n) {
		map <int, string> AName ={{1, "Russell Crowe"}, {2, "Daniel Craig"}, {3, "Keanu Reeves"}, {4, "Robert Downey Jr"}, {5, "Leonardo DiCaprio"}};
		return AName[n];
	}
	string direcName (int n) {
		map <int, string> DName ={{1, "Christopher Nolan"}, {2, "Jon Favreau"}, {3, "James Gunn"}, {4, "James Wan"}, {5, "David Leitch"}};
		return DName[n];
	}
	string yearName (int n) {
		map <int, string> YName ={{1, "2000s"}, {2, "2010s"}, {3, "2020s"}};
		return YName[n];
	}
	
	// Filter preferences
	void filter_preferences(MoviePreferences& mp) {
	    recommendation_count = 0;
	    for (int i = 0; i < n; ++i) {
	        if (movie_genres[i] == genreName(mp.getG()) && movie_year[i] == yearName(mp.getY())) {
	            recommendation_list[recommendation_count++] = i;
	        } else if (movie_genres[i] == mp.get_G() && movie_year[i] == mp.get_Y() ) {
	            recommendation_list[recommendation_count++] = i;
			}
	    }
	}
	
	// Generate movie recommendation list
	void generate_recommendations() const {
	    cout << "-----------------------" << endl;
	    cout << " Recommendations List:" << endl;
	    cout << "-----------------------" << endl;
	    for (int i = 0; i < recommendation_count; ++i) {
	        int index = recommendation_list[i];
	        movies[index]->get_details();
	    }
	}
	
	// Movie Matchmaker : Generate random movie list
	void randomMovie () {
		cout << "-----------------------" << endl;
        cout << " Movie Matchmaker List:" << endl;
        cout << "-----------------------" << endl;
        int index;
        
        // To avoid duplicate
        bool choosen[MAX_MOVIES] = {false};
        
        // Randomly generate 10 movies only
        for (int i = 0; i < 10; i ++) {
        	do {
        		index = rand() % movies.size();
			} while (choosen[index]);
			if (choosen[index] = true)
				movies[index]->get_details();
		}
	}
};

// Account class
// Composition
class Account {
private:
    string username, password;
    MoviePreferences preferences;

public:
    Account(const string& uname = "", const string& pwd = "", MoviePreferences pref = MoviePreferences()) 
        : username(uname), password(pwd), preferences(pref) {}
	
	// Getter function
	const string& getUsernme () const { return username; }
	const string& getPassword () const { return password; }
	
	// Create new account
    void create_account() {
    	cout << "----------------------------------" << endl;
        cout << "  Enter username: ";
        getline(cin, username);
        cout << "  Enter password: ";
        getline(cin, password);
        cout << endl;
    }
    
    MoviePreferences getPreferences() const { return preferences; }
};

// User class
// Aggregation
class User {
protected:
    string username, password;
    MoviePreferences* movie_preferences;
    int feedback;

public:
    User(const string& uname, const string& pwd) : username(uname), password(pwd) {}
	
	// Update movie preferences
    void update_preferences(MoviePreferences* preferences) {
        movie_preferences = preferences;
    }
    
	// Feedback
    void giveFeedback(int& feedback) {
        this -> feedback = feedback;
    }
    
	// Show movie preferences
    void showPreferences() const {
        movie_preferences->get_preferences();
    }

	// Reply to user feedback
    void showFeedback(int& feedback) const {
    	switch (feedback) {
    		case 1 : cout << " (Y_Y) We're sorry to hear about your bad experience and appreciate you bringing this to our attention." << endl;
    			break;
    		case 2 : cout << " (UwU) We're sorry to hear about your negative experience, that's definitely not what we want for our customers." << endl;
    			break;
    		case 3 : cout << " (O.O) We're really grateful and appreciate you taking the time to share your rating with us." << endl;
    			break;
    		case 4 : cout << " (^.^) We're really happy to hear about your positive feedback!" << endl;
    			break;
    		case 5 : cout << " (^3^) We're glad that you enjoyed our service!" << endl;
    			break;
    		default : cout << " *** Invalid Rating ***" << endl;
    			break;
		}
    }
    
    // Pure virtual function
    virtual void _giveFeedback(int feedback) {
        this->feedback = feedback;
    }
    
    // Display feedback menu
    void displayFeedback () {
    	int feedback;	
    	cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << " *  FEEDBACK                                         * " << endl;
		cout << " * ----------                                        * " << endl;
		cout << " *   1 - Very Unsatisfied   (Y_Y)                    * " << endl;
		cout << " *   2 - Unsatisfied        (UwU)                    * " << endl;
		cout << " *   3 - Neutral            (O.O)                    * " << endl;
		cout << " *   4 - Satisfied          (^.^)                    * " << endl;
		cout << " *   5 - Very Satisfied     (^3^)                    * " << endl;
		cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << " Please rate our system from 1 to 5: ";
	}
	
	// Display exit menu
	void displayExit() {
		cout << endl << endl << endl;
		cout << "\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << "\t\t             >>> Thank you for using our system , see you again next time! <<<	" << endl;
		cout << "\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl << endl;		
	}
};

// RegisteredUser class
// Inheritance
class RegisteredUser : public User {	
private:
    MoviePreferences preferences;
    
public:
    RegisteredUser(const string& uname, const string& pwd, const MoviePreferences& pref)
    	: User(uname, pwd), preferences(pref) {}
	
	// Indicate new account is created
    void create_account() {
        cout << "Account created successfully for user: " << username << endl;
    }
	
	// Indicate user's information is stored
    void store_information() {
        cout << "Storing information for user: " << username << endl;
    }
    
    // Override the virtual function
    void _giveFeedback(int feedback) override {
	// Specific implementation for giveFeedback in RegisteredUser
        this->feedback = feedback;
        User::giveFeedback(feedback);
    }
};

// Function to check whether username already exist
bool usernameExists(const string& username) {
    ifstream userFile("users.txt");
    if (!userFile.is_open()) {
        cerr << " Error opening users file." << endl;
        return false;
    }

    string line;
    while (getline(userFile, line)) {
        size_t delimiterPos = line.find(',');
        string storedUsername = line.substr(0, delimiterPos);
        if (storedUsername == username) {
            return true;
        }
    }
    return false;
}

// Function to sign up a new user and store their data
bool signUpUser(const string& username, const string& password, const MoviePreferences& preferences) {
    if (usernameExists(username)) {
        cout << " Username already exists. Please choose a different username." << endl << endl;
        return false;
    }

    ofstream userFile("users.txt", ios::app);
    if (!userFile.is_open()) {
        cerr << "Error opening users file." << endl;
        return false;
    }

    userFile << username << "," << password << endl;
    userFile.close(); 

    return true;
}

// Function to log in a user by checking their credentials
bool loginUser(const string& username, const string& password, MoviePreferences& preferences) {
    ifstream userFile("users.txt");
    if (!userFile.is_open()) {
        cerr << " Error opening users file." << endl;
        return false;
    }

    string line;
    while (getline(userFile, line)) {
        size_t delimiterPos = line.find(',');
        string storedUsername = line.substr(0, delimiterPos);
        string storedPassword = line.substr(delimiterPos + 1);

        if (storedUsername == username && storedPassword == password) {
            // Read preferences
            while (getline(userFile, line)) {
                size_t pos1 = line.find(',');
                size_t pos2 = line.find(',', pos1 + 1);
                size_t pos3 = line.find(',', pos2 + 1);
                size_t pos4 = line.find(',', pos3 + 1);
                string storedUser = line.substr(0, pos1);
                if (storedUser == username) {
                    string genre = line.substr(pos1 + 1, pos2 - pos1 - 1);
                    string actor = line.substr(pos2 + 1, pos3 - pos2 - 1);
                    string director = line.substr(pos3 + 1, pos4 - pos3 - 1);
                    string year = line.substr(pos4 + 1);
                    preferences.set_preferences(genre, actor, director, year);
                    break;
                }
            }
            return true;
        }
    }
    return false;
}


int main() {
    cout << "\n\n\n";
    cout << "\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "\t\t\t*                                                                         *" << endl;
    cout << "\t\t\t*        \(^_^)/   WELCOME TO MOVIE RECOMMENDATION SYSTEM   \(^_^)/         *" << endl;
    cout << "\t\t\t*                                                                         *" << endl;
    cout << "\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "\n\n\n";
 
    int choice;
    int feedback;
    RegisteredUser* regUser = nullptr;
	
	// Display main menu : Sign up @ Login @ Exit
    do {
        cout << "  1 - Sign Up" << endl;
        cout << "  2 - Login " << endl;
        cout << "  3 - Exit" << endl;
        cout << " Choose 1, 2 or 3 : ";
        cin >> choice;
        cin.ignore();
        cout << endl << endl;

        // 1.0 Sign Up
        if (choice == 1) {
            Account acc;
            MoviePreferences mPref;
            RecommendationSystem recommender;
			string uname, pwd;
			
			do {
	            // 1.1 Create User Account
	            cout << " USER SIGN UP " << endl;
	            acc.create_account();
	            uname = acc.getUsernme();
	            pwd = acc.getPassword();
	
	            // 1.2 Sign Up Successful
	            if (signUpUser(uname, pwd, mPref)) {
	                cout << "\n Sign Up Successful!" << endl;
	                cout << "----------------------------------" << endl << endl << endl;
	
	                // 1.2.1 Set Movie Preferences
	                mPref.displayGenresList();
	                mPref.displayActorsList();
	                mPref.displayDirectorsList();
	                mPref.displayYearList();
	
	                mPref.set_preferences();
	                // 1.2.2 Call savePreferences method of preferences object
	                mPref.savePreferences(uname);
					
	                // 1.2.3 Creating a RegisteredUser object
	                regUser = new RegisteredUser(uname, pwd, mPref);
	                regUser->update_preferences(&mPref);
	                regUser->showPreferences();
					
	                // 1.2.4 Recommendation System
	                cout << "-----------------------------------------------------------------------------------" << endl << endl << endl;
	                recommender.filter_preferences(mPref);
	                recommender.generate_recommendations();
	                cout << endl;
	                cout << "-----------------------------------------------------------------------------------" << endl << endl << endl;
	                
	                // 1.2.5 Feedback
					regUser->displayFeedback();
					cin >> feedback;
					regUser->giveFeedback(feedback);
					cout << endl << endl;
					regUser->showFeedback(feedback);
					regUser->displayExit();
					
					system("pause");
					return 0;
	            }
	            // 1.3 Sign Up Failed
	            else {
	                cout << " Sign Up Failed!" << endl;
	                cout << "----------------------------------" << endl << endl << endl;
	            }
	        } while (usernameExists(uname));
        }

        // 2.0 Login 
        else if (choice == 2) {
            RecommendationSystem recommender2;
            MoviePreferences pref;
            string uname, pwd;
            int input;

            // 2.1 User login
            do {
	            cout << " USER LOGIN " << endl;
	            cout << "----------------------------------" << endl;
	            cout << "  Enter username: ";
	            getline(cin, uname);
	            cout << "  Enter password: ";
	            getline(cin, pwd);
	
	            // 2.2 User Login Failed
	            if (!loginUser(uname, pwd, pref)) {
	                cout << "\n Login Failed!" << endl;
	                cout << "----------------------------------" << endl << endl << endl;	
	            }
	            // 2.3 User Login Successful
	            else {
	                cout << "\n Login Successful!" << endl;
	                cout << "----------------------------------" << endl << endl << endl;
	                cout << " Welcome to our Movie Recommendation System, " << uname << "! (^o^)/ " << endl << endl;
	                regUser = new RegisteredUser(uname, pwd, pref);
	                regUser->update_preferences(&pref);
	
	                do {
	                	cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * * " << endl;
	                    cout << " *  1 - Need Something Fresh? ---> Movie MatchMaker  * " << endl;
	                    cout << " *  2 - Stick with the familiar.                     * " << endl;
	                    cout << " *  3 - Exit                                         * " << endl;
	                    cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * * " << endl;
	                    cout << " Choose 1, 2 or 3: ";
	                    cin >> input;
	                    cin.ignore();
	                    cout << endl << endl << endl;
	
	                    // 2.3.1 Random Recommendation System : Movie Matchmaker
	                    if (input == 1) {
	                        cout << "-----------------------------------------------------------------------------------" << endl << endl << endl;
	                        recommender2.randomMovie();
	                        cout << "-----------------------------------------------------------------------------------" << endl << endl << endl;
	                    }
	                    // 2.3.2 Recommendation System
	                    else if (input == 2) {
	                        pref.loadPreferences(uname);
	                        pref.get_preferences();
	                        cout << "-----------------------------------------------------------------------------------" << endl << endl << endl;
	                        recommender2.filter_preferences(pref);
	                        recommender2.generate_recommendations();
	                        cout << endl;
	                        cout << "-----------------------------------------------------------------------------------" << endl << endl << endl;
	                    }
	                    // 2.3.3 Exit
	                    else if (input == 3) {
	                    	// Feedback
				        	regUser->displayFeedback();
				            cin >> feedback;
				            regUser->giveFeedback(feedback);
				            cout << endl << endl;
							regUser->showFeedback(feedback);
							regUser->displayExit();
							
				            system("pause");
				        	return 0;
	                    }
	                    // 2.3.4 Invalid Input
	                    else {
	                        cout << " *** INVALID. Please choose between 1, 2 or 3 ***" << endl << endl << endl;
	                    }
	                } while (input != 3);
	            }
	    	} while (!loginUser(uname, pwd, pref));
        }
        // 3.0 Exit Program
        else if (choice == 3) {
        	regUser->displayFeedback();
            cin >> feedback;
            cout << endl << endl;
			regUser->showFeedback(feedback);
			regUser->displayExit();
			
            system("pause");
        	return 0;
        }
        // Prompt for Invalid Input
        else {
            cout << " *** INVALID. Please choose between 1, 2 or 3 ***" << endl << endl << endl;
        }
    } while (choice < 1 || choice > 3);
    
    system("pause");
    return 0;
}