
#ifndef ASSIGNMENT4_MEDIATYPE_H
#define ASSIGNMENT4_MEDIATYPE_H

#include "Category.h"
#include <vector>
using namespace std;

// Media Type is used to categorize the different types of media
// stored in the inventory. The identifier is used to check each
// item to see if they are a correct media type. Essentially, this
// is used to idenfity its position in the inventory list and act as
// a filter for invalid identifiers.

class MediaType {

private:
    char id; //used to categorize the media type
    vector<Category*>* categories; //stores all categories of particular type

    Category* getCategory(char catID);

    friend class RentalStore;

public:

    //empty constructor
    MediaType(); // Maybe we don't need this?

    MediaType(char mediaID);

    // destructor for memory delete
    ~MediaType();

    //print media type
    void print();

    // returns media type identifier
    char getIdentifier();

    bool addCategory(char catID);

    bool isValidCategory(char catID);

    bool addItem(Item* item, int stock);

    bool rentItem(Item*& item);

    bool returnItem(Item*& item);

};

MediaType::MediaType() {

}

MediaType::MediaType(char mediaID) {
    this->id = mediaID;
    this->categories = new vector<Category*>();
}

MediaType::~MediaType() {
    for (int i = 0; i < this->categories->size(); i++) {
        delete this->categories->at(i);
    }
    delete this->categories;
}

void MediaType::print() {
    for (int i = 0; i < this->categories->size(); i++) {
        this->categories->at(i)->print();
    }
}

char MediaType::getIdentifier() {
    return this->id;
}


bool MediaType::addCategory(char catID) {
    Category* categ = getCategory(catID);
    if (categ != NULL) {
        return false;
    } else {
        this->categories->push_back(new Category(catID));
        return true;
    }
}

bool MediaType::isValidCategory(char catID) {
    Category* categ = getCategory(catID);
    return categ != NULL;
}


bool MediaType::addItem(Item* item, int stock) {
    Category* categ = getCategory(item->categoryID());
    if (categ == NULL) {
        return false;
    } else {
        categ->insertItem(item, stock);
        return true;
    }

}

bool MediaType::rentItem(Item*& item) {
    Category* categ = getCategory(item->categoryID());
    if (categ == NULL) {
        return false;
    } else {
        return categ->rentItem(item);
    }
}

bool MediaType::returnItem(Item*& item) {
    Category* categ = getCategory(item->categoryID());
    if (categ == NULL) {
        return false;
    } else {
        return categ->returnItem(item);
    }
}

Category* MediaType::getCategory(char catID) {
    for (int i = 0; i < this->categories->size(); i++) {
        if (this->categories->at(i)->getIdentifier() == catID) {
            return this->categories->at(i);
        }
    }
    return NULL;
}

#endif //ASSIGNMENT4_MEDIATYPE_H
