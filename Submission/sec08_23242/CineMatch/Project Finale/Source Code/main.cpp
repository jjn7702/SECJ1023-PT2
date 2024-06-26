#include<iostream>
#include"fMovie.hpp"
#include "Movie.hpp"
#include "GMovie.hpp"
#include "NC17Movie.hpp"
#include "PG13Movie.hpp"
#include "PGMovie.hpp"
#include "RMovie.hpp"
#include "user.hpp"
#include "function.cpp"
#include<vector>
#include<fstream>
#include<iomanip>
using namespace std;


int main() {
    vector<User> users;
    vector<Movie> movies;
    vector<GMovie> gmovies;
    vector<NC17Movie> nc17movies;
    vector<PG13Movie> pg13movies;
    vector<PGMovie> pgmovies;
    vector<RMovie> rmovies;
    fMovie fmovies;
    ifstream fin("users.txt");
    int userCount = 0;

try {
        if (!fin.is_open()) {
            throw runtime_error("Failed to open the users file.");
        }

    while (!fin.eof()) {
        string name;
        string pass;
        int age;
        getline(fin, name);
        if (name.empty()) break; // Skip empty lines
        fin >> pass >> age;
        fin.ignore(); // Ignore the newline character after age
        User newUser;
        newUser.setUsername(name);
        newUser.setPassword(pass);
        newUser.setAge(age);
        users.push_back(newUser);

        userCount++;
    }
    fin.close();
    }
    
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
        if (fin.is_open()) {
            fin.close();
        }
        system("pause");
        return 1; // Return with an error code
    }
    
    int movieCount = 0;
    ifstream moviefin("movie.txt");
try {
    if (!moviefin.is_open()) {
        throw runtime_error("Failed to open the movies file.");
    }
    while (!moviefin.eof()) {
        string name;
        int year;
        double rating;
        string classification;
        int ratingNum;
        string genre;
        getline(moviefin, name);
        if (name.empty()) break; // Skip empty lines
        moviefin >> year >> ratingNum >> rating >> classification >> genre;
        moviefin.ignore(); // Ignore the newline character after genre
        Movie newMovie;
        newMovie.setName(name);
        newMovie.setYear(year);
        newMovie.setRating(rating);
        newMovie.setClassification(classification);
        newMovie.setRatingNum(ratingNum);
        newMovie.setGenre(genre);
        movies.push_back(newMovie);
        movieCount++;

        if (classification == "G") {
            GMovie newMovie(name, year, ratingNum, rating, genre);
            gmovies.push_back(newMovie);
        } else if (classification == "PG-13") {
            PG13Movie newMovie(name, year, ratingNum, rating, genre);
            pg13movies.push_back(newMovie);
        } else if (classification == "R") {
            RMovie newMovie(name, year, ratingNum, rating, genre);
            rmovies.push_back(newMovie);
        } else if (classification == "PG") {
            PGMovie newMovie(name, year, ratingNum, rating, genre);
            pgmovies.push_back(newMovie);
        } else if (classification == "NC-17") {
            NC17Movie newMovie(name, year, ratingNum, rating, genre);
            nc17movies.push_back(newMovie);
        }
    }
    } catch (const exception& e) {
    cout << "Exception: " << e.what() << endl;
    if (moviefin.is_open()) {
        moviefin.close();
    }
    system("pause");
    return 1; // Return with an error code
    }
    moviefin.close();
    
    int userIndex = userinput(users, userCount);
    //cout<<"user index:"<<userIndex<<endl;
    
    if(userIndex!=-1){
    users[userIndex].readWatchlist();
    users[userIndex].PointfMovies(&fmovies);
    users[userIndex].readfavouritelist();
    //cout<<userIndex;
    userchoice(users,movies,movieCount,userIndex,gmovies,nc17movies,pg13movies,pgmovies,rmovies);
    cout<<"Thank you for having us!\n";
    }
    system("pause");
    return 0;
}