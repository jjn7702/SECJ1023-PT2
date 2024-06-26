#ifndef GMOVIE_H
#define GMOVIE_H

#include <vector>
#include <iostream>
#include "Movie.hpp"

using namespace std;

class GMovie : public Movie {
public:
    // Constructor with default values for all parameters
    GMovie(string _name = "", int _y = 0, int rNum = 0, double rate = 0, string _genre = "")
        : Movie(_name, _y, rNum, rate, "G", _genre) {
        Gcnt++;
    }

    // Getter for the static member variable
    int getCnt() const {
        return Gcnt;
    }

    bool displayClassification(int age) override {
        cout << "General audience movie: \n";
        return 1;
        }

    ~GMovie(){}

private:
    // Static member variable declaration
    static int Gcnt;
};

// Static member variable definition
int GMovie::Gcnt = 0;

#endif
