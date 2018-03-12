//
// Created by Joe on 3/11/18.
//

#include "../hdr/HistoryNode.h"

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
        cout << "(borrowed)";
    } else {
        cout << "(returned)";
    }
    this->item->print();
}