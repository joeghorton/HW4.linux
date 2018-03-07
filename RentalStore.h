
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
    vector<MediaType> mediaTypes;

public:
    RentalStore(); //empty constructor
    virtual ~RentalStore();


    void print();

    bool addMediaType(char id); //used to add media type so then data valid

    bool addCategory(char medID, char catID); //used to add category to media

    bool isValidCategory(char medID, char catID);

    bool addCustomer(int id, string firstName, string lastName); // used to add customer to database.

    Customer* getCustomer(int id);

    bool addItem(char medID, char catID, Item* item, int stock);

    Item* getItem(Item* item);

};

RentalStore::RentalStore() {
    //this->mediaTypes = new vector<MediaType>();
    for (int i = 0; i < MAX_CUST; i++) {
        customerList[i] = NULL;
    }
}

RentalStore::~RentalStore() {

}

void RentalStore::print() {
    for (int i = 0; i < this->mediaTypes.size(); i++) {
        this->mediaTypes.at(i).print();
    }
    cout << "Customers:" << endl;
    for (int i = 0; i < MAX_CUST; i++) {
        if (this->customerList[i] != NULL) {
            (*this->customerList[i]).print();
        }
    }
}

bool RentalStore::addMediaType(char id) {
    for (int i = 0; i < this->mediaTypes.size(); i++) {
        if (this->mediaTypes.at(i).getIdentifier() == id) {
            return false;
        }
    }
    this->mediaTypes.push_back(MediaType(id));
    return true;
}

bool RentalStore::addCategory(char medID, char catID) {
    for (int i = 0; i < this->mediaTypes.size(); i++) {
        if (this->mediaTypes.at(i).getIdentifier() == medID) {
            return this->mediaTypes.at(i).addCategory(catID);
        }
    }
    return false;
}

bool RentalStore::isValidCategory(char medID, char catID) {
    for (int i = 0; i < this->mediaTypes.size(); i++) {
        if (this->mediaTypes.at(i).getIdentifier() == medID) {
            return this->mediaTypes.at(i).isValidCategory(catID);
        }
    }
    return false;
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


bool RentalStore::addItem(char medID, char catID, Item* item, int stock) {
    if (item == NULL) {
        return false;
    }
    for (int i = 0; i < this->mediaTypes.size(); i++) {
        if (this->mediaTypes.at(i).getIdentifier() == medID) {
            return this->mediaTypes.at(i).addItem(catID, item, stock);
        }
    }
    return false;
}

Item* RentalStore::getItem(Item* item) {
    return NULL;
}

#endif //ASSIGNMENT4_INVENTORY_H

