//
// Created by emma on 3/1/18.
//

#ifndef ASSIGNMENT4_COMEDYMOVIE_H
#define ASSIGNMENT4_COMEDYMOVIE_H



// This class is used for all Comedy Movies.
// It contains exactly the same information provided in the
// Movie class, but it has its own comparison method.

class ComedyMovie : public Movie {

public:

    //constructor
    ComedyMovie(string title, string director, int year) : Movie(title, 'F', director, year) {};

    //destructor
    //~ComedyMovie();

    void print();

    // comparison method specific to this class
    bool operator ==(const Movie& other) const;
    bool operator <(const Movie& other) const;
    bool operator >(const Movie& other) const;

    bool operator ==(const ComedyMovie& other) const;
    bool operator <(const ComedyMovie& other) const;
    bool operator >(const ComedyMovie& other) const;


};

/*
ComedyMovie::~ComedyMovie() {

}
 */

void ComedyMovie::print() {
    cout << this->title << ", " << this->year;
}


bool ComedyMovie::operator ==(const ComedyMovie& other) const {
    return (this->title == other.title && this->year == other.year);
}

bool ComedyMovie::operator <(const ComedyMovie& other) const {
    if (this->title == other.title) { // secondary sort precedence
        return this->year < other.year;
    } else { // primary sort precedence
        return this->title < other.title;
    }
}

bool ComedyMovie::operator >(const ComedyMovie& other) const {
    if (this->title == other.title) { // secondary sort precedence
        return this->year > other.year;
    } else { // primary sort precedence
        return this->title > other.title;
    }
}


bool ComedyMovie::operator ==(const Movie& other) const {
    return *this == (ComedyMovie&) const_cast<Movie&>(other);
}

bool ComedyMovie::operator <(const Movie& other) const {
    return *this < (ComedyMovie&) const_cast<Movie&>(other);
}

bool ComedyMovie::operator >(const Movie& other) const {
    return *this > (ComedyMovie&) const_cast<Movie&>(other);
}

#endif //ASSIGNMENT4_COMEDYMOVIE_H
