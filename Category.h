
#ifndef ASSIGNMENT4_CATEGORY_H
#define ASSIGNMENT4_CATEGORY_H
#include "MediaType.h"
#include "ShelfNode.h"
#include "Item.h"

// The category class is used as the second part of a
// 2 part organizer. This class is used to only store
// items that are of the same media type and of the
// same category. This means that the items use the same
// comparison values and can be inserted in a specific
// sorted order

class Category {

private:
    char id; //genre identifier.
    ShelfNode* overallRoot; // pointer to items in this specific category

    // helper methods
    ShelfNode* insertItem(Item* item, int stock, ShelfNode* root);
    void print(ShelfNode* root);
    ShelfNode* findShelf(Item* item, ShelfNode* root);
    void destructorHelper(ShelfNode* root);

public:

    // constructor
    Category(char categID);

    //destructor.
    ~Category();

    //print the current inventory in this category.
    // traverse overall root
    void print();

    char getIdentifier();

    // inserts item into the root.
    // pre: item is same type as other items in this category
    void insertItem(Item* item, int stock);

    bool rentItem(Item*& item);

    bool returnItem(Item*& item);

};


Category::Category(char categID) {
    this->id = categID;
    this->overallRoot = NULL;
}

Category::~Category() {
    destructorHelper(this->overallRoot);
}

void Category::destructorHelper(ShelfNode* root) {
    if (root != NULL) {
        destructorHelper(root->left);
        destructorHelper(root->right);
        delete root;
    }
}

char Category::getIdentifier() {
    return this->id;
}

void Category::print() {
    cout << this->id << endl;
    print(this->overallRoot);
}

void Category::print(ShelfNode* root) {
    if (root != NULL) {
        print(root->left);
        root->print();
        print(root->right);
    }
}

void Category::insertItem(Item* item, int stock) {
    if (item != NULL) {
        this->overallRoot = insertItem(item, stock, this->overallRoot);
    } else {
        cout << "ERROR: NULL ITEM" << endl;
    }
}

ShelfNode* Category::insertItem(Item* item, int stock, ShelfNode* root) {
    if (root == NULL) {
        root = new ShelfNode(item, stock);
    } else if (*item < *root->item) {
        root->left = insertItem(item, stock, root->left);
    } else if (*item > *root->item) {
        root->right = insertItem(item, stock, root->right);
    } else { // items are equal, increase the stock
        root->addStock(stock);
        //delete item;
    }
    return root;
}

bool Category::rentItem(Item*& item) {
    ShelfNode* inTree = findShelf(item, this->overallRoot);
    if (inTree == NULL) {
        return false;
    } else {
        delete item;
        item = inTree->item;
        return inTree->borrowItem();
    }
}

bool Category::returnItem(Item*& item) {
    ShelfNode* inTree = findShelf(item, this->overallRoot);
    if (inTree == NULL) {
        return false;
    } else {
        inTree->returnItem();
        return true;
    }
}

// helper method
ShelfNode* Category::findShelf(Item* item, ShelfNode* root) {
    if (root == NULL) {
        return NULL;
    } else if (*item == *root->item) {
        return root;
    } else if (*item > *root->item) {
        return findShelf(item, root->right);
    } else { // item is less than than root
        return findShelf(item, root->left);
    }
}


#endif //ASSIGNMENT4_CATEGORY_H
