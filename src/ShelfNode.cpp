//
// Created by Joe on 3/11/18.
//

#include "../hdr/ShelfNode.h"

ShelfNode::ShelfNode(Item* item, int stock) {
    this->item = item;
    this->stock = stock;
    this->left = nullptr;
    this->right = nullptr;
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