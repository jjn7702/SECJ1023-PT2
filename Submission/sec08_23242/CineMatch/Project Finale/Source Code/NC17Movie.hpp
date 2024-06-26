#ifndef NC17MOVIE_H
#define NC17MOVIE_H

#include <vector>
#include <iostream>
#include "Movie.hpp"
//#include "user.hpp"
using namespace std;
class User;

class NC17Movie : public Movie {
public:
    // Constructor with default values for all parameters
    NC17Movie(string _name = "", int _y = 0, int rNum = 0, double rate = 0, string _genre = "")
        : Movie(_name, _y, rNum, rate, "NC-17", _genre) {
        nc17cnt++;
    }

    // Getter for the static member variable
    int getCnt() const {
        return nc17cnt;
    }

    bool displayClassification(int age) override {
        if(age<17)
        {cout<<"Warning!!\nYou are under age 17,movie is rated NC-17,inappropriate for children 17 and under\nExit.."<<endl;
        return 0;}
        else
        cout<<"Clearly adult movie:"<<endl;
        return 1;
    }

    ~NC17Movie(){}

private:
    // Static member variable declaration
    static int nc17cnt;
};

// Static member variable definition
int NC17Movie::nc17cnt = 0;

#endif
