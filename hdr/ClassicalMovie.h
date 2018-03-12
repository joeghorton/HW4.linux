//
// Created by emma on 3/1/18.
//

#ifndef ASSIGNMENT4_CLASSICALMOVIE_H
#define ASSIGNMENT4_CLASSICALMOVIE_H

#include "Movie.h"
#include <vector>
using namespace std;

class ClassicalMovie: public Movie {

protected:
    int month; //month released

    // assumed that actor has first AND last name
    // will use 2 indexes to store names.
    // ex: Katherine Hepburn and Cary Grant both in movie.
    // vector<string> actorNames;
    string actorFirst;
    string actorLast;

public:

    //constructor
    ClassicalMovie(string title, string director, int year, int month, string actorFirst,
                   string actorLast) : Movie(title, 'C', director, year) {
        // this->actorNames.push_back(actorFirst);
        // this->actorNames.push_back(actorLast);
        this->actorFirst = actorFirst;
        this->actorLast = actorLast;
        this->month = month;
    };

    //destructor
    ~ClassicalMovie();

    //void print();

    // return month created
    int getMonth();

    // comparison methods
    bool operator ==(const Movie& other) const;
    bool operator <(const Movie& other) const;
    bool operator >(const Movie& other) const;

    bool operator ==(const ClassicalMovie& other) const;
    bool operator <(const ClassicalMovie& other) const;
    bool operator >(const ClassicalMovie& other) const;

};

#endif //ASSIGNMENT4_CLASSICALMOVIE_H
