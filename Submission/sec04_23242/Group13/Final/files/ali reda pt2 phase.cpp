class Director : public Person
{
	private:
		int directorID;
		vector<Movie*>movies;
	
	public:
		Director(const string& name , const string & gender, int directorID):
			Person(name,gender);
		directorID(directorID){}
		int getDirectorID()const {return directoeID;}
		void addMovie(Movie*movie)
		{
		movies.push_back(movie);
		}
		const vector <Movie*>&getMovies()const
		{return movies;}
		
	
};


int main() {
    RecommendationSystem recSys;

    
    cout << "Enter user details:" << endl;
    string userName, userGender, userEmail, userPassword;
    int userID;
    cout << "Name: ";
    getline(cin, userName);
    cout << "Gender: ";
    getline(cin, userGender);
    cout << "Email: ";
    getline(cin, userEmail);
    cout << "Password: ";
    getline(cin, userPassword);
    cout << "User ID: ";
    cin >> userID;
    cin.ignore();  

    User* user1 = new User(userName, userGender, userEmail, userPassword, userID);

    int genreCount, actorCount, directorCount;
    vector<string> userGenres, userActors, userDirectors;
    string input;

    cout << "How many favorite genres? ";
    cin >> genreCount;
    cin.ignore();
    cout << "Enter favorite genres:" << endl;
    for (int i = 0; i < genreCount; ++i) {
        cout << "Genre " << i + 1 << ": ";
        getline(cin, input);
        userGenres.push_back(input);
    }
    user1->setGenres(userGenres);

    cout << "How many favorite actors? ";
    cin >> actorCount;
    cin.ignore();
    cout << "Enter favorite actors:" << endl;
    for (int i = 0; i < actorCount; ++i) {
        cout << "Actor " << i + 1 << ": ";
        getline(cin, input);
        userActors.push_back(input);
    }
    user1->setActors(userActors);

    cout << "How many favorite directors? ";
    cin >> directorCount;
    cin.ignore();
    cout << "Enter favorite directors:" << endl;
    for (int i = 0; i < directorCount; ++i) {
        cout << "Director " << i + 1 << ": ";
        getline(cin, input);
        userDirectors.push_back(input);
    }
    user1->setDirectors(userDirectors);

    recSys.addUser(user1);

    
    ofstream outputFile("user_inputs.txt");
    if (outputFile.is_open()) {
        outputFile << "User Details:" << endl;
        outputFile << "Name: " << userName << endl;
        outputFile << "Gender: " << userGender << endl;
        outputFile << "Email: " << userEmail << endl;
        outputFile << "Password: " << userPassword << endl;
        outputFile << "User ID: " << userID << endl;

        outputFile << "User Preferences:" << endl;
        outputFile << "Favorite Genres (" << genreCount << "):" << endl;
        for (const auto& genre : userGenres) {
            outputFile << "- " << genre << endl;
        }
        outputFile << "Favorite Actors (" << actorCount << "):" << endl;
        for (const auto& actor : userActors) {
            outputFile << "- " << actor << endl;
        }
        outputFile << "Favorite Directors (" << directorCount << "):" << endl;
        for (const auto& director : userDirectors) {
            outputFile << "- " << director << endl;
        }

        outputFile.close();
    } else {
        cerr << "Unable to open output file." << endl;
    }

    

    return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
}
