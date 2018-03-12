//
// Created by Joe on 3/11/18.
//

#include "../hdr/ClassicalMovie.h"

ClassicalMovie::~ClassicalMovie() = default;

/*
void ClassicalMovie::print() {
    cout << this->month << " " << this->year << ", " << this->actorFirst << " " << this->actorLast;
}
*/
int ClassicalMovie::getMonth() {
    return this->month;
}

bool ClassicalMovie::operator ==(const ClassicalMovie& other) const {
    return (this->actorFirst == other.actorFirst && this->actorLast == other.actorLast &&
            this->year == other.year && this->month == other.month);
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

bool ClassicalMovie::operator ==(const Movie& other) const {
    return *this == (ClassicalMovie&) other;
}

bool ClassicalMovie::operator <(const Movie& other) const {
    return *this < (ClassicalMovie&) other;
}

bool ClassicalMovie::operator >(const Movie& other) const {
    return *this > (ClassicalMovie&) other;
}