
#ifndef ASSIGNMENT4_RENTALNODE_H
#define ASSIGNMENT4_RENTALNODE_H

#include "Item.h"

// HistoryNode is used to keep track of an individual customer's
// transactions and whether the item was borrowed or borrowed.
// This class is used only as a basis for keeping
// the transactions organize. It does not serve any other purpose
// so it does not include many features.

class HistoryNode {

private:
    Item* item; // the particular item rented
    bool borrowed; //signifies if borrowed or borrowed

public:
    HistoryNode* prevRental; //next rental in historyFront

    //constructor
    HistoryNode(Item* item, bool returned);

    // destructor
    ~HistoryNode();

    // signifies if borrowed.
    // returns true if a return. false if borrow
    bool wasReturned();

    // prints the information about the item in rental historyFront
    // const because Item is stored in pointer and we dont want
    // to mess with data
    void printItem() const;

};

HistoryNode::HistoryNode(Item* item, bool returned) {
    this->item = item;
    this->borrowed = returned;
    this->prevRental = nullptr;
}

HistoryNode::~HistoryNode() = default;

bool HistoryNode::wasReturned() {
    return this->borrowed;
}

void HistoryNode::printItem() const {
    if (this->borrowed) {
        cout << "Borrowed: ";
    } else {
        cout << "Returned: ";
    }
    this->item->print();

}

#endif //ASSIGNMENT4_RENTALNODE_H
