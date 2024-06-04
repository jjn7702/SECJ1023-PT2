// Fouad's Class 1
class Person {
protected :
    string name;
    string gender;
};




// Fouad's class 2
class Genre{
private:
    int genreID;
    string type;
    vector<Movie> movies;

public:
    Genre(int id, string type) : genreID(id), type(type) {}

    void addMovieToGenre(Movie &movie) {
        movies.push_back(movie);
    }
    vector<Movie> getMoviesByGenre() {
      return movies;
    }
};
