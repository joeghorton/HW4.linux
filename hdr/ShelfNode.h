//
// Created by Joe on 3/5/18.
//

#ifndef HW4_STOCKNODE_H
#define HW4_STOCKNODE_H

#include "Item.h"


class ShelfNode {

public:

    Item* item; // points to specific item within
    int stock;  // number of item left in stock
    ShelfNode* left; // points to TreeNodes that are 'less than' this one
    ShelfNode* right; // points to TreeNodes that are 'greater than' this one

    // constructor
    ShelfNode() : ShelfNode(nullptr, 0) {};

    ShelfNode(Item* item, int stock);

    // destructor
    ~ShelfNode();

    // returns number of these items currently in stock
    int getStock();

    virtual void addStock(int val);

    //returns true if successfully borrowed.
    //may modify later to print if only error.
    bool borrowItem();

    //returns true if successfully borrowed.
    //may modify later to print if only error
    void returnItem();

    void print();

};

#endif //HW4_STOCKNODE_H