//
// Created by Joe on 3/11/18.
//

#include "../hdr/RentalStore.h"

RentalStore::RentalStore() {
    this->mediaTypes = new vector<MediaType*>();
    for (auto& i : customerList) {
        i = nullptr;
    }
}

RentalStore::~RentalStore() {
    for (auto& i : customerList) {
        delete i;
    }
    for (auto& mediaType : *this->mediaTypes) {
        delete mediaType;
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
    for (auto& mediaType : *this->mediaTypes) {
        mediaType->print();
    }
}

void RentalStore::printCustomers() {
    for (auto& i : this->customerList) {
        if (i != nullptr) {
            i->print();
        }
    }
}

bool RentalStore::addMediaType(char medID) {
    MediaType* med = getMediaType(medID);
    if (med == nullptr) {
        this->mediaTypes->push_back(new MediaType(medID));
        return true;
    } else { // media type already exists
        return false;
    }
}

bool RentalStore::addCategory(char medID, char catID) {
    MediaType* med = getMediaType(medID);
    return med != nullptr && med->addCategory(catID);
}

bool RentalStore::isValidCategory(char medID, char catID) {
    MediaType* med = getMediaType(medID);
    return med != nullptr && med->isValidCategory(catID);
}

bool RentalStore::addCustomer(int custID, string firstName, string lastName) {
    if (this->customerList[custID] == nullptr) {
        this->customerList[custID] = new Customer(custID, firstName, lastName);
        return true;
    } else {
        return false;
    }
}

Customer* RentalStore::getCustomer(int custID) {
    if (this->customerList[custID] == nullptr) {
        cout << "ERROR: INVALID CUSTOMER: " << custID << endl;
    }
    return this->customerList[custID];
}


bool RentalStore::addItem(Item* item, int stock) {
    if (item == nullptr || stock < 0) {
        return false;
    } else {
        MediaType* med = getMediaType(item->mediaID());
        if (med != nullptr) {
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
    if (item == nullptr || cust == nullptr) {
        return false;
    } else {
        bool success = false;
        MediaType* med = getMediaType(item->mediaID());
        if (med != nullptr) {
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
    for (auto& mediaType : *this->mediaTypes) {
        if (mediaType->getIdentifier() == medID) {
            return mediaType;
        }
    }
    return nullptr;
}