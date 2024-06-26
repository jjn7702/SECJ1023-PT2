#ifndef PGMOVIE_H
#define PGMOVIE_H

#include <vector>
#include <iostream>
#include "Movie.hpp"
//#include "user.hpp"
using namespace std;

class PGMovie : public Movie {
public:
    // Constructor with default values for all parameters
    PGMovie(string _name = "", int _y = 0, int rNum = 0, double rate = 0, string _genre = "")
        : Movie(_name, _y, rNum, rate, "PG", _genre) {
        pgcnt++;
    }

    // Getter for the static member variable
    int getCnt() const {
        return pgcnt;
    }

    bool displayClassification(int age) override {
        if(age<17)
        cout<<"Warning!!\nYou are under age 17,parental guidance suggested!\nparental guidance suggested movie:"<<endl;
        else
        cout<<"parental guidance suggested movie:"<<endl;

        return 1;
    }

private:
    // Static member variable declaration
    static int pgcnt;
};

// Static member variable definition
int PGMovie::pgcnt = 0;

#endif
