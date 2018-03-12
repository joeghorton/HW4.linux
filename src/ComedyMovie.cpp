//
// Created by Joe on 3/11/18.
//

#include "../hdr/ComedyMovie.h"

/*
ComedyMovie::~ComedyMovie() {

}
 */
/*
void ComedyMovie::print() {
    cout << this->title << ", " << this->year;
}
*/

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