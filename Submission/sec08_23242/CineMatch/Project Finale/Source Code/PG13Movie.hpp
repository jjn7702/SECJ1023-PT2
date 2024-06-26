#ifndef PG13MOVIE_H
#define PG13MOVIE_H

#include <vector>
#include <iostream>
#include "Movie.hpp"
//#include "user.hpp"

using namespace std;

class PG13Movie : public Movie {
public:
    // Constructor with default values for all parameters
    PG13Movie(string _name = "", int _y = 0, int rNum = 0, double rate = 0, string _genre = "")
        : Movie(_name, _y, rNum, rate, "PG-13", _genre) {
        pg13cnt++;
    }

    // Getter for the static member variable
    int getCnt() const {
        return pg13cnt;
    }

    bool displayClassification(int age) override {
        if(age<13)
        {cout<<"Warning!!\nYou are under age 13,movie contain violence, nudity, sensuality, language, adult activities or other elements beyond a PG rating\nExit.."<<endl;
        return 0;}
        else
        cout<<"parental guidance suggested movie:"<<endl;
        return 1;
    }

private:
    // Static member variable declaration
    static int pg13cnt;
};

// Static member variable definition
int PG13Movie::pg13cnt = 0;

#endif
