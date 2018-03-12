//
// Created by Joe on 3/11/18.
//

#include "../hdr/Category.h"

Category::Category(char categID) {
    this->catID = categID;
    this->overallRoot = nullptr;
}

Category::~Category() {
    destructorHelper(this->overallRoot);
}

void Category::destructorHelper(ShelfNode* root) {
    if (root != nullptr) {
        destructorHelper(root->left);
        destructorHelper(root->right);
        delete root;
    }
}

char Category::getIdentifier() {
    return this->catID;
}

void Category::print() {
    cout << this->catID << endl;
    print(this->overallRoot);
}

void Category::print(ShelfNode* root) {
    if (root != nullptr) {
        print(root->left);
        root->print();
        print(root->right);
    }
}

void Category::insertItem(Item* item, int stock) {
    if (item != nullptr) {
        this->overallRoot = insertItem(item, stock, this->overallRoot);
    } else {
        cout << "ERROR: NULL ITEM" << endl;
    }
}

ShelfNode* Category::insertItem(Item* item, int stock, ShelfNode* root) {
    if (root == nullptr) {
        root = new ShelfNode(item, stock);
    } else if (*item < *root->item) {
        root->left = insertItem(item, stock, root->left);
    } else if (*item > *root->item) {
        root->right = insertItem(item, stock, root->right);
    } else { // items are equal, increase the stock
        root->addStock(stock);
        delete item;
    }
    return root;
}

bool Category::rentItem(Item*& item) {
    ShelfNode* inTree = findShelf(item, this->overallRoot);
    if (inTree == nullptr) {
        return false;
    } else {
        item = inTree->item;
        return inTree->borrowItem();
    }
}

bool Category::returnItem(Item*& item) {
    ShelfNode* inTree = findShelf(item, this->overallRoot);
    if (inTree == nullptr) {
        return false;
    } else {
        item = inTree->item;
        inTree->returnItem();
        return true;
    }
}

// helper method
ShelfNode* Category::findShelf(Item* item, ShelfNode* root) {
    if (root == nullptr) {
        return nullptr;
    } else if (*item == *root->item) {
        return root;
    } else if (*item > *root->item) {
        return findShelf(item, root->right);
    } else { // item is less than than root
        return findShelf(item, root->left);
    }
}