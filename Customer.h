
#ifndef ASSIGNMENT4_CUSTOMER_H
#define ASSIGNMENT4_CUSTOMER_H

#include "HistoryNode.h"
#include <string>
#include <iostream>
using namespace std;

// The Customer class stores all necessary information
// about each customer. It stores a unique customerdId which is used
// to locate the Customer in the customer database.
// It stores the name of the customer as well as the customers
// history.

// This class is to add a valid customer to the database.
// only valid customers can borrow/return items to the movie store

class Customer{

private:
    int id; //4 digit customer ID
    string firstName; //first name
    string lastName; //last name
    HistoryNode* history; //history of rentals.

public:

    // constructor
    Customer(int id, string firstName, string lastName);

    // simple features
    int getID();
    string getFirstName();
    string getLastName();

    // prints out customer history in order of most recently checked out
    void displayHistory();
    void print();

};

Customer::Customer(int id, string firstName, string lastName) {
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->history = NULL;
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
    HistoryNode* cur = this->history;
    while (cur != NULL) {
        cur->printItem();
        cur = cur->nextRental;
    }
}

void Customer::print() {
    cout << this->id << " " << this->lastName << " " << this->firstName << endl;
}

#endif //ASSIGNMENT4_CUSTOMER_H
