//
// Created by emma on 3/1/18.
//

#ifndef ASSIGNMENT4_MOVIE_H
#define ASSIGNMENT4_MOVIE_H
#include <string>
#include "Item.h"

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
    Movie(string title, char category, string director, int year) : Item(title, 'D', category) {
        this->director = director;
        this->year = year;
    };

    //destructor
    virtual ~Movie();

    // returns name of director
    string getDirector();

    // returns year the movie was released
    int getReleaseYear();

    virtual void print();

    // default compare to for movie;
    // compare title then release year for generic movie.
    // Override when desired.
    virtual bool operator ==(const Item& other) const;
    virtual bool operator <(const Item& other) const;
    virtual bool operator >(const Item& other) const;

    virtual bool operator ==(const Movie& other) const;
    virtual bool operator <(const Movie& other) const;
    virtual bool operator >(const Movie& other) const;



};

#endif //ASSIGNMENT4_MOVIE_H
