//
// Created by Joe on 3/11/18.
//

#include "../hdr/MediaType.h"

MediaType::MediaType(char mediaID) {
    this->id = mediaID;
    this->categories = new vector<Category*>();
}

MediaType::~MediaType() {
    for (Category* cat : *this->categories) {
        delete cat;
    }
    delete this->categories;
}

void MediaType::print() {
    for (auto& cat : *this->categories) {
        cat->print();
    }
}

char MediaType::getIdentifier() {
    return this->id;
}


bool MediaType::addCategory(char catID) {
    Category* categ = getCategory(catID);
    if (categ != nullptr) {
        return false;
    } else {
        this->categories->push_back(new Category(catID));
        return true;
    }
}

bool MediaType::isValidCategory(char catID) {
    Category* categ = getCategory(catID);
    return categ != nullptr;
}


bool MediaType::addItem(Item* item, int stock) {
    Category* categ = getCategory(item->categoryID());
    if (categ == nullptr) {
        return false;
    } else {
        categ->insertItem(item, stock);
        return true;
    }

}

bool MediaType::rentItem(Item*& item) {
    Category* categ = getCategory(item->categoryID());
    return categ != nullptr && categ->rentItem(item);
}

bool MediaType::returnItem(Item*& item) {
    Category* categ = getCategory(item->categoryID());
    return categ != nullptr && categ->returnItem(item);
}

Category* MediaType::getCategory(char catID) {
    for (auto& cat : *this->categories) {
        if (cat->getIdentifier() == catID) {
            return cat;
        }
    }
    return nullptr;
}