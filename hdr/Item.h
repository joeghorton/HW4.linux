
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

    char mediaType; // media type of the item
    char category; // category of the item
    string title; //items must have some sort of title


public:

    //constructor
    Item(string title, char mediaType, char category);

    //destructor
    virtual ~Item();

    virtual void print();

    //returns title
    string getTitle();

    char categoryID();

    char mediaID();


    // Items must be compared to one another since they need to be
    // sorted. All items will have a specific way to be sorted. Should
    // implement sort in children class.
    virtual bool operator ==(const Item& other) const;
    virtual bool operator <(const Item& other) const;
    virtual bool operator >(const Item& other) const;

};

#endif //ASSIGNMENT4_ITEM_H