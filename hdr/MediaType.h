
#ifndef ASSIGNMENT4_MEDIATYPE_H
#define ASSIGNMENT4_MEDIATYPE_H

#include "Category.h"
#include "Item.h"
#include <vector>
using namespace std;

// Media Type is used to categorize the different types of media
// stored in the inventory. The identifier is used to check each
// item to see if they are a correct media type. Essentially, this
// is used to idenfity its position in the inventory list and act as
// a filter for invalid identifiers.

class MediaType {

private:
    char id; //used to categorize the media type
    vector<Category*>* categories; //stores all categories of particular type

    Category* getCategory(char catID);

    //friend class RentalStore;

public:

    //empty constructor

    explicit MediaType(char mediaID);

    // destructor for memory delete
    ~MediaType();

    //print media type
    void print();

    // returns media type identifier
    char getIdentifier();

    bool addCategory(char catID);

    bool isValidCategory(char catID);

    bool addItem(Item* item, int stock);

    bool rentItem(Item*& item);

    bool returnItem(Item*& item);

};

#endif //ASSIGNMENT4_MEDIATYPE_H
