#ifndef MOVIE_H
#define MOVIE_H
#include<vector>
#include<iostream>
#include<fstream>
//#include "user.hpp"
using namespace std;

class User;

class Movie{
    string name;
    int year;
    double rating;
    string classification;
    int ratingNum;
    string genre;

    public:
    Movie(string _name = "", int _y = 0, int rNum = 0, double rate = 0, string _classification = "", string _genre = "") {
        name = _name;
        genre = _genre;
        year = _y;
        rating = rate;
        ratingNum = rNum;
        classification = _classification;
    }

    
    void setName(const string& movieName) {
        name = movieName;
    }

    void setYear(int movieYear) {
        year = movieYear;
    }

    void setRating(double movieRating) {
        rating = movieRating;
    }

    void setClassification(const string& movieClassification) {
        classification = movieClassification;
    }

    void setRatingNum(int movieRatingNum) {
        ratingNum = movieRatingNum;
    }

    void setGenre(const string& movieGenre) {
        genre = movieGenre;
    }
    void renewRating(double r){
        rating=((rating*ratingNum)+r)/++ratingNum;
    }

    //accessor
    string getName(){
        return name;
    }
    string getGenre(){
        return genre;
    }
    double getRating(){
        return rating;
    }
    int getYear(){
        return year;
    }
    string getClassification(){
        return classification;
    }
    int getRatingNum(){
        return ratingNum;
    }


    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Year: "<<year<<"\trating: "<<rating<<"\tClassification: "<<classification<<"\t Genre: "<<genre<<endl<<endl;
        
    }

    virtual bool displayClassification(int age) {
        cout<<classification<<":"<<endl;
        return 1;
    }

    friend class User;
};

#endif
