#ifndef RMOVIE_H
#define RMOVIE_H

#include <vector>
#include <iostream>
#include "Movie.hpp"
//#include "user.hpp"

using namespace std;

class RMovie : public Movie {
public:
    // Constructor with default values for all parameters
    RMovie(string _name = "", int _y = 0, int rNum = 0, double rate = 0, string _genre = "")
        : Movie(_name, _y, rNum, rate, "R", _genre) {
        Rcnt++;
    }

    // Getter for the static member variable
    int getCnt() const {
        return Rcnt;
    }

    bool displayClassification(int age) override {
        if(age<17){
        cout<<"Warning!!\nYou are under age 17,movies specifically designed to be viewed by adults and therefore may be unsuitable for children under 17\nExit.."<<endl;
        return 0;}
        else
        cout<<"R rated movie:"<<endl;
        return 1;
    }

private:
    // Static member variable declaration
    static int Rcnt;
};

// Static member variable definition
int RMovie::Rcnt = 0;

#endif
