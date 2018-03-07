
#ifndef ASSIGNMENT4_ITEM_H
#define ASSIGNMENT4_ITEM_H

#include <iostream>
#include <string>
using namespace std;

// Item class is used to as a general base to each item that is
// stored in the inventory. Each item is required to contain a
// number of copies available and a title. These are minimal
// identifiers used for each item.

// We have not included an items media type or its category
// since it is already sorted according to this information.
// This data can be easily added later on if needed.

class Item {

protected:

    //int stock; //number of available copies
    string title; //items must have some sort of title


public:

    //constructor
    Item();

    Item(string title);

    //destructor
    ~Item();

    virtual void print();

    //returns title
    string getTitle();


    // Items must be compared to one another since they need to be
    // sorted. All items will have a specific way to be sorted. Should
    // implement sort in children class.
    virtual bool operator ==(const Item& other) const;
    virtual bool operator <(const Item& other) const;
    virtual bool operator >(const Item& other) const;

};

Item::Item() {

}

Item::Item(string title) {
    this->title = title;
}

Item::~Item() {

}


void Item::print() {
    cout << this->title;
}


string Item::getTitle() {
    return this->title;
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

#endif //ASSIGNMENT4_ITEM_H
