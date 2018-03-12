//
// Created by Joe on 3/11/18.
//

#include "../hdr/DramaMovie.h"

DramaMovie::~DramaMovie() = default;

/*
void DramaMovie::print() {
    cout << this->director << ", " << this->title;
}
 */

bool DramaMovie::operator ==(const DramaMovie& other) const {
    return (this->director == other.director && this->title == other.title);
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

bool DramaMovie::operator ==(const Movie& other) const {
    return *this == (DramaMovie&) other;
}

bool DramaMovie::operator <(const Movie& other) const {
    return *this < (DramaMovie&) other;
}

bool DramaMovie::operator >(const Movie& other) const {
    return *this > (DramaMovie&) other;
}