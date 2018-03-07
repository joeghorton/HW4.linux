//
// Created by emma on 3/1/18.
//

#ifndef ASSIGNMENT4_MOVIE_H
#define ASSIGNMENT4_MOVIE_H
#include "Item.h"
#include <string>

// The movie class is used to store a general movie description.
// The class extends Item, because it is an item stored within the
// Movie store's inventory.
// This movie class contains the year, director, title, and number
// of copies it has in the inventory.
// This movies class contains a compareTo method to compare this movie
// with other movies. It is a generic comparison method, first comparing
// the titles, then release years. However, this should be overridden in
// more specific move classes if a different comparison is desired.

class Movie : public Item {

protected:
    int year; //year movie was released
    string director; //director name

public:

    // constructor
    Movie();

    // constructor
    Movie(string title, string director, int year) : Item(title) {
        this->director = director;
        this->year = year;
    };

    //destructor
    ~Movie();

    // returns name of director
    string getDirector();

    // returns year the movie was released
    int getReleaseYear();

    void print();

    // default compare to for movie;
    // compare title then release year for generic movie.
    // Override when desired.
    virtual bool operator ==(const Movie& other) const;
    virtual bool operator <(const Movie& other) const;
    virtual bool operator >(const Movie& other) const;

};

Movie::Movie() {

}

Movie::~Movie() {

}

string Movie::getDirector() {
    return this->director;
}

int Movie::getReleaseYear() {
    return this->year;
}

void Movie::print() {
    cout << this->title << " " << "(" << this->year << ")";
}

bool Movie::operator ==(const Movie& other) const {
    return (this->year == other.year &&
            this->director == other.director &&
            this->title == other.title);
}

bool Movie::operator <(const Movie& other) const {
    if (this->title < other.title) {
        return true;
    } else {
        return this->year < other.year;
    }
}

bool Movie::operator >(const Movie& other) const {
    if (this->title > other.title) {
        return true;
    } else {
        return this->year > other.year;
    }
}


#endif //ASSIGNMENT4_MOVIE_H
