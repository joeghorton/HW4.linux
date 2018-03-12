//
// Created by Joe on 3/11/18.
//

#include "../hdr/Item.h"

Item::Item(string title, char mediaType, char category) {
    this->title = title;
    this->mediaType = mediaType;
    this->category = category;
}

Item::~Item() = default;


void Item::print() {
    cout << this->title;
}


string Item::getTitle() {
    return this->title;
}

char Item::categoryID() {
    return this->category;
}

char Item::mediaID() {
    return this->mediaType;
}

bool Item::operator ==(const Item& other) const {
    return this->title == other.title;
}

bool Item::operator <(const Item& other) const {
    return this->title < other.title;
}

bool Item::operator >(const Item& other) const {
    return this->title > other.title;
}