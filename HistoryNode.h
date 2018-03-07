
#ifndef ASSIGNMENT4_RENTALNODE_H
#define ASSIGNMENT4_RENTALNODE_H

#include "Item.h"

// HistoryNode is used to keep track of an individual customer's
// transactions and whether the item was borrowed or returned.
// This class is used only as a basis for keeping
// the transactions organize. It does not serve any other purpose
// so it does not include many features.

class HistoryNode {

private:
    Item* item; // the particular item rented
    bool returned; //signifies if borrowed or returned

public:
    HistoryNode* nextRental; //next rental in history

    //constructor
    HistoryNode(Item* item, bool returned);

    // destructor
    ~HistoryNode();

    // signifies if returned.
    // returns true if a return. false if borrow
    bool wasReturned();

    // prints the information about the item in rental history
    // const because Item is stored in pointer and we dont want
    // to mess with data
    void printItem() const;

};

HistoryNode::HistoryNode(Item* item, bool returned) {
    this->item = item;
    this->returned = returned;
}

HistoryNode::~HistoryNode() {

}

bool HistoryNode::wasReturned() {
    return this->returned;
}

void HistoryNode::printItem() const {
    if (this->returned) {
        cout << "Returned: ";
    } else {
        cout << "Borrowed: ";
    }
    this->item->print();

}

#endif //ASSIGNMENT4_RENTALNODE_H
