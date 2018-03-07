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
    DramaMovie(string title, string director, int year) : Movie(title, director, year) {};

    // destructor
    ~DramaMovie();

    // comparison method specific to this type of movie
    bool operator <(const DramaMovie& other) const;
    bool operator >(const DramaMovie& other) const;
};

DramaMovie::~DramaMovie() {

}

bool DramaMovie::operator <(const DramaMovie& other) const {
    if (this->director == other.director) { // secondary sort precedence
        return this->title < other.title;
    } else { // primary sort precedence
        return this->director < other.director;
    }
}

bool DramaMovie::operator >(const DramaMovie& other) const {
    if (this->director == other.director) { // secondary sort precedence
        return this->title > other.title;
    } else { // primary sort precedence
        return this->director > other.director;
    }
}


#endif //ASSIGNMENT4_DRAMAMOVIE_H
