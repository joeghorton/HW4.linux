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

    bool rentMovieFromInput(char medID, char catID, int custID, ifstream& input, bool borrowing);

    void readInInventory(ifstream& input); //read in inventory from file
    void readInCustomers(ifstream& input); //read in customers from file
    void readInCommands(ifstream& input); // read in commands from file
    
};

MovieStore::MovieStore() {
    addMediaType('D');
    addCategory('D', 'F');
    addCategory('D', 'D');
    addCategory('D', 'C');
}

MovieStore::~MovieStore() {

}

void MovieStore::readInInventory(ifstream& input) {
    while (!input.eof()) {
        char category = ' ';
        int stock = 0, month = 0, year = 0;
        string director = "", title = "", actorFirst = "", actorLast = "";
        input >> category;
        if (isValidCategory('D', category)) {
            input.get(); // gets rid of ','
            input >> stock;
            input.get(); // gets rid of ','
            getline(input, director, ',');
            getline(input, title, ',');
            if (category == 'C') {
                input >> actorFirst;
                input >> actorLast;
                input >> month;
            }
            input >> year;
            if (!addMovie(category, stock, director, title, actorFirst, actorLast, month, year)) {
                cout << "ERROR MESSAGE: COULDN'T ADD" << endl;
            }
        } else { // invalid category
            string temp; // gets rid of line with invalid type
            getline(input, temp);
            cout << "ERROR: INVALID MOVIE TYPE" << endl;
        }
    }
}

void MovieStore::readInCustomers(ifstream& input) {
    string firstName = "", lastName = "";
    int id = 0;
    while (!input.eof()) {
        input >> id;
        input >> lastName;
        input >> firstName;
        addCustomer(id, firstName, lastName);
    }
}

void MovieStore::readInCommands(ifstream& input) {
    char type = 'x';
    while (type != ' ' && !input.eof()) {
        type = ' ';
        input >> type;
        if (type == 'I') {
            print();
        } else {
            int id = -1;
            input >> id;
            if (type == 'H') { // print customer historyFront
                Customer* cust = getCustomer(id);
                if (cust != NULL) {
                    cust->displayHistory();
                }
            } else {
                char mediaType = ' ';
                char category = ' ';
                input >> mediaType;
                input >> category;
                if (type == 'B') {
                    if (!rentMovieFromInput(mediaType, category, id, input, true)) {
                        cout << "ERROR: CAN'T BORROW" << endl;
                    } else {
                        cout << "success rent" << endl;
                    }
                } else if (type == 'R') {
                    if (!rentMovieFromInput(mediaType, category, id, input, false)) {
                        cout << "ERROR: CAN'T RETURN" << endl;
                    } else {
                        cout << "success borrow" << endl;
                    }
                } else {
                    cout << "ERROR: INVALID COMMAND" << endl;
                }
            }
        }
    }
}


bool MovieStore::addMovie(char category, int stock, string director, string title, string actorFirst, string actorLast,
                                int month, int year) {
    if (category == 'C') {
        return addItem(factory.createClassicalMovie(director, title, actorFirst, actorLast, month, year), stock);
    } else {
        return addItem(factory.createMovie(category, director, title, year), stock);
    }
}


bool MovieStore::rentMovieFromInput(char medID, char catID, int custID, ifstream& input, bool borrowing) {
    if (catID == 'C') {
        int month = 0, year = 0;
        string actorFirst = "", actorLast = "";
        input >> month;
        input >> year;
        input >> actorFirst;
        input >> actorLast;
        ClassicalMovie* movie = (ClassicalMovie*) (factory.createClassicalMovie("", "", actorFirst, actorLast, month, year));
        if (!rentItem((ClassicalMovie*) movie, custID, borrowing)) {
            cout << "ERROR: MOVIE NO EXIST" << endl;
        }
    } else if (catID == 'F') {
        string title = "";
        int year = -1;
        getline(input, title, ',');
        input >> year;
        ComedyMovie* movie = (ComedyMovie*) factory.createMovie(catID, "", title, year);
        if (!rentItem((ComedyMovie*) movie, custID, borrowing)) {
            cout << "ERROR: COMEDY MOVIE NO EXIST" << endl;
        }
    } else if (catID == 'D') {
        string director = "";
        string title = "";
        getline(input, director, ',');
        getline(input, title, ',');
        DramaMovie* movie = (DramaMovie*) factory.createMovie(catID, director, title, -1);
        if (!rentItem((DramaMovie*) movie, custID, borrowing)) {
            cout << "ERROR: MOVIE NO EXIST" << endl;
        }
    } else {
         cout << "ERROR: INVALID CATEGORY RENTAL" << endl;
    }

}

#endif //ASSIGNMENT4_MOVIESTORE_H