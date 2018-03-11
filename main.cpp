#include <iostream>
#include <fstream>
#include "MovieStore.h"
using namespace std;

int main() {
    MovieStore store;
    // test file input
    ifstream infile1("data4movies.txt");

    if (!infile1) {
        cout << "File could not be opened." << endl;
        return 1;
    }

    //for each graph, find the shortest pathData from every node to all other nodes
    store.readInInventory(infile1);
    ifstream infile2("data4customers.txt");
    if (!infile2) {
        cout << "File could not be opened." << endl;
        return 2;
    }
    store.readInCustomers(infile2);
  //  store.print();

    ifstream infile3("data4commands.txt");
    if (!infile3) {
        cout << "File could not be opened." << endl;
        return 3;
    }
    cout << "--------------" << endl;
    store.readInCommands(infile3);
   // store.print();

    return 0;
}