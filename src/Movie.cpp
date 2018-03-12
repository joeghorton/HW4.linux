//
// Created by Joe on 3/11/18.
//

#include "../hdr/Movie.h"

Movie::~Movie() = default;

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
    return (this->year == const_cast<Movie&>(other).year &&
            this->director == const_cast<Movie&>(other).director &&
            this->title == const_cast<Movie&>(other).title);
}

bool Movie::operator <(const Movie& other) const {
    return this->title < other.title || this->year < other.year;
}

bool Movie::operator >(const Movie& other) const {
    return this->title > other.title || this->year > other.year;
}

bool Movie::operator ==(const Item& other) const {
    return *this == (Movie&) const_cast<Item&>(other);

}

bool Movie::operator <(const Item& other) const {
    return *this < (Movie&) const_cast<Item&>(other);
}

bool Movie::operator >(const Item& other) const {
    return *this > (Movie&) const_cast<Item&>(other);

}