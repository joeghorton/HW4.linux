
#ifndef ASSIGNMENT4_INVENTORY_H
#define ASSIGNMENT4_INVENTORY_H
#include "Customer.h"
#include "MediaType.h"
#include "Item.h"
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

    void printInventory();

    void printCustomers();

    bool addMediaType(char medID); //used to add media type so then data valid

    bool addCategory(char medID, char catID); //used to add category to media

    bool isValidCategory(char medID, char catID);

    bool addCustomer(int id, string firstName, string lastName); // used to add customer to database.

    Customer* getCustomer(int custID);

    bool addItem(Item* item, int stock);

    bool rentalAction(Item* item, int custID, bool borrowing);

    bool rentItem(Item* item, int custID);

    bool returnItem(Item* item, int custID);

};

RentalStore::RentalStore() {
    this->mediaTypes = new vector<MediaType*>();
    for (int i = 0; i < MAX_CUST; i++) {
        customerList[i] = NULL;
    }
}

RentalStore::~RentalStore() {
    for (int i = 0; i < MAX_CUST; i++) {
        delete customerList[i];
    }
    for (int i = 0; i < this->mediaTypes->size(); i++) {
        delete this->mediaTypes->at(i);
    }
    delete this->mediaTypes;
}

void RentalStore::print() {
    cout << "Inventory" << endl;
    printInventory();
    cout << "Customers:" << endl;
    printCustomers();
}

void RentalStore::printInventory() {
    for (int i = 0; i < this->mediaTypes->size(); i++) {
        this->mediaTypes->at(i)->print();
    }
}

void RentalStore::printCustomers() {
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

bool RentalStore::addCustomer(int custID, string firstName, string lastName) {
    if (this->customerList[custID] == NULL) {
        this->customerList[custID] = new Customer(custID, firstName, lastName);
        return true;
    } else {
        return false;
    }
}

Customer* RentalStore::getCustomer(int custID) {
    if (this->customerList[custID] == NULL) {
        cout << "ERROR: INVALID CUSTOMER: " << custID << endl;
    }
    return this->customerList[custID];
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

bool RentalStore::rentalAction(Item* item, int custID, bool borrowing) {
    if (borrowing) {
        return rentItem(item, custID);
    } else {
        return returnItem(item, custID);
    }
}

bool RentalStore::rentItem(Item* item, int custID) {
    return rentalHelper(item, custID, true);
}

bool RentalStore::returnItem(Item* item, int custID) {
    return rentalHelper(item, custID, false);
}


bool RentalStore::rentalHelper(Item* item, int custID, bool borrowing) {
    Customer* cust = getCustomer(custID);
    if (item == NULL || cust == NULL) {
        return false;
    } else {
        bool success = false;
        MediaType* med = getMediaType(item->mediaID());
        if (med != NULL) {
            if (borrowing) {
                success = med->rentItem(item);
            } else {
                success = med->returnItem(item);
            }
            if (success) {
                cust->addToHistory(item, borrowing);
            }
        }
        return success;
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

