#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <fstream> // Include the algorithm header for std::find

using namespace std;

// Fouad's class 1
class Person {
protected:
    string name;
    string gender;

public:
    Person(const string& name, const string& gender) : name(name), gender(gender) {}

    string getName() const {
        return name;
    }

    string getGender() const {
        return gender;
    }
};

// Moqbel's class 1
class User : public Person {
private:
    int userID;
    string email;
    string password;
    vector<string> genres;
    vector<string> actors;
    vector<string> directors;
    vector<pair<int, int> > ratings; // Pair of movieID and rating

public:
    User(const string& name, const string& gender, const string& email,
         const string& password, int userID) :
        Person(name, gender), email(email), password(password), userID(userID) {}

    int getUserID() const {
        return userID;
    }

    string getEmail() const {
        return email;
    }

    string getPassword() const {
        return password;
    }

    void setGenres(const vector<string>& genres) {
        this->genres = genres;
    }

    void setActors(const vector<string>& actors) {
        this->actors = actors;
    }

    void setDirectors(const vector<string>& directors) {
        this->directors = directors;
    }

    void rateMovie(int movieID, int rating) {
        for (size_t i = 0; i < ratings.size(); ++i) {
            if (ratings[i].first == movieID) {
                ratings[i].second = rating;
                return;
            }
        }
        ratings.push_back(make_pair(movieID, rating));
    }

    int getRating(int movieID) const {
        for (size_t i = 0; i < ratings.size(); ++i) {
            if (ratings[i].first == movieID) {
                return ratings[i].second;
            }
        }
        return -1; // Movie not rated
    }

    const vector<string>& getGenres() const {
        return genres;
    }

    const vector<string>& getActors() const {
        return actors;
    }

    const vector<string>& getDirectors() const {
        return directors;
    }

    // Other methods for user registration, login, updating preferences, etc.
};

// Moqbel's class 2
class Movie {
private:
    int movieID;
    string title;
    vector<string> genres;
    string director;
    vector<string> cast;
    string releaseDate;
    vector<pair<int, int> > ratings; // Pair of userID and rating

public:
    Movie(int movieID, const string& title, const vector<string>& genres,
          const string& director, const vector<string>& cast,
          const string& releaseDate) :
        movieID(movieID), title(title), genres(genres), director(director), cast(cast),
        releaseDate(releaseDate) {}

    int getMovieID() const {
        return movieID;
    }

    string getTitle() const {
        return title;
    }

    const vector<string>& getGenres() const {
        return genres;
    }

    string getDirector() const {
        return director;
    }

    const vector<string>& getCast() const {
        return cast;
    }

    string getReleaseDate() const {
        return releaseDate;
    }

    void addRating(int userID, int rating) {
        for (size_t i = 0; i < ratings.size(); ++i) {
            if (ratings[i].first == userID) {
                ratings[i].second = rating;
                return;
            }
        }
        ratings.push_back(make_pair(userID, rating));
    }

    double getAverageRating() const {
        if (ratings.empty()) {
            return 0.0;
        }
        double totalRating = 0.0;
        for (size_t i = 0; i < ratings.size(); ++i) {
            totalRating += ratings[i].second;
        }
        return totalRating / ratings.size();
    }

    // Other methods for getting movie details, etc.
};

// Fouad's class2
class Genre {
private:
    int genreID;
    string type;
    vector<Movie*> movies;

public:
    Genre(int genreID, const string& type) : genreID(genreID), type(type) {}

    int getGenreID() const {
        return genreID;
    }

    string getType() const {
        return type;
    }

    void addMovie(Movie* movie) {
        movies.push_back(movie);
    }

    const vector<Movie*>& getMovies() const {
        return movies;
    }
};

// Ali's class 1
class Director : public Person {
private:
    int directorID;
    vector<Movie*> movies;

public:
    Director(const string& name, const string& gender, int directorID) :
        Person(name, gender), directorID(directorID) {}

    int getDirectorID() const {
        return directorID;
    }

    void addMovie(Movie* movie) {
        movies.push_back(movie);
    }

    const vector<Movie*>& getMovies() const {
        return movies;
    }
};

// Kinan's class 1
class Actor : public Person {
private:
    int actorID;
    vector<Movie*> movies;

public:
    Actor(const string& name, const string& gender, int actorID) :
        Person(name, gender), actorID(actorID) {}

    int getActorID() const {
        return actorID;
    }

    void addMovie(Movie* movie) {
        movies.push_back(movie);
    }

    const vector<Movie*>& getMovies() const {
        return movies;
    }
};

// Kinan's class 2
class RecommendationSystem {
private:
    vector<User*> users;
    vector<Movie*> movies;
    vector<Genre*> genres;
    vector<Director*> directors;
    vector<Actor*> actors;
    string recommendationAlgorithm = "Content-Based Filtering";

public:
    void addUser(User* user) {
        users.push_back(user);
    }

    void addMovie(Movie* movie) {
        movies.push_back(movie);
        for (size_t i = 0; i < movie->getGenres().size(); ++i) {
            string genre = movie->getGenres()[i];
            // Assuming you have a way to get genreID from genre name
            int genreID = 1; // Replace with actual logic
            bool genreFound = false;
            for (size_t j = 0; j < genres.size(); ++j) {
                if (genres[j]->getGenreID() == genreID) {
                    genres[j]->addMovie(movie);
                    genreFound = true;
                    break;
                }
            }
            if (!genreFound) {
                Genre* newGenre = new Genre(genreID, genre);
                newGenre->addMovie(movie);
                genres.push_back(newGenre);
            }
        }

        for (size_t i = 0; i < directors.size(); ++i) {
            if (directors[i]->getName() == movie->getDirector()) {
                directors[i]->addMovie(movie);
                break;
            }
        }

        for (size_t i = 0; i < movie->getCast().size(); ++i) {
            string actorName = movie->getCast()[i];
            for (size_t j = 0; j < actors.size(); ++j) {
                if (actors[j]->getName() == actorName) {
                    actors[j]->addMovie(movie);
                    break;
                }
            }
        }
    }

    vector<Movie*> generateRecommendations(int userID) {
        vector<Movie*> recommendations;
        for (size_t i = 0; i < users.size(); ++i) {
            if (users[i]->getUserID() == userID) {
                User* user = users[i];
                vector<string> userGenres = user->getGenres();
                vector<string> userActors = user->getActors();
                vector<string> userDirectors = user->getDirectors();

                // Content-Based Filtering logic
                for (size_t j = 0; j < movies.size(); ++j) {
                    Movie* movie = movies[j];
                    bool matchesGenre = false;
                    for (size_t k = 0; k < movie->getGenres().size(); ++k) {
                        if (std::find(userGenres.begin(), userGenres.end(), movie->getGenres()[k]) != userGenres.end()) {
                            matchesGenre = true;
                            break;
                        }
                    }

                    bool matchesActor = false;
                    for (size_t k = 0; k < movie->getCast().size(); ++k) {
                        if (std::find(userActors.begin(), userActors.end(), movie->getCast()[k]) != userActors.end()) {
                            matchesActor = true;
                            break;
                        }
                    }

                    bool matchesDirector = std::find(userDirectors.begin(), userDirectors.end(), movie->getDirector()) != userDirectors.end();

                    if (matchesGenre || matchesActor || matchesDirector) {
                        recommendations.push_back(movie);
                    }
                }
                break;
            }
        }
        return recommendations;
    }

    void updateAlgorithm(const string& algorithm) {
        recommendationAlgorithm = algorithm;
    }

    // Other methods for managing users, movies.
};

//Ali's work
int main() {
    RecommendationSystem recSys;

    // Sample data entry
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
    cin.ignore();  // Ignore newline character left in buffer

    User* user1 = new User(userName, userGender, userEmail, userPassword, userID);

    // Setting user preferences
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

    // Write user inputs to a file
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

    // Rest of the code in final submision...

    return 0;
}