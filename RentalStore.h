
#ifndef ASSIGNMENT4_INVENTORY_H
#define ASSIGNMENT4_INVENTORY_H
#include "Customer.h"
#include "MediaType.h"
#include <vector>
#include <iostream>
using namespace std;



class RentalStore {

    static const int MAX_CUST = 10000; //customers have a 4 digit ID

private:

    //stores all customer info
    Customer* customerList[MAX_CUST];

    // stores first level of inventory categorization
    vector<MediaType*>* mediaTypes;

    bool rentalHelper(Item* item, int custID, bool borrowing);

    MediaType* getMediaType(char medID);

public:
    RentalStore(); //empty constructor
    virtual ~RentalStore();


    void print();

    bool addMediaType(char medID); //used to add media type so then data valid

    bool addCategory(char medID, char catID); //used to add category to media

    bool isValidCategory(char medID, char catID);

    bool addCustomer(int id, string firstName, string lastName); // used to add customer to database.

    Customer* getCustomer(int id);

    bool addItem(Item* item, int stock);

    bool rentItem(Item* item, int custID, bool borrowing);

    bool returnItem(Item* item, int custID);

};

RentalStore::RentalStore() {
    this->mediaTypes = new vector<MediaType*>();
    for (int i = 0; i < MAX_CUST; i++) {
        customerList[i] = NULL;
    }
}

RentalStore::~RentalStore() {

}

void RentalStore::print() {
    for (int i = 0; i < this->mediaTypes->size(); i++) {
        this->mediaTypes->at(i)->print();
    }
    cout << "Customers:" << endl;
    for (int i = 0; i < MAX_CUST; i++) {
        if (this->customerList[i] != NULL) {
            this->customerList[i]->print();
        }
    }
}

bool RentalStore::addMediaType(char medID) {
    MediaType* med = getMediaType(medID);
    if (med == NULL) {
        this->mediaTypes->push_back(new MediaType(medID));
        return true;
    } else { // media type already exists
        return false;
    }
}

bool RentalStore::addCategory(char medID, char catID) {
    MediaType* med = getMediaType(medID);
    if (med == NULL) {
        return false;
    } else {
        return med->addCategory(catID);
    }
}

bool RentalStore::isValidCategory(char medID, char catID) {
    MediaType* med = getMediaType(medID);
    if (med == NULL) {
        return false;
    } else {
        return med->isValidCategory(catID);
    }
}

bool RentalStore::addCustomer(int id, string firstName, string lastName) {
    if (this->customerList[id] == NULL) {
        this->customerList[id] = new Customer(id, firstName, lastName);
        return true;
    } else {
        return false;
    }
}

Customer* RentalStore::getCustomer(int id) {
    if (this->customerList[id] == NULL) {
        cout << "ERROR: INVALID CUSTOMER" << endl;
    }
    return this->customerList[id];
}


bool RentalStore::addItem(Item* item, int stock) {
    if (item == NULL) {
        return false;
    } else {
        MediaType* med = getMediaType(item->mediaID());
        if (med != NULL) {
            return med->addItem(item, stock);
        }
    }
    return false;
}

bool RentalStore::rentItem(Item* item, int custID, bool borrowing) {
    return rentalHelper(item, custID, borrowing);
}

bool RentalStore::returnItem(Item* item, int custID) {
    return rentalHelper(item, custID, false);
}


bool RentalStore::rentalHelper(Item* item, int custID, bool borrowing) {
    Customer* cust = getCustomer(custID);
    if (item == NULL || cust == NULL) {
        return false;
    } else {
        MediaType* med = getMediaType(item->mediaID());
        if (med != NULL) {
            bool success = false;
            Category* categ = med->getCategory(item->mediaID());
            if (categ != NULL) {
                if (borrowing) {
                    success = categ->rentItem(item);
                } else {
                    success = categ->returnItem(item);
                }
                if (success) {
                    cust->addToHistory(item, borrowing);
                }
            }
            return success;
        }
        return false;
    }
}

MediaType* RentalStore::getMediaType(char medID) {
    for (int i = 0; i < this->mediaTypes->size(); i++) {
        if (this->mediaTypes->at(i)->getIdentifier() == medID) {
            return this->mediaTypes->at(i);
        }
    }
    return NULL;
}

#endif //ASSIGNMENT4_INVENTORY_H

