//
// Created by emma on 3/1/18.
//

#ifndef ASSIGNMENT4_DRAMAMOVIE_H
#define ASSIGNMENT4_DRAMAMOVIE_H

#include "Movie.h"

// This class is used for all Drama Movies.
// It contains exactly the same information provided in the
// Movie class, but it has its own comparison method.

class DramaMovie : public Movie {

public:

    // constructor
    DramaMovie(string title, string director, int year) : Movie(title, 'D', director, year) {};

    // destructor
    ~DramaMovie();

    //void print();

    // comparison methods specific to this type of movie
    bool operator ==(const Movie& other) const;
    bool operator <(const Movie& other) const;
    bool operator >(const Movie& other) const;

    bool operator ==(const DramaMovie& other) const;
    bool operator <(const DramaMovie& other) const;
    bool operator >(const DramaMovie& other) const;

};

#endif //ASSIGNMENT4_DRAMAMOVIE_H