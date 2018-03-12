//
// Created by emma on 3/1/18.
//

#ifndef ASSIGNMENT4_COMEDYMOVIE_H
#define ASSIGNMENT4_COMEDYMOVIE_H
#include "Movie.h"


// This class is used for all Comedy Movies.
// It contains exactly the same information provided in the
// Movie class, but it has its own comparison method.

class ComedyMovie : public Movie {

public:

    //constructor
    ComedyMovie(string title, string director, int year) : Movie(title, 'F', director, year) {};

    //destructor
    //~ComedyMovie();

    //void print();

    // comparison method specific to this class
    bool operator ==(const Movie& other) const;
    bool operator <(const Movie& other) const;
    bool operator >(const Movie& other) const;

    bool operator ==(const ComedyMovie& other) const;
    bool operator <(const ComedyMovie& other) const;
    bool operator >(const ComedyMovie& other) const;

};

#endif //ASSIGNMENT4_COMEDYMOVIE_H
