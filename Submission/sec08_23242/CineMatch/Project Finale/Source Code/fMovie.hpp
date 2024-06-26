#ifndef FMOVIE_H
#define FMOVIE_H

#include <vector>
#include <iostream>
#include <fstream>
#include "Movie.hpp"

using namespace std;

class fMovie {
    vector<Movie> movies;
    //string favouritegenre;
    int moviescnt=0;

public:
    //fMovie():movies(0){};
    
    bool setMovies(Movie& movie) {

    for(int i = 0; i < moviescnt; i++) {
        if(movies[i].getName() == movie.getName()) {
            cout << "Movie already exists!\n";
            return 1;
        }
    }
    movies.push_back(movie);
    //favouritegenre = movie.getGenre();
    moviescnt++;
    return 0;
}

int getMoviesCnt(){
    return moviescnt;
}

void txtfavouriteMovies(const string& name){
        ofstream fout("users_recommended_movies.txt");
        if (!fout.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }
        for (int i = 0; i < moviescnt; i++) {
            fout << movies[i].getName() << endl;
            fout << movies[i].getYear() << " " << movies[i].getRatingNum() << " " << movies[i].getRating() << " " << movies[i].getClassification() << " " << movies[i].getGenre() << endl;
        }
        cout<<"Added successfully!"<<endl;
        fout.close();
}

void moviedisplay(){
    for(int i=0;i<moviescnt;i++){
    cout<<i+1<<".";
    movies[i].display();}
}

void deletefavouritemovielist(int num,string name){
    movies.erase(movies.begin() + num-1); 
       cout<<"Delete successfully!"<<endl;
        moviescnt--;
       ofstream fout("users_recommended_movies.txt");
        for(int i=0;i<moviescnt;i++){
            fout << movies[i].getName() << endl;
            fout << movies[i].getYear() << " " << movies[i].getRatingNum() << " " << movies[i].getRating() << " " << movies[i].getClassification() << " " << movies[i].getGenre() << endl;
    }
    fout.close();
}

~fMovie(){}

};

#endif
