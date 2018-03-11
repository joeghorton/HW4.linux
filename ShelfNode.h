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
    ShelfNode() : ShelfNode(NULL, 0) {};

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



ShelfNode::ShelfNode(Item* item, int stock) {
    this->item = item;
    this->stock = stock;
    this->left = NULL;
    this->right = NULL;
}

ShelfNode::~ShelfNode() {
    delete this->item;
}

int ShelfNode::getStock() {
    return this->stock;
}

void ShelfNode::addStock(int val) {
    if (val >= 0) {
        this->stock += val;
    } else {
        cout << "ERROR: CAN'T ADD NEGATIVE VALUES" << endl;
    }
}

bool ShelfNode::borrowItem() {
    if (this->stock > 0) {
        this->stock--;
        return true;
    } else {
        return false;
    }
}

void ShelfNode::returnItem() {
    this->stock++;
}

void ShelfNode::print() {
    this->item->print();
    cout << " | stock: " << this->stock << endl;
}

#endif //HW4_STOCKNODE_H