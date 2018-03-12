
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
    Customer* customerList[MAX_CUST]{};

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

    bool addCustomer(int custID, string firstName, string lastName); // used to add customer to database.

    Customer* getCustomer(int custID);

    bool addItem(Item* item, int stock);

    bool rentalAction(Item* item, int custID, bool borrowing);

    bool rentItem(Item* item, int custID);

    bool returnItem(Item* item, int custID);

};


#endif //ASSIGNMENT4_INVENTORY_H

