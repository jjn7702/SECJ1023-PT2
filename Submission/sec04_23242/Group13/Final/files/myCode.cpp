//KNAN FADI DAWARH: A23CS4013
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

// Recommendation system with content-based filtering
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

    // Other methods for managing users, movies, etc.
};

