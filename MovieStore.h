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
    int count = 0;
    char command = 'x'; // fencepost
    while (command != ' ' && !input.eof()) {
        command = ' ';
        input >> command;
        if (command == 'I') {
            printInventory();
        } else if (command == 'H' || command == 'B' || command == 'R') {
            int custID = -1;
            input >> custID;
            if (command == 'H') { // print customer historyFront

                Customer* cust = getCustomer(custID);
                if (cust != NULL) {
                    cust->print();
                }

            } else {
                char mediaType = ' ';
                char category = ' ';
                input >> mediaType;
                input >> category;
                if (command == 'B') {
                    if (!rentMovieFromInput(category, custID, input, true)) {
                        cout << "borrow FAIL: " << category << " " << custID << endl;
                    } else {
                        cout << "borrow SUCCESS" << endl;
                    }
                } else if (command == 'R') {

                    if (!rentMovieFromInput(category, custID, input, false)) {
                        cout << "return FAIL: " << category << " " << custID << endl;
                    } else {
                        cout << "return SUCCESS" << endl;
                    }

                }
            }
        } else {
            cout << "INVALID COMMAND: " << command << endl;
            string temp;
            getline(input, temp);
        }
        count++;
        cout << count << ": ";
    }
}


bool MovieStore::addMovie(char category, int stock, string director, string title, string actorFirst, string actorLast,
                                int month, int year) {
    if (category == 'C') {
        return addItem(factory.createClassicalMovie(director, title, actorFirst, actorLast, month, year), stock);
    } else if (category == 'D') {
        return addItem(factory.createDramaMovie(director, title, year), stock);
    } else if (category == 'F') {
        return addItem(factory.createComedyMovie(director, title, year), stock);
    } else {
        return false;
    }
}


bool MovieStore::rentMovieFromInput(char catID, int custID, ifstream& input, bool borrowing) {
    Movie* movie = NULL;
    if (catID == 'C') {
        int month = 0, year = 0;
        string actorFirst = "", actorLast = "";
        input >> month;
        input >> year;
        input >> actorFirst;
        input >> actorLast;
        movie = factory.createClassicalMovie("", "", actorFirst, actorLast, month, year);

    } else if (catID == 'F') {
        string title = "";
        int year = -1;
        getline(input, title, ',');
        input >> year;
        movie = factory.createComedyMovie("", title, year);

    } else if (catID == 'D') {
        string director = "";
        string title = "";
        getline(input, director, ',');
        getline(input, title, ',');
        movie = factory.createDramaMovie(director, title, -1);
    } else {
        cout << "ERROR: INVALID CATEGORY: " << catID << endl;
        return false;
    }
    bool result = rentalAction(movie, custID, borrowing);
    delete movie;
    return result;
}

#endif //ASSIGNMENT4_MOVIESTORE_H