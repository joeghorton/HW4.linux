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
    //vector<string> actorNames;
    string actorFirst;
    string actorLast;

public:

    //constructor
    ClassicalMovie(string title, string director, int year, int month, string actorFirst,
                   string actorLast) : Movie(title, director, year) {
        //this->actorNames.push_back(actorFirst);
        //this->actorNames.push_back(actorLast);
        this->actorFirst = actorFirst;
        this->actorLast = actorLast;
        this->month = month;
    };

    //destructor
    ~ClassicalMovie();

    // return month created
    int getMonth();

    // used if the same movie is read in from file multiple times
    // adds copies to sum

    // comparison methods
    bool operator <(const ClassicalMovie& other) const;
    bool operator >(const ClassicalMovie& other) const;

};

ClassicalMovie::~ClassicalMovie() {

}

int ClassicalMovie::getMonth() {
    return this->month;
}

bool ClassicalMovie::operator <(const ClassicalMovie& other) const {
    if (this->year == other.year) {
        if (this->month == other.month) {
            if (this->actorFirst == other.actorFirst) {
                return this->actorLast < other.actorLast;
            } else {
                return this->actorFirst < other.actorFirst;
            }
        } else { // secondary sort
            return this->month < other.month;
        }
    } else { // primary sort
        return this->year < other.year;
    }
}

bool ClassicalMovie::operator >(const ClassicalMovie& other) const {
    if (this->year == other.year) {
        if (this->month == other.month) {
            if (this->actorFirst == other.actorFirst) {
                return this->actorLast > other.actorLast;
            } else {
                return this->actorFirst > other.actorFirst;
            }
        } else { // secondary sort
            return this->month > other.month;
        }
    } else { // primary sort
        return this->year > other.year;
    }
}

#endif //ASSIGNMENT4_CLASSICALMOVIE_H
