
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
// historyFront.

// This class is to add a valid customer to the database.
// only valid customers can borrow/return items to the movie store

class Customer {

private:
    int id; //4 digit customer ID
    string firstName; //first name
    string lastName; //last name
    HistoryNode* historyFront; //historyFront of rentals.

public:

    // constructor
    Customer(int id, string firstName, string lastName);

    // destructor
    ~Customer();

    // simple features
    int getID();
    string getFirstName();
    string getLastName();

    // prints out customer historyFront in order of most recently checked out
    void displayHistory();
    void print();

    void addToHistory(Item* item, bool borrowing);

};

#endif //ASSIGNMENT4_CUSTOMER_H
