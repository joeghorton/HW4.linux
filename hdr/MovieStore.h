//
// Created by emma on 3/1/18.
//

#ifndef ASSIGNMENT4_MOVIESTORE_H
#define ASSIGNMENT4_MOVIESTORE_H

#include "RentalStore.h"
#include "MovieFactory.h"
#include <fstream>

using namespace std;


class MovieStore : public RentalStore {

public:

    MovieFactory factory;

    // constructors
    MovieStore();

    ~MovieStore();

    bool addMovie(char category, int stock, string director, string title,
                  string actorFirst, string actorLast, int month, int year);

    bool rentMovieFromInput(char catID, int custID, ifstream& input, bool borrowing);

    void readInInventory(ifstream& input); //read in inventory from file
    void readInCustomers(ifstream& input); //read in customers from file
    void readInCommands(ifstream& input); // read in commands from file
    
};

#endif //ASSIGNMENT4_MOVIESTORE_H