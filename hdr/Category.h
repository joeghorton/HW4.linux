
#ifndef ASSIGNMENT4_CATEGORY_H
#define ASSIGNMENT4_CATEGORY_H


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
    char catID; //genre identifier.
    ShelfNode* overallRoot; // pointer to items in this specific category

    // helper methods
    ShelfNode* insertItem(Item* item, int stock, ShelfNode* root);
    void print(ShelfNode* root);
    ShelfNode* findShelf(Item* item, ShelfNode* root);
    void destructorHelper(ShelfNode* root);

public:

    // constructor
    explicit Category(char categID);

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

#endif //ASSIGNMENT4_CATEGORY_H
