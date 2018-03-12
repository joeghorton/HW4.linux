//
// Created by Joe on 3/11/18.
//

#include "../hdr/Customer.h"

Customer::Customer(int id, string firstName, string lastName) {
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->historyFront = nullptr;
}

Customer::~Customer() {
    HistoryNode* cur = this->historyFront;
    while (cur != nullptr) {
        HistoryNode* next = cur->prevRental;
        delete cur;
        cur = next;
    }
}

int Customer::getID() {
    return this->id;
}

string Customer::getFirstName() {
    return this->firstName;
}

string Customer::getLastName() {
    return this->lastName;
}

void Customer::displayHistory() {
    HistoryNode* cur = this->historyFront;
    if (cur == nullptr) {
        cout << " (no rental history)";
    }
    while (cur != nullptr) {
        cout << endl;
        cur->printItem();
        cur = cur->prevRental;
    }
}

void Customer::print() {
    cout << this->lastName << ", " << this->firstName << " #" << this->id << ":";
    displayHistory();
    cout << endl;
}

void Customer::addToHistory(Item* item, bool borrowing) {
    HistoryNode* mostRecent = new HistoryNode(item, borrowing);
    mostRecent->prevRental = this->historyFront;
    this->historyFront = mostRecent;
}